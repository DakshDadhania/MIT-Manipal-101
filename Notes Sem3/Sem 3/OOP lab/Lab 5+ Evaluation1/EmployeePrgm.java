
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author student
 */
class Employee{
    String name,city;
    double basic_salary, dearness_allowance, house_rent;
    double total_salary;
    void getdata(String n,String m,double b,double d,double r){
        this.name=n;
        this.city=m;
        this.basic_salary=b;
        this.dearness_allowance=d;
        this.house_rent=r;
    }
    void calculate(){
        total_salary = basic_salary+basic_salary*dearness_allowance/100+basic_salary*house_rent/100;
    }
    void display(){
        System.out.println("Total salary is"+total_salary);
    }
}
public class EmployeePrgm {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        Employee e1=new Employee();
        String name,city;
        double bs, da, hr;
        System.out.print("Enter employee details first input name");
        name=in.next();
        System.out.print("Enter employee city");
        city=in.next();
        System.out.print("Enter employee basic salary");
        bs=in.nextDouble();
        System.out.print("Enter employee dearness_allowance");
        da=in.nextDouble();
        System.out.print("Enter employee house_rent");
        hr=in.nextDouble();
        
        e1.getdata(name, city, bs, da, hr);
        e1.calculate();
        e1.display();
        
    }
}
