#include <stdio.h>
#include <stdlib.h>
#include "users.h"

int main()
{
    UserList user_list;
    init_list(&user_list);

    load_from_file(&user_list, "users.bin");

    int option;

    while (1)
    {
        printf("1. Add User\n2. List Users\n3. Exit\nChoose: ");
        if (scanf("%d", &option) != 1) {
            while (getchar() != '\n');
            printf("Invalid option, please enter a number: ");
            continue;
        }
        switch (option)
        {
        case 1:
            system("clear");
            add_user(&user_list);
            break;
        case 2:
            system("clear");
            list_users(&user_list);
            break;
        case 3:
            save_to_file(&user_list, "users.bin");
            free_list(&user_list);
            printf("Data saved. Exiting...\n");
            return 0;
        default:
            printf("Invalid option");
        }
    }
    return 0;
}