package demo;

public class trc 
{
	public static void main(String[] args)
	{
	  int a[]= new int[4];
	  int b[]= new int[]{1,2,3,4};  //自动求长
	  int c[][]=new int[2][3];
	  int d[][]=new int[2][];
	  int e[][]=new int[][]{{1,2,3},{1,2,3}};
	  System.out.println(e[0].length);   //求小数组长度
	  System.out.println(e.length);		//求数组个数
	 //特殊写法  x是一维数组，y是二维数组
	 int[]x,y[];
	 d[0]=new int[10];
	 d[1]=new int[20];
	 x=new int[10];
	 y=new int[10][5];
	 System.out.println(d[0].length);
	 System.out.println(d[1].length);
	 
	  	  
	}					
}


