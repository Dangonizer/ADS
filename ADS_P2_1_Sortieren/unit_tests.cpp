/*************************************************
* ADS Praktikum 2
* Unit-Testdatei
* Stand: 02.05.2024
*
*************************************************
* Änderungen untersagt!
*************************************************/
#include <vector>
#include "catch.h"
#include "sorting.h"


std::vector<int> V{98, 44, 30, 22, 64, 63, 11, 23, 8, 18};

TEST_CASE("Quicksort", "[QUICKSORT]") {

  SECTION("sorting 10 elements - simple") {
  
    std::vector<int> a(V);
	sorting::QuickSort(a,0,a.size()-1);
    
    REQUIRE(a.at(0) == 8);
    REQUIRE(a.at(1) == 11);
    REQUIRE(a.at(2) == 18);
    REQUIRE(a.at(3) == 22);
    REQUIRE(a.at(4) == 23);
    REQUIRE(a.at(5) == 30);
    REQUIRE(a.at(6) == 44);
    REQUIRE(a.at(7) == 63);
    REQUIRE(a.at(8) == 64);
    REQUIRE(a.at(9) == 98);
  }
}


TEST_CASE("ShellSort", "[SHELLSORT]") {


  SECTION("sorting 10 elements - simple with 2n") {

    std::vector<int> b(V);
	sorting::ShellSort_2n(b,b.size());

    REQUIRE(b.at(0) == 8);
    REQUIRE(b.at(1) == 11);
    REQUIRE(b.at(2) == 18);
    REQUIRE(b.at(3) == 22);
    REQUIRE(b.at(4) == 23);
    REQUIRE(b.at(5) == 30);
    REQUIRE(b.at(6) == 44);
    REQUIRE(b.at(7) == 63);
    REQUIRE(b.at(8) == 64);
    REQUIRE(b.at(9) == 98);
  }

  SECTION("sorting 10 elements - simple with 3n") {

      std::vector<int> b(V);
      sorting::ShellSort_3n(b, b.size());

      REQUIRE(b.at(0) == 8);
      REQUIRE(b.at(1) == 11);
      REQUIRE(b.at(2) == 18);
      REQUIRE(b.at(3) == 22);
      REQUIRE(b.at(4) == 23);
      REQUIRE(b.at(5) == 30);
      REQUIRE(b.at(6) == 44);
      REQUIRE(b.at(7) == 63);
      REQUIRE(b.at(8) == 64);
      REQUIRE(b.at(9) == 98);
  }
}

TEST_CASE("HeapSort", "[HEAPSORT]") {

  SECTION("sorting 10 elements - simple") {
    std::vector<int> c(V);
	sorting::HeapSort(c,c.size());

    REQUIRE(c.at(0) == 8);
    REQUIRE(c.at(1) == 11);
    REQUIRE(c.at(2) == 18);
    REQUIRE(c.at(3) == 22);
    REQUIRE(c.at(4) == 23);
    REQUIRE(c.at(5) == 30);
    REQUIRE(c.at(6) == 44);
    REQUIRE(c.at(7) == 63);
    REQUIRE(c.at(8) == 64);
    REQUIRE(c.at(9) == 98);
  }
}

TEST_CASE("MergeSort", "[MERGESORT]") {

  SECTION("sorting 10 elements - simple") {
  
    std::vector<int> d(V);
    std::vector<int> tmp;
    tmp.resize(d.size());

	sorting::MergeSort(d,tmp,0,d.size()-1);

	REQUIRE(d.at(0) == 8);
	REQUIRE(d.at(1) == 11);
	REQUIRE(d.at(2) == 18);
	REQUIRE(d.at(3) == 22);
	REQUIRE(d.at(4) == 23);
	REQUIRE(d.at(5) == 30);
	REQUIRE(d.at(6) == 44);
	REQUIRE(d.at(7) == 63);
	REQUIRE(d.at(8) == 64);
	REQUIRE(d.at(9) == 98);
  }

}


TEST_CASE("NatMergeSort", "[MERGESORT]") {

    SECTION("sorting 10 elements - simple") {

        std::vector<int> d(V);
        std::vector<int> tmp;
        tmp.resize(d.size());

        sorting::natMergeSort(d, tmp);

        REQUIRE(d.at(0) == 8);
        REQUIRE(d.at(1) == 11);
        REQUIRE(d.at(2) == 18);
        REQUIRE(d.at(3) == 22);
        REQUIRE(d.at(4) == 23);
        REQUIRE(d.at(5) == 30);
        REQUIRE(d.at(6) == 44);
        REQUIRE(d.at(7) == 63);
        REQUIRE(d.at(8) == 64);
        REQUIRE(d.at(9) == 98);
    }
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++