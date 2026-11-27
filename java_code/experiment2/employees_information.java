package java_code.experiment2;

class Employee{
    private String id;
    private String name;
    private double salary;
    public Employee(String id, String name, double salary){
        this.id=id;
        this.name=name;
        this.salary=salary;
    }
    public String getId(){ return id; }
    public String getName(){ return name; }
    public double getSalary(){ return salary; }

    @Override
    public String toString(){
        return"ID:"+id+", name:"+name+", salary: "+salary;
    }

    public static void main(String[] args){
        Employee[] list={
            new Employee("0001", "董致源", 100000.0),
            new Employee("0005", "张三", 2500.0),
            new Employee("0006", "小王", 2500.0),
            new Employee("0007", "小夏", 2500.0),
            new Manager("0002", "李四", 3500.0, "软件开发部"),
            new Manager("0003", "王五", 3500.0, "软件销售部"),
            new Director("0004", "小明", 4500.0, 200.0)
        };
        System.out.println("所有员工:");
        for(Employee e:list) {
            System.out.println(e);   
        }
    }
}

class Manager extends Employee{
    private String department;
    public Manager(String id, String name, double salary, String department){
        super(id, name, salary);
        this.department=department;
    }
    @Override
    public String toString(){
        return super.toString()+", 管理部门: "+department;
    }
}

class Director extends Employee{
    private double allowance;
    public Director(String id, String name, double salary, double allowance){
        super(id, name, salary);
        this.allowance=allowance;
    }
    @Override
    public String toString(){
        return super.toString()+", 津贴: "+allowance;
    }
}