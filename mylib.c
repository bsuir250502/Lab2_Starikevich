#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

#define string 64

int print_manual() {
	char buffer[string];
	FILE *fp = fopen("README.md", "r");
	while (fgets(buffer, string, fp)) {
		printf("%s", buffer);
	} printf("\n");
	fclose(fp);

	return 0;
}

char myget_str(char *str, int length) {
fgets(str, length, stdin);
str[strlen(str) - 1] = '\0';

return *str;
}

int myget_int() {
	int number;

	char buffer[string];
	while (1) {
		fgets(buffer, string, stdin);
		number = atoi(buffer);
		if (number <= 0) {
		printf("Error! Please, enter the correct number...: ");
		continue;
		}
		break;
	}

	return number;
}

int myget_int_range(int a, int b) {
	int number;
	while (1) {
		number = myget_int();

		if (number >= a && number <= b) {
		return number;
		break;
		} else {
		printf
			("Error! Please, enter the correct number in range [%d-%d]...: ",
			 a, b);
		continue;
		}
	}
}

#ifdef __cplusplus
}
#endif
