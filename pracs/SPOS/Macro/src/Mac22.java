import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Hashtable;

public class Mac22 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader mnt = new BufferedReader(new FileReader("mnt.txt"));
		BufferedReader mdt = new BufferedReader(new FileReader("mdt.txt"));
		BufferedReader ala = new BufferedReader(new FileReader("ala.txt"));
		BufferedReader in = new BufferedReader(new FileReader("in.txt"));
		FileWriter output = new FileWriter("output.txt");

		String s;
		Hashtable<Integer, String> mdts = new Hashtable<Integer, String>(); // using
																			// mdt
																			// file

		int mdtc = 0, macstart = 0, alacount = 0;
		Hashtable<String, Integer> mnts = new Hashtable<String, Integer>(); // stores
																			// mdtc

		Hashtable<String, String> alas = new Hashtable<String, String>();

		while ((s = mnt.readLine()) != null) {
			String words[] = s.split(" ");
			if (words.length > 2)
				mnts.put(words[1], Integer.parseInt(words[2]));

		}

		while ((s = mdt.readLine()) != null) {
			if (s.length() > 2)
				mdts.put(mdtc, s.substring(1)); // leave 1st character. make
												// sure index is 1 digit

			mdtc++;
		}

		while ((s = in.readLine()) != null) {
			String words[] = s.split(" |\\,");

			if (mnts.containsKey(words[0])) { // macro present
				macstart = 1;
				mdtc = mnts.get(words[0]);
				mdtc++; // skip first line
				alas.clear(); // new ala for every macro
				alacount = 0;
				// for loop to add params
				for (int i = 1; i < words.length; i++) { // i=1 cuz 0 is macro
															// name
					alas.put(("#" + String.valueOf(alacount)), words[i]); // note
																			// first
																			// #
																			// and
																			// then
																			// word

					alacount++;
				}

			} else {
				output.write("\r\n" + s); // not macro
			}

			if (macstart == 1) {

				while (!mdts.get(mdtc).contains("MEND")) {

					output.write("\r\n");
					String lines[] = mdts.get(mdtc).split(" |\\,");
					for (int i = 0; i < lines.length; i++) {

						if (lines[i].contains("#")) { // need to substitute
														// param
							output.write(" " + alas.get(lines[i]));
						} else
							output.write(" " + lines[i]);
					}

					mdtc++;
				}
				if (mdts.get(mdtc).equals("MEND")) {
					macstart = 0; // end of macro
				}
				continue;
			}

		}

		mdt.close();
		output.close();
		mnt.close();
		ala.close();
		in.close();

	}

}
