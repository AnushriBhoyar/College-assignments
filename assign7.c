/*Implement Circular Queue using Array. Perform following operations on it. a) Insertion (Enqueue) b) Deque (Dequeue) Display
Roll No: SYITA114
*/

#include<stdio.h>
#include <stdlib.h>
#define MAX 9
int cqueue_arr[MAX];
int front = -1;
int rear = -1;
void insert(int ele)
{
if((front == 0 && rear == MAX-1) || (front == rear+1))
{
printf("\nQueue Overflown");
return;
}
if(front == -1)
{
front = 0;
rear = 0;
}
else
{
if(rear == MAX-1)
rear = 0;
else
rear = rear+1;
}
cqueue_arr[rear] = ele;
}
void Deque()
{
if(front == -1)
{
printf("\nQueue Underflown");
return ;
}
printf("\nElement deleted from the queue is : %d",cqueue_arr[front]);
if(front == rear)
{
front = -1;
rear=-1;
}
else
{
if(front == MAX-1)
front = 0;
else
front = front+1;
}
}
void display()
{
int front_position = front,rear_position = rear;
if(front == -1)
{
printf("\nQueue is empty");
return;
}
printf("\nQueue elements are: ");
if (front_position <= rear_position)
while(front_position <= rear_position)
{
printf("%d ",cqueue_arr[front_position]);
front_position++;
}
else
{
while(front_position <= MAX-1)
{
printf("%d ",cqueue_arr[front_position]);
front_position++;
}
front_position = 0;
while(front_position <= rear_position)
{
printf("%d ",cqueue_arr[front_position]);
front_position++;
}
}
printf("n");
}
int main()
{
int choice,ele;
do
{
printf("\nCircular Queue:");
printf("\n1)Insert");
printf("\n2)Delete");
printf("\n3)Display");
printf("\n4)Exit");
printf("\nEnter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 :
printf("Input the element to insert in queue: ");
scanf("%d", &ele);
insert(ele);
break;
case 2 :
Deque();
break;
case 3:
display();
break;
case 4:
exit(0);
break;
default:
printf("Invalid choice!!!");
}
}while(choice!=4);
return 0;
}
