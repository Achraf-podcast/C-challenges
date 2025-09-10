#include <stdio.h>

int t;
void showList(int arr[], int l){
	for(int i = 0; i<l; i++){
		printf("%d, ", arr[i]);
	}
}

void createList(int list[], int l){
	printf("Entrez les nombres:\n");
	for(int i = 0; i<l; i++){
		int n;
		scanf("%d", &n);
		list[i] = n;
	}
}

void mainList(int m_list[], int firstList[], int l1, int secondList[], int l2){
	int index = 0;
	for(int i = 0; i<l1; i++){
		m_list[i] = firstList[i];
		index++;
	}
	for(int i = 0; i<l2; i++){
		m_list[index] = secondList[i];
		index++;
	}
}

void sort(int arr[], int l){
	for(int i = 0; i<l; i++){
		for(int j = 0; j < l-1; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void eleminate(int list[], int size){
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[i] == list[j]) {
                for (int k = j; k < size - 1; k++) {
                    list[k] = list[k + 1];
                }
                size--;  
                j--;
            }
        }
    }
    t = size;
    
}

int search(int list[], int l, int n){
	int f_index = 0;
    int l_index = l - 1;

    while (f_index <= l_index) {
        int middle = f_index + (l_index - f_index) / 2;

        if (list[middle] == n) {
            return middle;
        }
        else if (list[middle] < n) {
            f_index = middle + 1;
        }
        else {
            l_index = middle - 1;
        }
    }

    return -1;
}

int main(){
	int l1, l2, m_l, n;
	
	printf("Entrez la taille de premier tableau: ");
	scanf("%d", &l1);
	int list1[l1];
	createList(list1, l1);
	
	printf("Entrez la taille de dexieme tableau: ");
	scanf("%d", &l2);
	int list2[l2];
	createList(list2, l2);
	
	m_l = l1 + l2;
	int m_list[m_l];
	mainList(m_list, list1, l1, list2, l2);
	
	sort(m_list, m_l);
	eleminate(m_list, m_l);
	m_l = t;
	
	printf("Voila votre tableau en bien ordre: ");
	showList(m_list, m_l);
	
	printf("\n\nLe minimum: %d", m_list[0]);
	printf("\nLe maximum: %d", m_list[m_l-1]);
	
	printf("\n\nEntrez un element a rechercher: ");
	scanf("%d", &n);
	int result = search(m_list, m_l, n);
	if(result != -1){
		printf("Element %d trouve a l'index %d.\n", n, result);
	}else{
		printf("Element %d non trouve dans le tableau.\n", n);
	}
	
	return 0;
}
