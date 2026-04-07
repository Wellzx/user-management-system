#ifndef USERS_H
#define USERS_H

typedef struct {
    int id;
    char name[50];
    char email[50];
    int age;
} User;

typedef struct {
    User *data;
    int count;
    int capacity;
} UserList;

void init_list(UserList *list);
void add_user(UserList *list);
void list_users(const UserList *list);
void save_to_file(const UserList *list, const char *filename);
void load_from_file(UserList *list, const char *filename);
void free_list(UserList *list);

#endif