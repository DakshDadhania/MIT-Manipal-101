class Bike {
    int speedlimit = 120;

    void run(){
        System.out.println("Vroom Vroom Vrooom!! at Speed " + speedlimit);
    }
}

class Splendor extends Bike {
    int speedlimit = 70;

    void run (){
        System.out.println("Splendor goes Vrooooooooom! at a speed of " + speedlimit);
    }
}

public class bike{
    public static void main(String args[]){
        Bike bike1 = new Bike();
        Bike bike2 = new Splendor();  
        
        bike2.run();
        bike1.run();
    }
}