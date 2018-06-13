package com.lee;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Hashtable;

public class Ass2 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader inter = new BufferedReader(new FileReader("inter.txt"));
		BufferedReader littab = new BufferedReader(new FileReader("littab.txt"));
		BufferedReader symtab = new BufferedReader(new FileReader("symtab.txt"));
		FileWriter output = new FileWriter("output.txt");
		Hashtable<String, String> lit = new Hashtable<String, String>();
		Hashtable<String, String> sym = new Hashtable<String, String>();
		String s;
		int litptr = 0, symptr = 0;

		while ((s = littab.readLine()) != null) {
			String words[] = s.split(" ");
			// System.out.println(litptr + words[1]);
			lit.put(String.valueOf(litptr), words[1]);
			litptr++;

		}

		while ((s = symtab.readLine()) != null) {
			String words[] = s.split(" ");
			// System.out.println(symptr + words[1]);
			sym.put(words[0], words[1]);
			symptr++;
		}

		while ((s = inter.readLine()) != null) {
			String words[] = s.split(" ");
			if (words.length > 2) {
				if (words[1].contains("IS")) { // for is
					output.write("\r\n" + words[0] + " " // lc
							+ words[1].replaceAll("[^0-9]", "") + " ");// is
					// code
					// + words[2].replaceAll("[^0-9]", "") + " "); // rg

					if (words[2].contains("L")) {
						output.write(lit.get(words[3].replaceAll("[^0-9]", ""))); // get
																					// lc
																					// for
																					// littab
					} else if (words[2].contains("S")) {
						output.write(sym.get(words[2].replaceAll("[^0-9]", ""))); // get
																					// lc
																					// from
																					// symtab
					}
				} else if (words[1].equals("(DL,02)") // for ltorg and dc
						|| words[1].equals("(DL,03)")) {
					output.write("\r\n" + words[0] + " 00 00 "
							+ words[2].replaceAll("[^0-9]", ""));
				} else if (words[1].equals("(DL,01)")) { // for ds
					output.write("\r\n" + words[0]);
				}
			}

		}

		output.close();
		inter.close();
		symtab.close();
		littab.close();

	}
}
