package cinema;

import java.time.LocalDateTime;
import java.util.*;
import java.util.function.BiPredicate;

/** Algorithm toolbox: seat recommendation, top-K, binary search, scheduling, grid BFS. */
public final class Algorithms {
    private Algorithms() {}

    /** Cleaning gap between two screenings in the same hall (minutes). */
    public static final int GAP_MIN=15;
    /** Business hours: screenings must start at or after OPEN_HOUR and end before midnight. */
    public static final int OPEN_HOUR=8;
    // ------------------------------------------------------------------
    // 1. Consecutive seat recommendation (sliding window + scoring)
    // ------------------------------------------------------------------
    
    /** A candidate block of consecutive seats in one row. Lower score is better. */
    public static class SeatGroup {
        public final int row, startCol, size;
        public final double score;
        public SeatGroup(int row, int startCol, int size, double score) {
            this.row = row; this.startCol = startCol; this.size = size; this.score = score;
        }
    }

    /**
     * Recommends blocks of k consecutive free seats.
     * Each row is scanned with a window of width k; the number of sold seats inside the window is
     * updated incrementally (O(1) per step) and a window with no sold seat is a candidate.
     * Score = distance of the window centre to the hall's centre column
     *       + 1.5 * distance of the row to the ideal row (about 60% of the hall depth)
     *       + 3 for every side where exactly one free seat would be left alone (a "fragment").
     * The best topN candidates are selected with a heap (see {@link #topK}).
     */
    public static List<SeatGroup> recommend(Screening s, int k, int topN) {
        Hall h = s.getHall();
        int rows = h.getRows(), cols = h.getCols();
        double idealRow = (rows - 1) * 0.6, midCol = (cols - 1) / 2.0;
        List<SeatGroup> all = new ArrayList<>();
        for (int r = 0; r < rows; r++) {
            int soldInWindow = 0;
            for (int c = 0; c < cols; c++) {
                if (s.isSold(r, c)) soldInWindow++;                        // seat entering the window
                if (c >= k && s.isSold(r, c - k)) soldInWindow--;          // seat leaving the window
                if (c >= k - 1 && soldInWindow == 0) {
                    int start = c - k + 1;
                    double score = Math.abs(start + (k - 1) / 2.0 - midCol) + 1.5 * Math.abs(r - idealRow);
                    int left = 0, right = 0;
                    for (int x = start - 1; x >= 0 && !s.isSold(r, x); x--) left++;
                    for (int x = c + 1; x < cols && !s.isSold(r, x); x++) right++;
                    if (left == 1) score += 3;
                    if (right == 1) score += 3;
                    all.add(new SeatGroup(r, start, k, score));
                }
            }
        }
        return topK(all, topN, Comparator.comparingDouble((SeatGroup g) -> -g.score));
    }

    // ------------------------------------------------------------------
    // 2. Generic top-K with a min-heap
    // ------------------------------------------------------------------

    /**
     * Returns the k greatest elements according to cmp (descending). A min-heap of size k is kept,
     * so the running time is O(n log k).
     */
    public static <T> List<T> topK(Collection<T> data, int k, Comparator<T> cmp) {
        PriorityQueue<T> heap = new PriorityQueue<>(cmp);
        for (T x : data) {
            if (heap.size() < k) heap.offer(x);
            else if (cmp.compare(x, heap.peek()) > 0) { heap.poll(); heap.offer(x); }
        }
        List<T> res = new ArrayList<>(heap);
        res.sort(cmp.reversed());
        return res;
    }

    // ------------------------------------------------------------------
    // 3. Binary searches on screening lists sorted by start time
    // ------------------------------------------------------------------

    /** First index whose start time is &gt;= t (lower bound). */
    public static int lowerBound(List<Screening> sorted, LocalDateTime t) {
        int lo = 0, hi = sorted.size();
        while (lo < hi) {
            int mid = (lo + hi) >>> 1;
            if (sorted.get(mid).getStart().isBefore(t)) lo = mid + 1; else hi = mid;
        }
        return lo;
    }

    /** Last index whose start time is &lt;= t, or -1 if there is none. */
    public static int floorIndex(List<Screening> sorted, LocalDateTime t) {
        int lo = 0, hi = sorted.size();
        while (lo < hi) {                       // find first index with start > t
            int mid = (lo + hi) >>> 1;
            if (sorted.get(mid).getStart().isAfter(t)) hi = mid; else lo = mid + 1;
        }
        return lo - 1;
    }

    // ------------------------------------------------------------------
    // 4. Scheduling: conflict detection and earliest free slot
    // ------------------------------------------------------------------

    /**
     * Finds a screening that conflicts with the interval [start, end] (including the cleaning gap).
     * Screenings of one hall are sorted and never overlap, so after a binary search only the
     * neighbour before and the neighbour after the insertion point can conflict: O(log n).
     * Returns null if there is no conflict.
     */
    public static Screening findConflict(List<Screening> hallSchedule, LocalDateTime start, LocalDateTime end) {
        int i = lowerBound(hallSchedule, start);
        if (i > 0) {
            Screening prev = hallSchedule.get(i - 1);
            if (prev.end().plusMinutes(GAP_MIN).isAfter(start)) return prev;
        }
        if (i < hallSchedule.size()) {
            Screening next = hallSchedule.get(i);
            if (next.getStart().isBefore(end.plusMinutes(GAP_MIN))) return next;
        }
        return null;
    }

    /** Moves t forward so that a show of the given duration starting at t is inside business hours. */
    private static LocalDateTime fitBusinessHours(LocalDateTime t, int duration) {
        LocalDateTime open = t.toLocalDate().atTime(OPEN_HOUR, 0);
        if (t.isBefore(open)) t = open;
        LocalDateTime close = t.toLocalDate().plusDays(1).atStartOfDay();
        if (t.plusMinutes(duration).isAfter(close)) t = t.toLocalDate().plusDays(1).atTime(OPEN_HOUR, 0);
        return t;
    }

    /** True if a show of the given duration starting at t is inside business hours. */
    public static boolean insideBusinessHours(LocalDateTime t, int duration) {
        return fitBusinessHours(t, duration).equals(t);
    }

    /**
     * Earliest start time (not before 'earliest') at which a show of the given duration fits into
     * the hall's schedule and into business hours. The candidate time only moves forward while the
     * sorted schedule is scanned once, so the scan itself is O(n).
     */
    public static LocalDateTime earliestSlot(List<Screening> hallSchedule, LocalDateTime earliest, int duration) {
        LocalDateTime cand = earliest;
        int i = 0;
        while (true) {
            cand = fitBusinessHours(cand, duration);
            boolean moved = false;
            while (i < hallSchedule.size()) {
                Screening s = hallSchedule.get(i);
                if (!cand.isBefore(s.end().plusMinutes(GAP_MIN))) { i++; continue; }   // entirely before cand
                if (s.getStart().isBefore(cand.plusMinutes(duration + GAP_MIN))) {      // overlaps cand
                    cand = s.end().plusMinutes(GAP_MIN);
                    i++;
                    moved = true;
                }
                break;
            }
            if (!moved) return cand;
        }
    }

    // ------------------------------------------------------------------
    // 5. Breadth-first search on the city grid
    // ------------------------------------------------------------------

    /** A target found by the grid BFS, with its walking distance and the path from the start. */
    public static class GridHit {
        public final int row, col, dist;
        public final List<int[]> path;       // cells from the start to the target, both included
        public GridHit(int row, int col, int dist, List<int[]> path) {
            this.row = row; this.col = col; this.dist = dist; this.path = path;
        }
    }

    /**
     * Breadth-first search from (sr, sc) over 4-connected walkable cells (grid value != blockedValue).
     * Cells are visited in non-decreasing walking distance, so the first targets reached are the
     * nearest ones. Stops after 'limit' targets. O(rows * cols).
     */
    public static List<GridHit> bfsNearest(int[][] grid, int blockedValue, int sr, int sc,
                                           BiPredicate<Integer, Integer> isTarget, int limit) {
        int rows = grid.length, cols = grid[0].length;
        int[] parent = new int[rows * cols];
        int[] dist = new int[rows * cols];
        Arrays.fill(dist, -1);
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        int startIdx = sr * cols + sc;
        dist[startIdx] = 0; parent[startIdx] = -1;
        queue.add(startIdx);
        int[] dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
        List<GridHit> hits = new ArrayList<>();
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            int r = cur / cols, c = cur % cols;
            if (isTarget.test(r, c)) {
                LinkedList<int[]> path = new LinkedList<>();
                for (int x = cur; x != -1; x = parent[x]) path.addFirst(new int[]{x / cols, x % cols});
                hits.add(new GridHit(r, c, dist[cur], path));
                if (hits.size() >= limit) break;
            }
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] == blockedValue) continue;
                int ni = nr * cols + nc;
                if (dist[ni] != -1) continue;
                dist[ni] = dist[cur] + 1; parent[ni] = cur;
                queue.add(ni);
            }
        }
        return hits;
    }
}
