#include "CVector.h"
#include <stdio.h>

int main() {
    Vector* vec = vector_create(100);
    for (int i = 0; i < 100; i++) {
        vector_push(vec, (void*) &i);
    };
    for (size_t i = 0; i < 100; i++) {
        printf!("%d", vector_index(i));
    };
    return 0;
}
