#include<iostream>
#include <vector>
#include <time.h>

using namespace std;

#define MAX 10

void showArr(vector<int>& arr)
{
	for (auto& it : arr)
		cout << it << " ";
	cout << endl;
}

//插入排序
void insertSort(vector<int>& arr)
{
	int j, temp;;
	for (size_t i = 1; i < arr.size(); i++)
	{
		j = i-1;
		temp = arr[i];
		while (j>=0&&arr[j]>temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		if (j!=i-1)
		{
			arr[j+1] = temp;
		}
	}
}
//希尔排序
void shellSort(vector<int>& arr)
{
	int len = arr.size();
	int step = len;
	int tmp;
	int k;
	do
	{
		step = step / 3 + 1;
		for (size_t i = 0; i < step; i++)
		{
			for (int j = step + i; j < len; j += step)
			{
				tmp = arr[j];
				k = j - step;
				while (k >= 0 && arr[k] > tmp)
				{
					arr[k + step] = arr[k];
					k -= step;
				}
				if (k!=j-step)
				{
					arr[k + step] = tmp;
				}
			}
		}
	} while (step>1);
}

//冒泡排序
void bubbleSort(vector<int>& arr)
{
	int len = arr.size();
	for (size_t i = 0; i < len-1; i++)
	{
		for (int j = len-1; j > i; j--)
		{
			if (arr[j]<arr[j-1])
			{
				swap(arr[j], arr[j - 1]);
			}
		}
	}
}
//快速排序	//划分函数
int partion(vector<int>& arr, int i, int j)
{
	int tmp = arr[i];//以最左元素为划分值
	while (i<j)
	{
		while (i < j&&arr[j] >= tmp) j--;
		arr[i] = arr[j];
		while (i<j&&arr[i]<tmp) i++;
		arr[j] = arr[i];
	}
	arr[i] = tmp;
	return i;
}
//快排函数
void quickSort(vector<int>& arr, int begin, int end)
{
	if (begin>=end)
	{
		return;
	}
	int pos = partion(arr, begin, end);
	
	quickSort(arr, begin, pos-1);
	quickSort(arr, pos+1, end);
}

//选择排序
void selectSort(vector<int>& arr)
{
	for (size_t i = 0; i < arr.size()-1; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[j]<arr[i])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}

//堆排序(大顶堆小顶堆)
//堆化
void heapT2B(vector<int>& arr, int index, int len)
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
		swap(arr[max], arr[index]);
		index = max;
	}
}
//建堆
void buildHeap(vector<int>& arr,int len)
{
	for (int i = len / 2 - 1; i > -1; i--)
	{
		heapT2B(arr, i, len);
	}
}
void heapSort(vector<int>& arr)
{
	int len = arr.size();
	buildHeap(arr, len);
	for (int i = len - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		heapT2B(arr,0, --len);
	}
}

//归并排序
void mergeArray(vector<int>& arr, int left,int mid, int right,vector<int>& tmp)
{	
	int i = left;
	int j = mid+1;
	int length = 0;
	while (i<=mid&&j<=right)
	{
		if (arr[i]<=arr[j])
		{
			tmp[length++]=arr[i++];
		}
		else
		{
			tmp[length++] = arr[j++];
		}
	}
	while (i<=mid)
	{
		tmp[length++] = arr[i++];
	}
	while (j<=right)
	{
		tmp[length++] = arr[j++];
	}
	for (size_t i = left; i <= right; i++)
	{
		arr[i] = tmp[i - left];
	}	
}
void mergeSort(vector<int>& arr, int left, int right, vector<int>& tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) >> 1;

	mergeSort(arr, left, mid, tmp);
	mergeSort(arr, mid + 1, right, tmp);

	mergeArray(arr, left, mid, right, tmp);
}

int main()
{
	srand((unsigned int)time(NULL));
	vector<int> arr;
	vector<int> tmp(MAX);
	
	for (int i = 0; i < MAX; i++)
	{
		arr.push_back(rand() % 10);
	}
	showArr(arr);
	heapSort(arr);
	showArr(arr);

	return 0;
}