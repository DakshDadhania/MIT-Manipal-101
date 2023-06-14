import java.util.Scanner;

interface SCAN {
    Scanner sc = new Scanner(System.in);
}

abstract class BUS {
    String Bus_name;
    int Price;
    static String Source = "Manipal";
    String Destination;
    String ACNAC;
    String time;
    String opens[] = new String[20];

}

class Admin extends BUS implements SCAN {

    Admin() {

    }

    Admin(String Destination, String Bus_name, String ACNAC, String time, int Price) {
        this.Bus_name = Bus_name;
        this.Price = Price;
        this.Destination = Destination;
        this.ACNAC = ACNAC;
        this.time = time;

    }

    void read(Admin ad[]) {
        System.out.println("ENTER DETAILS:\n");
        System.out.println("ENTER TOTAL NO.OF BUSES:\n");
        int ch = sc.nextInt();
        for (int i = 0; i < ch; i++) {
            sc.nextLine();
            System.out.println("Enter Destination");
            String Destination = sc.nextLine();
            System.out.println("Bus Name:");
            String Bus_name = sc.nextLine();
            System.out.println("AC / NON-AC");
            String ACNAC = sc.nextLine();
            System.out.println("Enter time in HH:MM:SS format");
            String Time = sc.nextLine();
            System.out.println("Enter Price");
            int Price = sc.nextInt();
            ad[i] = new Admin(Destination, Bus_name, ACNAC, Time, Price);
        }

    }

}

class User extends BUS implements SCAN {
    User() {

    }

    void display(int i, Admin ad[], int n) {
        int j = 1;
        for (int k = i; k <= n; k++) {
            
            System.out.println(j + ":");
            System.out.println("Bus name: " + ad[k].Bus_name);
            System.out.println("Feature: " + ad[k].ACNAC);
            System.out.println("Time: " + ad[k].time);
            System.out.println("Price: " + ad[k].Price);
            System.out.print("\n \n");
            j++;

        }
    }

    void select_seats(Admin ad[], int ch) {
        System.out.println("How many seats u want to select?\n");
        int num = sc.nextInt();
        System.out.println("Select your Seats");
        int sec[] = new int[20];
        for (int i = 0; i < num; i++) {
            sec[i] = sc.nextInt();
        }
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < num; j++) {
                if (i == sec[j]) {
                    ad[ch].opens[i] = " BOOKED ";
                    break;

                }
            }
        }
    }

    void display_seats(Admin ad[], int ch) {
        System.out.println("SEATS:");
        for (int i = 0; i < 20; i++) {

            System.out.print((i + 1) + " " + ad[ch].opens[i] + "  ");

            if (((i + 1) % 5 == 4))
                System.out.print("       " + ad[ch].opens[i] + "  ");

            if ((i + 1) % 5 == 0)
                System.out.println("");
        }

    }

    int selectbus(Admin ad[]) {
        System.out.println("enter your choice:\n");
        int ch = sc.nextInt();
        System.out.println(ad[ch].Bus_name);
        System.out.println("enter your option:\n 1.display seats 2.select seats \n");
        int a = sc.nextInt();
        for (int i = 0; i < 20; i++)
            ad[ch].opens[i] = "      ";
        while (a == 1 | a == 2) {
            if (a == 1)
                display_seats(ad, ch);
            else if (a == 2)
                select_seats(ad, ch);
            else if (a != 1 | a != 2)
                break;
            System.out.println("enter your option for seats:");
            a = sc.nextInt();

        }
        return 0;
    }

    void framework(Admin ad[]) {
        System.out.println("Choose Your Destination ");
        System.out.print("1. " + ad[0].Destination + "\n2. " + ad[3].Destination + "\n3. " + ad[6].Destination + "\n");
        int ch = sc.nextInt();
        while (ch < 4) {
            switch (ch) {
                case 1:
                    display(0, ad, 2);
                    selectbus(ad);
                    break;

                case 2:
                    display(3, ad, 5);
                    selectbus(ad);
                    break;

                case 3:
                    display(6, ad, 8);
                    selectbus(ad);
                    break;

            }
            System.out.println("Choose Your Destination ");
            System.out.print(
                    "1. " + ad[0].Destination + "\n2. " + ad[3].Destination + "\n3. " + ad[6].Destination + "\n");
            ch = sc.nextInt();
        }

    }

}

class assign implements SCAN {
    public static void main(String[] args) {

        System.out.println("                                     BUS RESERVATON SYSTEM                                    ");
        System.out.println("                                           LOGIN                                              ");
        Admin cp[] = new Admin[10];
        System.out.println("1.ADMIN\n2.USER\n3.EXIT\n");
        int ch = sc.nextInt();
        while (ch == 1 | ch == 2) {
            switch (ch) {
                case 1:
                    System.out.println("ADMIN");
                    Admin ob1, ad[] = new Admin[10];
                    ob1 = new Admin();
                    ob1.read(ad);
                    cp = ad;
                    break;
                case 2:
                    System.out.println("USER");
                    Login ob2;
                    ob2 = new Login();
                    ob2.framework(cp);

            }
            System.out.print("1.ADMIN \n 2.USER\n 3.EXIT \n");
            ch = sc.nextInt();
        }

        sc.close();

    }

}
