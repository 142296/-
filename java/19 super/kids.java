package ne;

public class kids extends ManKind{
	public kids(int age) {  //����ֻ���вι���������ʹ�õ�ʱ�����������ʾ�Ĺ���һ�������������ø�����вι��죬���ҵ��ø��๹�췽��Ҫд�ڵ�һ��
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
