package demo;

public class person4 {
	public static void printInfo1(String ...args)
	{
		for(int i=0;i<args.length;i++)
			System.out.println(args[i]);
	}
	public static void printInt(int[]a,int b)
	{
		for(int i=0;i<a.length;i++)
			System.out.println(a[i]);
	}
	public static void main(String[]args)
	{
		printInfo1("zhao","qian","sun","li");
	}
}
