#pragma once
template<class ValueType>
class MyVector;

template<class ValueType>
class MyIter
{
    friend class MyVector<ValueType>;
public:
    MyIter(ValueType* p);
public:
    MyIter(const MyIter& it);

    bool operator!=(MyIter const& other) const;
    ValueType& operator*() const;
    MyIter& operator++();
    MyIter& operator--();

    MyIter operator+(int) const;
    int operator-(const MyIter& itr) const;
    MyIter& operator+=(int);
private:
    ValueType* p;
};

template <class ValueType>
MyIter<ValueType>::MyIter(ValueType* p) : p(p)
{
}

template <class ValueType>
MyIter<ValueType>::MyIter(const MyIter& it) : p(it.p)
{
}

template <class ValueType>
bool MyIter<ValueType>::operator!=(MyIter const& other) const
{
    return p != other.p;
}

template <class ValueType>
ValueType& MyIter<ValueType>::operator*() const
{

    return *p;
}

template <class ValueType>
MyIter<ValueType>& MyIter<ValueType>::operator++()
{
    ++p;
    return *this;
}

template <class ValueType>
MyIter<ValueType>& MyIter<ValueType>::operator--()
{
    --p;
    return *this;
}

template<class ValueType>
inline MyIter<ValueType> MyIter<ValueType>::operator+(int count) const
{
    return MyIter(p + count);
}

template<class ValueType>
inline int MyIter<ValueType>::operator-(const MyIter& itr) const
{
    return p - itr.p;
}

template<class ValueType>
MyIter<ValueType>& MyIter<ValueType>::operator+=(int count)
{
    p =p + count;
    return *this;
}
