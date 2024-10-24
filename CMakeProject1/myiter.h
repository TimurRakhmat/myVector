#pragma once

template<typename ValueType>
class MyIter
{
    friend class MyVector;
private:
    MyIter(ValueType* p);
public:
    explicit MyIter(const MyIter& it);

    bool operator!=(MyIter const& other) const;
    ValueType& operator*() const;
    MyIter& operator++();
    MyIter& operator--();

    MyIter operator+(int) const;
    MyIter& operator+=(int);
private:
    ValueType* p;
};

template <typename ValueType>
MyIter<ValueType>::MyIter(ValueType* p) : p(p)
{
}

template <typename ValueType>
MyIter<ValueType>::MyIter(const MyIter& it) : p(it.p)
{
}

template <typename ValueType>
bool MyIter<ValueType>::operator!=(MyIter const& other) const
{
    return p != other.p;
}

template <typename ValueType>
ValueType& MyIter<ValueType>::operator*() const
{

    return *p;
}

template <typename ValueType>
MyIter<ValueType>& MyIter<ValueType>::operator++()
{
    ++p;
    return *this;
}

template <typename ValueType>
MyIter<ValueType>& MyIter<ValueType>::operator--()
{
    --p;
    return *this;
}

template<typename ValueType>
inline MyIter<ValueType> MyIter<ValueType>::operator+(int count) const
{
    return MyIter(p + count);
}

template<typename ValueType>
MyIter<ValueType>& MyIter<ValueType>::operator+=(int count)
{
    p =p + count;
    return *this;
}
