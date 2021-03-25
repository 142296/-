package ne;

public class Person {
	public Person(int height)	//修饰词和名字与类相同
	{
		age=1;
		name="zhangsan";
		this.height=height;		//用this区分类内同名变量
	}
	public Person(int age,String name)
	{
		this(155);//自调构造器，必须放在构造器首行，不能调用或间接自调本身构造器
		this age=age;
		this name=name;	
}
	int age;
	String name;
	int height;
	public void showInfo(){
		System.out.println(age);
		System.out.println(name);
		System.out.println(height);
		
		this.showInfo();   //自调
		
	}

}
