#include<stdio.h>


void swap(int *array, int i, int j, int len){
	if(array == NULL || i < 0 || j < 0 || i > len - 1|| j > len -1){
		return ;
	}

	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void bubble_sort(int *array, int len){
	if(array == NULL || len <= 0){
		return ;
	}

	for(int i = 0; i < len - 1; i++){
		for(int j = 0; j < len - 1 - i; j++){
			if(array[j] > array[j + 1]){
				swap(array, j, j+1, len);
			}
		}
	}

}

void show_data(int *array, int len){
	if(array == NULL || len <= 0){
		return ;
	}
	
	for(int i = 0; i < len; i++){
		printf("array[%d] = %d\n", i, array[i]);
	}
}

int main(){
	int array[] = {7, 5, 8, 0, 2, 1, 9};
	int len = sizeof(array)/sizeof(array[0]);
	printf("init elem_data:\n");
	show_data(array, len);
	bubble_sort(array, len);
	printf("bubble_sort elem_data:\n");
	show_data(array, len);
	return 0;
}
