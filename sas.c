#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define MAX 100

typedef struct {
    char f_name[50];
	char l_name[50];
	int shirtNum;
	char position[50];
	int goals;
	int age;
	char inscription[50];
	char status[50];
} Player;

void print(char value[], bool msg){
	if(strlen(value) <= 6){
		printf("\n|%s\t\t\t\t\t\t\t\t       |", value);
	}else if(strlen(value) <= 14 && strlen(value) > 6){
		printf("\n|%s\t\t\t\t\t\t\t       |", value);
	}else if(strlen(value) <= 22 && strlen(value) > 14){
		printf("\n|%s\t\t\t\t\t\t       |", value);
	}else if(strlen(value) <= 30 && strlen(value) > 22){
		switch(msg){
			case true:
				printf("\n|\t\t\t\t\t\t\t\t       |");
				printf("\n|%s%s %s\t\t\t\t\t       |",RED, value, RESET);
				break;
			case false:
				printf("\n|%s\t\t\t\t\t       |", value);
		}
		
	}else if(strlen(value) <= 38 && strlen(value) > 30){
		printf("\n|%s\t\t\t\t       |", value);
	}
	else if(strlen(value) <= 46 && strlen(value) > 38){
		printf("\n|%s\t\t\t       |", value);
	}else if(strlen(value) <= 54 && strlen(value) > 46){
		printf("\n|%s\t\t       |", value);
	}else if(strlen(value) <= 62 && strlen(value) > 54){
		printf("\n|%s\t       |", value);
	}else if(strlen(value) <= 70 && strlen(value) > 62){
		printf("\n|%s       |", value);
	}
}

void addIt(){	
	printf("\n  Nom:  ");
}

void addPlayer(){
	int command;
	
	system("cls");
	printf("\n--------------------- Gestion d'equipe de football ---------------------");
	print("1.  Ajouter un nouveau joueur.", false);
	print("2.  Ajouter plusieurs joueurs en une seule operation.", false);
	print("3.  Retour.", false);
	printf("\n------------------------------------------------------------------------");
	printf("\n Choix:  ");
	scanf("%d", &command);
	
	switch(command){
		case 1:
			addIt();
		case 3:
			break;
		default:
			addPlayer();
	}
}

int menu(){
	int command;
	bool do_it = true;
	bool msg = false;
	
	do{
		system("cls");
		printf("\n--------------------- Gestion d'equipe de football ---------------------");
		print("1.   Ajouter un joueur.", false);
		print("2.   Modifier un joueur.", false);
		print("3.   Supprimer un joueur.", false);
		print("4.   Rechercher un joueur.", false);
		print("5.   Statistiques.", false);
		print("0.   Quitter.", false);
		if(msg == true){
			print("     Ce choix n' existe pas !", true);
			msg = false;
		}
		printf("\n------------------------------------------------------------------------");
	
		printf("\n Choix:  ");
		scanf("%d", &command);
		switch(command){
			case 1:
				do_it = false;
				addPlayer();
			default:
				if(do_it){
					msg = true;
				}
				do_it = true;
		}
	}while(command != 0);
	return 0;
	
}

int main(){
	menu();

	return 0;
}
