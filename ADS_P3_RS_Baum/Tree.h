/*************************************************
 * ADS Praktikum 3
 * Tree.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.h"

class Tree
{

private:
	TreeNode *m_anker;
	int m_CurrentNodeChronologicalID;

	bool split4Node(TreeNode *node);
	void balance(TreeNode *node);
	bool rotateTreeRight(TreeNode *node);
	bool rotateTreeLeft(TreeNode *node);

public:
	Tree();
	~Tree();

	bool addNode(std::string Name, int Age, double Income, int PostCode);
	bool searchNode(std::string);
	int proofRBCriterion(TreeNode *node);

	void printAll();
	void printLevelOrder();
	void printLevelOrder(int level);

	// friend-Funktionen sind f�r die Tests erforderlich und m�ssen unangetastet bleiben!
	friend TreeNode *get_anker(Tree &TN);
};
