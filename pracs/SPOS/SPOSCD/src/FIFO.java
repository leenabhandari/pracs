import java.util.Scanner;

public class FIFO {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n, f, hit = 0, flagfault = 1, ind = 0;
		Scanner s = new Scanner(System.in);
		System.out.println("Enter number of frames:");
		f = s.nextInt();
		int buf[] = new int[f];
		System.out.println("Enter length of reference string:");
		n = s.nextInt();
		int ref[] = new int[n];
		int res[][] = new int[f][n];

		System.out.println("Enter reference string: ");
		for (int i = 0; i < n; i++) {
			ref[i] = s.nextInt();
		}

		for (int j = 0; j < f; j++) {
			buf[j] = -1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < f; j++) {
				res[j][i] = -1;
			}
		}

		//

		for (int i = 0; i < n; i++) {
			flagfault = 1;
			for (int j = 0; j < f; j++) {
				if (buf[j] == ref[i]) {
					hit++;
					flagfault = 0;
					break;
				}
			}

			if (flagfault == 1) {

				for (int j = 0; j < f; j++) {
					if (buf[j] == -1) {
						flagfault = 0;
						buf[j] = ref[i];
						for (int p = i; p < n; p++) {
							res[j][p] = buf[j];
						}
						break;
					}
				}

				if (flagfault == 1) {
					buf[ind] = ref[i];
					for (int p = i; p < n; p++) {
						res[ind][p] = buf[ind];
					}
					ind++;
					if (ind == f)
						ind = 0;

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
