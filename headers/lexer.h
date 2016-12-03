#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED
#include<iostream>
#include<string>
#include<vector>
#define k_w_len  10
#define t_w_len 4
using namespace std;
enum Tag{
    NUM=256,REAL,ID,AND,OR,EQ,NE,GE,LE,STR,CHAR,TYPE,KEY,ADD_A,ADD_E,MIN_M,MIN_E,MUL_E,DIV_E,IF,ELSE,FOR,WHILE,DO,BREAK,CONTINUE,RETURN
};

string Tag_Str[]={
    "NUM","REAL","ID","AND","OR","EQ","NE","GE","LE","STR","CHAR","TYPE","KEY","ADD_A","ADD_E","MIN_M","MIN_E","MUL_E","DIV_E","IF","ELSE","FOR","WHILE","DO","BREAK","CONTINUE","RETURN"
};
string keywords[k_w_len]={"main","void","if","else","for","while","do","break","continue","return"};
string typewords[t_w_len]={"int","real","char","const"};
vector<string> idwords;
vector<string> strwords;
vector<string> mychar;
class Token{
    private:
        int tag;
    public:
        Token(){}
        Token(int i){
            tag=i;
        }
        int get_tag(){
            return tag;
        }
        virtual int get_numvalue(){}
        virtual double get_realvalue(){}
        virtual int get_lexeme(){}
        virtual string get_lexeme_str(){}
        virtual string get_Char(){}
};
class Num: public Token{    //ÕûÊý{
    private:
        int value;
    public:
        Num(int t,int v):Token(t),value(v){};
        int get_numvalue(){
            return value;
        }
};
class Real: public Token{   //ÊµÊý{
    private:
        double value;
    public:
        Real(int t,double v):Token(t),value(v){};
        double get_realvalue(){
            return value;
        }
};
class Word: public Token{   //±êÊ¶·û¡¢ÀàÐÍ¡¢¹ØŒü×Ö{
    private:
        int lexeme;
    public:
        Word(int t,int v):Token(t),lexeme(v){};
        int get_lexeme(){
            return lexeme;
        }
        string get_lexeme_str(){
            if((this->get_tag())==ID) return idwords[lexeme];
            else if((this->get_tag())==TYPE) return typewords[lexeme];
            else if((this->get_tag())==KEY) return keywords[lexeme];
            else return strwords[lexeme];
        }
};
class Char: public Token{
    private:
        int value;
    public:
        Char(int t,int v):Token(t),value(v){};
        int get_value(){
            return value;
        }
    string get_Char(){
        return mychar[value];
    }
};
int find_key(string x);
int get_keyindex(string x);
int get_strindex(string x);
int get_typeindex(string x);
int get_idindex(string x);
int get_charindex(string x);
int str2num(string x);
double str2real(string x);
vector<Token*> token_list;
#endif // LEXER_H_INCLUDED
