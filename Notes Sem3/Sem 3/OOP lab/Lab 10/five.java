import java.io.*;
class Student implements Serializable{
    private static final long serialVersionUID = 1L;
    double percentage;
    char grade;
    int roll;
    Student(double p, int r,char g){
        percentage=p;
        grade=g;
        roll=r;
    }
    void display(){
        System.out.println(roll+" "+grade+" "+percentage);
    }
}

class five{
    public static void main(String args[])throws Exception{
        ObjectOutputStream oos= new ObjectOutputStream(new FileOutputStream(new File("5.txt")));
        Student s= new Student(Double.parseDouble("89.9"),1212, "B".charAt(0));
        oos.writeObject(s);
        oos.close();
        ObjectInputStream ois= new ObjectInputStream(new FileInputStream(new File("5.txt")));
        Student s1= (Student) ois.readObject();
        s1.display();
        ois.close();
    }
}