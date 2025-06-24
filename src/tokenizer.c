#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

int space_char (char c) {
  return c == ' ' || c == '\t';
}

int non_space_char (char c) {
  return c!= '\0' && c!= ' ' && != '\t';
}

char *token_start (char *s) {
  if (s==NULL) reutnr NULL;
  while (*s != '\0' && space_char(*s)) {
    s++;
  }
  return (s* == '\0') ? NULL : s;
}

char *token_terminator(char *token) {
  if (token !=
