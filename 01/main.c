#define  _GNU_SOURCE
#include <stdio.h>

#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

void usage(void) {
	printf("Usage: ./main -v1/-v2\n");
	printf("	-v1	solves part 1\n");
	printf("	-v2	solves part 2\n");
}

int main(int argc, char **argv) {
	char *line = NULL;
	size_t size = 0;
	long sum = 0;
	bool part2 = false;

	if (argc != 2) {
		usage();
		return 1;
	}

	if (strcmp(argv[1], "-v1") == 0) {
		part2 = false;
	} else if (strcmp(argv[1], "-v2") == 0) {
		part2 = true;
	} else {
		return 1;
	}

	while(getline(&line, &size, stdin) != EOF) {
		int d, d1 = -1, d2 = -1;

		for(char *ptr = line; *ptr != '\n'; ptr++) {
			d = -1;
			
			if (isdigit(*ptr))
				d = *ptr - '0';
			
			if (part2) {
				if (strncmp(ptr, "one", 3) == 0)
					d = 1;
				else if (strncmp(ptr, "two", 3) == 0)
					d = 2;
				else if (strncmp(ptr, "three", 5) == 0)
					d = 3;
				else if (strncmp(ptr, "four", 4) == 0)
					d = 4;
				else if (strncmp(ptr, "five", 4) == 0)
					d = 5;
				else if (strncmp(ptr, "six", 3) == 0)
					d = 6;
				else if (strncmp(ptr, "seven", 5) == 0)
					d = 7;
				else if (strncmp(ptr, "eight", 5) == 0)
					d = 8;
				else if (strncmp(ptr, "nine", 4) == 0) 
					d = 9;
			}
			
			if (d != -1) {
				if (d1 == -1)
					d1 = d;
				d2 = d;
			}
		}

		assert(0 <= d1 && d1 <= 9);
		assert(0 <= d2 && d2 <= 9);

		sum += d1 * 10 + d2;
	}

	printf("%lu\n", sum);
	return 0;
}
