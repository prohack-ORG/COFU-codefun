/* 

	Author : Siddheshwar P Sharma
	SJFS pre-emptive
	Date : 02-Feb-2017
	simple implementation of shortest job first preemptive algorithm in C
	
*/

#include <iostream>
#include <stdio.h>
#include <limits.h>						// for INT_MAX (used later)
using namespace std;

// Function to print any array ( used later to print wait time and turnaround time)
void print(int a[], int n)
{
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

// main code goes here
int main()
{
	
// 2 sample test cases, switch by changing 1 to 0 	
#if 1
	int arrival_time[10] = {0, 1, 2, 3};				// arrival time of jobs [input]
	int burst_time[10] = {8, 4, 9, 5};				// burst time of jobs   [input]
#else	
	int arrival_time[10] = {0, 2, 4, 5};				// arrival time of jobs [input]
	int burst_time[10] = {7, 4, 1, 4};                // burst time of jobs   [input]
#endif	

	int wait_time[10] = {0, 0, 0, 0};				// wait time of jobs		[output]
	int total_time[10] = {0, 0, 0, 0};				// turnaround time 		[output]
	
	int num_jobs = 4;									// total number of jobs
	int cur_time = 0;									// to track current time while execution
	int completed = 0;									// to count number of jobs completed
	burst_time[9] = INT_MAX;						// can intitialize to any big value (used in finding minimum in array below)
	
	while(completed!=num_jobs)					// loop will continue until all jobs are done
	{
		int smallest_job = 9;							// initialized smallest_job as max burst time job (for finding minimum burst time job)
		for(int job_id = 0; job_id<num_jobs; job_id++)		// iterate for all jobs
		{
			// if job has arrived and its burst time is not zero and burst time is less than other jobs which have come so far
			if(arrival_time[job_id] <= cur_time && burst_time[job_id] > 0 && burst_time[job_id] < burst_time[smallest_job])
			{
				smallest_job = job_id;
			}
		}
		
		burst_time[smallest_job] -- ;				// reduce burst time of smallest job by 1 sec
		for(int job_id = 0; job_id<num_jobs; job_id++)		// to update waiting time for other jobs 
		{
			// if job is not running and not already finished and has arrived already waiting for execution
			if(job_id != smallest_job && burst_time[job_id] != 0 && arrival_time[job_id] <= cur_time)
				wait_time[job_id] ++ ;				// then increase it's waiting time by 1 sec
		}
		
		if(burst_time[smallest_job] == 0)		// if the running job is finished
		{
			completed++;									// increase the number of completer jobs
			// turnaround time = (current time + 1) - arrival time
			total_time[smallest_job] = cur_time - arrival_time[smallest_job] + 1;		
		}
		cur_time ++ ;										// current time has elapsed now
	}
	// all jobs completed now	
	
	// compute total wait and turnaround
	float wait_total = 0;
	float time_total = 0;
	for(int job_id = 0; job_id<num_jobs; job_id++)
	{
		wait_total += wait_time[job_id];
		time_total += total_time[job_id];
	}

// change 0 to 1 if want to print waiting and turnaround time array	
#if 0	
	print(wait_time, num_jobs);
	print(total_time, num_jobs);
#endif	

	cout<<"\nAverage wait time : "<<wait_total/num_jobs;
	cout<<"\nAverage overall time : "<<time_total/num_jobs;
	cout<<endl;
	return 0;
}