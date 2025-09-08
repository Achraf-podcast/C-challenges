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

void selectionSort(int a[], int l){
	for (int step = 0; step < l - 1; step++) {
    int min_idx = step;
    	for (int i = step + 1; i < l; i++) {
    		if (a[i] < a[min_idx])
        	min_idx = i;
    	}

    int temp = a[step];
    a[step] = a[min_idx];
    a[min_idx] = temp;
  }
}

int main(){
	showList();
	selectionSort(list, 10);
	//bubbleSort(list, 10);
	printf("\n\n");
	showList();
	
	return 0;
}
