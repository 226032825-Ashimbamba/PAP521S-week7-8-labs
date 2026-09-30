#include <stdio.h>

/* function prototypes */
void displayWelcome();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
void displayMenu();
int searchEmployee(int id, int ids[], int size);

int main()
{
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int choice;
    float amount;
    float basic;
    float housing;
    float transport;
    float revenue;
    float expenses;
    float balance;
    int id;
    int position;

    displayWelcome();

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("VAT: %.2f\n", calculateVAT(amount));
                break;

            case 2:
                printf("Basic salary: ");
                scanf("%f", &basic);
                printf("Housing allowance: ");
                scanf("%f", &housing);
                printf("Transport allowance: ");
                scanf("%f", &transport);
                printf("Gross salary: %.2f\n",
                       calculateSalary(basic, housing, transport));
                break;

            case 3:
                printf("Enter revenue: ");
                scanf("%f", &revenue);
                printf("Enter expenses: ");
                scanf("%f", &expenses);
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

            case 4:
                printf("Enter employee ID: ");
                scanf("%d", &id);
                position = searchEmployee(id, employeeIDs, 5);
                if (position == -1)
                {
                    printf("Employee not found.\n");
                }
                else
                {
                    printf("Employee found at position %d.\n", position);
                }
                break;

            case 5:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

/* LAB TASK 1 */
void displayWelcome()
{
    printf("Welcome to the Municipal Financial Management System\n");
}

/* LAB TASK 2: VAT at 15% */
float calculateVAT(float amount)
{
    return amount * 0.15;
}

/* LAB TASK 3: gross salary */
float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

/* LAB TASK 4: revenue minus expenses */
float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

/* LAB TASK 5: menu */
void displayMenu()
{
    printf("\n");
    printf("==================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

/* LAB TASK 6: returns the position, or -1 if not found */
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
