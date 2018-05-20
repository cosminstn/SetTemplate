#pragma once
#include "stdafx.h"
#include <iostream>
template <class T> class Set
{
private:
	int cSize;
	T *arr;
public:
	Set();
	Set(int);
	Set(const Set&);
	~Set();

	void insert(T);
	void deleteAt(int);
	int indexOf(T);
	int count();
	T& operator[](int);
	Set<T> operator+(const Set<T>&);
	Set<T>& operator=(const Set<T>&);
	bool operator>(const Set<T>&);
	bool operator<(const Set<T>&);
	bool operator==(const Set<T>&);
	friend std::istream &operator>>(std::istream&, Set<T>&);
	friend std::ostream &operator<<(std::ostream&, const Set<T>&);
};

