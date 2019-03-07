#ifndef P_01_ARRAY_1_2_ARRAY_H_
#define P_01_ARRAY_1_2_ARRAY_H_

#include <stdexcept>

#define DEFAULT_CAPACITY 50

template <typename T>
class Array {
public:
  Array(unsigned int capacity = DEFAULT_CAPACITY)
      : capacity_(capacity),
        length_(0) {
    data_ = new T[capacity_];
  }
  ~Array() { delete[] data_; }

  unsigned int capacity() const { return capacity_; }
  unsigned int length() const { return length_; }

  void Add(T value);
  void Remove(unsigned int index);
  void Set(unsigned int index, T value);
  const T& operator[](unsigned int index);

private:
  // Add a value to data_.
  // After adding a value, data_ index will be between start and end+1.
  // Therefore, ensure data_ not full before using this function.
  void AddCore(T value, unsigned int start, unsigned int end);

  T* data_;
  unsigned int capacity_;
  unsigned int length_;
};

template <typename T>
void Array<T>::Add(T value) {
  if (length_ == capacity_) {
    throw std::out_of_range("Array is full");
  }

  if (length_ == 0) {
    data_[0] = value;
    length_++;
  } else {
    AddCore(value, 0, length_ - 1);
    length_++;
  }
}

template <typename T>
void Array<T>::Remove(unsigned int index) {
  if (index >= length_) {
    throw std::out_of_range("Invalid index");
  }

  for (int i = index; i < length_; i++) {
    data_[i] = data_[i + 1];
  }
  length_--;
}

template <typename T>
void Array<T>::Set(unsigned int index, T value) {
  if (index >= length_) {
    throw std::out_of_range("Invalid index");
  }

  if (data_[index] == value) {
    return;
  }

  if (index > 0 && value < data_[index - 1]) {
    AddCore(value, 0, index - 1);
  } else {
    unsigned int i = index + 1;
    while(i < length_ && value >= data_[i]) {
      i++;
    }
    // Insert on i - 1, values move forwards
    for (unsigned int j = index; j < i - 1; j++) {
      data_[j] = data_[j + 1];
    }
    data_[i - 1] = value;
  }
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) {
  if (index >= length_) {
    throw std::out_of_range("Invalid index");
  }

  return data_[index];
}

template <typename T>
void Array<T>::AddCore(T value, unsigned int start, unsigned int end) {
  // Find insert position
  unsigned int i = start;
  while (i <= end && value >= data_[i]) {
    i++;
  }
  // Insert on i
  for (unsigned int j = end + 1; j > i; j--) {
    data_[j] = data_[j - 1];
  }
  data_[i] = value;
}

#endif // P_01_ARRAY_1_2_ARRAY_H_
