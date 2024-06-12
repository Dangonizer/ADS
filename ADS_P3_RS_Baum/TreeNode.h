/*************************************************
 * ADS Praktikum 3
 * TreeNode.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include <string>

class TreeNode
{

private:
	///////////////////////////////////////
	// Ihr Code hier:
	int m_NodeChronologicalID;
	int m_NodeOrderID;
	std::string m_Name;
	int m_Age;
	double m_Income;
	int m_PostCode;
	TreeNode *m_left;
	TreeNode *m_right;
	bool m_red;
	TreeNode *m_parent;
	//
	////////////////////////////////////

public:
	///////////////////////////////////////
	// Ihr Code hier:
	TreeNode();
	explicit TreeNode(int nNodePos, int id, std::string name, int age, double income, int postCode);
	int getNodeChronologicalID() const;
	int getNodeOrderID() const;
	int getAge() const;
	void setAge(int);
	double getIncome() const;
	void setIncome(double);
	int getPostCode() const;
	void setPostCode(int);
	std::string getName() const;
	void setName(std::string Name);
	TreeNode *getLeft() const;
	TreeNode *getRight() const;
	void setLeft(TreeNode *);
	void setRight(TreeNode *);
	void print() const;
	bool getRed() const;
	void setRed(bool);
	TreeNode *getParent() const;
	void setParent(TreeNode *);
	//
	////////////////////////////////////
};
