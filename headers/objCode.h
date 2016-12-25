#ifndef OBJCODE_H_INCLUDED
#define OBJCODE_H_INCLUDED
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
struct obj{
    string op;
    string R0;
    string R1;
};
struct R{
    string name;
    string var;
    int flag;
    int active;
};
extern vector<obj>objCode;
extern vector<R> RDL;
void createObj();
void assignMent();
void operation(string a);
void GETR(int i);
#endif
