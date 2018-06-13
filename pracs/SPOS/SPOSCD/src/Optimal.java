import java.util.Scanner;

public class Optimal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner s = new Scanner(System.in);
		int n, f, flagfault = 1, flagtrav = 2, hit = 0, flagfut = 3; // both
																		// flags
																		// for
																		// page
		// faults
		System.out.println("Enter number of frames:");
		f = s.nextInt();
		int buf[] = new int[f];
		System.out.println("Enter length of reference string:");
		n = s.nextInt();
		int ref[] = new int[n];
		int res[][] = new int[f][n]; // note f then n

		System.out.println("Enter reference string: ");
		for (int i = 0; i < n; i++) {
			ref[i] = s.nextInt();
		}

		for (int j = 0; j < f; j++) {
			buf[j] = -1; // empty buffer
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < f; j++) {
				res[j][i] = -1; // result table
			}
		}

		// /

		for (int i = 0; i < n; i++) {
			flagtrav = 2; // if -1 is not there in buffer
			flagfault = 1;

			for (int j = 0; j < f; j++) {
				if (buf[j] == ref[i]) {
					hit++;
					flagfault = 0;
					flagtrav = 0;
					break;
				}
			}

			if (flagfault == 1) {
				for (int j = 0; j < f; j++) {
					if (buf[j] == -1) {
						buf[j] = ref[i];
						for (int p = i; p < n; p++) {
							res[j][p] = buf[j]; // fill result table
						}
						flagfault = 0;
						flagtrav = 0;
						break;
					}
				}
			}

			if (flagtrav == 2) {
				int search = i;
				int num = ref[i];

				for (int j = 0; j < f; j++) { // to find page to be replaced
					flagfut = 3;
					for (int x = i; x < n; x++) { // traverse forward
						if (buf[j] == ref[x]) {
							flagfut = 0;
							if (search < x) { // this pages cames later
								search = x;
								num = ref[x];
							}
							break; // once value is updated dont search again.
						}
					}
					if (flagfut == 3) { // if page not found in future
						num = buf[j];
						break;
					}
				} // now num is the page to be replaced

				for (int j = 0; j < f; j++) {
					if (buf[j] == num) { // replace num
						buf[j] = ref[i];
						for (int p = i; p < n; p++) {
							res[j][p] = ref[i]; // update result
						}
						break;
					}
				}
			}
		}

		// print result

		for (int j = 0; j < f; j++) {
			for (int i = 0; i < n; i++) {
				System.out.print(res[j][i] + "\t");
			}
			System.out.println();
		}

		System.out.println("Page hits: " + hit);
		s.close();

	}

}
