/*Write a Menu driven program in C for a cricket player’s display board. The information of the
cricketer can be (not limited to) Name, Age, Country, Category (Batsman, Bowler, Wicket keeper,
All-rounder), Number of ODI’s played, Number of International 20-20’s played. Display
following.
a) Number of batsman of a particular country
b) Sort the Batsman as per the average batting score(Bubble/insertion sort)
c) Batsman with highest average score (Binary search)
d) Number of bowlers of a particular country
e) The bowler that has taken a maximum no of wickets
f) Show particular players the entire “Display board information”
Delete/Modify the record
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cricket {
  char name[20], country[20], category[20];
  int age, odi, twenty, wickets;
  float batscore;
}
cricket;

int main() {
  cricket s[20];
  int n, op, counter, index;
  char country[20], nm[20], t[20];

  printf("\nEnter number of players ");
  scanf("%d", & n);

  printf("\n Enter data of %d players\n", n);
  for (int i = 0; i < n; i++) {
    printf("\n Enter name of the player ");
    scanf("%s", s[i].name);
    printf("\n Enter age of the player ");
    scanf("%d", & s[i].age);
    printf("\n Enter country of the player ");
    scanf("%s", s[i].country);
    printf("\n Enter category of the player ");
    scanf("%s", s[i].category);
    printf("\n Enter Number of ODIs played ");
    scanf("%d", & s[i].odi);
    printf("\n Enter Number of International 20-20s played ");
    scanf("%d", & s[i].twenty);
    printf("\n Enter Average batting score ");
    scanf("%f", & s[i].batscore);
    printf("\n Enter Total number of wickets taken ");
    scanf("%d", & s[i].wickets);
  }

		printf("\nPlayers:\n");
		printf("\n\nname \tcountry \tcategory \tage \todi \t20-20s \tbatscore \twickets\n");
		for (int i = 0; i < n; i++) {
			
          printf("%s \t\t%s \t\t%s \t\t%d ", s[i].name, s[i].country, s[i].category, s[i].age);
          printf("\t\t%d \t\t%d \t\t%f \t\t%d\n", s[i].odi, s[i].twenty, s[i].batscore, s[i].wickets);

		}

		

  do {
    printf("\n\nMENU \n1) Number of batsman of a particular country \n");
    printf("2)Sort the Batsman as per the average batting score\n");
    printf("3) Batsman with highest average score \n");
    printf("4) Number of bowlers of a particular country \n");
    printf("5) Bowler that has taken maximum no of wickets \n");
    printf("6) Show a particular players entire -Display board information \n");
    printf("7) Exit \n");
    printf("Enter your option: ");
    scanf("%d", & op);

	
    switch (op) {
    case 1:
      counter = 0;
      printf("\nEnter country to display number of batsman: ");
      scanf("%s", country);
      for (int i = 0; i < n; i++) {
        if ((strcmp(country, s[i].country) == 0) && (strcmp("batsman", s[i].category) == 0))
          counter++;
      }
      printf("\nNumber of batsman of a %s country= %d ", country, counter);
      break;

    case 2:

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
          if (s[j].batscore > s[j + 1].batscore) {
            strcpy(t, s[j].name);
            strcpy(s[j].name, s[j + 1].name);
            strcpy(s[j + 1].name, t);

          }
        }
      }
      printf("\nCricketer info in terms of runs scored \n");
      printf("\nNAME\t\t\tRUNS_SCORED\n");
      printf("------------------------------------------------------------------------\n");

      for (int i = 0; i < n; i++) {
        printf("%s\t\t\t%f\n", s[i].name,  s[i].batscore);
      }

      break;
    case 3:
      counter = 0;
      index = 0;
      for (int i = 0; i < n; i++) {
        if (strcmp("batsman", s[i].category) == 0) {
          if (s[i].batscore > counter) {
            counter = s[i].batscore;
            index = i;
          }
        }
      }
      printf("\n Name of Batsman with highest average score is %s\n", s[index].name);
      break;

    case 4:
      counter = 0;
      printf("\nEnter country to display number of bowlers: ");
      scanf("%s", country);
      for (int i = 0; i < n; i++) {
        if ((strcmp(country, s[i].country) == 0) && (strcmp("bowler", s[i].category) == 0))
          counter++;
      }
      printf("\nNumber of bowlers of a %s country= %d ", country, counter);
      break;
    case 5:
      counter = 0;
      index = 0;
      for (int i = 0; i < n; i++) {
        if (strcmp("bowler", s[i].category) == 0) {
          if (s[i].wickets > counter) {
            counter = s[i].wickets;
            index = i;
          }
        }
      }
      printf("\n Name of Bowler who has taken maximum no of wickets is %s\n", s[index].name);
      break;
    case 6:
      printf("\n Enter Name of player to display data ");
      scanf("%s", nm);
      for (int i = 0; i < n; i++) {
        if (strcmp(nm, s[i].name) == 0) {
          printf("name \tcountry \tcategory \tage \todi \t20-20s \tbatscore \twickets\n");
          printf("%s \t\t%s \t\t%s \t\t%d ", s[i].name, s[i].country, s[i].category, s[i].age);
          printf("\t\t%d \t\t%d \t\t%f \t\t%d\n", s[i].odi, s[i].twenty, s[i].batscore, s[i].wickets);
        }
      }
      break;
    case 7:
      exit(0);
      break;
    default:
      printf("\n!! Invalid Choice !!");
      break;

    }
  } while (op != 7);
  return 0;
}