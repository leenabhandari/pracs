import java.util.Scanner;

public class Priopre {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner s = new Scanner(System.in);
		int n, time = 0, temp, proc = 0, prio = 999;
		float wtsum = 0, ftsum = 0, btsum = 0, turnsum = 0;
		System.out.println("Enter number of processes: ");
		n = s.nextInt();
		int rt[] = new int[n];
		int pr[] = new int[n];
		int wt[] = new int[n];
		int ft[] = new int[n];
		int nam[] = new int[n]; // name
		int ar[] = new int[n]; // arrival time
		int at[] = new int[n]; // stores earlier ft

		System.out.println("Enter their run time:");
		for (int i = 0; i < n; i++) {
			rt[i] = s.nextInt();
			btsum = btsum + rt[i];
			wt[i] = 0;
			at[i] = 0;
			nam[i] = i;
		}

		System.out.println("ENter their arrival time: ");
		for (int i = 0; i < n; i++) {
			ar[i] = s.nextInt();
		}

		System.out.println("ENter their priorities: ");
		for (int i = 0; i < n; i++) {
			pr[i] = s.nextInt();
		}

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < (n - 1); j++) {
				if (ar[j - 1] > ar[j]) { // sort according to arrival
					temp = ar[j - 1]; // swap arrival
					ar[j - 1] = ar[j];
					ar[j] = temp;

					temp = rt[j - 1]; // swap runtime
					rt[j - 1] = rt[j];
					rt[j] = temp;

					temp = nam[j - 1]; // swap name
					nam[j - 1] = nam[j];
					nam[j] = temp;

					temp = pr[j - 1]; // swap priority
					pr[j - 1] = pr[j];
					pr[j] = temp;

				}
			}
		}

		while (time != btsum) {
			for (int i = 0; i < n; i++) // selecting shortest job
			{
				if (ar[i] > time || rt[i] == 0) {
					continue;
				} else if (pr[i] < prio) {
					prio = pr[i];

					proc = i;
				}
			}

			wt[proc] = wt[proc] + (time - at[proc]);
			time = time + 1;
			rt[proc] = rt[proc] - 1; // rt in memory

			at[proc] = time;
			if (rt[proc] == 0) {

				prio = 999;
				ft[proc] = time;
				ftsum = ftsum + ft[proc];

			}

		}
		turnsum = ftsum;
		for (int i = 0; i < n; i++) {
			wtsum = wt[i] - ar[i] + wtsum; // subtract arrival
			turnsum = turnsum - ar[i];
		}

		System.out.println("Average wait time=" + (wtsum / n));
		System.out.println("Average finish time=" + (ftsum / n));
		System.out.println("Average turnaround time=" + (turnsum / n));
		s.close();

	}

}
