#ifndef EXERCISE1_H
#define EXERCISE1_H

#include <stdio.h>
#include <stdlib.h>
#include "CircularArrayQ.h"
#include "Exercise1.h"

/** \fn int get_queue_length(CircularArrayQueue list);
 *  \brief Get the number of elements in the current queue.
 *  \param list The current queue.
*/
int get_queue_length(CircularArrayQueue list){
	return (list.rear>=list.front) ? 
			list.rear-list.front : MAX - list.front + list.rear;
}

/** \fn PersonLinkedList get_all_females(CircularArrayQueue list);
 *  \brief Returns all females as a linked list using the current list without removing them in the current list.
 *  \param list The current queue.
 *  Note: Use the queue basic operations (enqueue, dequeue, front)
*/
PersonLinkedList get_all_females(CircularArrayQueue list){
	PersonLinkedList LL = NULL;
	Type temp;
	int count = get_queue_length(list);
	
	while(count>-1){
		temp = front(list);
		dequeue(&list);
		
		if(temp.sex=='F'){
			insert_first_LL(&LL, temp);
		}
		count--;
	}
	return LL;
}

/** \fn PersonDynamicArrayList remove_all_males(CircularArrayQueue *list);
 *  \brief Remove all males in the current list and returns the removed males as a dynamic array list.
 *  \param list The current queue.
 *  Note: Use the concept of queue with out using the basic operations.
*/
PersonDynamicArrayList remove_all_males(CircularArrayQueue *list){
	PersonDynamicArrayList DAL;
	Person temp;
	int count;
	
	init_DAL(&DAL); //initialize Return Value
	
	if((list->rear+1)%MAX != list->front){ //is not empty ?
		if(list->rear > list->front){ //Calc Number of Elements
			count = list->rear-list->front;
		}else{
			count = MAX - list->front+list->rear;
		}
		
		for(; count>-1; count--){
			temp = list->data[list->front]; //getFront
			list->front = (list->front+1) % MAX; //dequeue
			
			displayPersonInfo(temp);
			
			if(temp.sex == 'M'){
				if(DAL.count+1 > DAL.max){ //Resize if Full
					DAL.max = DAL.max * 2;
					DAL.data = (Person*) realloc (DAL.data, DAL.max);
				}
				DAL.data[DAL.count] = temp; //insertLast;
				DAL.count++;	
			}else{
				list->rear = (list->rear+1)%MAX; //enqueue (rear)
				list->data[list->rear] = temp; //enqueue(data)
			}
		}
	}
	return DAL;
}

void displayQueue(CircularArrayQueue *list){
	int count = get_queue_length(*list);
	Person p;
	printf("\nDISPLAY CAQ {");
	while(count>-1){
		p = front(*list);
		dequeue(list);
		count--;
		enqueue(list, p);
		
		displayPersonInfo(p);
	}
	printf("\n\n}");
}

#endif








