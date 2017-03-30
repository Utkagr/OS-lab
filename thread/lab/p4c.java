class example implements Runnable{
	public void run(){
		int i;
		for(i=1;i<10;i++){
			try{Thread.sleep(1000);}
			catch(Exception e){}
			System.out.print(i);
		}
	}
}
class p4c{
	public static void main(String[] args) throws Exception{
		example k=new example();
		Thread a,b;
		a=new Thread(k);
		b=new Thread(k);
		a.start();
		for(int i=0;i<10;i++){
			System.out.print("x");
			Thread.sleep(720);
		}
	}
}