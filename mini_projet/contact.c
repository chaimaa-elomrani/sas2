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

    if (counter > MAX_CONTACT)
    {
        printf("le carnet est plein , impossible d'ajouter un nouveau contact");
    }

    struct contact c;
    printf("\n--- Ajouter un Contact ---\n");
    printf("Name: ");
    scanf(" %[^\n]s", c.name);
    printf("Number: ");
    scanf(" %[^\n]s", c.number);
    printf("Email: ");
    scanf(" %[^\n]s", c.email);

    stock[counter] = c;
    counter++;

    printf("contact added successfully !!");
};


// ******************************************ShowContacts function***************************************************

void showContacts()
{
    if (counter == 0)
    {
        printf("no contact existing yet");
        return;
    }

    struct contact c;

    for (int i = 0; i < counter; i++)
    {
        printf("Name %d : %s \n Phone : %s \n Email : %s", i + 1, stock[i].name, stock[i].number, stock[i].email);
    }
};


// ******************************************updateContact function***************************************************

void updateContact()
{
    char search[100];
    printf("Enter the contact you want to update :");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0;

    for (int i = 0; i < counter; i++)
    {
        if (strcmp(stock[i].name,search) == 0)
        {
            printf("enter the new phone number:");
            scanf("%s", stock[i].number);
            printf("enter the new email:");
            scanf("%s", stock[i].email);
            printf("contact updated successfully!!");
            return;
        }
    }

    printf("this contact doesn't exist!");
};


// *********************************************deleteContact function***********************************************

void deleteContact()
{
    char search[100];
    printf("Enter the contact you want to delete :");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0;
    for (int i = 0; i < counter; i++)
    {
        if (strcmp(stock[i].name,search) == 0)
        {
            for (int j = i; j < counter - 1; j++)
            {
                stock[j] =stock[j + 1];
            }
            counter--;
            printf("contact deleted successfully!!");
            return;
        }
    };
    printf("this contact doesn't exist!");
}


// *******************************************searchContact function***************************************************


void searchContact(){
    char search[100];
    printf("Enter the contact you want to delete :");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0;
     for (int i = 0; i < counter; i++)
    {
        if (strcmp(stock[i].name,search) == 0){
            printf("Name %d : %s \n Phone : %s \n Email : %s", i + 1, stock[i].name, stock[i].number, stock[i].email);
            return ; 
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
        
        printf("\n===== Carnet de Contacts =====\n");
        printf("1. Ajouter un contact\n");
        printf("2. Afficher tous les contacts\n");
        printf("3. Rechercher un contact\n");
        printf("4. Modifier un contact\n");
        printf("5. Supprimer un contact\n");
        printf("0. Quitter\n");
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