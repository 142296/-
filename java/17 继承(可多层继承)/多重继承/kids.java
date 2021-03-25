package ne;

public class kids extends ManKind{
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
	public static void main(String[] args) {
		kids someKid=new kids();
		someKid.setSalary(0);
		someKid.setSex(0);
		
		someKid.manOrWomen();
		someKid.employeed();
	}
}
