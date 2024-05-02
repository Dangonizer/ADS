/*************************************************
 * ADS Praktikum 1.2
 * TreeNode.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "TreeNode.h"
#include <iostream>
#include <string>

////////////////////////////////////
// Ihr Code hier:

TreeNode::TreeNode(int    NodeorderID,
                   int    chronologicalID,
                   string name,
                   int    alter,
                   double einkommen,
                   int    plz)
{
    this->m_NodeOrderID	= NodeorderID;
    this->m_NodeChronologicalID = chronologicalID;
    this->m_Name = name;
    this->m_Age	= alter;
    this->m_Income = einkommen;
    this->m_PostCode = plz;
    this->m_left = nullptr;
    this->m_right = nullptr;
}

void TreeNode::print(){
    std::cout << "NodeOrderID: " << m_NodeOrderID;
    std::cout << ", NodeChronologicalID: " << m_NodeChronologicalID;
    std::cout << ", Name: " << m_Name;
    std::cout << ", Age: " << m_Age;
    std::cout << ", Income: " << m_Income;
    std::cout << ", PostCode: " << m_PostCode << std::endl;
}



//
////////////////////////////////////
