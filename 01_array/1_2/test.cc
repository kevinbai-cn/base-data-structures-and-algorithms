#include "catch.hpp"
#include "array.h"
#include <stdexcept>

TEST_CASE("Test add") {
  const unsigned int capacity = 4;
  Array<int> arr(capacity);

  REQUIRE(arr.length() == 0);
  REQUIRE(arr.capacity() == capacity);

  arr.Add(3); // Add when array is empty
  REQUIRE(arr[0] == 3);

  arr.Add(1); // Add on head
  REQUIRE(arr[0] == 1);
  REQUIRE(arr[1] == 3);

  arr.Add(4); // Add on tail
  REQUIRE(arr[0] == 1);
  REQUIRE(arr[1] == 3);
  REQUIRE(arr[2] == 4);

  arr.Add(2); // Add on middle
  REQUIRE(arr[0] == 1);
  REQUIRE(arr[1] == 2);
  REQUIRE(arr[2] == 3);
  REQUIRE(arr[3] == 4);

  REQUIRE(arr.length() == capacity);
  REQUIRE(arr.capacity() == capacity);

  try { // Add when array is full
    arr.Add(5);
    FAIL("Expect exception");
  } catch (const std::out_of_range& e) {
    REQUIRE(std::string(e.what()) == "Array is full");
  } catch (...) {
    FAIL("Expect std::out_of_range exception");
  }
}

TEST_CASE("Test remove") {
  Array<int> arr;

  SECTION("Remove when array is empty") {
    try {
      arr.Remove(0);
      FAIL("Expect exception");
    } catch (const std::out_of_range& e) {
      REQUIRE(std::string(e.what()) == "Invalid index");
    } catch (...) {
      FAIL("Expect std::out_of_range exception");
    }
  }

  arr.Add(1);
  arr.Add(2);
  arr.Add(3);
  arr.Add(4);

  SECTION("Remove head") {
    arr.Remove(0);
    REQUIRE(arr[0] == 2);
    REQUIRE(arr[1] == 3);
    REQUIRE(arr[2] == 4);
    REQUIRE(arr.length() == 3);
  }

  SECTION("Remove middle") {
    arr.Remove(1); 
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 3);
    REQUIRE(arr[2] == 4);
    REQUIRE(arr.length() == 3);
  }
  
  SECTION("Remove tail") {
    arr.Remove(3); 
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 2);
    REQUIRE(arr[2] == 3);
    REQUIRE(arr.length() == 3);
  }

  SECTION("Remove with invalid index") {
    try {
      arr.Remove(4);
      FAIL("Expect exception");
    } catch (const std::out_of_range& e) {
      REQUIRE(std::string(e.what()) == "Invalid index");
    } catch (...) {
      FAIL("Expect std::out_of_range exception");
    }
  }
}

TEST_CASE("Test set") {
  Array<int> arr;

  SECTION("Set when array is empty") {
    try {
      arr.Set(0, 10);
      FAIL("Expect exception");
    } catch (const std::out_of_range& e) {
      REQUIRE(std::string(e.what()) == "Invalid index");
    } catch (...) {
      FAIL("Expect std::out_of_range exception");
    }
  }

  arr.Add(10);
  arr.Add(20);
  arr.Add(30);
  arr.Add(40);

  SECTION("Set on head, value less than head") {
    arr.Set(0, 5);
    REQUIRE(arr[0] == 5);
    REQUIRE(arr[1] == 20);
    REQUIRE(arr[2] == 30);
    REQUIRE(arr[3] == 40);
    REQUIRE(arr.length() == 4);
  }
  SECTION("Set on head, value greater than head") {
    arr.Set(0, 25);
    REQUIRE(arr[0] == 20);
    REQUIRE(arr[1] == 25);
    REQUIRE(arr[2] == 30);
    REQUIRE(arr[3] == 40);
    REQUIRE(arr.length() == 4);
  }

  SECTION("Set on middle, value less than middle") {
    arr.Set(2, 15);
    REQUIRE(arr[0] == 10);
    REQUIRE(arr[1] == 15);
    REQUIRE(arr[2] == 20);
    REQUIRE(arr[3] == 40);
    REQUIRE(arr.length() == 4);
  }
  SECTION("Set on middle, value greater than middle") {
    arr.Set(1, 35);
    REQUIRE(arr[0] == 10);
    REQUIRE(arr[1] == 30);
    REQUIRE(arr[2] == 35);
    REQUIRE(arr[3] == 40);
    REQUIRE(arr.length() == 4);
  }

  SECTION("Set on tail, value less than tail") {
    arr.Set(3, 15);
    REQUIRE(arr[0] == 10);
    REQUIRE(arr[1] == 15);
    REQUIRE(arr[2] == 20);
    REQUIRE(arr[3] == 30);
    REQUIRE(arr.length() == 4);
  }
  SECTION("Set on tail, value greater than tail") {
    arr.Set(3, 45);
    REQUIRE(arr[0] == 10);
    REQUIRE(arr[1] == 20);
    REQUIRE(arr[2] == 30);
    REQUIRE(arr[3] == 45);
    REQUIRE(arr.length() == 4);
  }

  SECTION("Set with existed value") {
    arr.Set(3, 20);
    REQUIRE(arr[0] == 10);
    REQUIRE(arr[1] == 20);
    REQUIRE(arr[2] == 20);
    REQUIRE(arr[3] == 30);
    REQUIRE(arr.length() == 4);
  }

  SECTION("Set with invalid index") {
    try {
      arr.Set(4, 50);
      FAIL("Expect exception");
    } catch (const std::out_of_range& e) {
      REQUIRE(std::string(e.what()) == "Invalid index");
    } catch (...) {
      FAIL("Expect std::out_of_range exception");
    }
  }
}

TEST_CASE("Test read") {
  Array<int> arr;

  arr.Add(1);
  REQUIRE(arr[0] == 1); // Read normally

  try { // Read with invalid index
    int value = arr[1];
    FAIL("Expect exception");
  } catch (const std::out_of_range& e) {
    REQUIRE(std::string(e.what()) == "Invalid index");
  } catch (...) {
    FAIL("Expect std::out_of_range exception");
  }  
}
