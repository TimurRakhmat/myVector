#pragma once

#include <memory>
#include "myiter.h"
#include <cassert>

class MyVector
{
private:
    unsigned _size = 0;
    unsigned _capacity = 0;
    std::unique_ptr<int[]> _data;

public:
    typedef MyIter<int> iterator;
    typedef MyIter<const int> const_iterator;

    // Member func
    MyVector();
    ~MyVector();
    MyVector& operator=(const MyVector& vec);

    // Element access
    int& at(unsigned int pos);
    int& operator[](unsigned int pos);
    int& operator[](unsigned int pos) const;

    int& front();
    int& back();
    int* data();

    // Iters
    iterator begin();
    const_iterator cbegin();
    iterator end();
    const_iterator cend();

    // Capacity
    bool empty() const;
    unsigned size() const;
    unsigned max_size() const;
    unsigned capacity() const;

    // Modifiers
    iterator erase(iterator);
    void push_back(const int&);

};
