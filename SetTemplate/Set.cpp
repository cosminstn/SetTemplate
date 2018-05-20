#include "stdafx.h"
#include "Set.h"


template<class T> Set<T>::Set(){
	cSize = 0;
	arr = new T[cSize];
}

template<class T> Set<T>::Set(int newSize) {
	cSize = newSize;
	arr = new T[cSize];
}

template<class T> Set<T>::Set(const Set &copy) {
	cSize = copy.cSize;
	arr = new T[copy.cSize];
	for (int i = 0; i < cSize; i++)
		arr[i] = copy.arr[i];
}

template<class T> void Set<T>::insert(T val) {
	//search if the element is already in the arr
	for (int i = 0; i < cSize; i++)
		if (arr[i] == val) break;
	//get the position to insert the element at
	int poz = 0; 
	for (int i = 0; i < cSize; i++)
		if (arr[i] < val)
			poz++;
	//copy the old array into a new array
	T *aux = new T[cSize + 1];
	for (int i = 0; i < poz; i++)
		aux[i] = arr[i];
	//insert the new element
	aux[poz] = val;
	for (int i = val + 1; i < cSize + 1; i++)
		aux[i] = arr[i - 1];
	//insert the new value on the last position
	aux[cSize] = val;
	//copy the new formed array into the arr pointer
	//increase cSize
	cSize++;
	arr = new T[cSize];
	for (int i = 0; i < cSize; i++)
		arr[i] = aux[i];
	delete[] aux;
}

template<class T> void Set<T>::deleteAt(int poz) {
	if (poz >= 0 && poz < cSize) {
		//a[poz] <-- a[poz+1], ..., a[cSize - 1]
		for (int i = poz; i < cSize - 1; i++)
			arr[i] = arr[i + 1];
		//decrease the cSize
		cSize--;
	}
}

template<class T> int Set<T>::indexOf(T) {
	//searches for an element in the arr
	//returns it's position or -1 if not found
	for (int i = 0; i < cSize; i++)
		if (arr[i] == T)
			return i;
	return -1;
}

template<class T> int Set<T>::count() {
	return cSize;
}

template<class T> T& Set<T>::operator[](int poz) {
	if(poz > 0 && poz < cSize)
		return arr[poz];
	return null;
}

template<class T> Set<T> Set<T>::operator+(const Set<T> &op2) {
	Set<T> newSet = (*this);
	for (int i = 0; i < op2.cSize; i++)
		newSet.insert(op2[i]);
	return newSet;
}

template<class T> bool Set<T>::operator<(const Set<T> &op2) {
	return cSize < op2.cSize;
}

template<class T> bool Set<T>::operator>(const Set<T> &op2) {
	return cSize > op2.cSize;
}

template<class T> bool Set<T>::operator==(const Set<T> &op2) {
	if (cSize == op2.cSize) {
		for (int i = 0; i < cSize; i++)
			if (arr[i] != op2.arr[i])
				return false;
		return true;
	}
	return false;
}

template<class T> std::ostream& operator<<(std::ostream& out, const Set<T>& op) {
	for (int i = 0; i < op.size; i++)
		out << op[i];
	return out;
}

template<class T> std::istream& operator>>(std::istream& in, Set<T>& op) {
	for (int i = 0; i < op2.size; i++)
		in >> op[i];
	return in;
}

template<class T> Set<T>& Set<T>::operator=(const Set<T> &op2) {
	cSize = op2.size;
	for (int i = 0; i < cSize; i++)
		arr[i] = op2.arr[i];
	return (*this);
}

template<class T> Set<T>::~Set() {
	cSize = 0;
	delete[]arr;
}
