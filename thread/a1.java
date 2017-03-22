class xyz implements rununnable{
	public void run(){
		int i;
		for(i=0;i<4;i++){
			System.out.println(i);
			try{Thread.sleep(3000);}
			catch(InterruptedException e){
				// System.err.println("Exception");\
				return;
			}
		}
	}
}
class a1{
	static void threadMessage(String message) {
        String threadName =
            Thread.currentThread().getName();
        System.out.format("%s: %s%n",
                          threadName,
                          message);
    }
	public static void main(String args[]) throws InterruptedException{
		// (new Thread(new xyz())).run(); //prints 12345x
		// (new Thread(new xyz())).run(); //prints 12345x

		Thread t1 = new Thread(new xyz());
		t1.start(); //prints x01234 or 0x1234
        threadMessage("Starting first thread");		

		while(t1.isAlive()){
			threadMessage("First thread still alive.");
			//let's wait for 1 sec
			t1.join(1000);
		}
		
        threadMessage("First thread finished");		
        threadMessage("Starting second thread");		
		Thread t2 = new Thread(new xyz());
		t2.start(); //prints x01234 or 0x1234
		while(t2.isAlive()){
			threadMessage("Second thread still alive.");
			//let's wait for 2 sec.
			t2.join(2000);
		}
        threadMessage("Second thread finished");		
		System.out.print("Hi");
	}
}