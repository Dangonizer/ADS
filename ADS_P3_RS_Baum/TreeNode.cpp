#include "TreeNode.h"
#include <iostream>
#include <string>

TreeNode::TreeNode(int nNodePos, int id, std::string name, int age, double income, int postCode)
	: m_NodeChronologicalID{id},
	  m_NodeOrderID{nNodePos}, m_Name{name}, m_Age{age}, m_Income{income}, m_PostCode{postCode}, m_left{nullptr}, m_right{nullptr}, m_red{true}, m_parent{nullptr}
{
}

int TreeNode::getNodeChronologicalID() const
{
	return this->m_NodeChronologicalID;
}

int TreeNode::getNodeOrderID() const
{
	return this->m_NodeOrderID;
}

std::string TreeNode::getName() const
{
	return this->m_Name;
}

void TreeNode::setName(std::string nName)
{
	this->m_Name = nName;
}

int TreeNode::getAge() const
{
	return this->m_Age;
}

void TreeNode::setAge(int nAlter)
{
	this->m_Age = nAlter;
}

double TreeNode::getIncome() const
{
	return this->m_Income;
}

void TreeNode::setIncome(double nIN)
{
	this->m_Income = nIN;
}

int TreeNode::getPostCode() const
{
	return this->m_PostCode;
}

void TreeNode::setPostCode(int nPLZ)
{
	this->m_PostCode = nPLZ;
}

TreeNode *TreeNode::getLeft() const
{
	return this->m_left;
}

void TreeNode::setLeft(TreeNode *nLeft)
{
	this->m_left = nLeft;
}

TreeNode *TreeNode::getRight() const
{
	return this->m_right;
}

void TreeNode::setRight(TreeNode *nRight)
{
	this->m_right = nRight;
}

bool TreeNode::getRed() const
{
	return this->m_red;
}

void TreeNode::setRed(bool nRed)
{
	this->m_red = nRed;
}

TreeNode *TreeNode::getParent() const
{
	return this->m_parent;
}

void TreeNode::setParent(TreeNode *nParent)
{
	this->m_parent = nParent;
}

void TreeNode::print() const
{
	std::cout << "NodeID: " << this->m_NodeOrderID
			  << ", Name: " << this->m_Name
			  << ", Alter: " << this->m_Age
			  << ", Einkommen: " << this->m_Income
			  << ", PLZ: " << this->m_PostCode
			  << ", PosID: " << this->m_NodeChronologicalID << std::endl;
}
