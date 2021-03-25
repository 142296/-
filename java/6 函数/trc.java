package demo;
class A{								//class外部，需先定义class 后定义函数
	/*public*/ static void P()			//注释内可有可无，区别待定。
	{
	System.out.println("Hello main!,I'm P");
	}
}
public class trc 
{
	/*public*/ static void p()						//class 内直接定义函数。注释内可有可无，区别待定
	{
	System.out.println("Hello main!,I'm small p");
	}
	public static void main(String[] args)
	{
  	 A.P();
  	 p();
	}			
}


