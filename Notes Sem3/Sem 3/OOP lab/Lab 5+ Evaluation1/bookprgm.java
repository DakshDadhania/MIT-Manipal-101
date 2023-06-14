/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter; 
import java.io.IOException;

class Book{
    
    
    

    public String title, author, edition;
    Book(String s1, String s2, String s3) {
        this.title = s1;
        this.author = s2;
        this.edition = s3;
    }
    void display() {
        System.out.println(this.title);
        System.out.println(this.author);
        System.out.println(this.edition);
    }
    void write(Book arr, FileWriter fr) throws IOException{
        // File f= new File("filewrit.txt");
        // BufferedWriter fr = new BufferedWriter(null);
        
        fr.append(arr.author);
        fr.append(arr.title);
        fr.append(arr.edition);
       fr.append("\n");
      
    }
}

public class bookprgm { 
    public static void main(String args[]) throws IOException {
        Book arr;
        File f=new File("filewrit.txt");
        FileWriter fr= new FileWriter(f);
        arr = new Book("A", "Harry", "12");
        arr.write(arr,fr);
        arr = new Book("B", "Mary", "13");
        arr.write(arr,fr);
        arr = new Book("A", "Harry", "12");
        arr.write(arr,fr);
        // arr = new Book("B", "Mary", "13");
        // arr.write(arr);
        // arr = new Book("A", "Harry", "12");
        // arr.write(arr);
        // arr = new Book("B", "Mary", "13");
        // arr.write(arr);
    //    Scanner in=new Scanner(System.in);
    //    String  n1=in.next();
    //    String n2=in.next();
    //    String n3=in.next();

    //    int arr=new Book(n1,n2,n3);
        fr.close();
        // FileReader br= new FileReader(f);
        // // BufferedReader br=new BufferedReader(Rr);
        // int s;
        // while((s=br.read())!=-1){
        //     System.out.print((char)s);
        // }
        Scanner inn= new Scanner(f);
        while(inn.hasNext()){
            System.out.println( inn.nextLine());
           
        }
           
        
        // in.close();
      
    }
}
