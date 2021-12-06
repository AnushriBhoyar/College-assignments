#include <stdio.h>

int A[10], B[10], C[10], D[10], i, j, k = 0, n, m, flag = 0;

void displayArray(int arr[], int a) {

	printf("{");
	for (int i = 0; i < a; i++)
	printf(" %d ", arr[i]);
	printf("}");
}

void arrayUnion() {
  for (int i = 0; i < n; i++) {
    C[k] = A[i];
    k++;
  }
  for (int i = 0; i < m; i++) {
    flag = 0;
    for (int j = 0; j < n; j++) {
      if (B[i] == A[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      C[k] = B[i];
      k++;
    }
  }
  printf("\nunion of sets = \t");
	printf("{");
  for (i = 0; i < k; i++) {
    printf("%d ", C[i]);
  }
	printf("}");
}

void intersection() {
  printf("\nIntersections of sets = ");
	printf("\t{ ");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (A[i] == B[j])
        printf("%d ", A[i]);
    }
  }
	printf("}");
}

void difference() {
  printf("\nA-B = \t");
	printf("{ ");
  for (i = 0; i < n; i++) {
    flag = 0;
		
    for (j = 0; j < m; j++) {
      if (A[i] == B[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      printf("%d ", A[i]);
  }
	printf("}");

  printf("\n\nB-A = \t");
	printf("{ ");
  for (i = 0; i < m; i++) {
    flag = 0;
    for (j = 0; j < n; j++) {
      if (B[i] == A[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      printf("%d ", B[i]);
  }
	printf("}");
}

void symmetric_diff() {
  k = 0;
  for (i = 0; i < n; i++) {
    flag = 0;
    for (j = 0; j < m; j++) {
      if (A[i] == B[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      D[k] = A[i];
      k++;
    }
  }
  for (i = 0; i < m; i++) {
    flag = 0;
    for (j = 0; j < n; j++) {
      if (B[i] == A[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      D[k] = B[i];
      k++;
    }
  }

  printf("\nSymmetric Difference of A and B are =");
	printf("\t{ ");
  for (i = 0; i < k; i++) {
    printf("%d ", D[i]);
  }
	printf("}");
}

int main() {
  printf("Enter the size of array A\n");
  scanf("%d", & n);
  printf("Enter the element of array A\n");
  for (i = 0; i < n; i++) {
    scanf("%d", & A[i]);
  }
  printf("Enter the size of array B\n");
  scanf("%d", & m);
  printf("Enter the elements of array B\n");
  for (j = 0; j < m; j++) {
    scanf("%d", & B[j]);
  }

	printf("\nSet A = "); displayArray(A, n);
	printf("\nSet B = ");displayArray(B, m);
	
	printf("\n");
  arrayUnion();
  printf("\n");

  intersection();
  printf("\n\n");

  printf("difference of set:\n");
  difference();
  printf("\n");

  symmetric_diff();
  printf("\n");

  return 0;
}