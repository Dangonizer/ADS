/*************************************************
 * ADS Praktikum 1.1
 * Unit-Testdatei
 * Aenderungen fuers Praktikum untersagt!
 *************************************************/
#include "Ring.h"
#include "RingNode.h"
#include "catch.h"
#include <string>

using namespace std;

// Friend-Methode fuer Testroutine
RingNode* get_anker(Ring& r)
{
    return r.m_anker;
}

int get_countNodes(Ring& r)
{
    return r.m_countNodes;
}

TEST_CASE("Ring Testing", "[Ring]")
{

    Ring rloop;

    SECTION("Hinzufuegen von Nodes und Suche - simple")
    {

        rloop.addNewNode("Alpha", "Data");
        rloop.addNewNode("Beta", "Data");
        rloop.addNewNode("Gamma", "Data");

        REQUIRE(get_countNodes(rloop) == 3);

        REQUIRE(rloop.search("Data") == true);
        REQUIRE(rloop.search("FAIL") == false);
        REQUIRE(rloop.search("Alpha") == false);
        REQUIRE(rloop.search("Data") == true);
    }

    SECTION("Hinzufuegen von Nodes - Rotaionsgrenze")
    {
        rloop.addNewNode("Alpha", "Data1");
        rloop.addNewNode("Beta", "Data2");
        rloop.addNewNode("Gamma", "Data3");
        rloop.addNewNode("Delta", "Data4");
        rloop.addNewNode("Phi", "Data5");
        rloop.addNewNode("Sept", "Data6");
        rloop.addNewNode("Gamma", "Data7");
        rloop.addNewNode("Gamma", "Data8");
        rloop.addNewNode("Gamma", "Data9");

        REQUIRE(get_countNodes(rloop) == 6);

        REQUIRE(rloop.search("Data1") == false);
        REQUIRE(rloop.search("Data2") == false);
        REQUIRE(rloop.search("Data7") == true);
        REQUIRE(rloop.search("Data5") == true);
    }

    SECTION("Hinzufuegen von Nodes - Rotaionsperformance")
    {

        for (int i = 0; i < 1024; i++)
        {
            string info = "Info" + to_string(i);
            string data = "Data" + to_string(i);
            rloop.addNewNode(info, data);
        }

        REQUIRE(get_countNodes(rloop) == 6);

        REQUIRE(rloop.search("Data1") == false);
        REQUIRE(rloop.search("Data2") == false);
        REQUIRE(rloop.search("Data1020") == true);
        REQUIRE(rloop.search("Data1023") == true);
    }

    SECTION("Ringarchitektur - Verkettungspruefung 1")
    {

        for (int i = 0; i < 3; i++)
        {
            string info = "Info" + to_string(i);
            string data = "Data" + to_string(i);
            rloop.addNewNode(info, data);
        }

        RingNode* ref = get_anker(rloop);
        REQUIRE(get_countNodes(rloop) == 3);
        REQUIRE(ref->getSymbolicData() == "Data2");
        ref = ref->getNext();
        REQUIRE(ref->getSymbolicData() == "Data0");
        ref = ref->getNext();
        REQUIRE(ref->getSymbolicData() == "Data1");
        ref = ref->getNext();
        REQUIRE(ref == get_anker(rloop));
    }
    SECTION("Ringarchitektur - Verkettungspruefung 2")
    {

        for (int i = 0; i < 10; i++)
        {
            string info = "Info" + to_string(i);
            string data = "Data" + to_string(i);
            rloop.addNewNode(info, data);
        }

        RingNode* ref = get_anker(rloop);
        REQUIRE(get_countNodes(rloop) == 6);
        REQUIRE(ref->getSymbolicData() == "Data9");
        ref = ref->getNext();
        REQUIRE(ref->getSymbolicData() == "Data4");
        ref = ref->getNext();
        REQUIRE(ref->getSymbolicData() == "Data5");
        ref = ref->getNext();
        REQUIRE(ref->getSymbolicData() == "Data6");
        ref = ref->getNext();
        REQUIRE(ref->getSymbolicData() == "Data7");
        ref = ref->getNext();
        REQUIRE(ref->getSymbolicData() == "Data8");
        ref = ref->getNext();
        REQUIRE(ref->getSymbolicData() == "Data9");
        REQUIRE(ref == get_anker(rloop));

        // Fail-Test:
        // REQUIRE(get_anker(rloop)->getData() == "Data4");
    }
}

TEST_CASE("RingNode Testing", "[RingNode]")
{

    SECTION("Get/Setter von RingNode - simple")
    {

        RingNode* node = new RingNode(1, "Info", "Data");
        REQUIRE(node->getOldAge() == 1);
        REQUIRE(node->getDescription() == "Info");
        REQUIRE(node->getSymbolicData() == "Data");
        REQUIRE(node->getNext() == nullptr);

        node->setOldAge(5);
        REQUIRE(node->getOldAge() == 5);

        node->setDescription("newInfo");
        REQUIRE(node->getDescription() == "newInfo");

        node->setSymbolicData("newData");
        REQUIRE(node->getSymbolicData() == "newData");

        RingNode* node2 = new RingNode(2, "Info2", "Data2");
        node->setNext(node2);
        REQUIRE(node->getNext() == node2);

        delete node;
        delete node2;
    }
}
