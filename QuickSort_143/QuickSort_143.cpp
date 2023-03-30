#include <iostream>
using namespace std;


int arr[20];                   //array of integers to hold velues
int cmp_count = 0;             //number of comparasion
int mov_count = 0;             //number of data movements
int n;

void input() {
	while (true)
	{
		cout << "Masukan panjang elemnet array : ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}

	cout << "\n==================" << endl;
	cout << "\nEnter Array Elemet" << endl;
	cout << "\n------------------" << endl;


	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}

//swaps the element st index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}


void q_short(int low, int high)
{
	int pivot, i, j;                                      //Langkah Algoritma No. 1
	if (low > high)
		return;

	//Partition the list into two parts:
	//one containing element lss that or equal ti pivot
	//Oouther conntaining elements greather than pivot

	pivot = arr[low];                                     //Langkah Algoritma No. 2

	i = low + 1;                                          //Langkah Algoritma No. 3
	j = high;                                             //Langkah Algoritma No. 4


	while (i <= j)                                        //Langkah Algoritma No. 10
	{
		//search for an element greather than pivot
		while ((arr[i] <= pivot) && (i <= high))          //Langkah Algoritma No. 5
		{
			i++;                                          //Langkah Algoritma No. 6
			cmp_count++;
		}
		cmp_count++;

		//search for an element less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low))             //Langkah Algoritma No. 7
		{
			j--;                                            //Langkah Algoritma No. 8
			cmp_count++;
		}
		cmp_count++;

		//if the greather element is on the left of the element
		if (i < j)                                          //Langkah Algoritma No. 9
		{
			//swap the element at index i with the element at index j
			swap(i, j);
			mov_count++;
		}
	}
	//j now containt the index of the last element in the sorted list
	if (low < j)                                            //Langkah Algoritma No. 11
	{
		//move the pivot to its correct pasition in the list
		swap(low, j);
		mov_count++;
	}
	