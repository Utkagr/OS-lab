class pqr implements Runnable{
	public void run(){
	int i=0;
	for(i=65;i<91;i++){
		System.out.print((char)i);
		try{Thread.sleep(200);}
		catch(Exception e){}
	}
	}
}
class example implements Runnable{
	public void run(){
		int i;
		for(i=0;i<10;i++){
			System.out.print(i);
			try{Thread.sleep(1000);}
			catch(Exception e){}
		}
	}
}
class p6{
	public static void main(String[] args) throws Exception{
		example k=new example();
		pqr t=new pqr();
		Thread a,b;
		a=new Thread(k);
		b=new Thread(t);
		a.start();
		try{Thread.sleep(700);}
		catch(Exception e){}
		b.run();
		System.out.print("ram");
	}
}