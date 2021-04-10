#ifndef RING_H
#define RING_H

#include <iostream>

template <class T> //
class ring
{
private:
    int m_pos; // to indicate the current position on the buffer
    int m_size;
    T* m_values; // pointer to an array of elements of the Type T
    // ALWAYS WORK WITH POINTERS WHEN WORKING WITH ARRAYS !!!!!! -->> ALOCATING MEMORY ON THE HEAP
public:
    class iterator;

    // we create another publich section to not mix up methodes with other class declarations
public:
    // constructor
    ring(int size)
        : m_pos(0)
        , m_size(size)
        , m_values(NULL)
    {
        // by default we set the pointer pointing nowhere
        // We allocate memory on the heap for that array
        m_values = new T[size]; // we set the size of the array to which the pointer will be pointing to
        // the pointer "m_values" will be pointing always to the same chuck of memory on the heap
    }

    // when working with pointer taking memory form the heap, ALWAYS when destroying that object that contains the
    // pointer, not forget to dealocate that memory!!!! Otherwise we wil lose that part of memory
    ~ring()
    {
        delete[] m_values; // when the object is destroied, we dealocate the memory used for that pointer!!! otherwise
                           // we would have memory leaks
    }

    // we implement the method "size" that words the same way as it does for for example in the std::vector
    int size()
    {
        return m_size;
    }

    // Add method, to add the elements that are going to construct that object
    // In a way that we will be overwritting the whole time the values when the final position is reached
    void add(T value) // each time we add a new element, we do a copy of the value
    {
        m_values[m_pos] = value;
        m_pos++;
        if(m_pos == m_size) {
            m_pos = 0;
        }
    }

    // get method implementation
    // we return a reference, so we will get the real value of the container, not a copy of it
    T& get(int pos)
    {
        return m_values[pos];
    }
};

template <class T> //
class ring<T>::iterator
{
public:
    void print();
};

template <class T> //
void ring<T>::iterator::print()
{
    std::cout << "Hello from iterator of template class ring" << std::endl;
}

#endif // RING_H
