#include <iostream>
using namespace std;

void quickSort(int*, int, int);
int partition(int* vector, int start, int end);

int main() {
	int length = 9;
	int* vector = new int[length]{8, 2, 5, 3, 9, 4, 7, 6, 1};

	quickSort(vector, 0, length - 1);

	for (int i = 0; i < length; i++)
	{
		cout << *(vector + i) << " ";
	}

	delete[] vector;

	return 0;
}

void quickSort(int* vector, int start, int end) {
	if (end <= start) { return; }

	int pivot = partition(vector, start, end);

	quickSort(vector, start, pivot - 1);
	quickSort(vector, pivot + 1, end);
}

int partition(int* vector, int start, int end) {
	int pivot = vector[end];
	int i = start - 1;

	for (int j = start; j <= end - 1; j++)
	{
		if (vector[j] < pivot) {
			i++;
			swap(vector[i], vector[j]);
		}
	}

	i++;
	swap(vector[i], vector[end]);

	return i;
}