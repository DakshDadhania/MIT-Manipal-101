public class outputs {
    public static void main(String[] args) {
        // Create a new thread and start it
        Thread thread1 = new Thread(new CountingTask());
        thread1.start();

        // Create a second thread and start it
        Thread thread2 = new Thread(new CountingTask());
        thread2.start();
    }

    // A task that counts from 1 to 10 and prints the numbers
    private static class CountingTask implements Runnable {
        @Override
        public synchronized void run() {
            for (int i = 1; i <= 10; i++) {
                System.out.println(i);
            }
        }
    }
}