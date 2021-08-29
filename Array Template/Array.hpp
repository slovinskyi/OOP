#pragma once

#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

template <typename T>
class Array
{

    friend std::istream &operator>>(std::istream &input, Array<T>& a)
    {
        for (std::size_t i = 0; i < a.size; ++i)
        input >> a.ptr[i];
        return input;
    }

    friend std::ostream &operator<<(std::ostream &output, const Array<T>& a)
    {
        for (std::size_t i = 0; i < a.size; ++i)
        {
            output << std::setw(12) << a.ptr[i];
            if ((i + 1) % 4 == 0)
            output << std::endl;
        }

        if (a.size % 4 != 0)
        output << std::endl;
        return output;
    }

public:
    explicit Array(int = 10);
    Array(const Array& );
    ~Array();
    std::size_t getSize() const;
    const Array &operator=(const Array&);
    bool operator==(const Array&) const;

    bool operator!=(const Array& right) const
    {
        return ! (*this == right);
    }

    T &operator[](int);
    T operator[](int) const;

    std::size_t size;
    T *ptr;

};

template <typename T>
Array<T>::Array(int arraySize) : size(arraySize > 0 ? arraySize : throw std::invalid_argument("Rozmiar tablicy ma byc wiekszy od 0")), ptr(new T[size])
{
    for (std::size_t i = 0; i < size; ++i)
    ptr[i] = 0; 
}

template <typename T>
Array<T>::Array(const Array &arrayToCopy) : size(arrayToCopy.size), ptr(new T[size])
{
    for (std::size_t i = 0; i < size; ++i)
    ptr[i] = arrayToCopy.ptr[i];
}

template <typename T>
Array<T>::~Array()
{
    delete [] ptr;
}

template <typename T>
std::size_t Array<T>::getSize() const
{
    return size;
}

template <typename T>
const Array<T> &Array<T>::operator=(const Array &right)
{
    if (&right != this)
    {
        if (size != right.size)
        {

            delete [] ptr;
            size = right.size;
            ptr = new T[size];
        }
    
        for (std::size_t i = 0; i < size; ++i)
        ptr[i] = right.ptr[i];
    }

    return *this;
}

template <typename T>
bool Array<T>::operator==(const Array& right) const
{
    if (size != right.size)
    return false;
    for (std::size_t i = 0; i < size; ++i)
    if (ptr[i] != right.ptr[i])
    return false;
    return true;
}

template <typename T>
T &Array<T>::operator[](int subscript)
{
    if (subscript < 0 || subscript >= size)
    throw std::out_of_range("Element o takim indeksie nie istnieje");
    return ptr[subscript];
}

template <typename T>
T Array<T>::operator[](int subscript) const
{
    if (subscript < 0 || subscript >= size)
    throw std::out_of_range("Element o takim indeksie nie istnieje");
    return ptr[subscript];
}

