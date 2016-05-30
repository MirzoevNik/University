/**
 * Created by nikita on 25.04.16.
 */
public class ThreadTest {

    public static int counter;

    public static void main(String[] args) {
        System.out.println("Start of new threads!");
        int count_of_threads = 10000;
        long start_time = System.currentTimeMillis();
        for ( counter = 0; counter < count_of_threads; counter++ ) {
            new Thread() {
                public void run() {
                    System.out.println("New proccess was starting.\nNumber of proccess: " + counter + "\n");
                    Object new_obj = new Object();
                    synchronized (new_obj) {
                        try {
                            new_obj.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }.start();
        }
        long finish_time = System.currentTimeMillis();
        long time = finish_time - start_time;
        System.out.println("Count of proccesses: " + count_of_threads + "\nTime: " + time + "\n");
    }

}
