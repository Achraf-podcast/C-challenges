#include <stdio.h>

int list[] = {1, 4, 3, 9, 8, 0, 2, 5, 7, 6};
void showList(){
	for(int i=0; i<10; i++){
		printf("%d, ", list[i]);
	}
}

void bubbleSort(int a[], int l){
	for(int i = 0; i<l; i++){
		for(int j = 0; j<(l-1); j++){
			if(a[j] > a[j + 1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int main(){
	showList();
	bubbleSort(list, 10);
	printf("\n\n");
	showList();
	
	return 0;
}
