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

int RBCriterionRecHelper(TreeNode *node)
{
	int height = 0;
	// end of tree
	if (node == nullptr)
		return -1;

	int heightLeft = RBCriterionRecHelper(node->getLeft());
	int heightRight = RBCriterionRecHelper(node->getRight());

	// error occured cancel execution
	if (heightLeft == -2 || heightRight == -2)
		return -2;

	// leafnode reached
	if (heightLeft == -1 && heightRight == -1)
		height = 0;

	// Only left child
	else if (heightRight == -1)
	{
		// only black child increases height
		if (node->getLeft()->getRed())
			height = heightLeft;
		else
			height = heightLeft + 1;
	}

	// Only right child
	else if (heightLeft == -1)
	{
		// only black child increases height
		if (node->getRight()->getRed())
			height = heightRight;
		else
			height = heightRight + 1;
	}

	// both children red -> same node -> height is equal
	else if (node->getLeft()->getRed() && node->getRight()->getRed())
	{
		if (heightLeft == heightRight)
			height = heightLeft;
		else
			return -2;
	}

	// both children black -> height is increased by one
	else if (!node->getLeft()->getRed() && !node->getRight()->getRed())
	{
		if (heightLeft == heightRight)
			height = heightLeft + 1;
		else
			return -2;
	}

	// only left child red -> height is equal to left
	else if (node->getLeft()->getRed() && !node->getRight()->getRed())
	{
		if (heightLeft == heightRight + 1)
			height = heightLeft;
		else
			return -2;
	}

	// only right child red -> height is equal to right
	else if (!node->getLeft()->getRed() && node->getRight()->getRed())
	{
		if (heightLeft + 1 == heightRight)
			height = heightRight;
		else
			return -2;
	}

	return height;
}

int Tree::proofRBCriterion(TreeNode *node)
{
	int result = RBCriterionRecHelper(node);
	if (result == -2)
	{
		std::cout << "RBCriterion not fulfilled" << std::endl;
		return -1;
	}
	std::cout << "RBCriterion fulfilled" << std::endl;
	return result;
}

// aka level order BST
void Tree::printAll()
{
	TreeNode *current = m_anker;
	if (current == nullptr)
	{
		return;
	}
	std::cout << "  ID | Name            | Age   | Income    | PostCode | OrderID | Red" << std::endl;
	std::cout << "----+------------------+-------+-----------+----------+---------+------" << std::endl;
	std::queue<TreeNode *> q;
	q.push(current);
	while (!q.empty())
	{
		TreeNode *node = q.front();
		node->print();
		q.pop();
		if (node->getLeft() != nullptr)
		{
			q.push(node->getLeft());
		}
		if (node->getRight() != nullptr)
		{
			q.push(node->getRight());
		}
	}
}

// aka level order 2-3-4 tree
void Tree::printLevelOrder()
{
	if (m_anker != nullptr)
	{
		std::queue<TreeNode *> Nodes;
		std::queue<int> Niveaus;

		Nodes.push(m_anker);
		Niveaus.push(0);
		int old_niveu = -1;
		while (!Nodes.empty())
		{
			TreeNode *node = Nodes.front();
			int niveau = Niveaus.front();
			Nodes.pop();
			Niveaus.pop();

			if (niveau != old_niveu)
			{
				std::cout << std::endl
						  << "Niveau: " << niveau;
				old_niveu = niveau;
			}

			std::cout << " ( ";

			if (node->getLeft() != nullptr)
			{
				if (node->getLeft()->getRed())
				{

					std::cout << node->getLeft()->getNodeOrderID() << ", ";

					if (node->getLeft()->getLeft() != nullptr)
					{
						Nodes.push(node->getLeft()->getLeft());
						Niveaus.push(niveau + 1);
					}
					if (node->getLeft()->getRight() != nullptr)
					{
						Nodes.push(node->getLeft()->getRight());
						Niveaus.push(niveau + 1);
					}
				}

				else
				{
					Nodes.push(node->getLeft());
					Niveaus.push(niveau + 1);
				}
			}

			std::cout << node->getNodeOrderID();

			if (node->getRight() != nullptr)
			{
				if (node->getRight()->getRed())
				{

					std::cout << ", " << node->getRight()->getNodeOrderID();

					if (node->getRight()->getLeft() != nullptr)
					{
						Nodes.push(node->getRight()->getLeft());
						Niveaus.push(niveau + 1);
					}
					if (node->getRight()->getRight() != nullptr)
					{
						Nodes.push(node->getRight()->getRight());
						Niveaus.push(niveau + 1);
					}
				}
				else
				{
					Nodes.push(node->getRight());
					Niveaus.push(niveau + 1);
				}
			}
			std::cout << " )";
		}
		std::cout << std::endl;
	}
}

void printNiveau(int start, int end, TreeNode *node)
{
	if (node == nullptr)
		return;

	if (start == end)
	{

		std::cout << "(";
		if (node->getLeft() != nullptr && node->getLeft()->getRed())
			std::cout << node->getLeft()->getNodeOrderID() << ", ";

		std::cout << node->getNodeOrderID();

		if (node->getRight() != nullptr && node->getRight()->getRed())
			std::cout << ", " << node->getRight()->getNodeOrderID();

		std::cout << ") ";
		return;
	}

	if (node->getLeft() != nullptr && !node->getLeft()->getRed())
		printNiveau(start + 1, end, node->getLeft());

	else if (node->getLeft() != nullptr && node->getLeft()->getRed())
	{
		printNiveau(start + 1, end, node->getLeft()->getLeft());
		printNiveau(start + 1, end, node->getLeft()->getRight());
	}

	if (node->getRight() != nullptr && !node->getRight()->getRed())
		printNiveau(start + 1, end, node->getRight());

	else if (node->getRight() != nullptr && node->getRight()->getRed())
	{
		printNiveau(start + 1, end, node->getRight()->getLeft());
		printNiveau(start + 1, end, node->getRight()->getRight());
	}
}

// aka print only one lvl of 2-3-4 tree
void Tree::printLevelOrder(int level)
{
	std::cout << "Level " << level << ": ";
	printNiveau(0, level, m_anker);
	std::cout << std::endl;
}
