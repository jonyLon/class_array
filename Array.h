#pragma once
#include <iostream>
using namespace std;
class Array
{
private:
	size_t size = 0;
	int* arr = nullptr;
public:
	Array() = default;
	template <typename... Args>
	Array(size_t sizeArr, Args... args) {
		this->size = sizeArr;
		int argsArr[] = { args ... };
		this->arr = new int[getSize()] {};
		for (size_t i = 0; i < this->size; i++)
		{
			this->arr[i] = argsArr[i];
		}
	}
	Array(Array& other) : size(other.size), arr(new int[size] {}){
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}
	~Array() {
		if (this->arr != nullptr) {
			delete[] this->arr;
		}
	}
	void operator =(Array& other)  {
		this->size = other.size;
		this->arr = new int[this->size] {};
		for (size_t i = 0; i < size; i++)
		{
			this->arr[i] = other.arr[i];
		}
	}
	inline const size_t &getSize() const {
		return this->size;
	}
	const void setSize(size_t size) {
		int* update = new int[size] {};
		for (size_t i = 0; i < this->size; i++)
		{
			update[i] = this->arr[i];
		}
		this->size = size;
		this->arr = update;
	}
	inline const int getElementAt(size_t index) const{
		if (index > getSize()) {
			cout << "Index error" << endl;
		} else return this->arr[index];
	}
	inline void setElementAt(size_t index, int elem) {
		if (index > getSize()) {
			cout << "Index error" << endl;
			return;
		}
		this->arr[index] = elem;
	}
	void quickSort(int arr[], int low, int high) {
		if (low < high) {
			int pivotIndex = partition(arr, low, high);
			quickSort(arr, low, pivotIndex - 1);
			quickSort(arr, pivotIndex + 1, high);
		}
	}
	int partition(int arr[], int low, int high) {
		int pivot = arr[high];
		int i = (low - 1);

		for (int j = low; j <= high - 1; j++) {
			if (arr[j] < pivot) {
				i++;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i + 1], arr[high]);
		return (i + 1);
	}
	void sort() {
		int* arr = this->arr;
		int start = 0, end = getSize() - 1;
		quickSort(arr, start, end);
	}
	int min() {
		int min = getElementAt(0);
		for (size_t i = 1; i < getSize(); i++)
		{
			if (min > getElementAt(i))
			{
				min = getElementAt(i);
			}
		}
		return min;
	}
	int max() {
		int max = getElementAt(0);
		for (size_t i = 1; i < getSize(); i++)
		{
			if (max < getElementAt(i))
			{
				max = getElementAt(i);
			}
		}
		return max;
	}

	void print() {
		cout << "Array size: " << this->size << endl;
		cout << "Array items: "<<endl;
		for (size_t i = 0; i < getSize(); i++)
		{		
			cout << getElementAt(i) << "\t";
		}
		cout << endl;
	}
};

