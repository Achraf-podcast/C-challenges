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
	char post[50];
	int goals;
	int age;
	char birthday[50];
	char inscription[50];
	char status[50];
} Player;

Player players[MAX];
int playersNum = 0;

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

void addIt(char f_name[], char l_name[], int shirtNum, char post[], int goals, int age, char birthday[], char inscription[], char status[]){	
	strcpy(players[playersNum].f_name, f_name);
	strcpy(players[playersNum].l_name, l_name);
	players[playersNum].shirtNum = shirtNum;
	strcpy(players[playersNum].post, post);
	players[playersNum].goals = goals;
	players[playersNum].age = age;
	strcpy(players[playersNum].birthday, birthday);
	strcpy(players[playersNum].inscription, inscription);
	strcpy(players[playersNum].status, status);
	playersNum++;
}

void addMultiPlayers(){
	printf("");
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
		//case 1:	
			//addIt();
		case 3:
			break;
		default:
			addPlayer();
	}
}

void showPlayers(){
		system("cls");
		for(int i = 0; i<playersNum; i++){
			if(strlen(players[i].f_name) <=7  && strlen(players[i].l_name) <=7){
				printf("\nId: %d\tPrenom: %s\t| Nom: %s\t|Maillot: %d| Post: %s | Buts: %d  | Age: %d | date d'inscription: %s | Statut: %s\n", i, 
				players[i].f_name, 
				players[i].l_name, 
				players[i].shirtNum,
				players[i].post,
				players[i].goals,
				players[i].age,
				players[i].inscription,
				players[i].status);
			}else printf("\nId: %d\tPrenom: %s | Nom: %s |Maillot: %d| Post: %s | Buts: %d  | Age: %d | date d'inscription: %s | Statut: %s\n", i, players[i].f_name, players[i].l_name, players[i].shirtNum,players[i].post,players[i].goals,players[i].age,players[i].inscription,players[i].status);
			printf("------------------------------------------------------------------------------------------------------------------------------------------------------------");
		}
		scanf("%d");
		
}
		
int menu(){
	int command;
	bool do_it = true;
	bool msg = false;
	
	do{
		system("cls");
		printf("\n--------------------- Gestion d'equipe de football ---------------------");
		print("1.   Ajouter un joueur.", false);
		print("2.   Afficher tout les joueurs.", false);
		print("3.   Modifier un joueur.", false);
		print("4.   Supprimer un joueur.", false);
		print("5.   Rechercher un joueur.", false);
		print("6.   Statistiques.", false);
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
			case 2:
				do_it = false;
				showPlayers();
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
	addIt("Achraf", "Agourram", 11, "Milieu", 9, 17, "05/11/2007", "01/09/2025", "Titluaire");
	addIt("aymen", "modich", 1, "attaquant", 26, 19, "26/07/2006", "14/08/2025", "Titluaire");
	addIt("rayan", "bniazza", 5, "Milieu", 15, 17, "28/02/2008", "01/09/2025", "Titluaire");
	addIt("anas", "brrada", 9, "Gardien", 1, 20, "01/01/2005", "01/09/2023", "Titluaire");
	addIt("mehdi", "lyazir", 4, "attaquant", 29, 24, "13/09/2000", "01/09/2018", "Titluaire");
	addIt("ousssama", "aouni", 23, "Defensseur", 8, 18, "17/12/2006", "01/09/2024", "Titluaire");
	addIt("mounir", "chrif", 7, "Defensseur", 9, 22, "03/03/2003", "01/09/2021", "Titluaire");
	addIt("morad", "lbessri", 99, "attaquant", 35, 21, "08/04/2004", "01/09/2021", "Titluaire");
	addIt("ayoub", "eldokkali", 17, "Milieu", 11, 17, "05/09/2008", "01/09/2025", "Titluaire");
	addIt("mstafa", "elwazani", 2, "attaquant", 30, 18, "19/06/2007", "01/09/2025", "Titluaire");
	
	menu();
	

	return 0;
}
