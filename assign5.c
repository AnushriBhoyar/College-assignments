/*Implement any database using a doubly-linked list with the following options a) Insert a record b) delete a record c) modify a record d) Display list forward Display list backward*
ROLL NO: SYITA114
*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
  int prn, marks;
  char name[20];
  struct node * prev, * next;

};

struct node * insert(struct node * head) {
  int student;
  char name[20];
  struct node * temp, * q;
  q = head;

  printf("Enter prn number :");
  scanf("%d", & head -> prn);
  printf("Enter name :");
  scanf("%s", name);
  strcpy(head -> name, name);
  printf("Enter IE marks :");
  scanf("%d", & head -> marks);
  head -> prev = NULL;
  head -> next = NULL;
  printf("Enter the nuber of students, whose data need to be taken\n");
  scanf("%d", & student);
  printf("Enter the data:\n");

  for (int i = 0; i < student; i++) {
    temp = (struct node * ) malloc(sizeof(struct node));
    printf("Enter prn no. :");
    scanf("%d", & temp -> prn);
    printf("Enter name :");
    scanf("%s", temp -> name);
    printf("enter IE marks :");
    scanf("%d", & temp -> marks);

    temp -> next = NULL;
    temp -> prev = head;
    head -> next = temp;
    head = head -> next;
  }
  return q;
}

void display(struct node * head) {
  struct node * p;
  p = head;

  while (p != NULL) {
    printf("prn_no:%d\n", p -> prn);
    printf("name:%s\n", p -> name);
    printf("IE_MARKS:%d\n\n\n", p -> marks);
    p = p -> next;
  }

}
void del(struct node * head) {
  int pn;
  printf("enter prn number to delete the record\n");
  scanf("%d", & pn);

  struct node * p, * q;
  p = head;
  q = head -> next;

  while (p -> prn != pn) {
    p = p -> next;
    q = q -> next;
  }
  p -> prev -> next = p -> next;
  q -> prev = p -> prev;
  free(p);

}
void DeleteStart(struct node * head) {
  struct node * p = head;
  head = head -> next;
  head -> prev = NULL;
  free(p);
  printf("Deleted succesfully\n");
}
void DeleteEnd(struct node * head) {
  struct node * p = head;
  while (p != NULL && p -> next != NULL) {
    p = p -> next;

  }
  p -> prev -> next = NULL;
  free(p);

}

int main(void) {
  int a;
  struct node * head;
  head = (struct node * ) malloc(sizeof(struct node));

  do {
    printf("\n1)Insert a record\n2)Delete a prn number between first and last \n3)Delete a prn number at starting\n4)Display list\n5)Deleting a prn number at end\n6)Exit");

    printf("\n\nEnter ur choice: \n");
    scanf("%d", & a);

    switch (a) {
    case 1:
      head = insert(head);
      break;
    case 2:
      del(head);
      break;
    case 3:
      DeleteStart(head);
      break;
    case 4:
      display(head);
      break;
    case 5:
      DeleteEnd(head);
      break;
    case 6:
      exit(0);

    }

  } while (a != 5);

}
