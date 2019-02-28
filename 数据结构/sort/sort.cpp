#include <iostream>

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Print(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

// 冒泡
void bubbleSort(int *array, int size)
{
	int change = 0;
	for (int i = 0; i < size - 1; i++)
	{
		change = 0;
		for (int j = 1; j < size - i; j++)
		{
			if (array[i] < array[j+i])
			{
				Swap(array[i], array[j+i]);
				change = 1;
			}
		}
		if (change == 0)
			break;
	}
}

// 插入排序
void InsertSort(int *array, int size)
{
	int key = 0;
	for (int i = 1; i < size; i++)
	{
		key = array[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (array[j] >= key)
				break;
			array[j + 1] = array[j];
		}
	}
}

// 希尔排序
void ShellSort(int *array, int size)
{
	int gap = size;
	while (gap)
	{
		gap = gap / 3;
		for (int i = gap; i < size; i++)
		{
			for (int j = gap - 1; j >= 0; j++)
			{
				int key = array[j];
				if (array[j] >= key)
					break;
				
				array[j + gap] = key;
			}
		}
	}
}

// 选择排序
void SelectSort(int *array, int size)
{
	int min_pos = 0;
	for (int i = 0; i < size; i++)
	{
		min_pos = i;
		for (int j = i+1; j < size; j--)
		{
			if (array[min_pos] > array[j])
				min_pos = j;
			if (array[min_pos] < array[i])
				Swap(array[min_pos], array[i]);
		}
	}
}

// 堆排序
void Adjust(int *array, int size, int root)
{
	int parent = root;
	int child = parent * 2 + 1; 
	while (child < size)
	{
		if (child + 1 < size && array[child + 1] > array[child])
			++child;
		if (array[child] > array[parent])
		{
			Swap(array[child], array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int *array, int size)
{
	for (int i = (size-2)/2; i >= 0; --i)
	{
		Adjust(array, size, i);
	}
	int end = size - 1;
	while (end > 0)
	{
		Swap(array[end], array[0]);
		Adjust(array, end, 0);
		--end;
	}
}
// 快速排序
int Partion(int *array, int left, int right)
{
	int begin = left;
	int end = right;
	int key = array[right];
	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
			++begin;
		while (begin < end && array[end] >= key)
			--end;
		if (begin < end)
			Swap(array[begin], array[end]);
	}
	Swap(array[begin], array[right]);
	return begin;
}

void QuickSort(int *array, int left, int right)
{
	if (left >= right)
		return;
	int div = Partion(array, left, right);
	QuickSort(array, left, div - 1);
	QuickSort(array, div + 1, right);
}

// 归并排序
void _Merge(int *array, int left, int right, int * temp)
{
	if (left >= right)
		return;
	int mid = left + ((right - left) >> 1);
	_Merge(array, left, mid, temp);
	_Merge(array, mid + 1, right, temp);
	int first_begin = left, first_end = mid;
	int second_begin = mid + 1, second_end = right;
	int index = left;
	while (first_begin <= first_end && second_begin <= second_end)
	{
		if (array[first_begin] < array[second_begin])
			temp[index++] = array[first_begin++];
		else
			temp[index++] = array[second_begin++];
	}
	while (first_begin <= first_end)
		temp[index++] = array[first_begin++];
	while (second_begin <= second_end)
		temp[index++] = array[second_begin++];

	index = left;
	while (index <= right)
	{
		array[index] = temp[index];
		++index;
	}
}

void MergeSort(int *array, int size)
{
	int *temp = (int *)malloc(sizeof(int)*size);
	_Merge(array, 0, size - 1, temp);
	free(temp);
}

int main()
{
    int array[] = { 5, 4, 3, 2, 1  };
    int size = sizeof(array)/sizeof(array[0]);
    MergeSort(array, size);
    Print(array, size);
    return 0;
}
