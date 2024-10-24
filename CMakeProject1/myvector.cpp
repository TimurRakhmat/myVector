//#include "myvector.h"
//
//MyVector::MyVector()
//{
//}
//
//MyVector::~MyVector()
//{
//}
//
//MyVector& MyVector::operator=(const MyVector& vec)
//{
//    _size = vec._size;
//    _capacity = vec._capacity;
//    _data = std::make_unique<int[]>(_capacity);
//    for (int i = 0; i < _size; i++) {
//        _data[i] = vec._data[i];
//    }
//
//    return *this;
//}
//
//int& MyVector::at(unsigned int pos)
//{
//    assert(pos < _size);
//    return *(_data.get() + pos);
//}
//
//int& MyVector::operator[](unsigned int pos)
//{
//    return *(_data.get() + pos);
//}
//
//int& MyVector::operator[](unsigned int pos) const
//{
//    return *(_data.get() + pos);
//}
//
//int& MyVector::front()
//{
//    return *(_data.get());
//}
//
//int& MyVector::back()
//{
//    return _data.get()[_size];
//}
//
//int* MyVector::data()
//{
//    return _data.get();
//}
//
//MyVector::iterator MyVector::begin()
//{
//    return iterator(_data.get());
//}
//
//MyVector::const_iterator MyVector::cbegin()
//{
//    return const_iterator(_data.get());
//}
//
//MyVector::iterator MyVector::end()
//{
//    return iterator(_data.get() + _size);
//}
//
//MyVector::const_iterator MyVector::cend()
//{
//    return const_iterator(_data.get() + _size);
//}
//
//bool MyVector::empty() const
//{
//    return _size == 0;
//}
//
//unsigned MyVector::size() const
//{
//    return _size;
//}
//
//unsigned MyVector::max_size() const
//{
//    return _capacity;
//}
//
//unsigned MyVector::capacity() const
//{
//    return _capacity;
//}
//
//MyVector::iterator MyVector::erase(iterator itr)
//{
//    int index = itr - begin();
//    assert(0 < index < _size);
//    
//    _size--;
//    auto enditr = end();
//    auto nextr = itr + 1;
//
//    for (; nextr != enditr; ++nextr, ++itr) {
//        *itr = std::move(*nextr);
//    }
//
//    return begin() + index + 1;
//}
//
//void MyVector::push_back(const int& value)
//{
//    if (_size == _capacity) {
//        unsigned old_cap = _capacity;
//        if (_capacity != 0)
//            _capacity *= 2;
//        else
//            _capacity = 1;
//
//        auto temp = std::make_unique<int[]>(_capacity);
//        for (int i = 0; i < old_cap; i++) {
//            temp[i] = std::move(_data[i]);
//        }
//
//        _data = std::move(temp);
//    }
//
//    _data[_size] = value;
//    _size++;
//}
