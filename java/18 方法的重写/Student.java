package ne;

public class Student extends Teacher{//����̳и���ķ���������
	String school;
/*	public void showInfo() {
		System.out.println(this.age);
		System.out.println(this.name);
		System.out.println(this.school);
		System.out.println(this.sex);
	}*/
	@Override
		public void showInfo() {
			System.out.println("����д");
		}
	public static void main(String[] args) {
		Student stu=new Student();
		stu.showInfo();
	}
}
