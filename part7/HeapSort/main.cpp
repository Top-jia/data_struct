#include<stdio.h>

void adjustHeap(int paraml, int j, int isNums[]){
	int temp = isNums[paraml];
	for(int k = paraml*2+1; k < j; k = k*2+1){
		if(k+1 < j && isNums[k] < isNums[k+1]){
			k++;
		}

		if(isNums[k] > temp){
			isNums[paraml] = isNums[k];
				paraml = k;
		}
		else{
			break;
		}
	}
	isNums[paraml] = temp;
}


void HeapSort(int nums, int isNums[]){
	for(int i = nums/2-1; i >= 0; i--){
		adjustHeap(i, nums, isNums);
	}
	
	for(int j = nums-1; j > 0; j--){
		int temp = isNums[0];
		isNums[0] = isNums[j];
		isNums[j] = temp;

		adjustHeap(0, j, isNums);
	}

}

int main(){
	int data[] = {6, 5, 8, 4, 7, 9, 1, 3, 2};
	int len = sizeof(data)/sizeof(data[0]);
	HeapSort(len, data);
	return 0;
}
