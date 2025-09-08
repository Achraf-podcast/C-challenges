#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char nom[50];
    char telephone[20];
    char email[50];
} Contact;

Contact contacts[MAX_CONTACTS];
int nombreContacts = 0;

int numeroValide(char *tel) {
    if (strlen(tel) > 10 || strlen(tel) < 10) return 0; 
    
    return 1;
}


int emailValide(char *email) {
    char *at = strchr(email, '@');
    char *dot = strrchr(email, '.');

    if (at == NULL || dot == NULL) return 0; 
    if (at > dot) return 0;
    if (at == email) return 0;
    return 1;
}


void ajouterContact() {
    if (nombreContacts >= MAX_CONTACTS) {
        printf("Carnet plein, impossible d ajouter un nouveau contact.\n");
        return;
    }

    printf("Entrer le nom: ");
    scanf(" %[^\n]", contacts[nombreContacts].nom);

    do {
        printf("Entrer le numero de telephone (max 10 chiffres): ");
        scanf(" %[^\n]", contacts[nombreContacts].telephone);
        if (!numeroValide(contacts[nombreContacts].telephone)) {
            printf("Numero invalide ! Ressayez.\n");
        }
    } while (!numeroValide(contacts[nombreContacts].telephone));

    do {
        printf("Entrer l'adresse e-mail: ");
        scanf(" %[^\n]", contacts[nombreContacts].email);
        if (!emailValide(contacts[nombreContacts].email)) {
            printf("Email invalide ! Ressayez.\n");
        }
    } while (!emailValide(contacts[nombreContacts].email));

    nombreContacts++;
    printf("Contact ajoute avec succes !\n");
}


void afficherContacts() {
    if (nombreContacts == 0) {
        printf("Aucun contact a afficher.\n");
        return;
    }
    printf("\n--- Liste des Contacts ---\n");
    for (int i = 0; i < nombreContacts; i++) {
        printf("Nom: %s\n", contacts[i].nom);
        printf("Telephone: %s\n", contacts[i].telephone);
        printf("Email: %s\n", contacts[i].email);
        printf("---------------------------\n");
    }
}

void rechercherContact() {
    char nomRecherche[50];
    printf("Entrer le nom du contact a rechercher: ");
    scanf(" %[^\n]", nomRecherche);

    for (int i = 0; i < nombreContacts; i++) {
        if (strcmp(contacts[i].nom, nomRecherche) == 0) {
            printf("Contact trouve :\n");
            printf("Nom: %s\n", contacts[i].nom);
            printf("Telephone: %s\n", contacts[i].telephone);
            printf("Email: %s\n", contacts[i].email);
            return;
        }
    }
    printf("Contact non trouve.\n");
}

void modifierContact() {
    char nomRecherche[50];
    printf("Entrer le nom du contact a modifier: ");
    scanf(" %[^\n]", nomRecherche);

    for (int i = 0; i < nombreContacts; i++) {
        if (strcmp(contacts[i].nom, nomRecherche) == 0) {
            printf("Entrer le nouveau numero de telephone: ");
            scanf(" %[^\n]", contacts[i].telephone);
            printf("Entrer le nouvel e-mail: ");
            scanf(" %[^\n]", contacts[i].email);
            printf("Contact modifie avec succes.\n");
            return;
        }
    }
    printf("Contact non trouve.\n");
}


void supprimerContact() {
    char nomRecherche[50];
    printf("Entrer le nom du contact a supprimer: ");
    scanf(" %[^\n]", nomRecherche);

    for (int i = 0; i < nombreContacts; i++) {
        if (strcmp(contacts[i].nom, nomRecherche) == 0) {
            for (int j = i; j < nombreContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            nombreContacts--;
            printf("Contact supprime avec succes.\n");
            return;
        }
    }
    printf("Contact non trouve.\n");
}


int main() {
    int choix;

    do {
        printf("\n--- Carnet de Contacts ---\n");
        printf("1. Ajouter un contact\n");
        printf("2. Afficher tous les contacts\n");
        printf("3. Rechercher un contact\n");
        printf("4. Modifier un contact\n");
        printf("5. Supprimer un contact\n");
        printf("6. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterContact(); break;
            case 2: afficherContacts(); break;
            case 3: rechercherContact(); break;
            case 4: modifierContact(); break;
            case 5: supprimerContact(); break;
            case 6: printf("Fermeture du programme.\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 6);

    return 0;
}