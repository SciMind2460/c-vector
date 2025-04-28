#ifndef CVECTOR_H
#define CVECTOR_H
#include <stdlib.h>

typedef struct {
    void** ptr;
    size_t len;
    size_t cap;
} Vector;

typedef struct {
    Vector* left;
    Vector* right;
} VectorPair;

Vector* vector_create(size_t initial_capacity);

Vector* vector_from_array(void** array, size_t length);
void** vector_to_array(Vector* vec);

void vector_push(Vector* vec, void* item);
void* vector_pop(Vector* vec);

void* vector_index(Vector* vec, size_t index);
void vector_modify(Vector* vec, size_t index, void* item);

void vector_add_at_index(Vector* vec, size_t index, void* item);
void vector_remove_at_index(Vector* vec, size_t index);

size_t vector_search(Vector* vec, void* item);

VectorPair* vector_split_at_index(Vector* vec, size_t index);

void vector_free(Vector* vec);
#endif
