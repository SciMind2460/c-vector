#ifndef CSTRING_H_
#define CSTRING_H_

#include <stdlib.h>

typedef struct {
  char* ptr;
  size_t len;
  size_t cap;
} String;

String* string_create(size_t initial_cap);
String* string_free(String* str);

String* string_from_chars(char* chrs, size_t len);
char* string_to_chars(String* str);

void string_push_char(String* str, char chr);
char string_pop_char(String* str);
void string_push_chars(String* str, char* chrs; size_t len);
void string_pop_chars(String* str, size_t len);

char string_index(String* str);
void string_modify(String* str, char new_chr);
char string_slice(String* str, size_t start, size_t end);
void string_slice_modify(String* str, char* new_chr, size_t start, size_t end);

size_t* string_search_single(String* str, char pat);
size_t** string_search(String* str, char* pat, size_t len);

void string_add_char_at_index(String* str, char chr, size_t index);
void string_remove_char_at_index(String* str, size_t index);
void string_add_chars_at_index(String* str, char* chr, size_t len, size_t index);
void string_remove_chars_at_index(String* str, size_t len, size_t index);

#endif
