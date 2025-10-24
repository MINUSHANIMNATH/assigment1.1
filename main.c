#include <stdio.h>
#include <stdlib.h>

#define MAXI CITY 30
#define MAXI LEN 40

//GLOBAL VARIABLE ADD
char cityList[MAXI CITY][MAXI LEN];
int cityTotal=0;





//function declarations--
void addNewCity();
void showCities();
void editCityName();
void deleteCity();
void cityMenu();
void routeMenu();

// --- Add City ---
void addNewCity() {
    if (cityTotal >= MAXI_CITY) {
        printf("City limit is over\n");
        return;
    }

    char tempName[MAXI_LEN];
    printf("Enter new city name: ");
    scanf("%s", tempName);

    // Check for duplicates
    for (int i = 0; i < cityTotal; i++) {
        if (strcmp(tempName, cityList[i]) == 0) {
            printf("This city already exists!\n");
            return;
        }
    }

    strcpy(cityList[cityTotal], tempName);
    cityTotal++;
    printf("City '%s' successfully added!\n", tempName);
}







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
