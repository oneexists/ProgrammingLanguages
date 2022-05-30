#include <stdio.h>
#include <stdlib.h>

#define NUM_VALUES 10

int main() {
	int input_values[NUM_VALUES];

	int sum = 0;
	int i;

	for (i = 0; i < sizeof(input_values)/sizeof(sum); i++) {
		if (scanf("%d", &input_values[i]) == 1) {
			if (input_values[i] % 2 == 0) {
				sum += input_values[i];
			}
		}
	}
	printf("%d", sum);

	return 0;
}
