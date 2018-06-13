import java.util.Scanner;

public class SJF {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n;
		System.out.println("ENter number of processes: ");
		n = s.nextInt();
		int rt[] = new int[n];
		int wt[] = new int[n];
		int ft[] = new int[n];
		int time = 0, process = 0, min = 999;
		float wtsum = 0, ftsum = 0;

		System.out.println("ENter run time:");
		for (int i = 0; i < n; i++) {
			rt[i] = s.nextInt();
		}

		for (int i = 0; i < n; i++) {
			min = 999;
			for (int j = 0; j < n; j++) {
				if (min > rt[j]) {
					min = rt[j];
					process = j;
				}
			}
			System.out.println("process " + process + " time " + time);
			wt[process] = time;
			time = time + rt[process];
			ft[process] = time;
			ftsum = ftsum + ft[process];
			wtsum = wtsum + wt[process];
			rt[process] = 999;
		}

		System.out.println("Average wait time=" + (wtsum / n));
		System.out.println("Average finish time=" + (ftsum / n));
		s.close();

	}

}
