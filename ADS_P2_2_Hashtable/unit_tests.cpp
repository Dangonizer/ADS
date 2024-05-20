/*************************************************
* ADS Praktikum 2
* Unit-Testdatei
* Stand: 06.05.2024
*
*************************************************
* Änderungen untersagt!
*************************************************/
#include <vector>
#include "catch.h"
#include "hashtable.h"

std::vector<int> V{98, 44, 30, 22, 64, 63, 11, 23, 8, 18};

TEST_CASE("HashTable", "[HASHTABLE]") {

    SECTION("Hashing 10 elements - Size: 20 : Rehashing") {

        HashTable H(20,0.6,1);

        for (unsigned int i = 0; i < V.size(); i++)
        {
            H.insert(V.at(i));
        }
        H.insert(15);
        H.insert(16);
        H.insert(21);
        H.insert(22);

        if (H.getSize() > 0) {
            REQUIRE(H.at(3) == 44);
            REQUIRE(H.at(8) == 8);
            REQUIRE(H.at(11) == 11);
            REQUIRE(H.at(15) == 15);
            REQUIRE(H.at(16) == 98);
            REQUIRE(H.at(17) == 16);
            REQUIRE(H.at(18) == 18);
            REQUIRE(H.at(21) == 21);
            REQUIRE(H.at(22) == 22);
            REQUIRE(H.at(23) == 63);
            REQUIRE(H.at(24) == 64);
            REQUIRE(H.at(25) == 22);
            REQUIRE(H.at(27) == 23);
            REQUIRE(H.at(30) == 30);
        }
        REQUIRE(H.getSize() == 41);
        REQUIRE(H.getCollisionCount() == 8);
        REQUIRE(H.getElements() == 14);
    }

    SECTION("Hashing 10 elements - quadratisch Sondieren - Size: 15 : Rehashing") {

        HashTable H(15, 0.6, 2);

        for (unsigned int i = 0; i < V.size(); i++)
        {
            H.insert(V.at(i));
        }
        H.insert(15);
        H.insert(16);
        H.insert(21);
        H.insert(22);

        if (H.getSize() > 0) {
            REQUIRE(H.at(1) == 63);
            REQUIRE(H.at(2) == 64);
            REQUIRE(H.at(5) == 98);
            REQUIRE(H.at(8) == 8);
            REQUIRE(H.at(11) == 11);
            REQUIRE(H.at(13) == 44);
            REQUIRE(H.at(15) == 15);
            REQUIRE(H.at(16) == 16);
            REQUIRE(H.at(18) == 18);
            REQUIRE(H.at(21) == 21);
            REQUIRE(H.at(22) == 22);
            REQUIRE(H.at(23) == 23);
            REQUIRE(H.at(26) == 22);
            REQUIRE(H.at(30) == 30);
        }
        REQUIRE(H.getSize() == 31);
        REQUIRE(H.getCollisionCount() == 2);
        REQUIRE(H.getElements() == 14);
    }

    SECTION("Hashing 10 elements - doppeltes Hashing- Size: 15 : Rehashing") {

        HashTable H(15, 0.6, 3);

        for (unsigned int i = 0; i < V.size(); i++)
        {
            H.insert(V.at(i));
        }
        H.insert(15);
        H.insert(16);
        H.insert(21);
        H.insert(22);

        if (H.getSize() > 0) {
            REQUIRE(H.at(1) == 63);
            REQUIRE(H.at(2) == 64);
            REQUIRE(H.at(5) == 98);
            REQUIRE(H.at(8) == 8);
            REQUIRE(H.at(11) == 11);
            REQUIRE(H.at(13) == 44);
            REQUIRE(H.at(15) == 15);
            REQUIRE(H.at(16) == 16);
            REQUIRE(H.at(18) == 18);
            REQUIRE(H.at(21) == 21);
            REQUIRE(H.at(22) == 22);
            REQUIRE(H.at(23) == 23);
            REQUIRE(H.at(29) == 22);
            REQUIRE(H.at(30) == 30);
        }
        REQUIRE(H.getSize() == 31);
        REQUIRE(H.getCollisionCount() == 1);
        REQUIRE(H.getElements() == 14);
    }
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++