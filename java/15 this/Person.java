package ne;

public class Person {
	public Person(int height)	//���δʺ�����������ͬ
	{
		age=1;
		name="zhangsan";
		this.height=height;		//��this��������ͬ������
	}
	public Person(int age,String name)
	{
		this(155);//�Ե���������������ڹ��������У����ܵ��û����Ե���������
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
		
		this.showInfo();   //�Ե�
		
	}

}
