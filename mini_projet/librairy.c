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
    printf("title: ");
    scanf("%[^\n]s", stock[counter].title);
    printf("author: ");
    scanf("%[^\n]s", stock[counter].author);
    printf("price: ");
    scanf("%f", stock[counter].price);
    printf("Quantity: ");
    scanf("%d", stock[counter].quantity);

    counter++;
    printf("book created successfully!!");
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

// *****************************************************************

void searchBook()
{

    int search;

    printf("Enter the title: ");
    scanf("%s", &search);

    if (counter == 0)
    {
        printf("no books to show!");
        return;
    }

    for (int i = 0; i < counter; i++)
    {
        if (stock[i].title == search)
        {
            printf("Title :%s \n", stock[i].title);
            printf("Author :%s\n", stock[i].author);
            printf("Price :%f \n", stock[i].price);
            printf("Quantity :%d \n", stock[i].quantity);
        }
        else
        {
            printf("this book doesnt exist in our librairy");
        }
    }
};

void updateQuantity()
{
    int search;

    printf("Enter the title: ");
    scanf("%s", &search);

    if (counter == 0)
    {
        printf("not found!");
        return;
    }

    for (int i = 0; i < counter; i++)
    {
        if (stock[i].title == search)
        {
            printf("enter the new quantity number :");
            scanf("%d", stock[i].quantity);
        }
        else
        {
            printf("this book doesnt exist");
        }
    }
};

void deleteBook()
{
    int search;

    printf("Enter the title: ");
    scanf("%s", &search);

    if (counter == 0)
    {
        printf("not found!");
        return;
    }

    for (int i = 0; i < counter; i++)
    {
        if (stock[i].title == search)
        {

            stock[i] = stock[i + 1];
            counter--;
        }
        else
        {
            printf("not found");
        }
    }
};

void totalBooks()
{
    int total = 0; 
    for (int i = 0; i < counter; i++){
       total +=stock[i].quantity;
    };
    printf("the total books quantity is : %d", total); 
};



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