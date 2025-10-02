#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

void submenuAdd();
void submenuDisplay();
void submenuModify();
void submenuSearch();
void addAnimal();
void addMany();
void showAnimals();
void showAnimalsSortedByName();
void animalsSortedByAge();
void showAnimalsByHabitat();
void updateHabitat(int id);
void updateAge();
void deleteAnimal();
int searchByName(char name[]);
void displayAnimalByName();
void searchByEspece();
void showStats();
void searchById();
int readInt(char *prompt);
void readString(char *prompt, char *output, int maxLength);
void toLowerCase(char *str);

int readInt(char *prompt)
{
    char input[100];
    int value;
    int valid = 0;

    while (!valid)
    {
        printf("%s", prompt);
        scanf("%s", input);

        valid = 1;
        for (int i = 0; input[i]; i++)
        {
            if (input[i] < '0' || input[i] > '9')
            {
                valid = 0;
                break;
            }
        }

        if (valid)
            value = atoi(input);
        else
            printf("Invalid input! Enter numbers only.\n");
    }
    return value;
}

void readString(char *prompt, char *output, int maxLength)
{
    int valid = 0;
    while (!valid)
    {
        printf("%s", prompt);
        scanf("%s", output);

        valid = 1;
        for (int i = 0; output[i]; i++)
        {
            if (!((output[i] >= 'a' && output[i] <= 'z') || (output[i] >= 'A' && output[i] <= 'Z')))
            {
                valid = 0;
                break;
            }
        }
        if (valid && strlen(output) > maxLength)
            valid = 0;

        if (!valid)
            printf("Invalid input! Enter letters only.\n");
    }
}

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
        choice = readInt("Enter your choice: ");

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

void submenuAdd()
{
    int choice;
    printf("\n--- ADD ANIMAL ---\n");
    printf("1. Add one animal\n");
    printf("2. Add multiple animals\n");
    printf("0. Back to main menu\n");
    choice = readInt("Enter your choice: ");

    switch (choice)
    {
    case 1:
        addAnimal();
        break;
    case 2:
        addMany();
        break;
    case 0:
        break;
    default:
        printf("Invalid choice!\n");
    }
}

void submenuDisplay()
{
    int choice;
    printf("\n--- DISPLAY ANIMALS ---\n");
    printf("1. Show all animals\n");
    printf("2. Show animals sorted by name\n");
    printf("3. Show animals sorted by age\n");
    printf("4. Show animals by habitat\n");
    printf("0. Back to main menu\n");
    choice = readInt("Enter your choice: ");

    switch (choice)
    {
    case 1:
        showAnimals();
        break;
    case 2:
        showAnimalsSortedByName();
        break;
    case 3:
        animalsSortedByAge();
        break;
    case 4:
        showAnimalsByHabitat();
        break;
    case 0:
        break;
    default:
        printf("Invalid choice!\n");
    }
}

void submenuModify()
{
    int choice, id;
    printf("\n--- MODIFY ANIMAL ---\n");
    printf("1. Modify habitat\n");
    printf("2. Modify age\n");
    printf("0. Back to main menu\n");
    choice = readInt("Enter your choice: ");

    if (choice == 1 || choice == 2)
        id = readInt("Enter animal ID: ");

    switch (choice)
    {
    case 1:
        updateHabitat(id);
        break;
    case 2:
        updateAge();
        break;
    case 0:
        break;
    default:
        printf("Invalid choice!\n");
    }
}

void submenuSearch()
{
    int choice;
    printf("\n--- SEARCH ANIMAL ---\n");
    printf("1. Search by ID\n");
    printf("2. Search by name\n");
    printf("3. Search by species\n");
    printf("0. Back to main menu\n");
    choice = readInt("Enter your choice: ");

    switch (choice)
    {
    case 1:
        searchById();
        break;
    case 2:
        displayAnimalByName();
        break;
    case 3:
        searchByEspece();
        break;
    case 0:
        break;
    default:
        printf("Invalid choice!\n");
    }
}

void addAnimal()
{
    if (counter >= MAX_ANIMALS)
    {
        printf("Zoo is full!\n");
        return;
    }

    struct Animal a;
    a.id = nextId++;

    readString("Enter name: ", a.nom, 49);
    readString("Enter species: ", a.espece, 29);
    a.age = readInt("Enter age (years): ");
    readString("Enter habitat: ", a.habitat, 19);
    a.poids = readInt("Enter weight (kg, 0 if unknown): ");

    animals[counter++] = a;

    printf("Animal added successfully!\n");
}

void addMany()
{
    int n = readInt("Enter how many animals you want to add: ");
    for (int i = 0; i < n; i++)
    {
        printf("\nAdding animal %d\n", i + 1);
        addAnimal();
    }
}

void showAnimals()
{
    if (counter == 0)
    {
        printf("No animals found.\n");
        return;
    }

    for (int i = 0; i < counter; i++)
    {
        printf("\n--- Animal ID: %d ---\n", animals[i].id);
        printf("Name    : %s\n", animals[i].nom);
        printf("Species : %s\n", animals[i].espece);
        printf("Age     : %d years\n", animals[i].age);
        printf("Habitat : %s\n", animals[i].habitat);
        if (animals[i].poids > 0)
            printf("Weight  : %.2f kg\n", animals[i].poids);
        else
            printf("Weight  : Unknown\n");
    }
}

void showAnimalsSortedByName()
{
    if (counter == 0)
    {
        printf("No animals found.\n");
        return;
    }

    for (int i = 0; i < counter - 1; i++)
    {
        for (int j = 0; j < counter - i - 1; j++)
        {
            if (strcasecmp(animals[j].nom, animals[j + 1].nom) > 0)
            {
                struct Animal temp = animals[j];
                animals[j] = animals[j + 1];
                animals[j + 1] = temp;
            }
        }
    }

    showAnimals();
}

void animalsSortedByAge()
{
    if (counter == 0)
    {
        printf("No animals found.\n");
        return;
    }

    for (int i = 0; i < counter - 1; i++)
    {
        for (int j = 0; j < counter - i - 1; j++)
        {
            if (animals[j].age > animals[j + 1].age)
            {
                struct Animal temp = animals[j];
                animals[j] = animals[j + 1];
                animals[j + 1] = temp;
            }
        }
    }

    showAnimals();
}

void toLowerCase(char *str)
{
    for (int i = 0; str[i]; i++)
        str[i] = tolower((unsigned char)str[i]);
}

void showAnimalsByHabitat()
{
    char habitat[50];
    int found = 0;
    readString("Enter habitat name: ", habitat, 49);
    toLowerCase(habitat);

    for (int i = 0; i < counter; i++)
    {
        char animalHabitat[50];
        strcpy(animalHabitat, animals[i].habitat);
        toLowerCase(animalHabitat);

        if (strcmp(animalHabitat, habitat) == 0)
        {
            printf("\n--- Animal ID: %d ---\n", animals[i].id);
            printf("Name    : %s\n", animals[i].nom);
            printf("Species : %s\n", animals[i].espece);
            printf("Age     : %d years\n", animals[i].age);
            printf("Habitat : %s\n", animals[i].habitat);
            if (animals[i].poids > 0)
                printf("Weight  : %.2f kg\n", animals[i].poids);
            else
                printf("Weight  : Unknown\n");
            found = 1;
        }
    }
    if (!found)
        printf("No animals found in %s.\n", habitat);
}

void updateHabitat(int id)
{
    char name[50];
    readString("Enter the name of the animal: ", name, 49);

    int search = searchByName(name);
    if (search == -1)
    {
        printf("No animal found with this name\n");
        return;
    }

    readString("Enter the new habitat: ", animals[search].habitat, 19);
    printf("Habitat updated successfully!\n");
}

void updateAge()
{
    char name[50];
    readString("Enter the name of the animal: ", name, 49);

    int search = searchByName(name);
    if (search == -1)
    {
        printf("No animal found with this name\n");
        return;
    }

    animals[search].age = readInt("Enter the new age: ");
    printf("Age updated successfully!\n");
}

void deleteAnimal()
{
    int id = readInt("Enter animal ID to delete: ");
    int index = -1;

    for (int i = 0; i < counter; i++)
        if (animals[i].id == id)
        {
            index = i;
            break;
        }

    if (index == -1)
    {
        printf("Animal with ID %d not found!\n", id);
        return;
    }

    for (int i = index; i < counter - 1; i++)
        animals[i] = animals[i + 1];

    counter--;
    nextId = counter + 1;

    printf("Animal deleted successfully!\n");
}

void searchById()
{
    int userId = readInt("Enter the ID of the animal: ");
    int found = 0;

    for (int i = 0; i < counter; i++)
    {
        if (animals[i].id == userId)
        {
            printf("\n--- Animal ID: %d ---\n", animals[i].id);
            printf("Name    : %s\n", animals[i].nom);
            printf("Species : %s\n", animals[i].espece);
            printf("Age     : %d years\n", animals[i].age);
            printf("Habitat : %s\n", animals[i].habitat);
            if (animals[i].poids > 0)
                printf("Weight  : %.2f kg\n", animals[i].poids);
            else
                printf("Weight  : Unknown\n");
            found = 1;
            break;
        }
    }
    if (!found)
        printf("No animal stored with this ID\n");
}

int searchByName(char name[])
{
    toLowerCase(name);
    for (int i = 0; i < counter; i++)
    {
        char animalName[50];
        strcpy(animalName, animals[i].nom);
        toLowerCase(animalName);
        if (strcmp(animalName, name) == 0)
            return i;
    }
    return -1;
}

void displayAnimalByName()
{
    char name[50];
    readString("Enter the name: ", name, 49);

    int search = searchByName(name);
    if (search == -1)
    {
        printf("No animal found with this name\n");
        return;
    }

    printf("\n--- Animal ID: %d ---\n", animals[search].id);
    printf("Name    : %s\n", animals[search].nom);
    printf("Species : %s\n", animals[search].espece);
    printf("Age     : %d years\n", animals[search].age);
    printf("Habitat : %s\n", animals[search].habitat);
    if (animals[search].poids > 0)
        printf("Weight  : %.2f kg\n", animals[search].poids);
    else
        printf("Weight  : Unknown\n");
}

void searchByEspece()
{
    char espece[50];
    readString("Enter species: ", espece, 49);
    toLowerCase(espece);
    int found = 0;

    for (int i = 0; i < counter; i++)
    {
        char animalEspece[50];
        strcpy(animalEspece, animals[i].espece);
        toLowerCase(animalEspece);

        if (strcmp(animalEspece, espece) == 0)
        {
            printf("\n--- Animal ID: %d ---\n", animals[i].id);
            printf("Name    : %s\n", animals[i].nom);
            printf("Species : %s\n", animals[i].espece);
            printf("Age     : %d years\n", animals[i].age);
            printf("Habitat : %s\n", animals[i].habitat);
            if (animals[i].poids > 0)
                printf("Weight  : %.2f kg\n", animals[i].poids);
            else
                printf("Weight  : Unknown\n");
            found = 1;
        }
    }

    if (!found)
        printf("No animals stored with this species\n");
}

void showStats()
{
    if (counter == 0)
    {
        printf("No animals in the zoo.\n");
        return;
    }

    printf("Total animals: %d\n", counter);

    int sum = 0, maxAge = animals[0].age, minAge = animals[0].age;
    for (int i = 0; i < counter; i++)
    {
        sum += animals[i].age;
        if (animals[i].age > maxAge)
            maxAge = animals[i].age;
        if (animals[i].age < minAge)
            minAge = animals[i].age;
    }

    printf("Average age: %.2f\n", (float)sum / counter);
    printf("Oldest animal(s):\n");
    for (int i = 0; i < counter; i++)
        if (animals[i].age == maxAge)
            printf("- %s (%s), %d years\n", animals[i].nom, animals[i].espece, animals[i].age);

    printf("Youngest animal(s):\n");
    for (int i = 0; i < counter; i++)
        if (animals[i].age == minAge)
            printf("- %s (%s), %d years\n", animals[i].nom, animals[i].espece, animals[i].age);

    char mostSpecie[50] = "";
    int maxCount = 0;
    for (int i = 0; i < counter; i++)
    {
        int count = 1;
        for (int j = i + 1; j < counter; j++)
            if (strcmp(animals[i].espece, animals[j].espece) == 0)
                count++;
        if (count > maxCount)
        {
            maxCount = count;
            strcpy(mostSpecie, animals[i].espece);
        }
    }
    printf("Most represented species: %s (%d animals)\n", mostSpecie, maxCount);
}

void seedData()
{
    animals[0] = (struct Animal){1, "Leo", "Lion", 5, "Savannah", 190.5};
    animals[1] = (struct Animal){2, "Molly", "Elephant", 10, "Forest", 540.0};
    animals[2] = (struct Animal){3, "Zara", "Zebra", 3, "Savannah", 120.2};
    animals[3] = (struct Animal){4, "Tina", "Tiger", 7, "Jungle", 220.0};
    animals[4] = (struct Animal){5, "Oscar", "Owl", 2, "Forest", 3.5};
    animals[5] = (struct Animal){6, "Nemo", "Fish", 1, "Aquarium", 0.2};
    animals[6] = (struct Animal){7, "Rex", "Lion", 6, "Savannah", 200.0};
    counter = 7;
    nextId = 8;
}

int main()
{
    seedData();
    menu();
    return 0;
}
