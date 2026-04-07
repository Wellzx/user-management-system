#include "users.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

void init_list(UserList *list){
    list->count = 0;
    list->capacity = 2;
    list->data = malloc(list->capacity * sizeof(User));

    if (list->data == NULL){
        exit(1);
    }
}

void add_user(UserList *list) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    if (list->count == list->capacity){
        int new_capacity = list->capacity * 2;
        User *temp_user = realloc(list->data, new_capacity * sizeof(User));

        if (temp_user == NULL){
            printf("Error: Failed to reallocate memory.\n");
            return;
        }
        list->data = temp_user;
        list->capacity = new_capacity;

        if (DEBUG) printf("[DEBUG] Memory expanded to %d\n", new_capacity);
    }

    User *user = &list->data[list->count];

    printf("Enter name: ");
    fgets(user->name, sizeof(user->name), stdin);

    user->name[strcspn(user->name, "\n")] = 0;

    printf("Enter email: ");
    fgets(user->email, sizeof(user->email), stdin);

    user->email[strcspn(user->email, "\n")] = 0;

    printf("Enter age: ");
    scanf("%d", &user->age);

    list->count++;

    printf("\n✅ User '%s' added successfully!\n", user->name);
}

void list_users(const UserList *list) {
    if (list->count == 0) {
        printf("\n[!] No users registered yet.\n");
        return;
    }
    printf("\n+-----+----------------------+---------------------------+-----+\n");
    printf("| %-3s | %-20s | %-25s | %-3s |\n", "ID", "NAME", "EMAIL", "AGE");
    printf("+-----+----------------------+---------------------------+-----+\n");

    for (int i = 0; i < list->count; i++) {
        printf("| %-3d | %-20s | %-25s | %-3d |\n", 
               i + 1, 
               list->data[i].name, 
               list->data[i].email, 
               list->data[i].age);
    }
    printf("+-----+----------------------+---------------------------+-----+\n");
    printf("Total: %d users.\n", list->count);
}

void free_list(UserList *list){
    if (list->data != NULL){
        free(list->data);
        list->data = NULL;
    }
    list->count = 0;
    list->capacity = 0;
    // Memory cleaned up here
}

void save_to_file(const UserList *list, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL){
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(&list->count, sizeof(int), 1, file);
    fwrite(list->data, sizeof(User), list->count, file);
}

void load_from_file(UserList *list, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL){
        printf("File does not exist.\n");
        return;
    }
    int saved_count;
    fread(&saved_count, sizeof(int), 1, file);

    list->data = realloc(list->data, saved_count * sizeof(User));
    list->count = saved_count;
    list->capacity = saved_count;

    fread(list->data, sizeof(User), saved_count, file);

    fclose(file);
    if (DEBUG) printf("Successfully loaded %d users from disk!\n", saved_count);
}