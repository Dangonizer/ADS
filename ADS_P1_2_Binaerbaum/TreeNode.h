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
    int m_NodeOrderId;
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
    TreeNode(int, int, string, int, double, int);
    int get_m_NodeOrderId();
    int get_m_NodeChronologicalID();
    string get_m_Name();
    int get_m_Age();
    double get_m_Income();
    int get_m_PostCode();
    TreeNode* get_m_left();
    TreeNode* get_m_right();
    void set_m_NodeOrderId(int);
    void set_m_NodeChronologicalID(int);
    void set_m_Name(string);
    void set_m_Age(int);
    void set_m_Income(double);
    void set_m_PostCode(int);
    void set_m_left(TreeNode*);
    void set_m_right(TreeNode*);
    void print();
    //
    ////////////////////////////////////
};
