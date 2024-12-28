#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void saveAccounts();
void loadAccounts();

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }

    Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);

    printf("Enter account holder name: ");
    scanf("%s", newAccount.name);

    newAccount.balance = 0.0;
    accounts[accountCount++] = newAccount;

    saveAccounts();
    printf("Account created successfully!\n");
}

void viewAccount() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void depositMoney() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;

            saveAccounts();
            printf("Deposit successful! New Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdrawMoney() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount > accounts[i].balance) {
                printf("Insufficient balance.\n");
                return;
            }
            accounts[i].balance -= amount;

            saveAccounts();
            printf("Withdrawal successful! New Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void saveAccounts() {
    FILE *file = fopen("accounts.dat", "wb");
    if (!file) {
        printf("Error saving accounts.\n");
        return;
    }
    fwrite(&accountCount, sizeof(int), 1, file);
    fwrite(accounts, sizeof(Account), accountCount, file);
    fclose(file);
}

void loadAccounts() {
    FILE *file = fopen("accounts.dat", "rb");
    if (!file) {
        return;
    }
    fread(&accountCount, sizeof(int), 1, file);
    fread(accounts, sizeof(Account), accountCount, file);
    fclose(file);
}

