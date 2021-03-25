package demo;

public class Girl {
		String name;
		int age;
		int level_of_appearance;
		int[]date=new int[3];
		int height;
		int weight;
		public void show()
		{
			System.out.println("name:"+name);
			System.out.println("age:"+age);
			System.out.println("level_of_appearance:"+level_of_appearance);
			System.out.println("date:"+date[0]+"\\"+date[1]+"\\"+date[2]);
			System.out.println("height:"+height);
			System.out.println("weight:"+weight);
		}
		public void kiss(int[]now_date)
		{
			System.out.println("你确定?");
			int year=now_date[0]-date[0];
			int month=now_date[1]-date[1];
			int day=now_date[2]-date[2];
			day+=month*30+year*365;
			System.out.println("我们才认识多少天");
			if(day==99)
			{
				System.out.println("(兴奋脸)你居然记着99天纪念日！");
				return;
			}
			else if(day>99)
			{
				System.out.println("行吧(冷漠)");
			}
			else {
				now_date[2]++;
				System.out.println("NO!");
				kiss(now_date);        //小递归
			}
		}
}
