#ifndef P_01_ARRAY_1_1_ARRAY_H_
#define P_01_ARRAY_1_1_ARRAY_H_

#include <stdexcept>

#define DEFAULT_CAPACITY 50
#define DEFAULT_CAPACITY_INCREASE_RATIO 1.5

template <typename T>
class Array {
public:
  Array(unsigned int capacity = DEFAULT_CAPACITY,
        double capacity_increase_ratio = DEFAULT_CAPACITY_INCREASE_RATIO)
      : capacity_(capacity),
        capacity_increase_ratio_(capacity_increase_ratio),
        length_(0) {
    data_ = new T[capacity_];
  }
  ~Array() { delete[] data_; }

  unsigned int capacity() const { return capacity_; }
  unsigned int length() const { return length_; }

  void Append(T value);
  void Insert(unsigned int index, T value);
  void Remove(unsigned int index);
  T& operator[](unsigned int index);

private:
  void IncreaseCapacityIfDataIsFull();

  T* data_;
  unsigned int capacity_;
  double capacity_increase_ratio_;
  unsigned int length_;
};

template <typename T>
void Array<T>::Append(T value) {
  IncreaseCapacityIfDataIsFull();
  
  data_[length_] = value;
  length_++;
}

template <typename T>
void Array<T>::Insert(unsigned int index, T value) {
  if (index > length_) {
    throw std::out_of_range("Invalid index");
  }
  IncreaseCapacityIfDataIsFull();

  for (unsigned int i = length_; i > index; i--) {
    data_[i] = data_[i - 1];
  }
  data_[index] = value;
  length_++;
}

template <typename T>
void Array<T>::Remove(unsigned int index) {
  if (index >= length_) {
    throw std::out_of_range("Invalid index");
  }

  for (unsigned int i = index; i < length_; i++) {
    data_[i] = data_[i + 1];
  }
  length_--;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
  if (index < 0 || index >= length_) {
    throw std::out_of_range("Invalid index");
  }

  return data_[index];
}

template <typename T>
void Array<T>::IncreaseCapacityIfDataIsFull() {
  if (length_ == capacity_) {
    T* temp = data_;
    capacity_ = (unsigned int)(capacity_ * capacity_increase_ratio_);
    data_ = new T[capacity_];
    for (unsigned int i = 0; i < capacity_; i++) {
      data_[i] = temp[i];
    }
    delete[] temp;
  }
}

#endif // P_01_ARRAY_1_1_ARRAY_H_
