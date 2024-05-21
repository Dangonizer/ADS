#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <iostream>
#include "hashtable.h"

int main()
{
    Catch::Session().run();
    HashTable H(1000, 0.6, 3);
    for (int i = 0; i < 200; i++)
    {
        H.insert(rand() % 499 + 1000);
    }
    H.print();
    std::cout << "Collisioncount: " << H.getCollisionCount() << std::endl;
    return 0;
}