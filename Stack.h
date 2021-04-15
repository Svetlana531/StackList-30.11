#pragma once
#include <list>
#include <string>
#include <fstream>
#include <iostream>

template<class T>
class Stack
{
private:
	std::list<T> list;
public:
	void push(T val);
	void pop();
	bool empty();
	int size();
	T Top();

	T FindMin();
	T FindMax();

	void OutputFile(std::string path);
	void FromFile(std::string path);

	void print();
};

template<class T>
void Stack<T>::push(T val)
{
	list.push_front(val);
}

template<class T>
void Stack<T>::pop()
{
	if (empty()) { throw std::out_of_range("Stack is empty"); }
	list.pop_back();
}

template<class T>
bool Stack<T>::empty()
{
	if (list.size() == 0) { return true; }
	else { return false; }

}

template<class T>
int Stack<T>::size()
{
	return list.size();
}

template<class T>
T Stack<T>::Top()
{
	if (empty()) { throw std::out_of_range("Stack is empty"); }
	return list.back();
}

template<class T>
T Stack<T>::FindMin()
{
	if (empty()) { throw std::out_of_range("Stack is empty"); }
	int countElements = size();
	Stack<T> tmp;
	T min = Top();

	for (int i = 0; i < countElements; i++)
	{
		if (Top() < min) { min = Top(); }
		tmp.push(Top());
		pop();
	}
	for (int i = 0; i < countElements; i++)
	{
		T tmpVal = tmp.Top();
		push(tmpVal);
		tmp.pop();
	}
	return min;
}

template<class T>
T Stack<T>::FindMax()
{
	if(empty()) { throw std::out_of_range("Stack is empty"); }
	int countElements = size();
	Stack<T> tmp;
	T max = Top();

	for (int i = 0; i < countElements; i++)
	{
		if (Top() > max) { max = Top(); }
		tmp.push(Top());
		pop();
	}
	for (int i = 0; i < countElements; i++)
	{
		T tmpVal = tmp.Top();
		push(tmpVal);
		tmp.pop();
	}
	return max;
}

template<class T>
void Stack<T>::OutputFile(std::string path)
{
	if (empty()) { throw std::out_of_range("Stack is empty"); }
	std::fstream fs;
	fs.open(path, std::ios::out | std::ios::trunc);
	if (!fs.is_open())
	{
		std::cout << "Error open file!" << std::endl;
	}
	else
	{
		int countElements = size();
		Stack<T> tmp;
		for (int i = 0; i < countElements; i++)
		{
			tmp.push(Top());
			pop();
		}
		for (int i = 0; i < countElements; i++)
		{
			T tmpVal = tmp.Top();
			push(tmpVal);
			fs << tmpVal << " ";
			tmp.pop();
		}
		std::cout << "File opened and rewritten!" << std::endl;
	}
	fs.close();
}

template<class T>
void Stack<T>::FromFile(std::string path)	// only int
{
	std::fstream fs;
	fs.open(path, std::ios::in | std::ios::app);
	if (!fs.is_open())
	{
		std::cout << "Error open file!" << std::endl;
	}
	else
	{
		std::string str;
		std::string num;
		getline(fs, str);

		for (int i = 0; i < str.size(); i++)
		{
			if (((str[i] == 45) || ((int(str[i]) > 47) && (int(str[i] < 58)))))
			{
				num += str[i];
			}
			else
			{
				push(atoi(num.c_str()));
				num.clear();
			}
		}
	}
	fs.close();
}


template<class T>
void Stack<T>::print()
{
	if (empty()) { throw std::out_of_range("Stack is empty"); }
	int countElements = size();
	Stack<T> tmp;
	for (int i = 0; i < countElements; i++)
	{
		tmp.push(Top());
		pop();
	}
	for (int i = 0; i < countElements; i++)
	{
		T tmpVal = tmp.Top();
		push(tmpVal);
		std::cout << tmpVal << " ";
		tmp.pop();
	}
}