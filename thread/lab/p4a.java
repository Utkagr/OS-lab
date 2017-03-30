class example implements Runnable{
	public void run(){
		int i;
		for(i=0;i<5;i++){
			System.out.print(i);
			try{Thread.sleep(1000);}
			catch(Exception e){}
		}
	}
}
class p4a{
	public static void main(String[] args) throws Exception{
		example k=new example();
		Thread a,b;
		a=new Thread(k);
		b=new Thread(k);
		a.start();
		Thread.sleep(1000);
		for(int i=0;i<5;i++){
			Thread.sleep(700);
			System.out.print("x");
		}
	}
}