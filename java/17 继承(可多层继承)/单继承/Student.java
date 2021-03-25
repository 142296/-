package ne;

public class Student extends Teacher{//子类继承父类的方法和属性
	String school;
	public void showInfo() {
		System.out.println(this.age);
		System.out.println(this.name);
		System.out.println(this.school);
		System.out.println(this.sex);
	}
}
