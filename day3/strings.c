// challenge 1

#include <stdio.h>
#include <string.h>

int main()
{

    char string[20];
    printf("enter a string : ");
    scanf(" %[^\n]s", string);
    printf("ur input was : %s", string);

    return 0;
}

// challenge 2
#include <stdio.h>
#include <string.h>

int main()
{
    char input[20];
    int length = 0;
    printf("enter a string : ");
    scanf(" %[^\n]s", input);

    for (int i = 0; input[i] != '\0'; i++)
    {

        length++;
    }

    printf("%d", length);
    return 0;
}

// challenge 3

#include <stdio.h>
#include <string.h>

int main()
{
    char input1[100];
    char input2[50];
    int i = 0, j = 0;

    printf("enter a string 1: ");
    scanf(" %[^\n]s", input1);
    printf("enter a string 2: ");
    scanf(" %[^\n]s", input2);

    while (input1[i] != '\0')
    {
        i++;
    }
    while (input2[j] != '\0')
    {
        input1[i] = input2[j];
        i++;
        j++;
    }
    input1[i] = '\0';

    printf("%s", input1);
}

// challenge 3 method 2
#include <stdio.h>
#include <string.h>

int main()
{
    char input1[100];
    char input2[50];

    printf("enter a string 1: ");
    scanf(" %[^\n]s", input1);
    printf("enter a string 2: ");
    scanf(" %[^\n]s", input2);

    strcat(input1, input2);
    printf("%s", input1);
    return 0;
}

// challenge 4
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50];
    char str2[50];
    int equal = 1;

    printf("enter a string 1: ");
    scanf(" %[^\n]s", str1);
    printf("enter a string 2: ");
    scanf(" %[^\n]s", str2);

    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            equal = 0;
            break;
        }
        i++;
    }

    if (str1[i] == str2[i])
    {
        equal = 0;
    }

    if (equal)
    {
        printf("they are same ");
    }
    else
    {
        printf("they are not equal");
    }

    return 0;
}

// exercise

#include <stdio.h>
#include <string.h>
int main()
{
    char search[100];
    char tracks[][80] = {
        "I left my heart in Harvard Med School",
        "Newark, Newark - a wonderful town",
        "Dancing with a Dork",
        "From here to maternity",
        "The girl from Iwo Jima",
    };

    int store;
    printf(" enter a string : ");
    scanf("%s", search);
    int found = 0;

    for (int i = 0; i < 80; i++)
    {
        if (strstr(tracks[i], search))
        {
            found = 1;
            store = i;
            break;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%s", tracks[store]);
        break;
    }

    if (!found)
    {
        printf("not found");
    }

    return 0;
}

// change to fgets

#include <stdio.h>
#include <string.h>
int main()
{
    char search[100];
    char tracks[][80] = {
        "I left my heart in Harvard Med School",
        "Newark, Newark - a wonderful town",
        "Dancing with a Dork",
        "From here to maternity",
        "The girl from Iwo Jima",
    };

    int store;
    printf(" enter a string : ");
    fgets(search, sizeof(search), stdin);

    search[strcspn(search, "\n")] = '\0';

    int found = 0;

    for (int i = 0; i < 80; i++)
    {
        if (strstr(tracks[i], search))
        {
            found = 1;
            store = i;
            break;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%s", tracks[store]);
        break;
    }

    if (!found)
    {
        printf("not found");
    }

    return 0;
}

// challenge 5

#include <stdio.h>
#include <string.h>
int main()
{
    char search[50];
    printf(" enter a string : ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0;

    int length = strlen(search);

    char inverse[50];
    int j = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        inverse[j] = search[i];
        j++;
    }
    inverse[j] = '\0';

    printf("%s", inverse);
    return 0;
}

// challenge 6
#include <stdio.h>
#include <string.h>
int main()
{

    char elm;
    int counter = 0;
    char string[50];

    printf("enter a string :");
    scanf("%s", string);

    printf("enter a letter: ");
    scanf("%s", &elm);

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == elm)
        {
            counter++;
        }
    }

    printf("%d", counter);
    return 0;
}

// challenge 7
#include <stdio.h>
#include <string.h>
int main()
{
    char word[20];
    printf("enter a word :");
    scanf("%s", word);

    for (int i = 0; i < strlen(word); i++)
    {
        word[i] = word[i] - 32;
    }

    printf("%s", word);

    return 0;
}

// challenge 8
#include <stdio.h>
#include <string.h>
int main()
{
    char word[20];
    printf("enter a word :");
    scanf("%s", word);

    for (int i = 0; i < strlen(word); i++)
    {
        word[i] = word[i] + 32;
    }

    printf("%s", word);

    return 0;
}

// challenge 9
#include <stdio.h>
#include <string.h>
int main()
{
    char word[50];
    printf("enter a word :");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = 0;

    int j = 0, i = 0;

    int length = strlen(word);
    for (i = 0; i < length; i++)
    {
        if (word[i] == ' ')
        {
            for (j = i; j < length; j++)
            {
                word[j] = word[j + 1];
            }
            length--;
            i--;
        }
    }

    printf("%s", word);
    return 0;
}

// challenge 10

#include <stdio.h>
#include <string.h>
int main()
{
    char sentence[50];
    char souschaine[50];
    printf("entrer la phrase principale :");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = 0;

    printf("entrer  le sous titre :");
    fgets(souschaine, sizeof(souschaine), stdin);
    souschaine[strcspn(souschaine, "\n")] = 0;

    int found = 0;
    int store;

    if (strstr(sentence, souschaine))
    {
        printf("found\n");
    }
    else
    {
        printf("not found\n");
    }
}
