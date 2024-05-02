/*************************************************
 * ADS Praktikum 1.2
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

////////////////////////////////////
// Ihr Code hier:

Tree::Tree(){
    m_anker = nullptr;
    m_currentNodeChronologicalID = 0;
}

void deleteHelper(TreeNode* node){
    if(node == nullptr){
        return;
    }
    deleteHelper(node->getLeft());
    deleteHelper(node->getRight());
    delete node;
}

Tree::~Tree(){
    deleteHelper(m_anker);
}

void Tree::addNode(string name, int age, double income, int postcode){
    TreeNode* newNode = new TreeNode(age + postcode + income , m_currentNodeChronologicalID, name, age, income, postcode);
    m_currentNodeChronologicalID++;
    if(m_anker == nullptr){
        m_anker = newNode;
    }else{
        TreeNode* current = m_anker;
        TreeNode* parent = nullptr;
        while(true){
            parent = current;
            if(newNode->getNodeOrderID() < current->getNodeOrderID()){
                current = current->getLeft();
                if(current == nullptr){
                    parent->setLeft(newNode);
                    return;
                }
            }else{
                current = current->getRight();
                if(current == nullptr){
                    parent->setRight(newNode);
                    return;
                }
            }
        }
    }
}

TreeNode* getSuccessor(TreeNode* node){
    TreeNode* successorParent = node;
    TreeNode* successor = node;
    TreeNode* current = node->getRight();
    //search min of right subtree
    while(current != nullptr){
        successorParent = successor;
        successor = current;
        current = current->getLeft();
    }
    if(successor != node->getRight()){
        successorParent->setLeft(successor->getRight());
        successor->setRight(node->getRight());
    }
    return successor;
}

bool Tree::deleteNode(int id){
    TreeNode* current = m_anker;
    TreeNode* parent = m_anker;
    bool isLeftChild = true;
    //search for the node and parent
    while(current->getNodeOrderID() != id){
        parent = current;
        if(id < current->getNodeOrderID()){
            isLeftChild = true;
            current = current->getLeft();
        }else{
            isLeftChild = false;
            current = current->getRight();
        }
        if(current == nullptr){
            return false;
        }
    }
    //if node has no children
    if(current->getLeft() == nullptr && current->getRight() == nullptr){
        if(current == m_anker){
            m_anker = nullptr;
        }else if(isLeftChild){
            parent->setLeft(nullptr);
        }else{
            parent->setRight(nullptr);
        }
    }
    //if node has no right child
    else if(current->getRight() == nullptr){
        if(current == m_anker){
            m_anker = current->getLeft();
        }else if(isLeftChild){
            parent->setLeft(current->getLeft());
        }else{
            parent->setRight(current->getLeft());
        }
    }
    //if node has no left child
    else if(current->getLeft() == nullptr){
        if(current == m_anker){
            m_anker = current->getRight();
        }else if(isLeftChild){
            parent->setLeft(current->getRight());
        }else{
            parent->setRight(current->getRight());
        }
    }
    //if node has two children
    else{
        TreeNode* successor = getSuccessor(current);
        if(current == m_anker){
            m_anker = successor;
        }else if(isLeftChild){
            parent->setLeft(successor);
        }else{
            parent->setRight(successor);
        }
        successor->setLeft(current->getLeft());
    }
    return true;
}

bool searchNodeHelper(TreeNode* node, string name){
    if(node == nullptr){
        return false;
    }

    bool found = false;
    if(node->getName() == name){
        node->print();
        found = true;
    }

    if (searchNodeHelper(node->getLeft(), name))
    {
        found = true;
    }

    if (searchNodeHelper(node->getRight(), name))
    {
        found = true;
    }

    return found;
}

bool Tree::searchNode(string name){
    TreeNode* current = m_anker;
    return searchNodeHelper(current, name);
}

void printPreOrderHelper(TreeNode* node){
    if(node == nullptr){
        return;
    }
    node->print();
    printPreOrderHelper(node->getLeft());
    printPreOrderHelper(node->getRight());
}

void Tree::printPreOrder(){
    TreeNode* current = m_anker;
    printPreOrderHelper(current);
}

void printInOrderHelper(TreeNode* node){
    if(node == nullptr){
        return;
    }
    printInOrderHelper(node->getLeft());
    node->print();
    printInOrderHelper(node->getRight());
}

void Tree::printInOrder(){
    TreeNode* current = m_anker;
    printInOrderHelper(current);
}

void printPostOrderHelper(TreeNode* node){
    if(node == nullptr){
        return;
    }
    printPostOrderHelper(node->getLeft());
    printPostOrderHelper(node->getRight());
    node->print();
}

void Tree::printPostOrder(){
    TreeNode* current = m_anker;
    printPostOrderHelper(current);
}

void Tree::levelOrder(){
    TreeNode* current = m_anker;
    if(current == nullptr){
        return;
    }
    std::queue<TreeNode*> q;
    q.push(current);
    while(!q.empty()){
        TreeNode* node = q.front();
        node->print();
        q.pop();
        if(node->getLeft() != nullptr){
            q.push(node->getLeft());
        }
        if(node->getRight() != nullptr){
            q.push(node->getRight());
        }
    }
}

void Tree::printAll(){
    cout << "PreOrder: " << endl;
    printPreOrder();
    cout << "InOrder: " << endl;
    printInOrder();
    cout << "PostOrder: " << endl;
    printPostOrder();
    cout << "LevelOrder: " << endl;
    levelOrder();
}


//
////////////////////////////////////
