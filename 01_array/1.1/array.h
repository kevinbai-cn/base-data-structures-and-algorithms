#include <stdexcept>

#define DEFAULT_CAPACITY 50
#define DEFAULT_CAPACITY_INC_RATIO 1.5

template <class T>
class Array {
public:
    Array(int capacity = DEFAULT_CAPACITY,
        double capacityIncRatio = DEFAULT_CAPACITY_INC_RATIO);
    ~Array();

public:
    int getSize();
    int getCapacity();
    void append(T ele);
    void insert(int pos, T ele);
    // void del(int pos);
    T& operator[](int pos);

private:
    void expandData();

private:
    int capacity; // Array max capacity
    T* data; // Save elements
    int size; // Array length
    // Expand capacity to capacityIncRatio times before when array full
    double capacityIncRatio;
};

template <class T>
Array<T>::Array(int capacity, double capacityIncRatio)
{
    this->capacity = capacity;
    this->data = new T[capacity];
    this->size = 0;
    this->capacityIncRatio = capacityIncRatio;
}

template <class T>
Array<T>::~Array()
{
    delete []this->data;
}

template <class T>
int Array<T>::getSize()
{
    return this->size;
}

template <class T>
int Array<T>::getCapacity()
{
    return this->capacity;
}

template <class T>
void Array<T>::append(T ele)
{
    if (this->size == this->capacity) {
        this->expandData();
    }
    this->data[this->size] = ele;
    this->size++;
}

template <class T>
void Array<T>::insert(int pos, T ele)
{
    if (pos > this->size) {
        throw std::out_of_range("Pos beyond array size");
    } 
    
    if (this->size == this->capacity) {
        this->expandData();
    }

    for (int i = this->size; i > pos; i--) {
        this->data[i] = this->data[i - 1];
    }
    this->data[pos] = ele;
    this->size++;
}

// template <class T>
// void Array<T>::del(int pos)
// {
//     if (pos >= this->size) {
//         throw std::out_of_range("Pos out of range");
//     }

//     for (int i = pos + 1; i < this->size; i++) {
//         this->data[i - 1] = this->data[i];
//     }
//     this->size--;
// }

template <class T>
T& Array<T>::operator[](int pos)
{
    if (pos >= this->size) {
        throw std::out_of_range("Pos out of range");
    }

    return this->data[pos];
}

template <class T>
void Array<T>::expandData()
{
    T* temp = this->data;
    this->capacity = (int)(this->capacity * this->capacityIncRatio);
    this->data = new T[this->capacity];
    for (int i = 0; i < this->capacity; i++) {
        this->data[i] = temp[i];
    }
    delete []temp;
}
