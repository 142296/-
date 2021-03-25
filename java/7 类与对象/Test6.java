package demo;

public class Test6 {
	public static void main(String[]args)
	{
		Girl girl1=new Girl();
		girl1.age=19;
		girl1.date[0]=2020;
		girl1.date[1]=9;
		girl1.date[2]=24;
		int[]now_date=new int[3];
		now_date[0]=2020;
		now_date[1]=9;
		now_date[2]=25;
		girl1.kiss(now_date);
	}

}
