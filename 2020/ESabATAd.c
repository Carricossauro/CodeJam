#include<stdio.h>
#include<stdlib.h>

void getNextNumbers(int *k, int *num1, int *num2, int B, int *numberOfQueries) {
	char c[100];
	// fprintf(stdout, "Enter a number");
	fprintf(stdout, "%d", (*k)+1); // Give position to get
	fflush(stdout); // Flush output as requested by interactive problems

	fscanf(stdin, "%[^\n]", c); // Get 0/1 from position k+1
	getchar();
	if (c[0] == 78) exit(-1);
	else (*num1) = c[0] - 48; // 48 is ascii value for 0 (49 is ascii for 1)

	fprintf(stdout, "%d", B-(*k)); // Give position to get
	fflush(stdout); // Flush output again
	
	fscanf(stdin, "%[^\n]", c); // Get 0/1 from position B-k
	getchar();
	if (c[0] == 78) exit(-1);
	else (*num2) = c[0] - 48; // 48 is ascii value for 0 (49 is ascii for 1)
	
	(*numberOfQueries) += 2; // Increase total number of queries by 2 because 2 queries were made
}

void getNumber(int *k, int *num1, int B, int *numberOfQueries) {
	fprintf(stdout, "%d", (*k)+1); // Give position to get
	fflush(stdout); // Flush output as requested by interactive problems

	char c[2];
	fscanf(stdin, "%[^\n]", c); // Get 0/1 from position k+1
	getchar();
	if (c[0] == 78) exit(-1);
	else (*num1) = c[0] - 48;
	
	(*numberOfQueries) += 1; // Increase total number of queries by 2 because 2 queries were made
}

void fixComplementation(int *array, int B) { // Implicit what this function does
	for (int i = 0; i < B; i++) array[i] = (array[i] + 1) % 2;
}

void fixReversal(int *array, int B) { // Implicit what this function does
	int temp;
	for (int i = 0; i < B/2; i++) {
		temp = array[i];
		array[i] = array[B-i-1];
		array[B-i-1] = temp;
	}
}

void storeNumbers(int *array, int num1, int num2, int k, int B) { // Stores values num1 and num2 in positions k and B-k-1
	array[k] = num1;
	array[B-k-1] = num2;
}

void fixArray(int *array, int complementation, int reversal, int B) {
	if (complementation) fixComplementation(array, B);
	if (reversal) fixReversal(array, B);
}

int main() {
	int T, B;
	fscanf(stdin, "%d %d", &T, &B); // Receive T and B
	getchar();
	char buffer[B+1];
	int array[B], num1, num2, k, total;
	int samePairk, diffPairk, queries;
	int comp, rev;

	// Loop for all test cases
	for (int CaseNumber = 0; CaseNumber < T; CaseNumber++) {

		k = 0;
		total = 2;
		samePairk = diffPairk = -1;
		queries = 0;
		comp = rev = 0;

		getNextNumbers(&k, &num1, &num2, B, &queries); // get positions 1 and B (10, 20 or 100)
		storeNumbers(array, num1, num2, k, B);
		k++;
		if (num1 == num2) { // First 2 numbers are a "same" pair
			samePairk = 0;
		} else {
			diffPairk = 0;
		}

		// Main (query -> fix/store) loop
		while (total < B) {
			while (queries % 10 != 0) { // 10 queries before quantum fluctuation possiblity
				getNextNumbers(&k, &num1, &num2, B, &queries); // Get next 2 numbers
				storeNumbers(array, num1, num2, k, B); // Store the numbers just received
				k++;

				if (samePairk == -1 && num1 == num2) samePairk = k-1;
				else if (diffPairk == -1 && num1 != num2) diffPairk = k-1;

				total += 2;
				if (total >= B) break;
			}
			if (total < B) {
				comp = rev = 0;
				if (samePairk != -1) { // Check for complementation
					getNumber(&samePairk, &num1, B, &queries); // Queries number 11, 21, 31, 41, 51 , ... go here
					if (array[samePairk] != num1) comp = 1;
				}
				if (diffPairk != -1) { // Check for reversal
					getNumber(&diffPairk, &num2, B, &queries); // Queries number 12, 22, 32, 42, 52 , ... go here
					if (array[diffPairk] != num2) {
						if (!comp) rev = 1;
					} else if (comp) rev = 1;
				}
				fixArray(array, comp, rev, B);
			}
		}
		// print elements
		for(int p = 0; p < B; p++) buffer[p] = 48 + array[p];
		buffer[B] = '\0';
		fprintf(stdout, "%s", buffer);
		fflush(stdout);
		fscanf(stdin, "%[^\n]", buffer);
		getchar();
		if (buffer[0] == 78) return -1;
	}
	return 0;
}