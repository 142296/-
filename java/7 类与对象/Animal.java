package demo;
/**
*动物的类
*
*/
public class Animal {
	String name;//动物名称
	int eye;//眼睛的个数
	int legs;//腿
	
	public void eat(String food)
	{
		System.out.println("此种动物的食物是："+food);
		
	}
	public void move(String moveType)
	{
		System.out.println("此种动物的移动方式是:"+moveType);		
	}
}
