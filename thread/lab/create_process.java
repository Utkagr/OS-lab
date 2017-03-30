class example implements Runnable{
	public void run(){
		int i;
		for(i=0;i<5;i++){
			System.out.print(i);
			try{
				Thread.sleep(1000);
			}
			catch(Exception e){}
		}
	}
}
class create_process{
	public static void main(String[] args) throws Exception{
		example k = new example();
		Thread a,b;
		a= new Thread(k);
		b= new Thread(k);
		// a.run(); //means that the nest instruction will start only when a is over.
		a.start();
		Thread.sleep(500);
		for(int i=0;i<3;i++){
			Thread.sleep(1000);
			System.out.print("x");
		}
		// b.start();
		// Thread.sleep(3500);
		System.out.print("x");
		Thread.sleep(1000);
		System.out.print("x");
	}
}