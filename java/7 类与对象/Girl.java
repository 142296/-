package demo;

public class Girl {
		String name;
		int age;
		int level_of_appearance;
		int[]date=new int[3];
		int height;
		int weight;
		public void kiss(int[]now_date)
		{
			System.out.println("��ȷ��?");
			int year=now_date[0]-date[0];
			int month=now_date[1]-date[1];
			int day=now_date[2]-date[2];
			day+=month*30+year*365;
			System.out.println("���ǲ���ʶ������");
			if(day==99)
			{
				System.out.println("(�˷���)���Ȼ����99������գ�");
				return;
			}
			else if(day>99)
			{
				System.out.println("�а�(��Į)");
			}
			else {
				now_date[2]++;
				System.out.println("NO!");
				kiss(now_date);        //С�ݹ�
			}
		}
}
