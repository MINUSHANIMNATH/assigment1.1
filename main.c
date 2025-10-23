#include <stdio.h>
#include <stdlib.h>

void addNewCity();
void showCities();
void editCityName();
void deleteCity();
void cityMenu();
void routeMenu();

// --- City Management Menu ---
void cityMenu() {
    int option;
    do {
        printf("\n--- City Management ---\n");
        printf("1. Add new City\n");
        printf("2. show Cities\n");
        printf("3. Edit City name\n");
        printf("4. delete City\n");
        printf("5.back\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: addNewCity();
             break;
            case 2: showCities();
             break;
            case 3: editCityName();
             break;
            case 4: deleteCity();
             break;
            case 5: break;
            default: printf("Invalid option!\n");
        }
    } while (option != 5);
}


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
            case 1: cityMenu();
             break;
            case 2: routeMenu();
             break;
            case 3: printf("Exit program.\n");
             break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 3);


    return 0;
}
