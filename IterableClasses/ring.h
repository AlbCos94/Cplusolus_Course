#ifndef RING_H
#define RING_H

#include <iostream>

template <class T> //
class ring
{
private:
    int m_pos;
    int m_size;
    T* m_values;

public:
    class iterator;

public:
    // constructor
    ring(int size)
        : m_pos(0)
        , m_size(size)
        , m_values(NULL)
    {
        m_values = new T[size];
    }

    ~ring()
    {
        delete[] m_values;
    }

    int size()
    {
        return m_size;
    }

    iterator begin()
    {
        return iterator(0, *this); // inside this class, we implement the class "iterator"
    }

    iterator end()
    {
        return iterator(m_size, *this);
    }

    void add(T value)
    {
        m_values[m_pos] = value;
        m_pos++;
        if(m_pos == m_size) {
            m_pos = 0;
        }
    }

    T& get(int pos)
    {
        return m_values[pos];
    }
};

template <class T> //
class ring<T>::iterator
{
private:
    int m_pos;
    ring& m_ring; // we implement the object attribute as a referece, so we will be working always with the real object

public:
    // initialization of the operator
    iterator(int pos, ring& aRing)
        : m_pos(pos)
        , m_ring(aRing)
    {
    }

    // method to implement the iterator
    iterator& operator++(int)
    {
        m_pos++;
        return *this;
    }

    iterator& operator++()
    {
        m_pos++;
        return *this;
    }

    // implementation of the reference start * operator, in ordert to get the value to which the iterator is pointing to
    // no copy is made, a reference is returned
    T& operator*()
    {
        return m_ring.get(m_pos);
    }

    bool operator!=(const iterator& other) const
    {
        return m_pos != other.m_pos;
    }
};

#endif // RING_H
