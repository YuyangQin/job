#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//swap
void swap(int arr[], int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

//¶Ñ»¯
void heapT2B(int arr[], int index, int len)
{
	while (true)
	{
		int max = index;
		int left = index * 2 + 1;
		int right = index * 2 + 2;

		if (left<len&&arr[left]>arr[max])
			max = left;
		if (right<len&&arr[right]>arr[max])
			max = right;
		if (max == index)
			break;
		swap(arr, max, index);
		index = max;
	}
}

//½¨¶Ñ
void heapBuild(int arr[], int len)
{
	for (int i = len/2-1; i > -1; i--)
	{
		heapT2B(arr, i, len);
	}
}

//¶ÑÅÅÐò
void heapSort(int arr[], int len)
{
	heapBuild(arr, len);
	for (int i = len - 1; i > 0; i--)
	{
		swap(arr,0, i);
		heapBuild(arr, --len);
	}
}

void myPrint(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void main1()
{
	int arr[] = { 4,5,1,6,3,2,7 };
	int len = sizeof(arr) / sizeof(int);
	myPrint(arr, len);
	heapSort(arr, len);
	myPrint(arr, len);
}
