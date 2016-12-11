#pragma once
#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED
#include<iostream>
#include<string>
#include<vector>
#define k_w_len  10
#define t_w_len 4
using namespace std;
enum Tag
{
    NUM=256,REAL,ID,AND,OR,EQ,NE,GE,LE,STR,CHAR,TYPE,KEY,ADD_A,ADD_E,MIN_M,MIN_E,MUL_E,DIV_E,IF,ELSE,FOR,WHILE,DO,BREAK,CONTINUE,RETURN
};
struct SYNBL  //符号表
{
    string name;
    int type;//0:int,1:real,2:char
    int cat; //0:函数。1：变量 3：常量
    int offset;
    int index;
};
extern string Tag_Str[];
extern string keywords[k_w_len];//关键字表
extern string typewords[t_w_len];
extern vector<SYNBL> idwords;//字符表
extern vector<string> strwords;//常数表
extern vector<string> mychar;
extern vector<double> number;
extern vector<SYNBL> temp;//变量表
class Token
{
    private:
        int tag;
    public:
        Token(){}
        Token(int i)
        {
            tag=i;
        }
        int get_tag()
        {
            return tag;
        }
        virtual double get_numvalue(){}
        virtual int get_numindex(){}
        virtual int get_value(){}
        virtual int get_lexeme(){}
        virtual string get_lexeme_str(){}
        virtual string get_Char(){}
        virtual string get_var(){}
};
class Num: public Token//整数和小数
{
    private:
        int value;
    public:
        Num(int t,int v):Token(t),value(v){};
        int get_numindex()
        {
            return value;
        }
        double get_numvalue()
        {
            cout<<value<<" ";
            return number[value];
        }
};
class Word: public Token   //标识符、类型、关键字
{
    private:
        int lexeme;
    public:
        Word(int t,int v):Token(t),lexeme(v){};
        int get_lexeme()
        {
            return lexeme;
        }
        string get_lexeme_str()
        {
            if((this->get_tag())==ID) return idwords[lexeme].name;
            else if((this->get_tag())==TYPE) return typewords[lexeme];
            else if((this->get_tag())==KEY) return keywords[lexeme];
            else return strwords[lexeme];
        }
};
class Char: public Token
{
private:
    int value;
public:
    Char(int t,int v):Token(t),value(v){};
    int get_value()
    {
        return value;
    }
   string get_Char()
    {
        return mychar[value];
    }
};
class temp_var:public Token
{
private:
    int var;
public:
    temp_var(int t,int v):Token(t),var(v){};
    string  get_var()
    {
        return temp[var].name;
    }

};
struct q   //四元式
{
    string op;
    Token* temp_1;
    Token* temp_2;
    Token*  res;
};
int find_key(string x);
int get_keyindex(string x);
int get_strindex(string x);
int get_typeindex(string x);
int get_idindex(string x);
int get_charindex(string x);
int str2num(string x);
int str2real(string x);
int  get_tempindex();
int lexer();
extern vector<Token*> token_list;
void startMath();
bool start_E();
bool start_F();
bool start_T();
bool start_F();
bool start_A();
bool start_B();
bool act(int temp);
bool act_2();
void q_out();

#endif // LEXER_H_INCLUDED
