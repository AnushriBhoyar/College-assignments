#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
  int roll;
  int prn;
  char name[30];
  struct node * next;

};
struct node * create() {
  struct node * head;
  int p, r;
  char name[20];
  head = (struct node * ) malloc(sizeof(struct node));
  printf("Enter ur prn no, roll no and name\n");
  scanf("%d%d%s", & p, & r, name);
  head -> prn = p;
  head -> roll = r;
  strcpy(head -> name, name);
  head -> next = NULL;
  return head;
}
void AddMember(struct node * head) {
  int a;
  struct node * temp, * q;
  q = head;
  printf("Number of members you want to add\n");
  scanf("%d", & a);
  for (int i = 0; i < a; i++) {
    temp = (struct node * ) malloc(sizeof(struct node));
    printf("Enter ur prn-no,roll_no and name\n");
    scanf("%d %d %s", & temp -> prn, & temp -> roll, temp -> name);
    q -> next = temp;
    q = temp;
  }

}
void display(struct node * head) {
  while (head != NULL) {
    printf("\nprn_no=%d\n", head -> prn);
    printf("roll_no=%d\n", head -> roll);
    printf("name=%s\n", head -> name);
    head = head -> next;
  }
}
void DeletePresident(struct node * head) {
  struct node * q;
  q = head -> next;
  free(head);
}
void AddSecretary(struct node * head) {
  struct node * s;
  char ja[30];
  s = (struct node * ) malloc(sizeof(struct node));
  printf("enter prn-no,roll-no and name\n");
  scanf("%d%d", & s -> prn, & s -> roll);
  scanf("%s", ja);
  strcpy(s -> name, ja);
  while (head != NULL && head -> next != NULL) {
    head = head -> next;
  }
  head -> next = s;
  s -> next = NULL;

}
void DeleteSecratary(struct node * head) {
  while (head != NULL && head -> next != NULL) {
    head = head -> next;
  }
  free(head);
}
void DeleteMember(struct node * head) {
  int n;
  struct node * p;

  printf("Enter the prn nunber to delete the node\n");
  scanf("%d", & n);

  while (head -> prn != n) {
    p = head;
    head = head -> next;

  }

  p -> next = head -> next;
  free(head);

}

int getCount(struct node* head)
{
    int count = 0;  // Initialize count
    struct node* current = head;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}



int main() {
  int a;
  char ch;
  struct node * head;
  do {
    printf("WELCOME TO THE PINACCLE CLUB");
    printf("\nMenu");
    printf("\n1)Add president\n2)Add member\n3)Add secratery\n4)Delete president\n5)Delete secratery\n6)Delete member\n7)Display\n8)Compute the total\n9)Exit the program\n");
    printf("enter your choice\n");
    scanf("%d", & a);
    switch (a) {
    case 1:
      head = create();
      break;
    case 2:
      AddMember(head);
      break;
    case 3:
      AddSecretary(head);
      break;
    case 4:
      DeletePresident(head);
      break;
    case 5:
      DeleteSecratary(head);
      break;
    case 6:
      DeleteMember(head);
      break;
    case 7:
      display(head);
      break;
		case 8:
			getCount(head);
			printf("The total count is: %d", getCount(head));
    case 9:
      exit(0);

    }

  } while (a != 8);

}

