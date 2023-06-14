public class four extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
            System.out.println(Thread.currentThread()+ " "+i);
        }
    }

    public static void main(String args[]) {
        four t1 = new four();
        t1.setPriority(10);
        t1.setName("1");
        four t2 = new four();
        t2.setPriority(1);
        t2.setName("2");
        t1.start();
        t2.start();
    }
}