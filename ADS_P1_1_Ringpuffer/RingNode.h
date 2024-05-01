/*************************************************
* ADS Praktikum 1.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>

class RingNode{
	
private:
	//
	int m_oldAge;
	std::string m_description;
	std::string m_symbolicData;
	RingNode* m_next;
	//	
public:
	//
	RingNode(int age, std::string description, std::string symbolicData){this->m_description = description; this->m_symbolicData = symbolicData; this->m_next = nullptr; this->m_oldAge = age;}
	RingNode(){this->m_description = ""; this->m_symbolicData = ""; this->m_next = nullptr; this->m_oldAge = 0;}
	int getOldAge() {return m_oldAge;}
	void setOldAge(int oldAge) {this->m_oldAge = oldAge;}
	std::string getDescription(){return m_description;}
	void setDescription(std::string description){this->m_description = description;}
	std::string getSymbolicData(){return m_symbolicData;}
	void setSymbolicData(std::string symbolicData){this->m_symbolicData = symbolicData;}
	RingNode* getNext(){return m_next;}
	void setNext(RingNode* next){this->m_next = next;}
	//
};
