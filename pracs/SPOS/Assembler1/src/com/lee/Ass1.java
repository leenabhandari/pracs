package com.lee;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.LinkedHashMap;
import java.util.Map;

public class Ass1 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		FileWriter symtab = new FileWriter("symtab.txt");
		FileWriter littab = new FileWriter("littab.txt");
		FileWriter pooltab = new FileWriter("pooltab.txt");
		FileWriter inter = new FileWriter("inter.txt");
		String s;
		int lc = 0, symptr = 0, litptr = 0, mind_lc = 0, poolptr = 0;
		ArrayList<String> lits = new ArrayList<String>(); // this is for ltorg.
															// to add lc in
															// littab

		Hashtable<String, String> is = new Hashtable<String, String>();
		is.put("MOVR", "01");
		is.put("MOVEM", "02");
		is.put("ADD", "03");
		is.put("STOP", "03");
		is.put("SUB", "04");

		Hashtable<String, String> ad = new Hashtable<String, String>();
		ad.put("START", "01");
		ad.put("END", "02");

		Hashtable<String, String> dl = new Hashtable<String, String>();
		dl.put("DS", "01");
		dl.put("DC", "02");
		dl.put("LTORG", "03");

		Hashtable<String, String> rg = new Hashtable<String, String>();
		rg.put("AREG", "01");
		rg.put("BREG", "02");
		rg.put("CREG", "03");
		rg.put("DREG", "04");
		LinkedHashMap<String, String> syms = new LinkedHashMap<String, String>(); // to
																					// add
																					// lc
																					// in
																					// symtab.
																					// Linkedhashmap
																					// is
																					// used
																					// to
																					// retain
																					// the
																					// insertion
																					// order
																					// for
																					// symtab

		Hashtable<String, String> sym = new Hashtable<String, String>(); // always
																			// add
																			// symptr/litptr
																			// not
																			// lc
		Hashtable<String, String> lit = new Hashtable<String, String>(); // sym
																			// and
																			// lit
																			// hashtables
																			// are
																			// for
																			// inter

		while ((s = br.readLine()) != null) { // for every line
			String words[] = s.split(" |\\,");
			inter.write("\r\n" + lc + " "); // at other places dont write \r\n
											// for
											// inter except ltorg
			mind_lc = 0;

			for (int i = 0; i < words.length; i++) { // for every word

				if ((!is.containsKey(words[i])) && (!dl.containsKey(words[i]))
						&& (!ad.containsKey(words[i]))
						&& (!sym.containsKey(words[i]))
						&& (!rg.containsKey(words[i]))
						&& (!words[i].contains("="))
						&& (!dl.containsKey(words[i]))) {
					sym.put(words[i], String.valueOf(symptr)); // for inter
					syms.put(words[i], "0");
					symptr++;
					// 1. find symbols add them to sym hashtable.
				}
				if (words[i].equalsIgnoreCase("START")) {
					lc = Integer.parseInt(words[i + 1]);
					inter.write("(AD,01) (C," + words[i + 1] + ")"); // no space
																		// before
																		// brackets
																		// for
																		// all
																		// ifs
																		// with
																		// break
					mind_lc = 1;
					break;
				}

				if (words[i].equalsIgnoreCase("LTORG")) {
					pooltab.write(poolptr + "\r\n");
					int temp = poolptr;
					for (int j = poolptr; j < lits.size(); j++) {
						if (j != temp) // inorder to print lc here
							inter.write(lc + " (DL,03) (C,"
									+ lits.get(j).replaceAll("[^0-9]", "")
									+ ")\r\n");
						else {
							inter.write("(DL,03) (C,"
									+ lits.get(j).replaceAll("[^0-9]", "")
									+ ")\r\n");
						}

						littab.write(lits.get(j) + " " + lc + "\r\n"); // write
																		// into
																		// littab
																		// while
																		// ltorg
																		// because
																		// you
																		// need
																		// lc
						poolptr++;
						lc++;
					}

					mind_lc = 1;
					break;

				}
				if (words[i].equalsIgnoreCase("END")) {

					pooltab.write(poolptr + "\r\n");

					for (int j = poolptr; j < lits.size(); j++) {

						littab.write(lits.get(j) + " " + lc + "\r\n");
						poolptr++;
						lc++;
					}

					inter.write("(AD,02)");
					mind_lc = 1;
					break;

				}
				if (dl.containsKey(words[i])) {
					inter.write("(DL," + dl.get(words[i]) + ") (C,"
							+ words[i + 1].replaceAll("[^0-9]", "") + ")"); // to
																			// only
																			// extract
																			// number
																			// from
																			// string
																			// use
																			// replaceall
					syms.put(words[i - 1], String.valueOf(lc)); // write into
																// symtab while
																// ds/dc because
																// you
																// need lc.
																// update lc
																// here
					// symtab.write(words[i - 1] + " " + lc + "\r\n");

					if (words[i].equalsIgnoreCase("DS")) {
						lc = lc + Integer.parseInt(words[i + 1]);
						mind_lc = 1; // only if ds
					}
					break;
				}

				if (words[i].contains("=")) {
					lit.put(words[i], String.valueOf(litptr)); // for inter
					lits.add(words[i]); // for littab
					// 2. find literals add to arraylist(cause you have to get
					// address during ltorg/end.
					litptr++;
				}

				if (is.containsKey(words[i])) {
					inter.write("(IS," + is.get(words[i]) + ")"); // no space
																	// for IS as
																	// it is the
																	// printed
																	// after lc
					continue;

				}

				if (rg.containsKey(words[i])) {
					inter.write(" (RG," + rg.get(words[i]) + ")");
					continue;

				}

				if (lit.containsKey(words[i])) {
					inter.write(" (L," + lit.get(words[i]) + ")");
					continue;
				}

				if (sym.containsKey(words[i]) && i != 0) {
					inter.write(" (S," + sym.get(words[i]) + ")");
					continue;
				}

			}
			if (mind_lc == 0)
				lc++;

		}

		for (Map.Entry m : syms.entrySet()) {
			symtab.write(m.getKey() + " " + m.getValue() + "\r\n");
		}

		br.close();
		symtab.close();
		littab.close();
		pooltab.close();
		inter.close();

	}
}
