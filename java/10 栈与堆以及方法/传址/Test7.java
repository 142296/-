package demo;

public class Test7 {
	public static void swap(Date ds1)
	{
		ds1.a=6;
		System.out.println(ds1.a);
	}
	public static void main(String[] args) {
		Date ds=new Date();//ds保存new出来的地址，所以是传址。
		System.out.println(ds.a);
		swap(ds);
		System.out.println(ds.a);
	}

}
