package objict_o;

public class DVD extends Item{
	private String director;
	private int playingTime;
	private boolean gotTt=false;
	private String comment;
	
	public void print(DVD dvd) {
		System.out.println(title+":"+director);
	}

	public DVD(String title, String director, int playingTime, String comment) {
		super(title);
		this.director = director;
		this.playingTime = playingTime;
		this.comment = comment;
	}
}
