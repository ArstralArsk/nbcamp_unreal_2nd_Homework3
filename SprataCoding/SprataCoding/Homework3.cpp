#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;
public:
	void resize(int newCapacity)
	{
		if (newCapacity > currentCapacity)
		{
			T* newData = new T[newCapacity];
			for (int i = 0; i < currentCapacity; i++)
			{
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			currentCapacity = newCapacity;
		}
	}
	SimpleVector(int capacity = 10) : currentCapacity(capacity) {
		data = new T[currentCapacity];
	}

	SimpleVector(const SimpleVector& other) {
		currentSize = other.currentSize;
		currentCapacity = other.currentCapacity;
		data = new T[currenctCapacity];
		for (int i = 0; i < currentSize; i++)
		{
			data[i] = other.data[i];
		}
	}

	~SimpleVector() { delete[] data; }

	void push_back(const T& t) {
		if (currentSize == currentCapacity)
		{
			resize(currentCapacity + 5);
		}
		data[currentSize] = t;
	}

	void pop_back()
	{
		if (currentSize > 0)
		{
			currentSize--;
		}
	}

	int size()
	{
		return currentSize;
	}

	int capacity()
	{
		return currentCapacity;
	}

	void sortData()
	{
		sort(data, data+this->size());
	}
};