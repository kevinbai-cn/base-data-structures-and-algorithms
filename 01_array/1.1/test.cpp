#include "catch.hpp"
#include "array.h"
#include <stdexcept>

TEST_CASE("Test append") {
    int capacity = 3;
    double capacity_inc_ratio = 1.5;
    Array<int> arr(capacity, capacity_inc_ratio);

    REQUIRE(arr.getSize() == 0);
    REQUIRE(arr.getCapacity() == capacity);

    arr.append(1);
    REQUIRE(arr[0] == 1);

    arr.append(3);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 3);

    arr.append(5);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 3);
    REQUIRE(arr[2] == 5);

    REQUIRE(arr.getSize() == capacity);
    REQUIRE(arr.getCapacity() == capacity);

    SECTION("Increase capacity") {
        arr.append(7);
        REQUIRE(arr[0] == 1);
        REQUIRE(arr[1] == 3);
        REQUIRE(arr[2] == 5);
        REQUIRE(arr[3] == 7);

        REQUIRE(arr.getSize() == 4);
        REQUIRE(arr.getCapacity() == (int)(capacity * capacity_inc_ratio));      
    }
}

TEST_CASE("Test insert") {
    int capacity = 4;
    double capacity_inc_ratio = 1.5;
    Array<int> arr(capacity, capacity_inc_ratio);

    REQUIRE(arr.getSize() == 0);
    REQUIRE(arr.getCapacity() == capacity);

    arr.insert(0, 1); // Insert when empty
    REQUIRE(arr[0] == 1);

    arr.insert(0, 3); // Insert on head
    REQUIRE(arr[0] == 3);
    REQUIRE(arr[1] == 1);

    arr.insert(2, 5); // Insert on tail
    REQUIRE(arr[0] == 3);
    REQUIRE(arr[1] == 1);
    REQUIRE(arr[2] == 5);

    arr.insert(1, 7); // Insert on middle
    REQUIRE(arr[0] == 3);
    REQUIRE(arr[1] == 7);
    REQUIRE(arr[2] == 1);
    REQUIRE(arr[3] == 5);

    REQUIRE(arr.getSize() == capacity);
    REQUIRE(arr.getCapacity() == capacity);

    try {
        arr.insert(5, 7);
        FAIL("Expect exception");
    } catch (const std::out_of_range & e) {
        REQUIRE(std::string(e.what()) == "Pos beyond array size");
    } catch (...) {
        FAIL("Expect std::out_of_range exception");
    }

    SECTION("Increase capacity") {
        arr.insert(0, 9);
        REQUIRE(arr[0] == 9);
        REQUIRE(arr[1] == 3);
        REQUIRE(arr[2] == 7);
        REQUIRE(arr[3] == 1);
        REQUIRE(arr[4] == 5);

        REQUIRE(arr.getSize() == 5);
        REQUIRE(arr.getCapacity() == (int)(capacity * capacity_inc_ratio));
    }
}
