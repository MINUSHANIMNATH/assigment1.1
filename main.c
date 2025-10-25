#include <stdio.h>
#include <string.h>

#define MAX_CITY 30
#define MAX_LEN 50

//GLOBAL VARIABLE ADD
char cityList[MAX_CITY][MAX_LEN];
int cityTotal=0;
int route[MAX_CITY][MAX_LEN];




//function declarations--
void addNewCity();
void showCities();
void editCityName();
void deleteCity();
void setRouteDistance();
void printRouteChart();
void cityMenu();
void routeMenu();
void initializeVehicles();
void vehicleMenu();


// --- Add City ---
void addNewCity() {
    if (cityTotal >= MAX_CITY) {
        printf("City limit is over\n");
        return;
    }

    char tempName[MAX_LEN];
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

// Show City List ---
void showCities() {
    if (cityTotal == 0) {
        printf("No cities have been added yet.\n");
        return;
    }
    printf("\n-- City Directory --\n");
    for (int i = 0; i < cityTotal; i++) {
        printf("%d. %s\n", i, cityList[i]);
    }
}

// --- Edit City Name ---
void editCityName() {
    if (cityTotal == 0) {
        printf("cities are not rename.\n");
        return;
    }

    showCities();
    int id;
    char newName[MAX_LEN];
    printf("cities are selected rename: ");
    scanf("%d", &id);

    if (id < 0 || id >= cityTotal) {
        printf("wrong index!\n");
        return;
    }

    printf("Enter new name: ");
    scanf("%s", newName);
    strcpy(cityList[id], newName);
    printf("City name is successfully done.\n");
}

//delete city...
void deleteCity(){
 if (cityTotal==0){
    printf("no cities to delete.");
    return;
 }

  showCities();
    int id;
    printf("Select delete city number: ");
    scanf("%d", &id);

    if (id < 0 || id >= cityTotal) {
        printf("wrong city number!\n");
        return;
    }

    for (int i = id; i < cityTotal - 1; i++) {
        strcpy(cityList[i], cityList[i + 1]);
    }
    cityTotal--;
    printf("City removed successfully done.\n");
}
//set distance menu...
void setRouteDistance(){
  if (cityTotal<2){
  printf("at minimum one cities required.\n");
  return;}

  showCities();
  int A,B,E;
  printf("ENTER FIRST CITY NUMBER ADD:");
  scanf("%d",&A);
  printf("ENTER SECOND CITY NUMBER ADD:");
  scanf("%d",&B);

  if(A<0|| A>=cityTotal ||B<0|| B>=cityTotal||A==B){
    printf("WRONG SELECTION!\n");
    return;
  }

  printf("enter distance (in km):");
  scanf("%d",&E);

  route[A][B]=E;
  route[B][A]=E;
  printf("DISTANCE BETWEEN %s AND %s SET TO %d km.\n",cityList[A],cityList[B],E);

}
//show distance chart...
void printRouteChart(){
if (cityTotal==0){
    printf("do not cities .\n");
    return;

}
printf("\n* Distance Chart(km)*\n");
for (int i=0;i<cityTotal;i++){
    printf("%-10s",cityList[i]);

}
printf("\n");

  for (int i = 0; i < cityTotal; i++) {
        printf("%-10s", cityList[i]);
        for (int j = 0; j < cityTotal; j++) {
            printf("%-10d", route[i][j]);
        }
        printf("\n");
  }

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

//2.route Management ...
void routeMenu() {
    int option;
    do {
        printf("\n** Route Management **\n");
        printf("1. Set Distance\n");
        printf("2. View Distance chart\n");
        printf("3. Back\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: setRouteDistance();
             break;
            case 2: printRouteChart();
             break;
            case 3: break;
            default: printf("Invalid option!\n");
        }
    } while (option != 3);
}
//--function to add default vehicle--
void initializeVehicles();{
// Default vehicle data
    strcpy(vehicleList[0].type, "Van");
    vehicleList[0].capacity = 1000;
    vehicleList[0].ratePerKm = 30.0;
    vehicleList[0].speed = 60.0;
    vehicleList[0].fuelEfficiency = 12.0;

    strcpy(vehicleList[1].type, "Truck");
    vehicleList[1].capacity = 5000;
    vehicleList[1].ratePerKm = 40.0;
    vehicleList[1].speed = 50.0;
    vehicleList[1].fuelEfficiency = 6.0;

    strcpy(vehicleList[2].type, "Lorry");
    vehicleList[2].capacity = 10000;
    vehicleList[2].ratePerKm = 80.0;
    vehicleList[2].speed = 45.0;
    vehicleList[2].fuelEfficiency = 4.0;

    vehicleCount = 3;
    printf("Default vehicles initialized successfully!"\n");
}



//3.vehicle Menu...
vehicleMenu(){
int choice;
do {
        printf("\n** Vehicle Management **\n");
        printf("1. Load Default Vehicles\n");
        printf("2. View Vehicle List\n");
        printf("3. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

     switch (option){

       case1:initializeVehicles();
       break;
       case2:displayVehicle();
       break:
       case3:back;
       default:printf("wrong choice!\n");
     }

     while(option!=3);
     }
   }



}

// *** Main Program ***
int main() {
    int choice;
    do {
        printf("\n*** Logistics System ***\n");
        printf("1. City Management\n");
        printf("2. Route Management\n");
        printf("3.vehicle Management\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: cityMenu();
             break;
            case 2: routeMenu();
             break;
             case 3:vehicleMenu();
             break;
            case 4: printf("Exit program.\n");
             break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);


    return 0;
}
