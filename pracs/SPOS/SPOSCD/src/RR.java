import java.util.Scanner;

public class RR {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner s = new Scanner(System.in);
		int n, time = 0, q;
		float wtsum = 0, ftsum = 0, btsum = 0;
		System.out.println("Enter number of processes: ");
		n = s.nextInt();
		int rt[] = new int[n];
		int wt[] = new int[n];
		int ft[] = new int[n];
		int at[] = new int[n]; // stores earlier ft

		System.out.println("Enter their run time:");
		for (int i = 0; i < n; i++) {
			rt[i] = s.nextInt();
			btsum = btsum + rt[i];
			wt[i] = 0;
			at[i] = 0;
		}

		System.out.println("Enter time quantum: ");
		q = s.nextInt();

		while (time != btsum) {
			for (int i = 0; i < n; i++) // for each process
			{
				if (rt[i] == 0) {
					continue;
				} else if (rt[i] > q) {
					wt[i] = wt[i] + (time - at[i]);
					wtsum = wtsum + wt[i];
					time = time + q; // increase time and reduce rt by q
					rt[i] = rt[i] - q;
					at[i] = time; // save current ft to add it in wt in the next
									// wt
				} else if (rt[i] <= q) {
					wt[i] = wt[i] + (time - at[i]);
					wtsum = wtsum + wt[i];
					time = time + rt[i]; // increase time and reduce rt by rt
					rt[i] = 0;
					ft[i] = time;
					ftsum = ftsum + ft[i];
				}
			}
		}

		System.out.println("Average wait time=" + (wtsum / n));
		System.out.println("Average finish time=" + (ftsum / n));
		s.close();

	}

}
