#include<stdio.h>
int main ()
  {
    int count, j, n, time, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];
    printf ("Enter Total Process:\t ");
    scanf ("%d", &n);
    remain = n;
    for (count = 0; count < n; count++)
      {
	printf
	  ("Enter Arrival Time and Burst Time for Process Process Number %d :",
	   count + 1);
	scanf ("%d", &at[count]);
	scanf ("%d", &bt[count]);
	rt[count] = bt[count];
      }
    printf ("Enter Time Quantum:\t");
    scanf ("%d", &time_quantum);
    printf ("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for (time = 0, count = 0; remain != 0;)
      {
	if (rt[count] <= time_quantum && rt[count] > 0)
	  {
	    time += rt[count];
	    rt[count] = 0;
	    flag = 1;
	  }
	else if (rt[count] > 0)
	  {
	    rt[count] -= time_quantum;
	    time += time_quantum;
	  }
	if (rt[count] == 0 && flag == 1)
	  {
	    remain--;
	    printf ("P[%d]\t|\t%d\t|\t%d\n", count + 1, time - at[count],
		    time - at[count] - bt[count]);
	    wait_time += time - at[count] - bt[count];
	    turnaround_time += time - at[count];
	    flag = 0;
	  }
	if (count == n - 1)
	  count = 0;
	else if (at[count + 1] <= time)
	  count++;
	else
	  count = 0;
      }
    printf ("\nAverage Waiting Time= %f\n", wait_time * 1.0 / n);
    printf ("Avg Turnaround Time = %f", turnaround_time * 1.0 / n);

    return 0;
  }
  <<"WT\t\t" << "TAT\t\t\n";
  for (int i = 0; i < n; i++)
    {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      cout << " " << proc[i].pid << "\t\t"
	<< proc[i].bt << "\t\t " << wt[i] << "\t\t " << tat[i] << endl;
    }
  cout << "\nAverage waiting time = " << (float) total_wt / (float) n;
  cout << "\nAverage turn around time = " << (float) total_tat / (float) n;
}

int main ()
{
  Process proc[] = { {2, 4, 6}, {1, 1, 4},
  {7, 5, 5}, {5, 8, 0}, {4, 3, 2}};
  int n = sizeof (proc) / sizeof (proc[0]);
  findavgTime (proc, n);
  return 0;
}
