
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


import javax.swing.*;

class Count {
    int Count;

    Count() {
        this.Count = 0;
    }

    void add() {
        this.Count += 6;
    }

    String ret() {
        return Integer.toString(this.Count);
    }
}

class Myframe extends JFrame implements ActionListener {
    JButton b;
    JTextField t;
    Count c = new Count();
    Myframe() {

        this.setTitle("Counter");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);// exit on close
        this.setVisible(true);
        this.setSize(800, 400);
        this.setLayout(new FlowLayout());
        JLabel l = new JLabel("Counter");
        this.add(l);
        t = new JTextField(20);
        this.add(t);
        b = new JButton("Count");
        b.addActionListener(this);
        this.add(b);

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==b){
        c.add();
        t.setText(c.ret());
        }

    }
}

public class seven  {
  

    public static void main(String[] args) {
       Myframe frame=new Myframe();

    }

}
