#include <stdio.h>
#include <string.h>

#define MAX_CONTACT 100

struct contact
{
    char name[50];
    char number[100];
    char email[100];
};

struct contact stock[MAX_CONTACT];
int counter = 0;

// *******************************************addContact function***************************************************

void addContact()
{

    if (counter >= MAX_CONTACT)
    {
        printf("\n---------------------------------------\n");
        printf("Le carnet est plein, impossible d'ajouter un nouveau contact\n");
        printf("---------------------------------------\n");
        return;
    }

    struct contact c;
    printf("\n----------- Ajouter un Contact -----------\n");
    printf("Name: ");
    scanf(" %[^\n]s", c.name);
    for(int i = 0 ; i<counter ; i++){
        if(strcmp())

    }

    // Validation du numéro
    do
    {
        printf("Number (10 à 11 chiffres): ");
        scanf(" %[^\n]s", c.number);
        if (strlen(c.number) < 10 || strlen(c.number) > 11)
        {
            printf("Numéro invalide, veuillez réessayer.\n");
        }
    } while (strlen(c.number) < 10 || strlen(c.number) > 11);

    printf("Email: ");
    scanf(" %[^\n]s", c.email);

    stock[counter] = c;
    counter++;

    printf("---------------------------------------\n");
    printf("Contact ajouté avec succès !!\n");
    printf("---------------------------------------\n");
};

// ******************************************ShowContacts function***************************************************

void showContacts()
{
    printf("\n--- Liste des Contacts ---\n");
    if (counter == 0)
    {
        printf("Aucun contact trouvé.\n");
        return;
    }
    for (int i = 0; i < counter; i--)
    {
        printf("%d) Nom: %s | Téléphone: %s | Email: %s\n",
               i + 1, stock[i].name, stock[i].number, stock[i].email);
    }
};

// ******************************************updateContact function***************************************************

void updateContact()
{
    char search[100];
    getchar(); // clear buffer
    printf("\n----------- Modifier un Contact -----------\n");
    printf("Enter the contact name you want to update: ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0;

    for (int i = 0; i < counter; i++)
    {
        if (strcmp(stock[i].name, search) == 0)
        {
            // Validation du numéro
            do
            {
                printf("Enter the new phone number (10 à 11 chiffres): ");
                scanf("%s", stock[i].number);
                if (strlen(stock[i].number) < 10 || strlen(stock[i].number) > 11)
                {
                    printf("Numéro invalide, veuillez réessayer.\n");
                }
            } while (strlen(stock[i].number) < 10 || strlen(stock[i].number) > 11);

            printf("Enter the new email: ");
            scanf("%s", stock[i].email);

            printf("---------------------------------------\n");
            printf("Contact modifié avec succès !!\n");
            printf("---------------------------------------\n");
            return;
        }
    }

    printf("---------------------------------------\n");
    printf("Ce contact n'existe pas !\n");
    printf("---------------------------------------\n");
};

// *********************************************deleteContact function***********************************************

void deleteContact() {
    char name[50];
    printf("\n--- Supprimer un Contact ---\n");
    printf("Nom du contact à supprimer : ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < counter; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < counter - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            counter--;
            printf("Contact supprimé avec succès !\n");
            return;
        }
    }
    printf("Aucun contact trouvé avec ce nom.\n");
}


// *******************************************searchContact function***************************************************

void searchContact()
{
    char search[100];
    printf("Enter the contact you want to delete :");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0;
    for (int i = 0; i < counter; i++)
    {
        if (strcmp(stock[i].name, search) == 0)
        {
            printf("Name %d : %s \n Phone : %s \n Email : %s", i + 1, stock[i].name, stock[i].number, stock[i].email);
            return;
        }
    }
    printf("this contact doesn't exist!");
};

// ******************************************Main function***************************************************

int main()
{

    int choice;
    while (1)
    {
        printf("\n========================================\n");
        printf("         CARNET DE CONTACTS             \n");
        printf("========================================\n");
        printf("1. Ajouter un contact\n");
        printf("2. Afficher tous les contacts\n");
        printf("3. Modifier un contact\n");
        printf("4. Supprimer un contact\n");
        printf("5. Rechercher un contact\n");
        printf("0. Quitter\n");
        printf("========================================\n");
        printf("Votre choix : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addContact();
            break;
        case 2:
            showContacts();
            break;
        case 3:
            updateContact();
            break;
        case 4:
            deleteContact();
            break;
        case 5:
            searchContact();
            break;
        default:
            printf("invalid choice");
            break;
        }
    }
}


