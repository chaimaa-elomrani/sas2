#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

struct Contact contacts[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Carnet plein ! Impossible d'ajouter plus de contacts.\n");
        return;
    }
    struct Contact c;
    printf("\n--- Ajouter un Contact ---\n");
    printf("Nom : ");
    scanf(" %[^\n]", c.name);
    printf("Téléphone : ");
    scanf(" %[^\n]", c.phone);
    printf("Email : ");
    scanf(" %[^\n]", c.email);

    contacts[contactCount] = c;
    contactCount++;

    printf("Contact ajouté avec succès !\n");
}

void displayContacts() {
    printf("\n--- Liste des Contacts ---\n");
    if (contactCount == 0) {
        printf("Aucun contact trouvé.\n");
        return;
    }
    for (int i = 0; i < contactCount; i++) {
        printf("%d) Nom: %s | Téléphone: %s | Email: %s\n",
               i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

void searchContact() {
    char name[50];
    printf("\n--- Rechercher un Contact ---\n");
    printf("Nom à rechercher : ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact trouvé :\nNom: %s\nTéléphone: %s\nEmail: %s\n",
                   contacts[i].name, contacts[i].phone, contacts[i].email);
            return;
        }
    }
    printf("Aucun contact trouvé avec ce nom.\n");
}

void modifyContact() {
    char name[50];
    printf("\n--- Modifier un Contact ---\n");
    printf("Nom du contact à modifier : ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Nouveau téléphone : ");
            scanf(" %[^\n]", contacts[i].phone);
            printf("Nouvel email : ");
            scanf(" %[^\n]", contacts[i].email);

            printf("Contact modifié avec succès !\n");
            return;
        }
    }
    printf("Aucun contact trouvé avec ce nom.\n");
}

void deleteContact() {
    char name[50];
    printf("\n--- Supprimer un Contact ---\n");
    printf("Nom du contact à supprimer : ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contactCount--;
            printf("Contact supprimé avec succès !\n");
            return;
        }
    }
    printf("Aucun contact trouvé avec ce nom.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== Carnet de Contacts =====\n");
        printf("1. Ajouter un contact\n");
        printf("2. Afficher tous les contacts\n");
        printf("3. Rechercher un contact\n");
        printf("4. Modifier un contact\n");
        printf("5. Supprimer un contact\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: modifyContact(); break;
            case 5: deleteContact(); break;
            case 0: printf("Au revoir !\n"); break;
            default: printf("Choix invalide. Réessayez.\n");
        }
    } while (choice != 0);

    return 0;
}
