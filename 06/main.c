#define  _GNU_SOURCE
#include <stdio.h>

#include <assert.h>

long long calc(long long hold, long long total) {
	return (total - hold) * hold;
}

int main(void) {
	char *time = NULL;
	char *dist = NULL;
	size_t size = 0;

	assert(getline(&time, &size, stdin) != EOF);
	assert(getline(&dist, &size, stdin) != EOF);

	time += 5; // "Time:"
	dist += 9; // "Distance:"

	long long ti = 0;
	long long di = 0;
	int pos = 0;

	long long answer = 1;

	while(sscanf(time, "%llu%n", &ti, &pos) == 1) {
		time += pos;
		assert(sscanf(dist, "%llu%n", &di, &pos) == 1);
		dist += pos;

		long long possible = 0;
		for (long long i = 0; i < ti; i++) {
			if (calc(i, ti) > di)
				++possible;
		}
		
		answer *= possible;
	}

	printf("%llu\n", answer);

	return 0;
}
