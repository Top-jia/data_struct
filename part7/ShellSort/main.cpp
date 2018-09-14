#include<stdio.h>
#include<stdlib.h>

#define SIZE	10

void input_data(int *array){
	if(array == NULL){
		return ;
	}

	for(int i = 0; i < SIZE; i++){
		array[i] = rand()%100;
	}
}

void show_data(int *array){
	if(array == NULL){
		return;
	}

	for(int i = 0; i < SIZE; i++){
		printf("array[%d] = %d\n", i, array[i]);
	}
}

/*
 *	主要考虑增量的问题
 * */
void shell_sort(int *array){
	if(array == NULL){
		return ;
	}
	
	int incream = SIZE/2;
	int j = 0;
	for(; incream > 0; incream /= 2){
		for(int i = incream; i < SIZE; i++){
		
			int temp = array[i];
			for(j = i; j - incream >= 0 && temp < array[j - incream]; j -= incream){
				array[j] = array[j - incream];
			}
			array[j] = temp;
		}
	}
}

int main(){
	int array[SIZE] = {0};
	input_data(array);
	printf("shell_sort-- init_data:\n");
	show_data(array);
	shell_sort(array);
	printf("shell_sort-- after\n");
	show_data(array);
	return 0;
}
