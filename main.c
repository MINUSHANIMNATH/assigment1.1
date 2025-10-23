#include <stdio.h>
#include <stdlib.h>

//void cityMenu();
//void routeMenu();



// *** Main Program ***
int main() {
    int choice;
    do {
        printf("\n*** Logistics System ***\n");
        printf("1. City Management\n");
        printf("2. Route Management\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: //cityMenu();
             break;
            case 2: //routeMenu();
             break;
            case 3: printf("Exit program.\n");
             break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
