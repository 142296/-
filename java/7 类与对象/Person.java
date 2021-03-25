package demo;
public class Person {
	//属性，成员变量，类的成员变量，有初始值
		String name;//姓名，默认值是null
		int age;//年龄,默认值是0
		
	//行为，方法也叫函数
	public void showName() 
	{
		System.out.println("姓名:"+name);
	}
	public int GetAge()
	{
		return age;
	}

}
