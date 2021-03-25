package demo;

public class test {
		public static void main(String[]args)
		{
		person4 p4=new person4();
		String[]a=new String[]{"zhao","qian","sun","li"};//多维字符串的申请方法
		p4.printInfo1(a);
		p4.printInfo1("陕西西安","do","15399014015");
		int []a1=new int[] {1,2,3,4,5,6,7};
		p4.printInt(a1,10);         //传入int 型
		}
	}
