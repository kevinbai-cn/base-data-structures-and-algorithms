#ifndef P_01_ARRAY_1_3_MERGE_H_
#define P_01_ARRAY_1_3_MERGE_H_

#include <vector>

// Merge ordered array a and b
template <typename T>
std::vector<T> Merge(const std::vector<T>& a, const std::vector<T>& b);

template <typename T>
std::vector<T> Merge(const std::vector<T>& a, const std::vector<T>& b) {
  unsigned int a_length = a.size();
  unsigned int b_length = b.size();
  std::vector<T> c(a_length + b_length);

  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int k = 0;
  while (i < a_length && j < b_length) {
    if (a[i] < b[j]) {
      c[k] = a[i];
      k++;
      i++;
    } else {
      c[k] = b[j];
      k++;
      j++;
    }
  }

  while (i < a_length) {
    c[k] = a[i];
    k++;
    i++;
  }
  while (j < b_length) {
    c[k] = b[j];
    k++;
    j++;
  }

  return c;
}

#endif // P_01_ARRAY_1_3_MERGE_H_
