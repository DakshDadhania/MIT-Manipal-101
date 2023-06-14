import javax.swing.*;
import javax.swing.JTextField;

public class jfrrame {
    public static void main(String[] args) {
        Myframe m= new Myframe();  
        JLabel lab=new JLabel();
        lab.setText("Do you code?");
        m.add(lab);
        lab.setText("Do you code?");
        m.add(lab);
        JLabel l1=new JLabel("Username :");
        m.add(l1);
        JTextField t1= new JTextField(40);
        m.add(t1);
        JLabel l2=new JLabel("Password");
        m.add(l2);
        JTextField t2= new JTextField(20);
        m.add(t2);
        JButton b=new JButton("Submit");
        m.add(b);


    }
}
