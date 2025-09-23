// challenge 1 

#include <stdio.h>

int main() {

    char nom[50]; 
    char prenom[50]; 
    char email[50];
    char sexe ; 
    int age ; 

    printf("entrer votre nom : "); 
    scanf("%s", nom);
    printf("entrer votre prenom: "); 
    scanf("%s", prenom);
    printf("email: ");
    scanf("%s", email); 
    printf("le sexe f ou h :"); 
    scanf(" %c", &sexe); 
    printf("age: ");
    scanf("%d", &age);


    printf("\n=============info personelle=============== \n");
    printf(" nom : %s\n", nom); 
    printf("prenom: %s\n", prenom);
    printf("email: %s\n", email);  
    printf("age : %d\n", age); 
    if(sexe == 'f' || sexe == 'F'){
        printf("le sexe: femme \n" ); 
    }else{
        printf("le sexe : homme"); 
    };

    printf("=========================================\n"); 
    return 0; 
}


// challenge 12
#include <stdio.h>

int main(){

    int number ,  inverse = 0 , last ; 

    printf("enter 4  numbers : "); 
    scanf("%d", &number); 

    while(number>0){
      last = number % 10 ;
      inverse = inverse*10 + last ; 
      number = number / 10;   
    }

    printf(" le nombre final est : %d", inverse); 
    return 0; 
}


// challenge 2

#include <stdio.h>

int main(){
    float temp , k; 
    
    printf("enter temp : "); 
    scanf("%f", &temp); 

    k = temp + 273.15; 
    printf("la temp en kelvein : %f", k); 
}

// challenge 3 

#include <stdio.h>

int main(){
    float dist , yards; 
    
    printf("enter dist en km  : "); 
    scanf("%f", &dist); 

    yards = dist * 1093.61; 
    printf("la dist en yards : %f", yards); 
    return 0; 
}

// challenge 4

#include <stdio.h>

int main(){

    float kmh , ms; 
    
    printf("enter dist en km/h  : "); 
    scanf("%f", &kmh); 
    
    ms = kmh * 0.27778; 

    printf("la dist en m/s : %f", ms);
    return 0;

}


