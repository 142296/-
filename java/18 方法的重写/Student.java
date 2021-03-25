package ne;

public class Student extends Teacher{//子类继承父类的方法和属性
	String school;
/*	public void showInfo() {
		System.out.println(this.age);
		System.out.println(this.name);
		System.out.println(this.school);
		System.out.println(this.sex);
	}*/
	@Override
		public void showInfo() {
			System.out.println("已重写");
		}
	public static void main(String[] args) {
		Student stu=new Student();
		stu.showInfo();
	}
}
