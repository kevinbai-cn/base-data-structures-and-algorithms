#include "merge.h"

#include <vector>

#include "catch.hpp"

// TODO remove
#include <iostream>

TEST_CASE("Test merge") {
  SECTION("Normal") {
    int a_data[5] = {1, 3, 5, 7, 9};
    int b_data[5] = {2, 4, 6, 8, 10};
    int c_data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> a(a_data, a_data + 5);
    std::vector<int> b(b_data, b_data + 5);
    std::vector<int> c = Merge(a, b);

    for (unsigned int i = 0; i < c.size(); i++) {
      REQUIRE(c[i] == c_data[i]);
    }
  }

  SECTION("A length less than b length") {
    int a_data[2] = {1, 3};
    int b_data[5] = {2, 4, 6, 8, 10};
    int c_data[7] = {1, 2, 3, 4, 6, 8, 10};
    std::vector<int> a(a_data, a_data + 2);
    std::vector<int> b(b_data, b_data + 5);
    std::vector<int> c = Merge(a, b);

    for (unsigned int i = 0; i < c.size(); i++) {
      REQUIRE(c[i] == c_data[i]);
    }
  }
  SECTION("A length greater than b length") {
    int a_data[5] = {1, 3, 5, 7, 9};
    int b_data[2] = {2, 4};
    int c_data[7] = {1, 2, 3, 4, 5, 7, 9};
    std::vector<int> a(a_data, a_data + 5);
    std::vector<int> b(b_data, b_data + 2);
    std::vector<int> c = Merge(a, b);

    for (unsigned int i = 0; i < c.size(); i++) {
      REQUIRE(c[i] == c_data[i]);
    }
  }

  SECTION("A is empty, b is not empty") {
    int b_data[2] = {2, 4};
    int c_data[2] = {2, 4};
    std::vector<int> a;
    std::vector<int> b(b_data, b_data + 2);
    std::vector<int> c = Merge(a, b);

    for (unsigned int i = 0; i < c.size(); i++) {
      REQUIRE(c[i] == c_data[i]);
    }
  }
  SECTION("A is not empty, b is empty") {
    int a_data[2] = {2, 4};
    int c_data[2] = {2, 4};
    std::vector<int> a(a_data, a_data + 2);
    std::vector<int> b;
    std::vector<int> c = Merge(a, b);

    for (unsigned int i = 0; i < c.size(); i++) {
      REQUIRE(c[i] == c_data[i]);
    }
  }
  SECTION("A and b are empty") {
    std::vector<int> a;
    std::vector<int> b;
    std::vector<int> c = Merge(a, b);

    REQUIRE(c.size() == 0);
  }
}
