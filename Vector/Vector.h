

#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Vector {
	void *arr;
	int n;
	int capacity;
	int eachSize;
	bool ok = true;
};

void resize (Vector *vec, int size) {
	assert (vec->ok);

	void *nArr = malloc (size * vec->eachSize);
	for (int i = 0; i < size && i < vec->capacity; i++) {
		memcpy ((char *) nArr + i * vec->eachSize, (char *) vec->arr + i * vec->eachSize, vec->eachSize);
	}
	free (vec->arr);
	vec->arr = nArr;
	vec->capacity = size;
}

void init (Vector *vec, int eachSize) {
	assert (vec->ok);

	vec->eachSize = eachSize;
	resize (vec, 16);
}