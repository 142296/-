package demo;

public class Person6 {
	private int age;	//隐藏属性，通过方法更改属性，保护
	private int height;
	private int weight;
	
	public void Input_age(int Age)
	{
		age=Age;
	}
	public int Get_age()
	{
		return age;
	}

}
