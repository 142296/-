package demo;

public class Test4 {
	public static void main(String[] args)
	{
		//ʵ����Person��==����Person����
		/*
		 * �ⲻ���ǽṹ�������
		 */
		Person Girl_friend=new Person();//����һ��Person ���͵ı���.
		Girl_friend.name="niu";
		Girl_friend.age=18;
		Girl_friend.weight=100;
		Girl_friend.height=156;
		Girl_friend.showName();
		System.out.print("����:"+Girl_friend.GetAge());
		System.out.println();
	}

}
