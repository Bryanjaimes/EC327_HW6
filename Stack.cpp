#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
Stack<T>::Stack()
{
    this->size = 0;
    this->elements = new T[25];
}

template<typename T>
bool Stack<T>::isEmpty() const
{
    if (this->size == 0)
        return true;
    else
        return false;
}

template<typename T> 
void Stack<T>::push(T value)
{
    if (this->size < 24)
        this->elements[this->size++] = value;
}

template<typename T>
T Stack<T>::pop()
{
    T temp = this->elements[size - 1];
    T * old = elements;
    this->elements = new T[25];
    for (int i = 0; i < size - 1; i++)
        elements[i] = old[i];

    delete [] old;
    this->size--;
    return temp;
}

template<typename T>
int Stack<T>::getSize() const
{
    return this->size;
}

template class Stack<int>;
template class Stack<double>;
template class Stack<string>;
template class Stack<float>;
template class Stack<char>;