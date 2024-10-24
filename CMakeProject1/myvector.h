#pragma once

#include <memory>
#include "myiter.h"
#include <cassert>

template<class T>
class MyVector
{
private:
    unsigned _size = 0;
    unsigned _capacity = 0;
    std::unique_ptr<T[]> _data;

public:
    typedef MyIter<T> iterator;
    typedef MyIter<const T> const_iterator;

    // Member func
    MyVector();
    ~MyVector();
    MyVector& operator=(const MyVector& vec);

    // Element access
    T& at(unsigned int pos);
    T& operator[](unsigned int pos);
    T& operator[](unsigned int pos) const;
    T& front();
    T& back();
    T* data();

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
    void push_back(const T&);

};

template<class T>
MyVector<T>::MyVector()
{
}

template<class T>
MyVector<T>::~MyVector()
{
}

template<class T>
MyVector<T>& MyVector<T>::operator=(const MyVector& vec)
{
    _size = vec._size;
    _capacity = vec._capacity;
    _data = std::make_unique<int[]>(_capacity);
    for (int i = 0; i < _size; i++) {
        _data[i] = vec._data[i];
    }

    return *this;
}

template<class T>
T& MyVector<T>::at(unsigned int pos)
{
    assert(pos < _size);
    return *(_data.get() + pos);
}

template<class T>
T& MyVector<T>::operator[](unsigned int pos)
{
    return *(_data.get() + pos);
}

template<class T>
T& MyVector<T>::operator[](unsigned int pos) const
{
    return *(_data.get() + pos);
}
template<class T>
T& MyVector<T>::front()
{
    return *(_data.get());
}

template<class T>
T& MyVector<T>::back()
{
    return _data.get()[_size];
}

template<class T>
T* MyVector<T>::data()
{
    return _data.get();
}

template<class T>
MyVector<T>::iterator MyVector<T>::begin()
{
    return iterator(_data.get());
}

template<class T>
MyVector<T>::const_iterator MyVector<T>::cbegin()
{
    return const_iterator(_data.get());
}

template<class T>
MyVector<T>::iterator MyVector<T>::end()
{
    return iterator(_data.get() + _size);
}

template<class T>
MyVector<T>::const_iterator MyVector<T>::cend()
{
    return const_iterator(_data.get() + _size);
}

template<class T>
bool MyVector<T>::empty() const
{
    return _size == 0;
}

template<class T>
unsigned MyVector<T>::size() const
{
    return _size;
}

template<class T>
unsigned MyVector<T>::max_size() const
{
    return _capacity;
}

template<class T>
unsigned MyVector<T>::capacity() const
{
    return _capacity;
}

template<class T>
MyVector<T>::iterator MyVector<T>::erase(iterator itr)
{
    int index = itr - begin();
    assert(0 < index < _size);

    _size--;
    auto enditr = end();
    auto nextr = itr + 1;

    for (; nextr != enditr; ++nextr, ++itr) {
        *itr = std::move(*nextr);
    }

    return begin() + index + 1;
}

template<class T>
void MyVector<T>::push_back(const T& value)
{
    if (_size == _capacity) {
        unsigned old_cap = _capacity;
        if (_capacity != 0)
            _capacity *= 2;
        else
            _capacity = 1;

        auto temp = std::make_unique<T[]>(_capacity);
        for (int i = 0; i < old_cap; i++) {
            temp[i] = std::move(_data[i]);
        }

        _data = std::move(temp);
    }

    _data[_size] = value;
    _size++;
}