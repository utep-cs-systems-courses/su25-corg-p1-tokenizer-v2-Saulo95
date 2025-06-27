#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

#define MaxSize 100

int main() {
    char input[MaxSize];
    List *history = init_history();

    printf("Type text to tokenize.\n");
    printf("Use '!n', history, exit as options\n");

 start:
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) goto end;;
	
        char *end = strchr(input, '\n');
        if (end) *end = '\0';
        if (strcmp(input, "exit") == 0) goto end;
        if (strcmp(input, "history") == 0) {
            print_history(history);
            goto start;}

        if (input[0] == '!' && input[1] != '\0') {
            int id = atoi(&input[1]);
            char *previous = get_history(history, id);
            if (previous) {
                printf("You recalled%d: %s\n", id, previous);
                char **tokens = tokenize(previous);
                if (tokens) {
                    print_tokens(tokens);
                    free_tokens(tokens);
                }
            } else {
                printf("Error!! No history for:!%d\n", id);}
            goto start; }
        add_history(history, input);
        char **tokens = tokenize(input);
        if (tokens) {
            print_tokens(tokens);
            free_tokens(tokens); }
	goto start;
 end:

    free_history(history);
    return 0;}
