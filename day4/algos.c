// challenge 1
// *****************************************bubble sort*******************************************
#include <stdio.h>

int main()
{

    int arr[] = {8, 9, 5, 2, 7, 6, 3};

    int helper = 0;

    for (int i = 0; i < 7; i++)
    {
        for (int j = i + 1; j < 7; j++)
        {
            if (arr[i] > arr[j])
            {
                helper = arr[j];
                arr[j] = arr[i];
                arr[i] = helper;
            }
        }
    }

    for (int i = 0; i < 7; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}

// challenge 2
// ******************************************insertion sort***************************************

#include <stdio.h>

int main()
{

    // comparer deux par deux
    int arr[] = {9, 8, 5, 2, 7, 6, 3};

    for (int i = 0; i < 7; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--; //
        }
        arr[j + 1] = temp;
    }

    for (int i = 0; i < 7; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}

// challenge 3
// ******************************************selection sort***************************************

#include <stdio.h>
int main()
{

    int arr[] = {8, 9, 5, 2, 7, 6, 3};

    for (int i = 0; i < 7; i++)
    {
        int min = i;

        for (int j = i + 1; j < 7; j++)
        {
            if (arr[min] > arr[j])
            {
                int temp = arr[min];
                arr[min] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}

// challenge 4
// ******************************************quick sort***************************************

#include <stdio.h>

void quickSort(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start;
    int temp = 0;
    if (start >= end)
        return;
    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;
    quickSort(arr, start, i - 1);
    quickSort(arr, i + 1, end);
}
int main()
{
    int arr[] = {3, 9, 5, 2, 7, 6, 8};
    int n = 7;

    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}



//####################### search algorithms ########################
