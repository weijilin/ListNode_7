#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void swap(int *c, int *b){
	int temp = *c;
	*b = *c;
	*c = temp;
}

//直接插入排序
void insret(int a[], int size)
{
	for (int i = 0; i < size; i++){
		int k = a[i];
		int j;
		for (j = i - 1; j >= 0 && a[j] > k; j--){
			a[j + 1] = a[j];
		}
		a[j + 1] = k;
	}
}

//希尔排序
void shellsert(int a[], int size){
	int gap = size;
	while (1){
		gap = gap / 3 + 1;
		for (int i = 0; i < size; i++){
			int k = a[i];
			int j;
			for (j = i - gap; j >= 0 && a[j] < k; j -= gap){
				a[j + gap] = a[j];
			}
			a[j + gap] = k;
		}
		if (gap == 1){
			break;
		}
	}
}

//冒泡排序
void maopaosert(int a[], int size){
	for (int i = 0; i < size; i++){
		int s = 1;
		for (int j = 0; j < size - i - 1; j++){
			if (a[j] < a[j + 1]){
				swap(a + j, a + j + 1);
				s = 0;
			}
		}

		if (s == 1){
			break;
		}
	}
}
//快排
int partsort(int a[], int left,int right){
	int begin = left;
	int end = right;
	int pivot = a[right];
	while (begin < end) {
		while (begin < end && a[begin] <= pivot) {
			begin++;
		}
		while (begin < end && a[end] >= pivot) {
			end--;
		}
		swap(a + begin, a + end);
	}
	swap(a + begin, a + right);
	return begin;
}
//递归实现
#include<assert.h>
//void quicksort(int* a, int left, int right)
//{
//	assert(a);
//	if (left < right){
//		int div = partsort(a, left, right);
//		quicksort(a, left, div - 1);
//		quicksort(a, div - 1, right);
//	}
//
//}
void quickSortInternal(int a[], int left, int right) {
	if (left >= right) {
		// [left, right] 区间内只剩 1 或者 0 个数
		return;
	}
	// 1. 确定基准值，最右边	a[right]
	// 2. 做 partition，小的左，大的右，返回基准值最终的下标
	int pivotIndex = partsort(a, left, right);
	// 3. 分治处理左右两个小区间
	quickSortInternal(a, left, pivotIndex - 1);
	quickSortInternal(a, pivotIndex + 1, right);
}


void printfsert(int a[], int size){
	for (int i = 0; i < size; i++){
		printf("%d ", a[i]);
	}
	printf("\n");

}

int main()
{
	int a[] = {2,5,5,8,6,59,56,562,5,9532,66,6,56,7,3};
	int size = sizeof(a) / sizeof(0);
	//insret(a, size);
	//printfsert(a, size);
	//shellsert(a, size);
	//printfsert(a, size);
	//maopaosert(a, size);
	//printfsert(a, size);
	partsort(a,0 ,size-1);
	printfsert(a, size);
	system("pause");
	return 0;
}