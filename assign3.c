/*Implement a sparse matrix with operations like initialize empty sparse matrix, insert an element, add two matrices, transpose a matrix*/

#include<stdio.h>

#include<stdlib.h>

#define MAX 20

void printsparse(int[MAX][3]);
void readsparse(int[MAX][3]);
void transpose(int[MAX][3], int[][3]);
void addsparse(int b1[MAX][3], int b2[MAX][3], int b3[MAX][3]);

int main() {
  int choice;
	int b1[MAX][3], b2[MAX][3], b3[MAX][3];
  int m, n;
	A:
  printf("\n\nEnter your choice among the following:");
  printf("\n1)addition of two matrix\n2)transpose of matrix\n3)exit the program.\nenter ur choice:");
  scanf("%d", & choice);

  switch (choice) {

  case 1:
      
    readsparse(b1);

    readsparse(b2);

    addsparse(b1, b2, b3);

    printsparse(b3);

		goto A;

  case 2:

    
    readsparse(b1);
    printf("\n\nSparse Matrix: \n\n");
    printsparse(b1);
    transpose(b1, b2);
    printf("\n\n After Transpose \n\n");
    printsparse(b2);
		goto A;

	case 3:
		exit(0);
	default:

	printf("Invalid input");
	goto A;
  }
}
void readsparse(int b[MAX][3])
{
   
int i,t,m,n;
   
printf("nEnter no. of rows and columns");
   
scanf("%d%d",&m,&n);
    printf("No. of non-zero triples:");
   
scanf("%d",&t);
   
b[0][0]=m;
   
b[0][1]=n;
   
b[0][2]=t;
   
for(i=1;i<=t;i++)
    {
       
printf("Enter the triples(row,column,value):");
       
scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
    }
}

void printsparse(int b[MAX][3]) {
  int i, n;
  n = b[0][2];

  printf("\nrow\t\tcolumn\t\tvalue\n");
  for (i = 0; i <= n; i++)
    printf("%d\t\t\t%d\t\t\t%d\n", b[i][0], b[i][1], b[i][2]);
}

void transpose(int b1[][3], int b2[][3]) {
  int i, j, k, n;
  b2[0][0] = b1[0][1];
  b2[0][1] = b1[0][0];
  b2[0][2] = b1[0][2];
  k = 1;
  n = b1[0][2];
  for (i = 0; i < b1[0][1]; i++)
    for (j = 1; j <= n; j++)

      if (i == b1[j][1]) {
        b2[k][0] = i;
        b2[k][1] = b1[j][0];
        b2[k][2] = b1[j][2];
        k++;
      }
}

void addsparse(int b1[MAX][3], int b2[MAX][3], int b3[MAX][3]) {

  int t1, t2, i, j, k;

  if (b1[0][0] != b2[0][0] || b1[0][1] != b2[0][1]) {
    printf("You have entered invalid matrix!!Size must be equal");

    exit(0);
  }

  t1 = b1[0][2];

  t2 = b2[0][2];

  i = j = k = 0;

  b3[0][0] = b1[0][0];

  b3[0][1] = b1[0][1];

  while (i <= t1 && j <= t2) {

    if (b1[i][0] < b2[j][0])

    {

      b3[k][0] = b1[i][0];

      b3[k][1] = b1[i][1];

      b3[k][2] = b1[i][2];

      k++;

      i++;

    } else if (b2[j][0] < b1[i][0])

    {

      b3[k][0] = b2[j][0];

      b3[k][1] = b2[j][1];

      b3[k][2] = b2[j][2];

      k++;

      j++;

    } else if (b1[i][1] < b2[j][1])

    {

      b3[k][0] = b1[i][0];

      b3[k][1] = b1[i][1];

      b3[k][2] = b1[i][2];

      k++;

      i++;
    } else if (b2[j][1] < b1[i][1])

    {

      b3[k][0] = b2[j][0];

      b3[k][1] = b2[j][1];

      b3[k][2] = b2[j][2];

      k++;

      j++;

    } else

    {

      b3[k][0] = b1[i][0];

      b3[k][1] = b1[i][1];

      b3[k][2] = b1[i][2] + b2[j][2];

      k++;

      i++;

      j++;

    }
  }

  while (i <= t1) {

    b3[k][0] = b1[i][0];

    b3[k][1] = b1[i][1];

    b3[k][2] = b1[i][2];

    i++;

    k++;
  }

  while (j <= t2) {

    b3[k][0] = b2[j][0];

    b3[k][1] = b1[j][1];

    b3[k][2] = b1[j][2];

    j++;

    k++;
  }

  b3[0][2] = k - 1;
}
