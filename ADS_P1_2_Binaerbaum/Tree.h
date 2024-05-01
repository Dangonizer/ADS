/*************************************************
 * ADS Praktikum 1.2
 * Tree.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include "TreeNode.h"
#include "catch.h"
#include <string>

using namespace std;

class Tree
{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode* m_anker;
    int m_currentNodeChronologicalID;
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    Tree();
    ~Tree();
    void addNode(string name, int age, double income, int postcode);
    bool deleteNode(int id);
    bool searchNode(int name);
    void printAll();
    void printLevelOrder();
    void printPreOrder();
    void printInOrder();
    void printPostOrder();
    //
    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};
