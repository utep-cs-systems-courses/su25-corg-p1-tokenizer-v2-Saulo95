#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

// Initialize history list
List* init_history() {
    List *list = malloc(sizeof(List));
    if (list) list->root = NULL;
    return list;}


void add_history(List *list, char *str) {
    if (!list || !str) return;
    Item *new_item = malloc(sizeof(Item));//Allocates memory for an item
    if (!new_item) return;
    new_item->str = malloc(strlen(str) + 1);//allocates memeory for input string plus terminator
    if (!new_item->str) {
        free(new_item);
        return;}
    strcpy(new_item->str, str);
    new_item->next = NULL;

    int next_id = 1;
    Item *current = list->root;
    if (!current) {
        list->root = new_item;
    } else {
        while (current->next) {
            current = current->next;}
        next_id = current->id + 1;
        current->next = new_item;}
    new_item->id = next_id;}


char *get_history(List *list, int id) {
    if (!list) return 0;
    Item *current = list->root;
    while (current) {
        if (current->id == id) {
            return current->str;}
        current = current->next;}
    return 0;}

void print_history(List *list) {
    if (!list) return;
    Item *current = list->root;
    while (current) {
        printf("%d: %s\n", current->id, current->str);
        current = current->next;}}


void free_history(List *list) {
    if (!list) return;
    Item *current = list->root;
    while (current) {
        Item *next = current->next;
        free(current->str);
        free(current);
        current = next;}
    free(list);}
