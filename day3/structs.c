// challenge 1

#include <stdio.h>
#include <string.h>

struct person
{
    char firstname[50];
    char lastname[50];
    int age;
};

int main()
{

    struct person p1;

    strcpy(p1.firstname, "chaima");
    strcpy(p1.lastname, "omrani");
    p1.age = 18;
    printf("%s \n %s\n %d", p1.firstname, p1.lastname, p1.age);
}

// challenge 2
#include <stdio.h>
#include <string.h>

struct person
{
    char firstname[50];
    char lastname[50];
    int age;
    int notes[50];
};

int main()
{

    struct person p;
    strcpy(p.firstname, "chaima");
    strcpy(p.lastname, "omrani");
    p.age = 18;
    int value[] = {15, 18, 19, 20};
    int size = sizeof(value) / sizeof(value[0]);

    for (int i = 0; i < size; i++)
    {
        p.notes[i] = value[i];
    }
    printf("Nom    : %s\n", p.firstname);
    printf("Prénom : %s\n", p.lastname);
    printf("Notes  : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", p.notes[i]);
    }

    return 0;
}

// challenge 3

#include <stdio.h>
#include <string.h>

struct rectangle
{
    float lon;
    float larg;
};

float aire(struct rectangle r)
{
    return r.lon * r.larg;
}

int main()
{

    struct rectangle rec;
    printf("entrez la longueur: ");
    scanf("%f", &rec.lon);

    printf("entrez la largeur: ");
    scanf("%f", &rec.larg);
    float result = aire(rec);

    printf("l'aire de ce rectangle est : %.2f", result);
    return 0;
}

// challenge 4

#include <stdio.h>
#include <string.h>

struct point
{
    float x;
    float y;
};

int main()
{

    struct point p;
    struct point *ppoint = &p;

    ppoint->x = 12;
    ppoint->y = 19;

    printf("x = %.2f \n y = %.2f", ppoint->x, ppoint->y);
}


// challenge 5

#include <stdio.h>
#include <string.h>

struct book
{
    char title[20];
    char author[20];
    int year;
};

struct book  bookinfo()
{
    struct book b;

    strcpy(b.title, "test");
    strcpy(b.author, "chaima");
    b.year = 2025;

    return b;
}

int main(){

    struct book mb ; 
    mb = bookinfo(); 
    printf("the book informations : \n title : %s \n author : %s \n year : %d" ,mb.title , mb.author , mb.year) ; 

return 0; 
}