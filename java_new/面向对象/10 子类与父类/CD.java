package objict_o;

public class CD extends Item{
	private String artist;
	private int numofTracks;
	private int playingTime;
	private boolean gotTt=false;
	private String comment;
	public CD(String title, String artist, int numofTracks, int playingTime, String comment) 
	{
		super(title);
		this.artist = artist;	
		this.numofTracks = numofTracks;
		this.playingTime = playingTime;
		this.comment = comment;
	}
	public void print(CD cd) 
	{
		System.out.println(title+":"+artist);
	}
	
}
