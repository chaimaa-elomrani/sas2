#include <stdio.h>
int main()
{

    int n;
    int counter = 0;
    printf("enter a number : ");
    scanf("%d", &n);

    while (n != 0)
    {
        n = n / 10;
        counter++;
    }

    printf("%d", counter);
}

// exercise 2
#include <stdio.h>
int main()
{
    int n;
    printf("enter a number : ");
    scanf("%d", &n);

    int last;
    int inverse = 0;
    while (n != 0)
    {
        last = n % 10;
        inverse = inverse * 10 + last;
        n = n / 10;
    }

    printf("%d", inverse);
}


