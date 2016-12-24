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
extern vector<obj>objCode;
void createObj();
void assignMent();
void operation(string a);
#endif
