public class SleepMessages {
    private static class print_message implements Runnable{
        public void run(){
        String importantInfo[] = {
            "Mares eat oats",
            "Does eat oats",
            "Little lambs eat ivy",
            "A kid will eat ivy too"
        };

        for (int i = 0;
             i < importantInfo.length;
             i++) {
            //Pause for 4 seconds
            try{Thread.sleep(4000);}
            catch(InterruptedException e){
                System.err.println("Exception");
                return;
            }
            //Print a message
            System.out.println(importantInfo[i]);
        }
    }
}
    public static void main(String args[])
        throws InterruptedException {
            Thread t = new Thread(new print_message());
            t.start();
            System.out.println("Starting t thread.");
            System.out.println("Wating for t thread to finish.");
            t.join(9000);
            if(t.isAlive()){
                t.interrupt();
                t.join();
            }
    }
}