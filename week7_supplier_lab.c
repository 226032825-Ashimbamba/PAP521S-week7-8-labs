#include <stdio.h>
#include <string.h>

int main()
{
    char supplierName[100];
    char email[100];
    char phone[30];
    char town[50];
    char backup[100];
    char searchName[100];
    char description[300];
    char supplier1[] = "ABC Office Supplies";
    char supplier2[] = "Namibia Stationery";

    /* LAB TASK 1: Basic supplier details */
    printf("Enter supplier name: ");
    fgets(supplierName, sizeof(supplierName), stdin);
    supplierName[strcspn(supplierName, "\n")] = '\0';   /* remove newline */

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s\n", supplierName);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town : %s\n", town);

    /* LAB TASK 2: String length */
    printf("\nSupplier name length: %zu\n", strlen(supplierName));
    printf("Email length: %zu\n", strlen(email));
    printf("Town length: %zu\n", strlen(town));

    /* LAB TASK 3: Supplier search using strcmp() */
    printf("\nEnter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(searchName, supplier1) == 0 || strcmp(searchName, supplier2) == 0)
    {
        printf("Supplier found.\n");
    }
    else
    {
        printf("Supplier not found.\n");
    }

    /* LAB TASK 4: Copy the supplier name using strcpy() */
    strcpy(backup, supplierName);
    printf("\nOriginal: %s\n", supplierName);
    printf("Backup  : %s\n", backup);

    /* LAB TASK 5: Build a sentence using strcpy() and strcat() */
    strcpy(description, supplierName);
    strcat(description, " operates in ");
    strcat(description, town);
    strcat(description, ".");
    printf("\n%s\n", description);

    return 0;
}
