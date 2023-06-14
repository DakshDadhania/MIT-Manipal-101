import java.util.*;
import java.io.FileWriter;
import java.io.IOException;  

class Book{
    String book;
    String author;
    float edition;

    Book(String b, String a, float e){
        this.book = b;
        this.author = a;
        this.edition = e;
    }

    void writeToFile() throws IOException {
        FileWriter fw = new FileWriter("books.txt", true);
        fw.write(book + " " + author + " " + edition + "\n");
        fw.close();
    }
}

public class six {
    public static void main(String[] args) throws IOException {
        Book b1 = new Book("Kudryavka's Order", "Harry", 4);
        Book b2 = new Book("The Murder on the Orient Express", "Agatha Christie", 4);
        Book b3 = new Book("A Study in Scarlet", "Sir Arthur Conan Doyle", 4);
        Book b4 = new Book("Animal Farm", "George Orwell", 4);
        Book b5 = new Book("No Longer Human", "Osamu Dazai", 4);
        Book b6 = new Book("The Murder of Roger Ackroyd", "Agatha Christie", 4);
        b1.writeToFile();
        b2.writeToFile();
        b3.writeToFile();
        b4.writeToFile();
        b5.writeToFile();
        b6.writeToFile();
        Scanner in = null;
        in = new Scanner("books.txt");
        String line = in.nextLine();
        while(in.hasNext()) {
            if(line.contains("Harry")) {
                System.out.println(line);
            }   
                   
            if(!line.contains("Harry")) {
                System.out.println("no match for your search");
                System.exit(0);
            }
        }
        in.close();
    }
}
