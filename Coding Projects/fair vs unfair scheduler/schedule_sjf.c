/* Parker Blue, Aidan Breshears, Bryant Randleman
 * 3/28/23 
 * Operating Systems
 * This is a mock scheduler implementation of shortest job first.
 * It adds items to the queue, sorts the tasks and picks the next task from the queue to do as they are now in shortest order, and schedules them accordingly.
 * */

#include"queue.h"
#include"task.h"
#include"cpu.h"
#include"schedulers.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

// add a task to the list 
void add(Queue *queue, char *name, int priority, int burst)
{
	//creates task to add to the queue using passed in params
	Task *Next = malloc(sizeof(Task));
	Next->name = strdup(name);
	Next->priority= priority;
	Next->burst = burst;
	//add new task to queue
	enqueue(queue, Next);
}

// select a task from the queue
Task* pickNextTask(Queue *queue)
{
	//returns NULL if queue is empty
	//grab first item, compare, store the smallest item 
	Task *tmp = dequeue(queue);
	for (int i =0;i<length(queue);i++){
		Task* task = dequeue(queue);
		if(tmp->burst <= task->burst){
			enqueue(queue, task);
		}
		else{
			Task* swap = tmp;
			tmp = task;
			task = swap;
			enqueue(queue, task);}
	}
	//returns smallest item
	return tmp;	 
}

// invoke the scheduler
void schedule(Queue *queue)
{
	//time variables for total time spent waiting, running, and a counter of items it has run
	double wait = 0, tRan= 0, count = 0;
	Task *task;
	//while not empty, pick the next task and run it to completion.
	while((task = pickNextTask(queue))!= NULL){
		//increase counter of tasks processed and add their wait and time running to totals
		count++;
		wait+=tRan;
		tRan+=task->burst;
		run(task, task->burst);
		//avg wait for first run item is 0, so no need to add its runtime to wait
		delete(queue, task);
		free(task);
	}
	//div by number of items (first)
	double avgwait = wait/count, avgturn = (tRan+wait)/count;
	//avg wait and avg resonse is the same in first come first serve
	printf("avg wait time: %f  avg response time: %f  avg turnaround time: %f\n", avgwait, avgwait, avgturn);
}

