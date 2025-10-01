#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ANIMALS 200

struct Animal
{
    int id;
    char nom[50];
    char espece[30];
    int age;
    char habitat[20];
    float poids;
};

struct Animal animals[MAX_ANIMALS];
int counter = 0;
int nextId = 1;


// ***************************** main menu ***********************************

void menu()
{
    int choice;
    do
    {
        printf("\n========== ZOO MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Animal\n");
        printf("2. Display Animals\n");
        printf("3. Modify Animal\n");
        printf("4. Delete Animal\n");
        printf("5. Search Animal\n");
        printf("6. Statistics\n");
        printf("0. Exit\n");
        printf("===========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            submenuAdd();
            break;
        case 2:
            submenuDisplay();
            break;
        case 3:
            submenuModify();
            break;
        case 4:

            deleteAnimal();
            break;
        case 5:
            submenuSearch();
            break;
        case 6:

            showStats();
            break;
        case 0:
            printf("Exiting program... Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

// ***************************** sous menu ajout ***********************************
    void submenuAdd()
    {
        int choice;
        printf("\n--- ADD ANIMAL ---\n");
        printf("1. Add one animal\n");
        printf("2. Add multiple animals\n");
        printf("0. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            ajouterAnimal();
            break;
        case 2:
            ajouterPlusieursAnimaux();
            break;
        case 0:
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    // ***************************** sous menu affichage ***********************************

    void submenuDisplay()
    {
        int choice;
        printf("\n--- DISPLAY ANIMALS ---\n");
        printf("1. Show all animals\n");
        printf("2. Show animals sorted by name\n");
        printf("3. Show animals sorted by age\n");
        printf("4. Show animals by habitat\n");
        printf("0. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            afficherAnimaux();
            break;
        case 2:
            afficherAnimauxTriesParNom();
            break;
        case 3:
            afficherAnimauxTriesParAge();
            break;
        case 4:
            afficherAnimauxParHabitat();
            break;
        case 0:
            break;
        default:
            printf("Invalid choice!\n");
        }
    }

 // ***************************** sous menu update ***********************************

    void submenuModify()
    {
        int choice, id;
        printf("\n--- MODIFY ANIMAL ---\n");
        printf("1. Modify habitat\n");
        printf("2. Modify age\n");
        printf("0. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2)
        {
            printf("Enter animal ID: ");
            scanf("%d", &id);
        }

        switch (choice)
        {
        case 1:
            modifierHabitat(id);
            break;
        case 2:
            modifierAge(id);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice!\n");
        }
    }

    // ***************************** sous menu search ***********************************

    void submenuSearch()
    {
        int choice, id;
        char name[50], species[30];

        printf("\n--- SEARCH ANIMAL ---\n");
        printf("1. Search by ID\n");
        printf("2. Search by name\n");
        printf("3. Search by species\n");
        printf("0. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter ID: ");
            scanf("%d", &id);
            rechercherParId(id);
            break;
        case 2:
            printf("Enter name: ");
            scanf("%s", name);
            rechercherParNom(name);
            break;
        case 3:
            printf("Enter species: ");
            scanf("%s", species);
            rechercherParEspece(species);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice!\n");
        }
    }

    void addAnimal();

    void addMany();

    void showAnimals();

    void showAnimalsSortedByName();

    void showAnimalsByHabitat();

    // update
    void updateHabitat(int id);
    void updateAge(int id);

    // delete
    void deleteAnimal(int id);

    // search
    void searchById(int id);
    void searchById(const char *nom);
    void searchByEspece(const char *espece);

    // stats

    void showStats();
   

    int main()
    {
        menu();
        return 0;
    }