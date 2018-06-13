import java.util.Scanner;

public class FCFS {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n, time = 0;
		float wtsum = 0, ftsum = 0;
		System.out.println("Enter number of processes: ");
		n = s.nextInt();
		int rt[] = new int[n];
		int wt[] = new int[n];
		int ft[] = new int[n];

		System.out.println("Enter their run time:");
		for (int i = 0; i < n; i++) {
			wt[i] = time;
			rt[i] = s.nextInt();
			time = time + rt[i];
			ft[i] = time;
			wtsum = wtsum + wt[i];
			ftsum = ftsum + ft[i];
		}

		System.out.println("Average wait time is: " + (wtsum / n));
		System.out.println("Average finish time is: " + (ftsum / n));
		s.close();
	}

}
