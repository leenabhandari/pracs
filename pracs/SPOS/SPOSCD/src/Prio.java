import java.util.Scanner;

public class Prio {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner s = new Scanner(System.in);
		int n, time = 0, temp;
		float wtsum = 0, ftsum = 0;
		System.out.println("Enter number of processes: ");
		n = s.nextInt();
		int rt[] = new int[n];
		int wt[] = new int[n];
		int ft[] = new int[n];
		int pr[] = new int[n];

		System.out.println("Enter their run time:");
		for (int i = 0; i < n; i++) {
			rt[i] = s.nextInt();
		}

		System.out.println("Enter their priorities:");
		for (int i = 0; i < n; i++) {
			pr[i] = s.nextInt();
		}

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < (n - 1); j++) {
				if (pr[j - 1] > pr[j]) {
					temp = pr[j - 1];
					pr[j - 1] = pr[j];
					pr[j] = temp;

					temp = rt[j - 1];
					rt[j - 1] = rt[j];
					rt[j] = temp;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			System.out.println("time" + time);
			wt[i] = time;
			time = time + rt[i];
			ft[i] = time;
			wtsum = wtsum + wt[i];
			ftsum = ftsum + ft[i];
		}

		System.out.println("Average wait time: " + (wtsum / n));
		System.out.println("Average finish time: " + (ftsum / n));
		s.close();

	}

}
