#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5

int main()
{
    char names[MAX_SUPPLIERS][100];
    char emails[MAX_SUPPLIERS][100];
    char phones[MAX_SUPPLIERS][30];
    char towns[MAX_SUPPLIERS][50];
    char line[100];
    char searchName[100];
    char summary[300];
    int count = 0;
    int choice = 0;
    int found;

    do
    {
        printf("\n================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        /* read the choice as text, then convert it */
        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            choice = 5;
        }
        else if (sscanf(line, "%d", &choice) != 1)
        {
            choice = 0;
        }

        switch (choice)
        {
            case 1:
                if (count >= MAX_SUPPLIERS)
                {
                    printf("Supplier list is full (maximum %d).\n", MAX_SUPPLIERS);
                }
                else
                {
                    printf("Enter supplier name: ");
                    fgets(names[count], sizeof(names[count]), stdin);
                    names[count][strcspn(names[count], "\n")] = '\0';

                    printf("Enter email: ");
                    fgets(emails[count], sizeof(emails[count]), stdin);
                    emails[count][strcspn(emails[count], "\n")] = '\0';

                    printf("Enter phone: ");
                    fgets(phones[count], sizeof(phones[count]), stdin);
                    phones[count][strcspn(phones[count], "\n")] = '\0';

                    printf("Enter town: ");
                    fgets(towns[count], sizeof(towns[count]), stdin);
                    towns[count][strcspn(towns[count], "\n")] = '\0';

                    count++;
                    printf("Supplier added.\n");
                }
                break;

            case 2:
                if (count == 0)
                {
                    printf("No suppliers have been added yet.\n");
                }
                else
                {
                    printf("\n--- SUPPLIER DETAILS ---\n");
                    for (int i = 0; i < count; i++)
                    {
                        printf("\nSupplier %d\n", i + 1);
                        printf("Name : %s\n", names[i]);
                        printf("Email: %s\n", emails[i]);
                        printf("Phone: %s\n", phones[i]);
                        printf("Town : %s\n", towns[i]);
                    }
                }
                break;

            case 3:
                printf("Enter supplier name to search: ");
                fgets(searchName, sizeof(searchName), stdin);
                searchName[strcspn(searchName, "\n")] = '\0';

                found = 0;
                for (int i = 0; i < count; i++)
                {
                    if (strcmp(names[i], searchName) == 0)
                    {
                        found = 1;
                        printf("Supplier found.\n");
                        printf("Name : %s\n", names[i]);
                        printf("Email: %s\n", emails[i]);
                        printf("Phone: %s\n", phones[i]);
                        printf("Town : %s\n", towns[i]);

                        /* build a sentence with strcpy() and strcat() */
                        strcpy(summary, names[i]);
                        strcat(summary, " operates in ");
                        strcat(summary, towns[i]);
                        strcat(summary, ".");
                        printf("%s\n", summary);
                        break;
                    }
                }
                if (!found)
                {
                    printf("Supplier not found.\n");
                }
                break;

            case 4:
                if (count == 0)
                {
                    printf("No suppliers have been added yet.\n");
                }
                else
                {
                    for (int i = 0; i < count; i++)
                    {
                        printf("Supplier %d name length: %zu\n", i + 1, strlen(names[i]));
                    }
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
