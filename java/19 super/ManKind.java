package ne;

public class ManKind extends Person1{
	public ManKind(int age)
	{
		this.age=age;
	}
	int sex;
	int salary;
	public int getSex() {
		return sex;
	}
	public void setSex(int sex) {
		this.sex = sex;
	}
	public int getSalary() {
		return salary;
	}
	public void setSalary(int salary) {
		this.salary = salary;
	}
	public void manOrWomen() {
		if(this.sex==1)
		{
			System.out.println("man");
		}
		else if(this.sex==0) {
			System.out.println("women");
		}
	}
	public void employeed(){
		if(this.salary==0) {
			System.out.println("no job");
		}
		else {
			System.out.println("job");
		
		}
	}
	public static void main(String[] args) {
		ManKind nos = new ManKind(3);
		System.out.println(nos.age);
	}
}
