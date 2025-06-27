#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


int space_char(char c) {
    return c == ' ' || c == '\t';}

int non_space_char(char c) {
    return c != '\0' && c != ' ' && c != '\t';}

char *token_start(char *str) {
    while (*str != '\0' && space_char(*str)) {
        str++;}
    return (*str == '\0') ? 0 : str;}

char *token_terminator(char *token) {
    while (*token != '\0' && non_space_char(*token)) {
        token++;}
    return token;}

int count_tokens(char *str) {
    int count = 0;
    char *start = token_start(str);
    while (start) {
        count++;
        char *end = token_terminator(start);
        start = token_start(end);}
    return count;}

char *copy_str(char *inStr, short len) {
    if (inStr == 0 || len <= 0) return 0;
    char *copy = malloc(len + 1);
    if (copy == 0) return 0;
    for (short i = 0; i < len; i++) {
        copy[i] = inStr[i];}
    copy[len] = '\0';
    return copy;}

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

void print_tokens(char **tokens) {
    if (tokens == 0) return;
    for (int i = 0; tokens[i] != 0; i++) {
        puts(tokens[i]);}}

void free_tokens(char **tokens) {
    if (tokens == 0) return;
    for (int i = 0; tokens[i] != 0; i++) {
        free(tokens[i]);}
    free(tokens);}
