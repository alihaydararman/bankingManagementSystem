#include <stdio.h>
#include <string.h>
#include "login.h"

#define USERNAME "alihaydar"
#define PASSWORD "1661"

int login() {
    char username[50], password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
        printf("Login successful!\n");
        return 1;
    } else {
        printf("Invalid username or password.\n");
        return 0;
    }
}

