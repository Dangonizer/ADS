/*************************************************
* ADS Praktikum 1.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>

// Ihr Code hier:
void Ring::addNewNode(std::string description, std::string data)
{
    RingNode* newNode = new RingNode(0, description, data);
    if (m_anker == nullptr)
    {
        m_anker = newNode;
        m_anker->setNext(m_anker);
    }
    else if (m_countNodes <6) {
        newNode->setNext(m_anker->getNext());
        m_anker->setNext(newNode);
        m_anker = newNode;
        RingNode* temp = m_anker->getNext();
        while (temp != m_anker)
        {
            temp->setOldAge(temp->getOldAge() + 1);
            temp = temp->getNext();
        }
    }
    else
    {
        RingNode* del = m_anker->getNext();
        newNode->setNext(del->getNext());
        m_anker->setNext(newNode);
        m_anker = newNode;
        delete del;
        RingNode* temp = m_anker->getNext();
        while (temp != m_anker)
        {
            temp->setOldAge(temp->getOldAge() + 1);
            temp = temp->getNext();
        }
    }
    if (m_countNodes < 6)
        m_countNodes++;   
}

bool Ring::search(std::string data){
    if (m_anker == nullptr)
    {
        return false;
    }

    if (m_anker->getSymbolicData() == data)
    {
        return true;
    }

    RingNode* temp = m_anker->getNext();
    while (temp != m_anker)
    {
        if (temp->getSymbolicData() == data)
        {
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}

void Ring::print()
{
    if (m_anker == nullptr)
    {
        return;
    }

    printNode(m_anker);
    RingNode* temp = m_anker->getNext();
    RingNode* store[5];
    int i = 0;
    while (temp != m_anker)
    {
        store[i] = temp;
        i++;
        temp = temp->getNext();
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printNode(store[j]);
    }
}

void Ring::printNode(RingNode* node)
{
    std::cout << "Age " << node->getOldAge()  << " Description: " << node->getDescription() << "Data: " << node->getSymbolicData() << std::endl;
}
//
////////////////////////////////////