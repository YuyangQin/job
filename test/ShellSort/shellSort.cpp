#include <iostream>
#include <time.h>
#include <sys/timeb.h>

using namespace std;

#define MAX 10

long getTime()
{
	struct timeb t;
	ftime(&t);
	return t.time * 1000 + t.millitm;
}

void shellSort1(int arr[MAX])
{
	int increasement = MAX;
	int k = 0;
	
	do
	{
		increasement = increasement / 3 + 1;
		for (int i = 0; i < increasement; i++)
		{
			for (int j = i + increasement; j < MAX; j += increasement)
			{
				int temp = arr[j];
				for (k = j - increasement; (k >= 0) && (temp < arr[k]); k -= increasement)
				{
					arr[k + increasement] = arr[k];
				}
				arr[k+increasement] = temp;
			}
		}
	} while (increasement>1);
}

void quickSort(int arr[], int st, int end)
{
	int temp = arr[st];
	int i = st;
	int j = end;
	if (i < j)
	{
		while (i < j)
		{
			while ((i<j) && (arr[j] >= temp))
			{
				j--;
			}
			if (i<j)
			{
				arr[i] = arr[j];
				i++;
				while ((i<j) && (arr[i]<temp))
				{
					i++;
				}
				if (i<j)
				{
					arr[j] = arr[i];
					j--;
				}
			}
		}
		arr[i] = temp;
		//µÝ¹é×ó°ë²¿·Ö
		quickSort(arr, st, i - 1);
		//µÝ¹éÅÅÐòÓÒ°ë²¿·Ö
		quickSort(arr, i + 1, end);
	}
}


void showArray(int arr[MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main()
{
	srand((unsigned int)time(NULL));
	int arr[MAX];

	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % 10;
	}

	//long startT = getTime();
	showArray(arr);
	shellSort1(arr);
	//quickSort(arr,0,MAX-1);
	showArray(arr);
	//long endT = getTime();
	//cout << endT - startT << endl;

	return 0;
}