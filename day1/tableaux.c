// challenge 1

#include <stdio.h>

int main(){

    int arr[] = {1, 2, 3, 4, 5}; 
    for(int i =0 ; i<5 ;i++){
        printf("%d\n", arr[i]);
    }

}

// challenge 2

#include <stdio.h>

int main(){

    int n ; 
   printf("combien d'element dans le tableau : "); 
   scanf("%d", &n);

    int arr[n]; 

    printf("enter those elements numbers : \n"); 
    for (int i =0 ; i<n; i++){
        printf("element %d: ", i+1);
        scanf("%d",&arr[i]);
    }

     for(int i =0 ;i<n ; i++ ){
         printf("%d",arr[i] );
     }

       printf("\n=============== array elements ====================\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

return 0; 

}

// challenge 3
#include <stdio.h>

int main(){

    int n ; 
   printf("combien d'element dans le tableau : "); 
   scanf("%d", &n);

    int arr[n]; 
    int sum = 0; 

    printf("enter those elements numbers : \n"); 
    for (int i =0 ; i<n; i++){
        printf("element %d: ", i+1);
        scanf("%d",&arr[i]);
        sum += arr[i];
    }


        printf("la somme est : %d\n", sum );


return 0; 

}


// challenge 4

#include <stdio.h>

int main(){

    int n ; 
   printf("combien d'element dans le tableau : "); 
   scanf("%d", &n);

    int arr[n]; 
    int max = 0; 

    printf("enter those elements  : \n"); 
    for (int i =0 ; i<n; i++){
        printf("element %d: ", i+1);
        scanf("%d",&arr[i]);
    }

     for (int i =0 ; i<n; i++){
       if (max<arr[i]){
        max = arr[i];
       }
    }
    
    printf("le plus grand nombre est : %d", max );

return 0; 

}


// challenge 5
#include <stdio.h>

int main(){

    int n ; 
   printf("combien d'element dans le tableau : "); 
   scanf("%d", &n);

    int arr[n]; 
    int min; 

    printf("enter those elements  : \n"); 
    for (int i =0 ; i<n; i++){
        printf("element %d: ", i+1);
        scanf("%d",&arr[i]);
    }

     for (int i =0 ; i<n; i++){
        min = arr[0];
       if (min>arr[i]){
        min = arr[i];
       }
    }
    
    printf("le plus grand nombre est : %d", min );

return 0; 

}

// challenge 6 
int main(){

    int n ; 
   printf("combien d'element dans le tableau : "); 
   scanf("%d", &n);

    int arr[n]; 
    int mlt = 0; 

    printf("enter those elements numbers : \n"); 
    for (int i =0 ; i<n; i++){
        printf("element %d: ", i+1);
        scanf("%d",&arr[i]);
    }

    int f; 
    printf("enter the multiplication factor  : \n"); 
    scanf("%d", &f)

    for(int i = 0; i < n ;i++ )
        printf("la somme est : %d\n", sum );


return 0; 

}