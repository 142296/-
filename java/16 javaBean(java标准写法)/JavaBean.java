package ne;

public class JavaBean { //类是公共的
	public  JavaBean() {//至少有一个构造器。
		sex=0;
	}
	private String name;//	属性用局部变量，通过方法更改，可以保护属性
	private int sex;
	public void setName(String name) {//首字母大写,每一个属性对应get、set方法
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
