#include <stdio.h>
#include <stdlib.h>
#include "login.h"
#include "account.h"

void menu();

int main() {
    if (login()) {
        menu();
    } else {
        printf("Login failed. Exiting...\n");
    }
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\nBanking Management System\n");
        printf("1. Create Account\n");
        printf("2. View Account\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
}
