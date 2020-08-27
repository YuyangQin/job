#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void mergeArr(int a[], int begin, int mid, int end, int temp[])
{
	int i = begin;
	int j = mid + 1;
	int length = 0;
	while (i <= mid&&j <= end)
	{
		if (a[i] <= a[j])
			temp[length++] = a[i++];
		else
			temp[length++] = a[j++];
	}
	while (i <= mid)
		temp[length++] = a[i++];
	while (j <= end)
		temp[length++] = a[j++];
	for (int i = 0; i < length; i++)
	{
		a[begin + i] = temp[i];
	}
}

void mergeSort(int a[], int begin, int end, int temp[])
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;

	mergeSort(a, begin, mid, temp);
	mergeSort(a, mid+1, end, temp);

	mergeArr(a, begin, mid, end, temp);
}



void main01()
{
	int a[] = { 9,5,0,3,7,8,41,2,1 };
	int size = sizeof(a) / sizeof(a[0]);
	int *temp = new int[size];
	mergeSort(a, 0, size - 1, temp);
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
