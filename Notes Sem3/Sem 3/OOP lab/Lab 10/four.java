import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;

public class four{
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        File f1 = new File("4.txt");
        if (!f1.exists())
            f1.createNewFile();
        try{
            KeyGenerator kg = KeyGenerator.getInstance("DES");
            SecretKey myKey = kg.generateKey();

            Cipher dC;
            dC = Cipher.getInstance("DES");

            FileOutputStream bor = new FileOutputStream(f1, true);
            System.out.println("Enter a line of string:");
            String s1 = scan.nextLine();
           
            byte[] text = s1.getBytes("UTF8");
            dC.init(Cipher.ENCRYPT_MODE, myKey);
            byte[] textEnc = dC.doFinal(text);
            
            bor.write(textEnc);
            bor.write('\n');
            bor.flush();
            System.out.println("Successfully written!");
            

            String s = new String(textEnc);
            

            dC.init(Cipher.DECRYPT_MODE, myKey);
            
            FileInputStream bir = new FileInputStream(f1);
            System.out.println("READING FILE:");
            int ch;
            while (( ch = bir.read()) != -1) {
                System.out.print((char) ch);
            }
            byte[] textDecr = dC.doFinal(textEnc);
            s = new String(textDecr);
            System.out.println(s);
        }catch(Exception e)
        {
            System.out.println("Exception");
        }
    }
}