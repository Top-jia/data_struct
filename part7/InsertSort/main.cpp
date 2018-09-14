#include<stdio.h>
#include<stdlib.h>

#define SIZE	10

void input_data(int *array){
	if(array == NULL){
		return;
	}
	
	for(int i = 0; i < SIZE; i++){
		array[i] = rand()%500;
	}
}

void show_data(int *array){
	if(array == NULL){
		return ;
	}

	for(int i = 0; i < SIZE; i++){
		printf("array[%d] = %d\n", i, array[i]);
	}
}

void insert_sort(int *array){
	if(array == NULL){
		return ;
	}

	int j = 0;
	for(int i = 0; i < SIZE - 1; i++){
		int temp = array[i + 1];
		for(j = i + 1; j > 0 && temp < array[j - 1]; j--){
			array[j] = array[j - 1];
		}
		array[j] = temp;
	}
}

int main(){
	int array[SIZE] = {0};
	input_data(array);
	printf("insert_sort--init_data:\n");
	show_data(array);
	insert_sort(array);
	printf("insert_sort--after:\n");
	show_data(array);
	return 0;
}
