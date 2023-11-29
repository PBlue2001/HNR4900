/* Parker Blue
 * 3/28/23
 * Operating Systems
 * This is a mock scheduling implementation of round robin, where every process gets equal time running
 * it adds items to the queue, picks the next task from the queue to do, and schedules accordingly
 * */

#include "queue.h"
#include "task.h"
#include "cpu.h"
#include "schedulers.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

 // add a task to the list 
void add(Queue* queue, char* name, int priority, int burst)
{
    // creates task to add to the task queue using passed params
    Task* new_task = malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->burst = burst;

    // add new task to queue
    enqueue(queue, new_task);
}

// select a task from the queue
Task* pickNextTask(Queue* queue)
{
	//returns null if empty
    return dequeue(queue);
}

// invoke the scheduler
void schedule(Queue* queue)
{
	//inialize variables
    double wait = 0, response = 0, turnaround = 0, totResp = 0, totTurn = 0;
    int tItems = queue->length, cntItems = tItems, oldCnt = tItems;
    while (queue->length > 0)
    {
	    Task* task = pickNextTask(queue);
    // if task can be completed within a single quantum, run it and remove from queue
        if (task->burst <= QUANTUM)
        {
        // if its the first time thru, cadd too adn calc response time
            if (cntItems > 1) {
                cntItems--;
                response += task->burst;
                totResp += response;
            }
            //run tasks, calc wait and run time
            run(task, task->burst);
	        turnaround+=task->burst;
	        wait+=task->burst*length(queue);
            //delete finished process and free the memory
            delete (queue, task);
	        free(task);
        }
        //else run task for a quantum and add back to queue
        else
        {
            
	        if (cntItems>1){
		        cntItems--;
		        response+=QUANTUM;
		        totResp+=response;
	        }
            run(task, QUANTUM);
	        turnaround+=QUANTUM;
	        wait+=QUANTUM*length(queue);
            task->burst -= QUANTUM;
            enqueue(queue, task);
        }
	//if a process finished, save its total completion time, easy way to calc turnaround for any
	    if( oldCnt>length(queue)){
		    oldCnt--;
		    totTurn+=turnaround;
	}
    }
    //print and calc averages
printf("Wait: %f, Response: %f, Turnaround: %f  \n",wait/tItems, totResp/tItems, totTurn/tItems);
}
