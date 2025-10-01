#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_ANIMALS 200

struct Animal
{
    int id;
    char nom[50];
    char espece[30];
    int age;
    char habitat[20];
    float poids;
    char date[11];  //"YYYY-MM-DD"
    char regime[15];
};

struct Animal animals[MAX_ANIMALS]; 
int counter = 0; 
int nextId = 1 ; 


// ************************************** load data from animaux.csv ********************************
int load_from_csv(const char *name){
    printf("Trying to open file: %s\n", name);
    FILE* file = fopen(name, "r");
    if (!file){
        printf("Fichier %s introuvable!!\n", name);
        return 0; 
    }

    char line[200]; 
    
    fgets(line, sizeof(line), file); // pour ignorer l first line 

    while(fgets(line, sizeof(line), file)){
        if(counter >=  MAX_ANIMALS)
        break; 

        struct Animal a ; 

        char poidsstr[20];

        sscanf(line, "%d,%49[^,],%29[^,],%d,%19[^,],%19[^,],%10[^,],%14[^\n]", &a.id, a.nom, a.espece, &a.age, a.habitat, poidsstr, a.date, a.regime);
        
        // id generation 
        if(a.id == 0){
            a.id = nextId++; 

        }else if(a.id>= nextId){
            nextId = a.id+1; 
        }


        // optional wweigth optinal 
        if(strlen(poidsstr) == 0){
            a.poids = -1.0f; 
        }else{
            sscanf(poidsstr , "%f" , &a.poids); 
        }

        animals[counter++] = a ; //adding it to the  table animals 
    }
    fclose(file); 
    return 1 ; 
}


void print_animals() {
    if (counter == 0) {
        printf("Aucun animal chargé.\n");
        return;
    }

    for (int i = 0; i < counter; i++) {
        printf("ID: %d, Nom: %s, Espèce: %s, Age: %d, Habitat: %s, Poids: ",
               animals[i].id, animals[i].nom, animals[i].espece, animals[i].age, animals[i].habitat);

        if (animals[i].poids == -1.0f)
            printf("inconnu");
        else
            printf("%.2f", animals[i].poids);
            printf(" | Date: %s , Régime: %s\n", animals[i].date, animals[i].regime);

        printf("\n");
    }
}

int main() {
    if (load_from_csv("C:/Users/safiy/day1/final_project/animaux.csv")) {
        printf("Animaux chargés avec succès !\n");
        print_animals(); // <-- print all loaded animals
    } else {
        printf("Erreur lors du chargement du fichier.\n");
    }
    return 0;
}
