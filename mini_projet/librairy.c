#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book
{
    char title[50];
    char author[20];
    float price;
    int quantity;
};

struct Book stock[MAX_BOOKS];
int counter = 0;

void addBook()
{
    if (counter == MAX_BOOKS)
    {
        printf("you can not add a book , stockage is full!");
        return;
    }

    printf("\n=============== Enter book informations ====================\n");
    printf("Title: ");
    scanf("%s", stock[counter].title);

    printf("Author: ");
    scanf("%s", stock[counter].author);

    printf("Price: ");
    scanf("%f", &stock[counter].price);

    printf("Quantity: ");
    scanf("%d", &stock[counter].quantity);

    counter++;
    printf("Book created successfully!!\n");
};

// ************************************************************************

void showBooks()
{
    if (counter == 0)
    {
        printf("no books to show!");
        return;
    }

    for (int i = 0; i < counter; i++)
    {
        printf("\n______book %d :_________\n ", i + 1);
        printf("Title :%s \n", stock[i].title);
        printf("Author :%s \n", stock[i].author);
        printf("Price :%f \n", stock[i].price);
        printf("Quantity :%d \n", stock[i].quantity);
    }
};

// *************************************************************************

void searchBook()
{
    char search[50];
    int found = 0;

    printf("Enter the title: ");
    scanf("%s", search);

    if (counter == 0)
    {
        printf("No books to show!\n");
        return;
    }

    for (int i = 0; i < counter; i++)
    {
        if (strcmp(stock[i].title, search) == 0)
        {
            printf("Title   : %s\n", stock[i].title);
            printf("Author  : %s\n", stock[i].author);
            printf("Price   : %.2f\n", stock[i].price);
            printf("Quantity: %d\n", stock[i].quantity);
            found = 1;
            break;  
        }
    }

    if (!found)
    {
        printf("This book doesnt exist in our library.\n");
    }
}


// *************************************************************************


void updateQuantity()
{
    char search[50];
    int newQuantity;
    int found = 0;

    printf("Enter the title: ");
    scanf("%s", search);

    if (counter == 0)
    {
        printf("No books to update!\n");
        return;
    }

    for (int i = 0; i < counter; i++)
    {
        if (strcmp(stock[i].title, search) == 0)
        {
            printf("Enter the new quantity: ");
            scanf("%d", &newQuantity);
            stock[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("This book doesnt exist.\n");
    }
}


// *************************************************************************

void deleteBook()
{
    char search[50];
    int found = 0;

    printf("Enter the title: ");
    scanf("%s", search);

    if (counter == 0)
    {
        printf("No books to delete!\n");
        return;
    }

    for (int i = 0; i < counter; i++)
    {
        if (strcmp(stock[i].title, search) == 0)
        {
            for (int j = i; j < counter - 1; j++)
            {
                stock[j] = stock[j + 1];
            }
            counter--;
            printf("Book deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("This book doesnt exist.\n");
    }
};



// *************************************************************************


void totalBooks()
{
    int total = 0; 
    for (int i = 0; i < counter; i++){
       total +=stock[i].quantity;
    };
    printf("the total books quantity is : %d", total); 
};


// *************************************************************************


int main()
{
    int choice;

    while (1)
    {
        printf("\n=== Librairy menu ===\n");
        printf("1. Add a book \n");
        printf("2. Show all books \n");
        printf("3. Search a book \n");
        printf("4. Update quantity \n");
        printf("5. Delete book\n");
        printf("6. Total number of books \n");
        printf("7. Quit\n");
        printf("Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            showBooks();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            updateQuantity();
            break;
        case 5:
            deleteBook();
            break;
        case 6:
            totalBooks();
            break;
        case 7:
            return 0;
        default:
            printf("invalid choice");
        }
    }
}