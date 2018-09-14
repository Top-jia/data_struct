#include<stdio.h>

void swap(int *array, int i, int j){
	if(array == NULL || i < 0 || j < 0){
		return;
	}

	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void select_sort(int *array, int len){
	if(array == NULL || len <= 1){
		return;
	}

	for(int i = 0; i < len - 1; i++){
		for(int j = i + 1; j < len; j++){
			if(array[i] > array[j]){
				swap(array, i, j);
			}
		}
	}
}

void show_data(int *array, int len){
	if(array == NULL || len <= 1){
		return;
	}
	
	for(int i = 0; i < len; i++){
		printf("array[%d] = %d\n", i, array[i]);
	}
}
int main(){
	int array[] = {7, 0, 8, 2, 1, 6, 4, 9, 3};

	int len = sizeof(array)/sizeof(array[0]);
	printf("select_sort--init data:\n");
	show_data(array, len);
	select_sort(array, len);
	printf("select_sort--after\n");
	show_data(array, len);
	return 0;
}
