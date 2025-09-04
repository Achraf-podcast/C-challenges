#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char s[] = "0";
int EvenNums[] = {0, 2, 4, 6, 8};

void EvenOrOdd(int len, int LastCharacter){
	bool value = false;
	
	for(int i=0; i<5; i++){
		if (EvenNums[i] == LastCharacter){
			value = true;
			break;
		}
	}
	
	if (value){
		printf("Ce nombre est pair.");
	}else{
		printf("Ce nombre est impaire.");
	}
}

int main() {
    printf("Entrez un nombre: ");
    scanf("%s", s);
    int l = strlen(s);
    char c = s[l-1];
    int LastCharacter = atoi(&c);
    EvenOrOdd(l, LastCharacter);

    return 0;
}
	//int l = strlen(s);
	//int n = atoi(s);
