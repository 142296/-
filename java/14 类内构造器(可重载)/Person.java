package ne;

public class Person {
	public Person(int h)	//修饰词和名字与类相同
	{
		age=1;
		name="zhangsan";
		height=h;
	}
	int age;
	String name;
	int height;
	public void showInfo(){
		System.out.println(age);
		System.out.println(name);
		System.out.println(height);
		
	}

}
