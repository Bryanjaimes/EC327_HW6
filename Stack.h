#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template<typename T>
class Stack
{
    public:
        Stack();
        bool isEmpty() const;
        void push(T value);
        T pop();
        int getSize() const;
    private:
        T * elements;
        int size;
};

#endif