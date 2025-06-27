#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

// Return true if c is a space or tab
int space_char(char c) {
    return c == ' ' || c == '\t';}

// Return true if c is NOT a space or tab and NOT the null terminator
int non_space_char(char c) {
    return c != '\0' && c != ' ' && c != '\t';}

// Return pointer to first non-space character in str, or 0 if none
char *token_start(char *str) {
    while (*str != '\0' && space_char(*str)) {
        str++;}
    return (*str == '\0') ? 0 : str;}

// Return pointer to first space/tab or '\0' after the token
char *token_terminator(char *token) {
    while (*token != '\0' && non_space_char(*token)) {
        token++;}
    return token;}

// Count how many tokens are in the string
int count_tokens(char *str) {
    int count = 0;
    char *start = token_start(str);
    while (start) {
        count++;
        char *end = token_terminator(start);
        start = token_start(end);}
    return count;}

// Return a null-terminated copy of a string segment of length len
char *copy_str(char *inStr, short len) {
    if (inStr == 0 || len <= 0) return 0;
    char *copy = malloc(len + 1);
    if (copy == 0) return 0;
    for (short i = 0; i < len; i++) {
        copy[i] = inStr[i];}
    copy[len] = '\0';
    return copy;}

// Tokenize the string into an array of dynamically allocated strings
char **tokenize(char *str) {
    int count = count_tokens(str);
    if (count == 0) return 0;
    char **tokens = malloc((count + 1) * sizeof(char *));
    if (tokens == 0) return 0;
    char *start = token_start(str);
    int i = 0;
    while (start && i < count) {
        char *end = token_terminator(start);
        short len = end - start;
        tokens[i] = copy_str(start, len);
        if (tokens[i] == 0) {
            for (int j = 0; j < i; j++) free(tokens[j]);
            free(tokens);
            return 0;}
        i++;
        start = token_start(end);}
    tokens[i] = 0;
    return tokens;}

// Print each token on its own line
void print_tokens(char **tokens) {
    if (tokens == 0) return;
    for (int i = 0; tokens[i] != 0; i++) {
        puts(tokens[i]);}}

// Free all tokens and the array itself
void free_tokens(char **tokens) {
    if (tokens == 0) return;
    for (int i = 0; tokens[i] != 0; i++) {
        free(tokens[i]);}
    free(tokens);}
