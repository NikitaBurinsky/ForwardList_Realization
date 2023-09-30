#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;


template <class T>
class List
{
public:
	T& operator[](const int index);
	T& operator=(T newData);
	List()
	{
		pHead = nullptr;
		size = 0;
	}
	~List()
	{
		this->clear();
	}
	void push_back(T aData);
	void pop_back();
	void pop_front();
	void insert(int index, T aData);
	void erase(int index);
	void DEBUG();
	void clear();
	T& back();
	T& front();
	void merge(List<T> &target); // Параметр - цель, Вызывающий обьект - откуда
	void remove(T value);
	void removeif(bool(*Condition)(T value));
	void resize(int newSize, int value = 0);
	void sort();
	void swap(List<T> &target);
	void push_front(T data);
	int size;

private:	

	template <class T>
	class Node
	{

	public:
		Node<T>* pNext;
		T data;
		inline Node(T aData = T(), Node<T>* pNext = nullptr)
		{
				this->data = aData;
				this->pNext = pNext;
		}
		inline ~Node()
		{}
	};
	Node<T>* pHead;
};



//Operators Overloading
template <class T>
T& List<T>::operator[](const int index)
{
	int count = 0;
	Node<T>* current = this->pHead;
	while(current != nullptr)
	{
		if (count == index)
		{
			return current->data;
		}
		current = current->pNext;
		count++;
	}
}
template <class T>
T& List<T>::operator=(T newData)
{
	this = newData;
}

//List Methods
template <class T>
void List<T>::push_back(T aData)
{
	if (size > 0)
	{
		Node<T>* current = pHead;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
			current->pNext = new Node<T>(aData);
	}

	else if (pHead == nullptr)
	{
		pHead = new Node<T>(aData);
	}
	size++;
}

template <class T>
void List<T>::pop_back()
{
	Node<T>* current = pHead;
	int count = 0;
	while (count < size)
	{
		current = current->pNext;
		++count;
	}
	if (current == pHead)
		pHead = nullptr;
	delete current;
	size--;
}

template<class T>
void List<T>::pop_front()
{
	if (size > 1)
	{
		auto temp = pHead->pNext;
		delete pHead;
		pHead = temp;
		--size;
	}
	else if (size == 1)
	{
		delete pHead;
		size = 0;
		pHead = nullptr;
	}

}

template <typename T>
void List<T>::insert(int index, T aData)
{
	Node<T>* current = pHead;
	for (int i = 1; i < index; i++)
	{
		current = current->pNext;
	};
	Node<T>* temp = current->pNext;
	current->pNext = new Node<T>(aData, temp);
	current->pNext->pNext = temp;
	size++;
}

template <typename T>
void List<T>::erase(int index)
{
	Node<T>* current = pHead;
	for (int i = 1; i < index; i++)
	{
		current = current->pNext;
	}
	if (current->pNext != nullptr)
	{
		Node<T>* temp = current->pNext->pNext;

		if (current == pHead)
		{
			pHead = current->pNext;
		}

		delete(current->pNext);
		current->pNext = temp;

		size--;
	}
}

template <class T>
void List<T>::DEBUG()
{
	cout << "\n---Debug Info--------------\n";
	auto iter = pHead;
	int i = 0;
	while (i < size)
	{
		cout << iter->data << "  ";
		iter = iter->pNext;
		++i;
	}
	cout << "\nList size: " << size;
	cout << "\nList weigth: " << sizeof(this) * size;
	cout << "\n---------------------------\n";
}

template <class T>
void List<T>::clear()
{
	while(size)
	{
		this->pop_back();
	}
}

template <class T>
T& List<T>::back()
{
	auto current = pHead;
	while (current->pNext != nullptr)
	{
		current = current->pNext;
	}
	return current->data;
}

template <class T>
T& List<T>::front()
{
	return pHead->data;
}

template <class T>
void List<T>::merge(List<T> &target)
{
	auto current = target.pHead;
	while (current->pNext != nullptr)
		current = current->pNext;
	current->pNext = this->pHead;
	this->pHead = nullptr;
	target->size += this->size;
	size = 0;
}

template<class T>
void List<T>::remove(T value)
{
	auto current = pHead;
	for (int i = 0; i < size; i++)
		if (current->data == value)
			this->erase(i);
		else
			current = current->pNext;
}

template<class T>
void List<T>::removeif(bool(*Condition)(T value))
{
	auto current = pHead;
	for (int i = 0; i < size; i++)
	{
		if (Condition(current->data))
		{
			cout << "\n" << current->data << "------\n";
			this->erase(i);
		}
		else
			current = current->pNext;
	}
}

template<class T>
void List<T>::resize(int newSize, int value)
{
	int count;
	if (size > newSize)
	{
		count = size - newSize;
		for (int i = 0; i < count; i++)
		{
			this->pop_back();
		}
	}
	else
	{
		count = newSize - size;
		for (int i = 0; i < count; i++)
		{
			this->push_back(value);
		}
	}
}

template<class T>
void List<T>::sort()
{
	T temp;
	for (int x = 0; x < size; x++)
	{
		for (int i = 0; i < size; i++)
		{
			if ((*this)[i] < (*this)[i - 1])
			{
				temp = (*this)[i];
				(*this)[i] = (*this)[i - 1];
				(*this)[i - 1] = temp;
			}
		}
	}
}

template<class T>
void List<T>::swap(List<T>& target)
{
	int t = size;
	size = target->size;
	target->size = t;
	auto temp = target.pHead;
	target.pHead = this->pHead;
	this->pHead = temp;

}

template<class T>
void List<T>::push_front(T data)
{
	auto temp = pHead;
	pHead = new Node<T>(data);
	pHead->pNext = temp;
	size++;
}
