import java.io.*;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;
class Login {
    static ArrayList<String> Username= new ArrayList<>();
    static ArrayList<String> Password= new ArrayList<>();
    Login(String User, String Pass){
        Username.add(User);
        Password.add(Pass);
    }

    static boolean check_User(String User, String pass){
        if(Username.contains(User) && Password.contains(pass)){
            return true;
        }
        return false;
    }

}
interface GlobalConstants
{


    static final int available[] = new int[6];
    static final int ticketI[][] = new int [100][3];
    static final String ticketS[][] = new String[100][3];
    static final double ticketD[][] = new double [100][3];
    static final double pay[] = new double[20];
    static final double change[] = new double[20];
}
class BusReservationAndTicketingSystem implements GlobalConstants {
    public static void BUSR() throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String yn,search,again,choice;

        int to=0,y=1,z=0,end=0,r=1;




        //"available[]" is the SEAT AVAILABLE//
        //store 20 seats every destination [1-5]//
        for(int o=1; o<=5; o++){
            available[o]=20;
        }

        //if user and password are correct proceed to MAIN MENU//
        for(int x=1; x==1;){
            //the MAIN MENU//
            System.out.println("**********************************************************");
            System.out.println("****** BUS RESERVATION AND TICKETING SYSTEM-MANIPAL ******");
            System.out.println("**********************************************************");
            System.out.println("** [1] Destination/ Timings available                   **");
            System.out.println("** [2] Passenger Booking                                **");
            System.out.println("** [3] Billing/ Payment Gateway                         **");
            System.out.println("** [4] View                                             **");
            System.out.println("** [5] Exit                                             **");
            System.out.println("**********************************************************");
            System.out.println("**********************************************************\n");

            for(x=1; x==1;){
                System.out.print("ENTER CHOICE: ");
                choice=in.readLine();

                //if CHOICE is "1" display the DESTINATION//
                switch (choice) {
                    case "1":
                        //the DESTINATION DETAILS//
                        //display the "Destination", every destination "Fare", and the "Seat" available//
                        System.out.println("*******************************************************************************************************************");
                        System.out.println("****    SOURCE  ->    DESTINATION      |                 Timings         |  FARE    |         SEAT             ****");
                        System.out.println("*******************************************************************************************************************");
                        System.out.println("**** 1.)MANIPAL -> MUMBAI Bus Depot    |   9:55 PM - 3:07 PM 17hr 12min  | Rs. 3600 |   " + available[1] + "   ****");
                        System.out.println("**** 2.)MANIPAL -> BANGALORE Bus Depot |   8:30 PM - 4:52 AM 8hr 22min   | Rs. 1300 |   " + available[2] + "   ****");
                        System.out.println("**** 3.)MANIPAL -> DELHI Bus Depot     |   9:55 PM - 8:32 AM  1day 11hr  | Rs. 4500 |   " + available[3] + "   ****");
                        System.out.println("**** 4.)MANIPAL -> AHMEDABAD Bus Depot |   9:55 PM - 5:35 AM  1day 8hr   | Rs. 4000 |   " + available[4] + "   ****");
                        System.out.println("**** 5.)MANIPAL -> CHENNAI Bus Depot   |   8:55 PM - 11:00 AM  14hr 5min | Rs. 1950 |   " + available[5] + "   ****");
                        System.out.println("*******************************************************************************************************************");
                        System.out.println("*******************************************************************************************************************\n");
                        System.out.println("PWD, STUDENT, & SENIOR CITIZEN with 20% DISCOUNT!!!\n");
                        x = 0;
                        break;

                    //if CHOICE is "2" proceed to Ticket Booking//
                    case "2":
                        int print = 1;


                        //display first the Destination Details//
                        System.out.println("*******************************************************************************************************************");
                        System.out.println("****    SOURCE  ->    DESTINATION      |                 Timings         |  FARE    |         SEAT             ****");
                        System.out.println("*******************************************************************************************************************");
                        System.out.println("**** 1.)MANIPAL -> MUMBAI Bus Depot    |   9:55 PM - 3:07 PM 17hr 12min  | Rs. 3600 |   " + available[1] + "   ****");
                        System.out.println("**** 2.)MANIPAL -> BANGALORE Bus Depot |   8:30 PM - 4:52 AM 8hr 22min   | Rs. 1300 |   " + available[2] + "   ****");
                        System.out.println("**** 3.)MANIPAL -> DELHI Bus Depot     |   9:55 PM - 8:32 AM  1day 11hr  | Rs. 4500 |   " + available[3] + "   ****");
                        System.out.println("**** 4.)MANIPAL -> AHMEDABAD Bus Depot |   9:55 PM - 5:35 AM  1day 8hr   | Rs. 4000 |   " + available[4] + "   ****");
                        System.out.println("**** 5.)MANIPAL -> CHENNAI Bus Depot   |   8:55 PM - 11:00 AM  14hr 5min | Rs. 1950 |   " + available[5] + "   ****");
                        System.out.println("*******************************************************************************************************************");
                        System.out.println("*******************************************************************************************************************\n");
                        System.out.println("PWD, STUDENT, & SENIOR CITIZEN with 20% DISCOUNT!!!\n");

                        if ((available[1] == 0) && (available[2] == 0) && (available[3] == 0) && (available[4] == 0) && (available[5] == 0)) {
                            System.out.println("Sorry, We don't  have available seats for all Destination!");
                            x = 0;

                        }


                        //inputting of Passenger's Name//
                        else {
                            for (x = 1; x == 1; ) {
                                System.out.print("\nENTER PASSENGER'S NAME: ");
                                ticketS[z][0] = in.readLine();

                                x = 0;

                                //if Passenger's Name already used, display error and go back to Inputting//
                                for (int l = 0; l < z; l++) {
                                    if (ticketS[l][0].equalsIgnoreCase(ticketS[z][0])) {
                                        System.out.println("Sorry, Passenger's name have already used!");
                                        x = 1;
                                    }
                                }
                            }

                            //inputting of Destination//
                            //integers Only [1-5]//
                            for (x = 1; x == 1; ) {
                                System.out.print("ENTER DESTINATION [number]: ");
                                to = Integer.parseInt(in.readLine());

                                //if Inputted integers are "<1" or ">5", display error and go back to Inputting//
                                if (to < 1 || to > 5) {
                                    System.out.println("Invalid Input!");
                                    x = 1;
                                }
                                //if available seat is equal to "Zero", display error and go back to Inputting//
                                for (int d = 1; d <= 5; d++) {
                                    if (to == d) {
                                        if (available[to] == 0) {
                                            System.out.println("Sorry, We don't have available seat!");
                                        }
                                        x = 0;
                                    }
                                }
                            }

                            //convert the integer to string//
                            String dest[] = {" ", "MUMBAI", "BANGALORE", "DELHI", "AHMEDABAD", "CHENNAI"};
                            double fare[] = {0, 3600,1300, 4500, 4000, 1950};

                            //converted integer to string, transfer to storage array//
                            ticketS[z][1] = dest[to];
                            ticketD[z][0] = fare[to];

                            //inputting for Number of Passenger's//
                            for (x = 1; x == 1; ) {
                                System.out.print("HOW MANY PASSENGERS ARE YOU?: ");
                                ticketI[z][0] = Integer.parseInt(in.readLine());

                                //subtract the available seat by the number inputted//
                                for (int p = 1; p <= 5; p++) {
                                    if (to == p) {
                                        print = 1;
                                        available[to] = available[to] - ticketI[z][0];

                                        //if the subtracted available seat is "<0", display error//
                                        //add the inputted number to the subtracted seat, to back the original seat//
                                        //display the available seat and back to the inputting//
                                        if (available[to] < 0) {
                                            System.out.print("Sorry, We don't have seat available for " + ticketI[z][0] + " person\n");
                                            available[to] = available[to] + ticketI[z][0];
                                            System.out.print("We only have " + available[to] + " seat available\n");
                                            x = 1;
                                            print = 0;
                                        } else {
                                            x = 0;
                                        }
                                    }
                                }

                            }

                            //inputting for Number of Discounted Passenger's//
                            for (x = 1; true; ) {
                                System.out.print("HOW MANY PASSENGERS HAVE DISCOUNT?: ");
                                ticketI[z][1] = Integer.parseInt(in.readLine());

                                if (ticketI[z][1] > ticketI[z][0]) {

                                    System.out.println("Invalid Input!");
                                    System.out.println("No. of Passengers are only " + ticketI[z][0] + "!");
                                    x = 1;
                                } else {
                                    break;
                                }
                            }


                            //print out of passengers details....
                            if (print == 1) {
                                System.out.println("\n***************************************");
                                System.out.println("**        PASSENGER'S DETAILS        **");
                                System.out.println("***************************************");
                                System.out.println("PASSENGER'S NAME: " + ticketS[z][0]);
                                System.out.println("PASSENGER'S DESTINATION : " + ticketS[z][1]);
                                System.out.println("FARE PRICE: Rs. " + ticketD[z][0]);
                                System.out.println("NO. OF PASSENGERS: " + ticketI[z][0]);
                                System.out.println("NO. OF PASSENGERS WITH DISCOUNT: " + ticketI[z][1]);
                                System.out.println("***************************************");
                                System.out.println("***************************************\n");
                                ticketS[z][2] = "0";
                                double discount = (ticketD[z][0] - (ticketD[z][0] * 0.2)) * ticketI[z][1];
                                ticketD[z][2] = ((ticketI[z][0] - ticketI[z][1]) * ticketD[z][0]) + discount;
                                x = 0;
                            }
                            z++;
                        }
                        break;
                    case "3":


                        for (x = 1; x == 1; ) {

                            System.out.print("ENTER PASSENGER'S NAME: ");
                            search = in.readLine();


                            int s = 1;
                            for (int b = 0; b < z; b++) {
                                if (search.equalsIgnoreCase(ticketS[b][0])) {
                                    System.out.println("***************************************");
                                    System.out.println("**        PASSENGER'S DETAILS        **");
                                    System.out.println("***************************************");
                                    System.out.println("PASSENGER'S NAME: " + ticketS[b][0]);
                                    System.out.println("PASSENGER'S DESTINATION : " + ticketS[b][1]);
                                    System.out.println("FARE PRICE: Rs." + ticketD[b][0]);
                                    System.out.println("NO. OF PASSENGERS: " + ticketI[b][0]);
                                    System.out.println("NO. OF PASSENGERS WITH DISCOUNT: " + ticketI[b][1]);
                                    System.out.println("***************************************");
                                    System.out.println("***************************************");
                                    s = 0;

                                    if (ticketS[b][2].equals("x")) {
                                        System.out.println("Passenger's Already Paid!");
                                        x = 0;
                                    } else {
                                        ticketS[b][2] = "x";


                                        for (x = 1; x == 1; ) {
                                            System.out.println("\nPASSENGER'S TOTAL FARE: Rs. " + ticketD[b][2]);
                                            System.out.print("ENTER AMOUNT TO PAY: ");
                                            pay[b] = Double.parseDouble(in.readLine());
                                            change[b] = pay[b] - ticketD[b][2];

                                            if (change[b] < 0) {
                                                System.out.println("Invalid Input!");
                                                x = 1;
                                            } else {
                                                System.out.println("CHANGE: Rs. " + change[b]);
                                                System.out.println("");
                                                x = 0;
                                            }
                                        }
                                    }
                                }
                            }
                            if (s == 1) {
                                System.out.println("\nPASSENGER'S NAME NOT FOUND!\n");
                                for (int q = 1; q == 1; ) {

                                    System.out.print("Do you wish to continue with this transaction? [Y/N]: ");
                                    again = in.readLine();

                                    if (again.equalsIgnoreCase("y")) {
                                        q = 0;
                                    } else if (again.equalsIgnoreCase("n")) {
                                        q = 0;
                                        x = 0;

                                    } else {
                                        System.out.println("\nInvalid input!\n");
                                    }


                                }
                            }
                        }

                        break;
                    case "4":


                        for (int sx = 1; sx <= 3; ) {
                            System.out.print("SEARCH PASSENGER'S NAME: ");
                            search = in.readLine();

                            int s = 1;
                            for (x = 0; x <= z; x++) {
                                if (search.equalsIgnoreCase(ticketS[x][0])) {
                                    System.out.println("***************************************");
                                    System.out.println("**        PASSENGER'S DETAILS        **");
                                    System.out.println("***************************************");
                                    System.out.println("PASSENGER'S NAME: " + ticketS[x][0]);
                                    System.out.println("PASSENGER'S DESTINATION : " + ticketS[x][1]);
                                    System.out.println("FARE PRICE: Rs." + ticketD[x][0]);
                                    System.out.println("NO. OF PASSENGERS: " + ticketI[x][0]);
                                    System.out.println("NO. OF PASSENGERS WITH DISCOUNT: " + ticketI[x][1]);
                                    System.out.println("TOTAL FARE PRICE: Rs. " + ticketD[x][2]);
                                    if (ticketS[x][2].equals("x")) {
                                        System.out.println("PAY: Rs. " + pay[x]);
                                        System.out.println("CHANGE: Rs. " + change[x]);
                                        System.out.println("STATUS: PAID");
                                    } else {
                                        System.out.println("STATUS: NOT PAID");
                                    }
                                    System.out.println("***************************************");
                                    System.out.println("***************************************");
                                    s = 0;
                                    sx = 4;
                                }
                            }


                            if (s == 1) {
                                System.out.println("Passenger's Name not found!");
                                sx++;
                            }

                        }
                        break;
                    case "5":
                        end = 1;
                        x = 0;
                        System.out.println("Thank You!");
                        break;
                    default:
                        System.out.println("Invalid Input!");
                        x = 1;
                        break;
                }
            }

            for(y=1; y==1;){
                if(end==1){
                    break;
                }
                System.out.print("Do you want another transaction? [Y/N]: ");
                yn = in.readLine();

                if (yn.equalsIgnoreCase("y")){
                    x=1;
                    y=0;
                }
                else if (yn.equalsIgnoreCase("n")){
                    System.out.println("\nThank You!!!");
                    break;
                }
                else{
                    System.out.println("Invalid Input!!!");
                    y=1;
                }
            }
        }





    }
    public static void main(String[] args)  throws IOException  {
        Scanner sc=new Scanner(System.in);
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("                                     BUS RESERVATION SYSTEM-MANIPAL                                    ");
        System.out.println("                                           LOGIN  PAGE                                            ");


        System.out.println("1.USER LOGIN\n2.CREATE ACCOUNT\n3.EXIT");
        int ch = sc.nextInt();
        String user,password,repass;
        while (ch == 1 | ch == 2 ) {
            switch (ch) {

                case 1: {
                    System.out.println("USER LOGIN");
                    System.out.print("Enter Username: ");
                    user = in.readLine();
                    System.out.print("Enter Password: ");
                    password = in.readLine();
                    if (Login.check_User(user, password)) {
                        System.out.println("WELCOME " + user);
                        BUSR();
                    }
                    else{
                        System.out.println(user+"- this doesn't exist in our database !! OR Your Password is incorrect !!");
                        System.out.println();
                    }
                    break;
                }
                case 2: {
                    System.out.println("CREATE ACCOUNT");
                    System.out.print("Enter Username: ");
                    user = in.readLine();
                    System.out.println("Enter Password: ");
                    password = in.readLine();
                    System.out.println("Reenter the Password: ");
                    repass = in.readLine();
                    if (Objects.equals(repass, password)) {
                        Login cl = new Login(user, password);
                        System.out.println("Account created !!");
                        System.out.println();
                    }
                    else{
                        System.out.println("Passwords don't match !! Make your account again !!");
                        System.out.println();
                    }
                    break;
                }
            }
            System.out.println("1.USER LOGIN\n2.CREATE ACCOUNT\n3.EXIT");
            ch = sc.nextInt();
        }

        sc.close();


    }
}
