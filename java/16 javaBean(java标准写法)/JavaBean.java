package ne;

public class JavaBean { //���ǹ�����
	public  JavaBean() {//������һ����������
		sex=0;
	}
	private String name;//	�����þֲ�������ͨ���������ģ����Ա�������
	private int sex;
	public void setName(String name) {//����ĸ��д,ÿһ�����Զ�Ӧget��set����
		this.name=name;
	}
	public String getName() {
			return this.name;
	}
	public void setSex(int sex) {
		this.sex=sex;
	}
	public int getSex() {
		return this.sex;
	}
}
