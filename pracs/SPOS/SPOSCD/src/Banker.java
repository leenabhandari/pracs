import java.util.Scanner;

public class Banker {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner s = new Scanner(System.in);
		int n, r, count = 0, flag = 0, np, nr, nq; // flag for processes, count
													// for
		// resources
		System.out.println("ENter number of processes:");
		n = s.nextInt();
		System.out.println("Enter number of resources: ");
		r = s.nextInt();
		int need[][] = new int[n][r];
		int alot[][] = new int[n][r];
		int claim[][] = new int[n][r];
		int res[] = new int[r];
		int avail[] = new int[r];
		String cho = "y";

		System.out.println("Enter claim matrix:");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < r; j++) {
				claim[i][j] = s.nextInt();
			}
		}

		System.out.println("Enter alotted matrix:");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < r; j++) {
				alot[i][j] = s.nextInt();
			}
		}

		System.out.println("Enter actual resources:");
		for (int j = 0; j < r; j++) {
			res[j] = s.nextInt();
		}

		do {
			// System.out.println("Need matrix:");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < r; j++) {
					need[i][j] = claim[i][j] - alot[i][j];
				}
			}

			// System.out.println("Available resources");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < r; j++) {
					avail[j] = res[j] - alot[i][j];
				}
			}

			for (int x = 0; x < n; x++) {
				for (int i = 0; i < n; i++) {
					count = 0;
					for (int j = 0; j < r; j++) {
						if ((avail[j] - need[i][j]) >= 0 && need[i][j] != -1) {
							count++;
						}
					}
					if (count == r) {
						flag++;
						System.out.println("Process: " + i);
						for (int j = 0; j < r; j++) {
							avail[j] = avail[j] - need[i][j];
							avail[j] = avail[j] + claim[i][j];
							need[i][j] = -1;
						}
					}
				}
			}

			if (flag == n) {
				System.out.println("System state is safe.");
			} else {
				System.out.println("System state is not safe.");
			}

			System.out.println("Do you have new request?");
			cho = s.next();
			if (cho.equals("y")) {
				System.out.println("ENter process:");
				np = s.nextInt();
				System.out.println("Enter resource number:");
				nr = s.nextInt();
				System.out.println("Enter requirement: ");
				nq = s.nextInt();
				claim[np][nr] = nq;
			}
		} while (cho.equals("y"));
		s.close();

	}

}
