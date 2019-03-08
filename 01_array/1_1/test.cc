#include "array.h"

#include <stdexcept>

#include "catch.hpp"

TEST_CASE("Test append") {
  const unsigned int capacity = 2;
  const double capacity_increase_ratio = 1.5;
  Array<int> arr(capacity);

  REQUIRE(arr.length() == 0);
  REQUIRE(arr.capacity() == capacity);

  arr.Append(1);
  REQUIRE(arr[0] == 1);

  arr.Append(3);
  REQUIRE(arr[0] == 1);
  REQUIRE(arr[1] == 3);

  REQUIRE(arr.length() == capacity);
  REQUIRE(arr.capacity() == capacity);

  arr.Append(5);
  REQUIRE(arr[0] == 1);
  REQUIRE(arr[1] == 3);
  REQUIRE(arr[2] == 5);

  REQUIRE(arr.length() == capacity + 1);
  REQUIRE(arr.capacity() == (unsigned int)(capacity * capacity_increase_ratio));
}

TEST_CASE("Test insert") {
  const unsigned int capacity = 4;
  const double capacity_increase_ratio = 1.5;
  Array<int> arr(capacity);

  REQUIRE(arr.length() == 0);
  REQUIRE(arr.capacity() == capacity);

  arr.Insert(0, 1); // Insert when empty
  REQUIRE(arr[0] == 1);

  arr.Insert(0, 3); // Insert on head
  REQUIRE(arr[0] == 3);
  REQUIRE(arr[1] == 1);

  arr.Insert(2, 5); // Insert on tail
  REQUIRE(arr[0] == 3);
  REQUIRE(arr[1] == 1);
  REQUIRE(arr[2] == 5);

  arr.Insert(1, 7); // Insert on middle
  REQUIRE(arr[0] == 3);
  REQUIRE(arr[1] == 7);
  REQUIRE(arr[2] == 1);
  REQUIRE(arr[3] == 5);

  REQUIRE(arr.length() == capacity);
  REQUIRE(arr.capacity() == capacity);

  try { // Insert with invalid index
    arr.Insert(5, 9);
    FAIL("Expect exception");
  } catch (const std::out_of_range& e) {
    REQUIRE(std::string(e.what()) == "Invalid index");
  } catch (...) {
    FAIL("Expect std::out_of_range exception");
  }

  arr.Insert(4, 9); // Insert when full
  REQUIRE(arr[0] == 3);
  REQUIRE(arr[1] == 7);
  REQUIRE(arr[2] == 1);
  REQUIRE(arr[3] == 5);
  REQUIRE(arr[4] == 9);

  REQUIRE(arr.length() == capacity + 1);
  REQUIRE(arr.capacity() == (unsigned int)(capacity * capacity_increase_ratio));
}

TEST_CASE("Test remove") {
  Array<int> arr;

  arr.Append(1);
  arr.Append(3);
  arr.Append(5);

  SECTION("Remove on head") {
    arr.Remove(0);
    REQUIRE(arr[0] == 3);
    REQUIRE(arr[1] == 5);
    REQUIRE(arr.length() == 2);
  }
  SECTION("Remove on middle") {
    arr.Remove(1);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 5);
    REQUIRE(arr.length() == 2);
  }
  SECTION("Remove on tail") {
    arr.Remove(2);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 3);
    REQUIRE(arr.length() == 2);
  }

  SECTION("Remove with invalid index") {
    try {
      arr.Remove(3);
      FAIL("Expect exception");
    } catch (const std::out_of_range& e) {
      REQUIRE(std::string(e.what()) == "Invalid index");
    } catch (...) {
      FAIL("Expect std::out_of_range exception");
    }
  }
}

TEST_CASE("Test modify") {
  Array<int> arr;

  arr.Append(1);
  REQUIRE(arr[0] == 1);

  arr[0] = 3; // Modify normally
  REQUIRE(arr[0] == 3);

  try { // Modify with invalid index
    arr[1] = 5;
    FAIL("Expect exception");
  } catch (const std::out_of_range& e) {
    REQUIRE(std::string(e.what()) == "Invalid index");
  } catch (...) {
    FAIL("Expect std::out_of_range exception");
  }  
}

TEST_CASE("Test read") {
  Array<int> arr;

  arr.Append(1);
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
