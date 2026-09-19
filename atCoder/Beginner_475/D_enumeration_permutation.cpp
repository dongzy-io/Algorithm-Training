#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

using namespace std;

bool is_prime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    if (!(cin >> S)) return 0;
    vector<char> unique_chars;
    for (char c : S) {
        if (find(unique_chars.begin(), unique_chars.end(), c) == unique_chars.end()) {
            unique_chars.push_back(c);
        }
    }

    int k = unique_chars.size();
    if (k > 10) {
        cout << -1 << "\n";
        return 0;
    }

    // Try all digit permutations
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    do {
        map<char, int> char_to_digit;
        for (int i = 0; i < k; ++i) {
            char_to_digit[unique_chars[i]] = digits[i];
        }
        if (char_to_digit[S[0]] == 0) {
            continue;
        }
        long long P = 0;
        for (char c : S) {
            P = P * 10 + char_to_digit[c];
        }
        if (is_prime(P)) {
            cout << P << "\n";
            return 0;
        }
    } while (next_permutation(digits.begin(), digits.end()));

    cout << -1 << "\n";
    return 0;
}