import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Hashtable;

public class Mac1 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		FileWriter mdt = new FileWriter("mdt.txt");
		FileWriter mnt = new FileWriter("mnt.txt");
		FileWriter ala = new FileWriter("ala.txt");

		Hashtable<String, String> a = new Hashtable<String, String>();
		String s;
		int mpresent = 0, alacount = 0, mdtc = 0, firstline = 0, mntc = 0;

		while ((s = br.readLine()) != null) {
			String words[] = s.split(" |\\,");
			if (words[0].equalsIgnoreCase("MACRO")) {
				mpresent = 1; // macropresent from next line
				firstline = 1;
				continue;
			}
			if (firstline == 1) {
				firstline = 0;
				mnt.write("\r\n" + mntc + " " + words[0] + " " + mdtc);
				mntc++;
				alacount = 0;
				a.clear(); // clear the ala hashtable for every new macro
				ala.write("\r\n ALA " + mntc);
				mdt.write("\r\n" + mdtc + " " + s);
				mdtc++;
				for (int i = 0; i < words.length; i++) {
					if (words[i].contains("&")) {
						a.put(words[i], String.valueOf(alacount)); // for taking
																	// the
																	// parameters
																	// of macro
						ala.write("\r\n" + alacount + " " + words[i]);
						alacount++;
					}
				}
				continue;
			}

			if (mpresent == 1) {
				// for start of line
				if (words[0].equalsIgnoreCase("MEND")) {
					mpresent = 0; // macro not present from next line
					mdt.write("\r\n" + mdtc + " MEND");
					mdtc++;
					continue;

				} else {
					mdt.write("\r\n" + mdtc);
					for (int i = 0; i < words.length; i++) {
						if (words[i].contains("&")) {
							mdt.write(" #" + a.get(words[i])); // if param found
																// in ala
						} else {
							mdt.write(" " + words[i]); // otherwise
						}
					}
				}
				mdtc++;
			}

		}

		br.close();
		ala.close();
		mnt.close();
		mdt.close();

	}
}
