package objict_o;

import java.util.ArrayList;

public class Database {
		private ArrayList<Item> listItem =new ArrayList<Item>();
		
		public void add(Item item)
		{
			listItem.add(item);
		}
		public void list()
		{
			for(Item item : listItem )
			{
				item.print();
			}
		}
		public static void main(String[] args) {
			Database db = new Database();
			CD Cd = new CD("我知道", "By2", 1,4*60+9 , "我相信这首歌迟早会999 的");
			db.add(Cd);
			db.add(new CD("白月光与朱砂痣","大籽",1,3*60+24,"“白月光是年少欢喜，朱砂痣是相守一生无悔。”\r\n" + 
					"年少无知无畏无惧，一心想做你的白月光，却成了孤芳自赏，就如水镜花月一般，虚幻渺茫；你风尘仆仆而来，犹如我的白月光，令我轸念万分。感之万分，你的出现。\r\n" + 
					"后来，她凌波微步而来，闯入我的平淡无味的生活，落日余晖，我们邂逅相遇。无意间嘴角微微一笑，便令我心中荡漾，夜幕星河，人面桃花何时再遇，愁绪万千。\r\n" + 
					"沧海桑田，世事难料，最终还是落花有意，流水无情，到头来，一片空白。朱砂痣成了最无助的心痛，犹如滔滔江水，连绵不绝，难以忘怀。感之万千，你的离开。\r\n" + 
					"“心上朱砂痣，迢迢白月光。”愿这漫天的繁星，点点镶嵌，熠熠生辉；愿这梦境的美好，密密蔓延，恋恋不舍。"));
		
		}
}

