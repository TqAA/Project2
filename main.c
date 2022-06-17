/*
Author: Boev Maxim
 Calculator with 6 basic functions
 The user must select one of the allowable operations and 2 numbers, then the calculator will make calculations and prompt the user to continue or stop working
*/

#define _CRT_SECURE_NO_WARNINGS
//Standard libraries
#include <stdio.h>
#include <stdlib.h>
//Function for degree expansion
double degree(float num1, float num2)
{
	if (num2 == 0) return 1;
	else
	{
		float numb1 = num1;
		for (int i = 1; i < num2; i++)
		{
			numb1 *= num1;
		}
		return numb1;
	}
}

//Function for vector operations
void vectorCalculation(char operations, FILE* inFile, FILE* outFile)
{
	int* vector1;
	int* vector2;
	float scalar;
	int vectorSize;// The dimensionality of the vector

	fscanf(inFile, "%i", &vectorSize);

	vector1 = malloc(vectorSize * sizeof(int));
	vector2 = malloc(vectorSize * sizeof(int));

	for (int i = 0; i < vectorSize; i++) fscanf(inFile, "%i", &vector1[i]);

	for (int i = 0; i < vectorSize; i++) fscanf(inFile, "%i", &vector2[i]);

	void printVector(int* vector)
	{
		fprintf(outFile, "(");
		for (int i = 0; i < (vectorSize - 1); i++) fprintf(outFile, "%i, ", vector[i]);
		fprintf(outFile, "%i)", vector[vectorSize - 1]);
	}

	printVector(vector1);
	fprintf(outFile, " %c ", operations);

	printVector(vector2);
	fprintf(outFile, " = ");

	int result[vectorSize]; //to store the result in vector form

	switch (operations)
	{
	case '+':
		for (int i = 0; i < vectorSize; i++) result[i] = vector1[i] + vector2[i];
		printVector(result);
		fprintf(outFile, "\n");
		break;
	case '-':
		for (int i = 0; i < vectorSize; i++) result[i] = vector1[i] - vector2[i];
		printVector(result);
		fprintf(outFile, "\n");
		break;
	case '^':
		for (int i = 0; i < vectorSize; i++) scalar += vector1[i] * vector2[i];
		fprintf(outFile, "%g\n", scalar);
		break;
	default:
		fprintf(outFile, "Error404\n", operations);

	}
	//Freeing the memory
	free(vector1);
	free(vector2);
}
//Function for determining the factorial
long long int factorial(int num1)
{
	if (num1 == 0) return 1;
	else
	{
		long long int fact = 1;
		for (int i = 1; i <= num1; i++)
		{
			fact *= i;
		}
		return fact;
	}
}

//Function for simple arithmetic operations
void arithmetic(char operations, FILE* inFile, FILE* outFile)
{
	float num1, num2 = 1; //Variables for operands
	
	fscanf(inFile, "%f", &num1);

	int wholeA = num1;
	float CheckA = num1 / wholeA; //Checking for an integer

	if (operations != '!')
	{
		fscanf(inFile, "%f", &num2);
	}

	int wholeB = num2; //Checking for an integer
	float CheckB = num2 / wholeB;

	switch (operations)
	{
	case '+':
		fprintf(outFile, "%g %c %g = %g\n", num1, operations, num2, num1 + num2);
		break;

	case '-':
		fprintf(outFile, "%g %c %g = %g\n", num1, operations, num2, num1 - num2);
		break;

	case '*':
		fprintf(outFile, "%g %c %g = %g\n", num1, operations, num2, num1 * num2);
		break;

	case '/':
		if (num2 == 0) fprintf(outFile, "Don't do it\n");
		else fprintf(outFile, "%g %c %g = %g\n", num1, operations, num2, num1 / num2);
		break;

	case '!':
		if ((CheckA != 1) || (num1 < 0)) fprintf(outFile, "Must be a non-negative integer\n");
		else fprintf(outFile, "%g %c = %lli\n", num1, operations, factorial(num1));
		break;

	case '^':
		if ((CheckB != 1) || (num2 < 0)) fprintf(outFile, "Degree Must be a non-negative integer\n");
		else fprintf(outFile, "%g %c %g = %g\n", num1, operations, num2, degree(num1, num2));
		break;

	default:
		fprintf(outFile, "Error404\n", operations);
	}
}


int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	printf("You need to write down the data in a certain order:\n");
	printf("Operation(+,- etc), Data type(v,s), Dimension(for v),Operands (separated by a space)\n");

	while (1) //Infinite while loop
	{
		char choice, operation, type; //type - переменная для хранения типа операндов
		char input_Name[255];
		char output_Name[255];//Variables for storing file names


		printf("Enter a name for the input file: ");
		scanf("%s", &input_Name);

		printf("Enter a name for the output file: ");
		scanf("%s", &output_Name);

		FILE* input = fopen(input_Name, "r");
		FILE* output = fopen(output_Name, "w");

		while (fscanf(input, " %c %c", &operation, &type) != EOF) //Reading a file all the way through("EOF"indicator of the operating system
		{                                                         //indicating that the data in the source has run out of)
			if (type == 'v') vectorCalculation(operation, input, output);
			else if (type == 's') arithmetic(operation, input, output);//Definitions of the type of operations (vector or scalar)
			else
			{
				fprintf(output, "Error404\n", type);
			}
		}

		//Closing files after the end of the run
		fclose(input);
		fclose(output);

		//Restarting the programme
		printf("Do you want to continue working with the calculator? (y/n) \n");
		scanf(" %c", &choice);
		if (choice == 'n') break;

	}


	return 0;
}