import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class AnswerToGnu {

	static final int MIN = 0;
	static final int MAX = 100;

	public static void main(String[] args) throws IOException {

		String infile = args[0];
		String ansfile = args[1];

		File in = new File(infile);
		File ans = new File(ansfile);

		Scanner inscan = new Scanner(in);

		// read infile
		
		Scanner ansscan = new Scanner(new FileReader(ans));

		// read ansfile
		
		if (!ansscan.hasNextInt()) {
			System.out.println();
			return;
		}
		int num = ansscan.nextInt();
		for (int i = 0; i < num; i++) {
			System.out.println(ansscan.nextInt() + " " + ansscan.nextInt());
		}
		// sysout 
		// "set object i rect from x, y to x, y fs empty border lc palette frac x"
		// "set label i at x,y front center"
	}

	public static double toFrac(int n) {
		return ((double) Math.min(Math.max(MIN, n), MAX)) / (MAX - MIN) ;
	}
}
