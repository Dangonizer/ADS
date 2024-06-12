#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
#include <queue>

Tree::Tree()
	: m_anker{nullptr}, m_CurrentNodeChronologicalID{0}
{
}

void deleteHelper(TreeNode *node)
{
	if (node == nullptr)
	{
		return;
	}
	deleteHelper(node->getLeft());
	deleteHelper(node->getRight());
	delete node;
}

Tree::~Tree()
{
	deleteHelper(m_anker);
}

/**
 * Rekursive Hilfsfunktion f�r die Suche nach einem Knoten mittels Namensvergleich.
 * Da der Name kein Alleinstellungsmerkmal ist, muss der gesamte Baum in Preorder durchlaufen und gepr�ft werden.
 * Eine Score ermittelt die Fundh�ufigkeit eines Namens.
 *
 * \param[in] node Aktueller Knoten im Baum
 * \param[in] Name String nach dem gesucht wird
 * \param[out] score Anzahl der gefundenen Knoten mit entsprechendem Namen
 */
void searchNode_RecHelper(TreeNode *node, std::string Name, int &score)
{
	if (node->getName() == Name)
	{
		node->print();
		score++;
	}
	if (node->getLeft() != nullptr)
		searchNode_RecHelper(node->getLeft(), Name, score);
	if (node->getRight() != nullptr)
		searchNode_RecHelper(node->getRight(), Name, score);
}

/**
 * Rekursive Suche nach Knoten (preorder)
 *
 * \string Name Der String der im Baum gesucht werden soll
 */
bool Tree::searchNode(std::string Name)
{
	if (m_anker == nullptr)
		return false;

	int search_score = 0;
	searchNode_RecHelper(m_anker, Name, search_score);

	if (search_score > 0)
		return true;

	return false;
}

bool Tree::split4Node(TreeNode *node)
{
	// 4-Knoten
	if (!node->getRed() && node->getLeft() != nullptr && node->getRight() != nullptr && node->getLeft()->getRed() == true && node->getRight()->getRed() == true)
	{
		node->getLeft()->setRed(false);
		node->getRight()->setRed(false);
		node->setRed(true);
		return true;
	}
	return false;
}

void Tree::balance(TreeNode *node)
{
	// traverse bottomup
	while (node->getParent() != nullptr && node->getParent()->getParent() != nullptr)
	{
		// check for red-red conflict
		TreeNode *parent = node->getParent();
		TreeNode *pparent = parent->getParent();
		if (node->getRed() && parent->getRed())
		{
			// double right
			if (parent->getRight() == node && pparent->getRight() == parent)
			{
				rotateTreeLeft(parent);
			}
			// double left
			else if (parent->getLeft() == node && pparent->getLeft() == parent)
			{
				rotateTreeRight(parent);
			}
			else if (parent->getRight() == node && pparent->getLeft() == parent)
			{
				rotateTreeLeft(node);
				rotateTreeRight(node);
			}
			else if (parent->getLeft() == node && pparent->getRight() == parent)
			{
				rotateTreeRight(node);
				rotateTreeLeft(node);
			}
		}
		if (node->getParent() != nullptr && node->getParent()->getParent() != nullptr)
		{
			node = node->getParent();
		}
	}
	if (m_anker->getRed())
	{
		m_anker->setRed(false);
	}
}

// node is lower node of rotation
bool Tree::rotateTreeRight(TreeNode *node)
{
	// get relevant nodes
	TreeNode *parent = node->getParent();
	TreeNode *pparent = parent->getParent();

	// pass right child to parent
	parent->setLeft(node->getRight());
	if (node->getRight() != nullptr)
	{
		node->getRight()->setParent(parent);
	}

	// set parent as right child of node
	node->setRight(parent);
	node->getRight()->setParent(node);

	// check if parent is anker
	if (pparent != nullptr)
	{
		// set node as child of pparent
		if (parent->getNodeOrderID() < pparent->getNodeOrderID())
		{
			pparent->setLeft(node);
			node->setParent(pparent);
		}
		else
		{
			pparent->setRight(node);
			node->setParent(pparent);
		}
	}
	// set node as anker
	else
	{
		m_anker = node;
		node->setParent(nullptr);
	}
	// set colors
	node->setRed(false);
	parent->setRed(true);
	return true;
}

// node is lower node of rotation
bool Tree::rotateTreeLeft(TreeNode *node)
{
	// get relevant nodes
	TreeNode *parent = node->getParent();
	TreeNode *pparent = parent->getParent();

	// pass left child to parent
	parent->setRight(node->getLeft());
	if (node->getLeft() != nullptr)
	{
		node->getLeft()->setParent(parent);
	}

	// set parent as left child of node
	node->setLeft(parent);
	node->getLeft()->setParent(node);

	if (pparent != nullptr)
	{
		if (parent->getNodeOrderID() < pparent->getNodeOrderID())
			pparent->setLeft(node);
		else
			pparent->setRight(node);
		node->setParent(pparent);
	}
	else
	{
		m_anker = node;
		node->setParent(nullptr);
	}
	node->setRed(false);
	parent->setRed(true);
	return true;
}

bool Tree::addNode(std::string Name, int Age, double Income, int PostCode)
{
	TreeNode *newNode = new TreeNode(Age + PostCode + int(Income), m_CurrentNodeChronologicalID, Name, Age, Income, PostCode);
	m_CurrentNodeChronologicalID++;
	if (m_anker == nullptr)
	{
		m_anker = newNode;
		m_anker->setRed(false);
		return true;
	}
	TreeNode *current = m_anker;
	TreeNode *parent = nullptr;
	while (current != nullptr)
	{
		parent = current;
		split4Node(current);
		if (newNode->getNodeOrderID() < current->getNodeOrderID())
			current = current->getLeft();
		else
			current = current->getRight();
	}
	newNode->setParent(parent);
	if (newNode->getNodeOrderID() < parent->getNodeOrderID())
		parent->setLeft(newNode);
	else
		parent->setRight(newNode);
	balance(newNode);
	return true;
}

int Tree::proofRBCriterion(TreeNode *node)
{
	return 0;
}

/**
 * Ausgabe aller Knoten in Tabellenform Levelorder-BST
 *
 */
void Tree::printAll() // Levelorder-BST
{
	///////////////////////////////////////
	// Ihr Code hier:

	//
	///////////////////////////////////////
}

void Tree::printLevelOrder()
{
	return;
}

void Tree::printLevelOrder(int level)
{
	return;
}
