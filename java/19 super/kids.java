package ne;

public class kids extends ManKind{
	public kids(int age) {  //父类只有有参构造器可以使用的时候，子类必须显示的构建一个构造器来调用父类的有参构造，并且调用父类构造方法要写在第一行
		super(age);
		// TODO Auto-generated constructor stub
	}
	int yearsOld;
	public int getYearsOld() {
		return yearsOld;
	}
	public void setYearsOld(int yearsOld) {
		this.yearsOld = yearsOld;
	}
	public void printAge() {
		System.out.println("this.yearsold");
	}
	@Override
	public void employeed() {
		System.out.println("Kids showld study and no job");
	}
	public static void main(String[] args) {
		kids someKid=new kids(3);
		someKid.setSalary(0);
		someKid.setSex(0);
		
		someKid.manOrWomen();
		someKid.employeed();
	}
}
