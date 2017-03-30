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
class p5{
	public static void main(String[] args) throws Exception{
	int i;
	for(i=1;i<=10;i++){
		Thread a;
		System.out.print("x");
		example k=new example();
		a=new Thread(k);
		a.start();
		try{Thread.sleep(2400);}
		catch(Exception e){}
	}		
	}
}