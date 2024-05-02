/*************************************************
 * ADS Praktikum 1.2
 * TreeNode.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode
{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    int m_NodeOrderID;
    int m_NodeChronologicalID;
    string m_Name;
    int m_Age;
    double m_Income;
    int m_PostCode; 
    TreeNode* m_left;
    TreeNode* m_right;
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode(int NodeorderID, int chronologicalID, string name, int alter, double einkommen, int plz);
    int getNodeOrderID(){return m_NodeOrderID;}
    int getNodeChronologicalID(){return m_NodeChronologicalID;}
    string getName(){return m_Name;}
    int getAge(){return m_Age;}
    double getIncome(){return m_Income;}
    int getPostCode(){return m_PostCode;}
    TreeNode* getLeft(){return m_left;}
    TreeNode* getRight(){return m_right;}
    void setNodeOrderID(int id){m_NodeOrderID = id;}
    void setNodeChronologicalID(int id){m_NodeChronologicalID = id;}
    void setName(string name){m_Name = name;}
    void setAge(int age){m_Age = age;}
    void setIncome(double income){m_Income = income;}
    void setPostCode(int postcode){m_PostCode = postcode;}
    void setLeft(TreeNode* left){m_left = left;}
    void setRight(TreeNode* right){m_right = right;}
    void print();
    //
    ////////////////////////////////////
};
