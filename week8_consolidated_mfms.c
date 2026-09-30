#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 10

/* supplier data is stored globally so the supplier functions can share it */
char supplierNames[MAX_SUPPLIERS][100];
char supplierEmails[MAX_SUPPLIERS][100];
char supplierPhones[MAX_SUPPLIERS][30];
char supplierTowns[MAX_SUPPLIERS][50];
int supplierCount = 0;

/* input helpers */
void readLine(char text[], int size);
int readInt();
float readFloat();

/* supplier functions */
void addSupplier();
void displaySupplier();
void searchSupplier();

/* financial functions */
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);
void displayMenu();

int main()
{
    int choice;
    float amount;
    float basic;
    float housing;
    float transport;
    float revenue;
    float expenses;
    float balance;

    do
    {
        displayMenu();
        choice = readInt();

        switch (choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySupplier();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                printf("Enter amount: ");
                amount = readFloat();
                printf("VAT: %.2f\n", calculateVAT(amount));
                break;

            case 5:
                printf("Basic salary: ");
                basic = readFloat();
                printf("Housing allowance: ");
                housing = readFloat();
                printf("Transport allowance: ");
                transport = readFloat();
                printf("Gross salary: %.2f\n",
                       calculateSalary(basic, housing, transport));
                break;

            case 6:
                printf("Enter revenue: ");
                revenue = readFloat();
                printf("Enter expenses: ");
                expenses = readFloat();
                balance = calculateBudget(revenue, expenses);
                printf("Budget balance: %.2f\n", balance);
                if (balance > 0)
                {
                    printf("SURPLUS\n");
                }
                else if (balance < 0)
                {
                    printf("DEFICIT\n");
                }
                else
                {
                    printf("BALANCED\n");
                }
                break;

            case 7:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}

void displayMenu()
{
    printf("\n");
    printf("========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Calculate VAT\n");
    printf("5. Calculate Salary\n");
    printf("6. Calculate Budget\n");
    printf("7. Exit\n");
    printf("Enter choice: ");
}

/* reads one line and removes the newline left by fgets() */
void readLine(char text[], int size)
{
    text[0] = '\0';
    if (fgets(text, size, stdin) != NULL)
    {
        text[strcspn(text, "\n")] = '\0';
    }
}

int readInt()
{
    char line[50];
    int value;

    readLine(line, sizeof(line));
    if (sscanf(line, "%d", &value) != 1)
    {
        return 0;
    }
    return value;
}

float readFloat()
{
    char line[50];
    float value;

    readLine(line, sizeof(line));
    if (sscanf(line, "%f", &value) != 1)
    {
        return 0;
    }
    return value;
}

void addSupplier()
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full.\n");
        return;
    }

    printf("Enter supplier name: ");
    readLine(supplierNames[supplierCount], sizeof(supplierNames[supplierCount]));
    printf("Enter email: ");
    readLine(supplierEmails[supplierCount], sizeof(supplierEmails[supplierCount]));
    printf("Enter phone: ");
    readLine(supplierPhones[supplierCount], sizeof(supplierPhones[supplierCount]));
    printf("Enter town: ");
    readLine(supplierTowns[supplierCount], sizeof(supplierTowns[supplierCount]));

    supplierCount++;
    printf("Supplier added.\n");
}

void displaySupplier()
{
    if (supplierCount == 0)
    {
        printf("No suppliers have been added yet.\n");
        return;
    }

    printf("\n--- SUPPLIER DETAILS ---\n");
    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Name : %s\n", supplierNames[i]);
        printf("Email: %s\n", supplierEmails[i]);
        printf("Phone: %s\n", supplierPhones[i]);
        printf("Town : %s\n", supplierTowns[i]);
    }
}

void searchSupplier()
{
    char searchName[100];

    printf("Enter supplier name to search: ");
    readLine(searchName, sizeof(searchName));

    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(supplierNames[i], searchName) == 0)
        {
            printf("Supplier found.\n");
            printf("Name : %s\n", supplierNames[i]);
            printf("Email: %s\n", supplierEmails[i]);
            printf("Phone: %s\n", supplierPhones[i]);
            printf("Town : %s\n", supplierTowns[i]);
            return;
        }
    }
    printf("Supplier not found.\n");
}

/* VAT at 15% */
float calculateVAT(float amount)
{
    return amount * 0.15;
}

/* gross salary */
float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

/* revenue minus expenses: positive = surplus, negative = deficit */
float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

/* returns the position of the ID, or -1 if not found */
int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }
    return -1;
}
