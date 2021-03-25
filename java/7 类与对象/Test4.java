package demo;

public class Test4 {
	public static void main(String[] args)
	{
		//实例化Person类==创建Person对象
		/*
		 * 这不就是结构体变量？
		 */
		Person Girl_friend=new Person();//生命一个Person 类型的变量.
		Girl_friend.name="niu";
		Girl_friend.age=18;
		Girl_friend.weight=100;
		Girl_friend.height=156;
		Girl_friend.showName();
		System.out.print("年龄:"+Girl_friend.GetAge());
		System.out.println();
	}

}
