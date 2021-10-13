/*To simulate a simple calculator that performs basic tasks such as addition, subtraction,
multiplication, and division.*/

#include <stdio.h>

float addition(float a, float b){
	return a + b;
}

float subtract(float a, float b) {
	return a - b;
}

float multiply(float a, float b) {
	return a*b;
}

float divide(float a, float b) {
		return a/b;
}


int main(void) {

	float a;
	float b;
	int choice;
  printf("\nEnter first number:");
	scanf("%f", &a);
	printf("\nEnter second number:");
	scanf("%f", &b);
	
	A :
	printf("\nSpecify the operation to perform among: \n1.Addition \n2.Subtraction \n3.Product \n4.Divide \n");
	scanf("%d", &choice);

	switch (choice) {
		case 1:
		printf("\n Addition: %f", addition(a,b));
		break;

		case 2:
		printf("\n subtraction: %f", subtract(a,b));
		break;

		case 3:
		printf("\n Product: %f", multiply(a,b));
		break;

		case 4:
		if (b == 0) {
			printf("Invalid input for second number.");
		}	else {
			printf("\n Division: %f", divide(a,b));
		}
		break;

		default: 
		printf("\nInvalid Choice!");
		printf("\n");
		goto A;
		
	}
  return 0;
}

	