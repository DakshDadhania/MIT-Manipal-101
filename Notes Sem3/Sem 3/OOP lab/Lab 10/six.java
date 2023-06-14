import java.io.*;
import java.util.Scanner;
class Employee implements Serializable{
    private static final long serialVersionUID= 1L;
    double salary, allowance, deductions;
    int empno;
    Employee(int e, double s){
        empno=e;
        salary=s;
    }
    void calculate(){
        deductions=0.2*salary;
        allowance=10000;
        salary=salary+allowance-deductions;
    }
    void display(){
        System.out.println(empno+" "+salary+" ");
    }
}

public class six{
    public static void main(String args[])throws Exception{
        Scanner in=new Scanner(System.in);
        System.out.println("Enter Employee No and Employee Salary");
        int empno,salary;
        empno=in.nextInt();
        salary=in.nextInt();
        Employee e= new Employee(empno, salary);
        ObjectOutputStream oos= new ObjectOutputStream(new FileOutputStream(new File("Sixth.txt")));
        oos.writeObject(e);
        oos.close();
        ObjectInputStream ois= new ObjectInputStream(new FileInputStream(new File("Sixth.txt")));
        Employee e1=(Employee)ois.readObject();
        e1.calculate();
        e1.display();
    }
}