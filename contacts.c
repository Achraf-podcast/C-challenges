#include <stdio.h>
#include <string.h>

struct Livre {
    char titre[100];
    char auteur[100];
    int annee;
};


struct Livre creerLivre(char titre[], char auteur[], int annee) {
    struct Livre livre;
    strcpy(livre.titre, titre);
    strcpy(livre.auteur, auteur);
    livre.annee = annee;
    return livre;
}

int main() {
    struct Livre monLivre = creerLivre("boite", "ahmed", 1952);
    struct Livre monLivre2 = creerLivre("antigone", "achraf", 1964);
    
    printf("Titre: %s\n", monLivre.titre);
    printf("Auteur: %s\n", monLivre.auteur);
    printf("Annee: %d\n", monLivre.annee);
    
    return 0;
}