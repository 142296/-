package demo;

public class trc {

	public static void main(String[] args)
	{
		//String str1=4    错
		String str2=3.5f+""; //对
		System.out.println(str2);	//输出3.5
		System.out.println(3+4+"hello!");//输出7hello
		System.out.println("hello"+3+4); //输出hello34
		System.out.println('a'+1+"hello");//输出:98hello
		System.out.println("hello"+'a'+1);//输出helloa1
	}
}


