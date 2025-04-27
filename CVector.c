#include "CVector.h"

Vector* vector_create(size_t initial_capacity) {
    Vector* vec = (Vector*)malloc(sizeof(Vector));
    if (!vec) return NULL;
    vec->ptr = (void**)malloc(initial_capacity * sizeof(void*));
    if (!vec->ptr) {
        free(vec);
        return NULL;
    }
    vec->len = 0;
    vec->cap = initial_capacity;
    return vec;
}

Vector* vector_from_array(void** array, size_t length) {
    Vector* vec = vector_create(length);
    if (!vec) return NULL;
    for (size_t i = 0; i < length; i++) {
        vec->ptr[i] = array[i];
    }
    vec->len = length;
    return vec;
}

void** vector_to_array(Vector* vec) {
    void** array = (void**)malloc(vec->len * sizeof(void*));
    if (!array) return NULL;
    for (size_t i = 0; i < vec->len; i++) {
        array[i] = vec->ptr[i];
    }
    return array;
}

void vector_push(Vector* vec, void* item) {
    if (vec->len >= vec->cap) {
        vec->cap *= 2;
        vec->ptr = (void**)realloc(vec->ptr, vec->cap * sizeof(void*));
    }
    vec->ptr[vec->len++] = item;
}

void vector_pop(Vector* vec) {
    if (vec->len > 0) {
        vec->len--;
    }
}

void* vector_index(Vector* vec, size_t index) {
    if (index < vec->len) {
        return vec->ptr[index];
    }
    return NULL;
}

void vector_modify(Vector* vec, size_t index, void* item) {
    if (index < vec->len) {
        vec->ptr[index] = item;
    }
}

size_t vector_search(Vector* vec, void* item) {
    for (size_t i = 0; i < vec->len; i++) {
        if (vec->ptr[i] == item) {
            return i;
        }
    }
    return -1;
}

void vector_add_at_index(Vector* vec, size_t index, void* item) {
    if (index > vec->len) return;
    if (vec->len >= vec->cap) {
        vec->cap *= 2;
        vec->ptr = (void**)realloc(vec->ptr, vec->cap * sizeof(void*));
    }
    for (size_t i = vec->len; i > index; i--) {
        vec->ptr[i] = vec->ptr[i - 1];
    }
    vec->ptr[index] = item;
    vec->len++;
}

void vector_remove_at_index(Vector* vec, size_t index) {
    if (index >= vec->len) return;
    for (size_t i = index; i < vec->len - 1; i++) {
        vec->ptr[i] = vec->ptr[i + 1];
    }
    vec->len--;
}

VectorPair* split_at_index(Vector* vec, size_t index) {
    if (index > vec->len) return NULL;
    VectorPair* pair = (VectorPair*)malloc(sizeof(VectorPair));
    if (!pair) return NULL;
    pair->left = vector_create(index);
    pair->right = vector_create(vec->len - index);
    if (!pair->left || !pair->right) {
        free(pair->left);
        free(pair->right);
        free(pair);
        return NULL;
    }
    for (size_t i = 0; i < index; i++) {
        vector_push(pair->left, vec->ptr[i]);
    }
    for (size_t i = index; i < vec->len; i++) {
        vector_push(pair->right, vec->ptr[i]);
    }
    return pair;
}

void vector_free(Vector* vec) {
    if (vec) {
        free(vec->ptr);
        free(vec);
    }
}