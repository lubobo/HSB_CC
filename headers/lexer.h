#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#define k_w_len  10
#define t_w_len 5
using namespace std;
enum Tag
{
    NUM=256,REAL,ID,AND,OR,EQ,NE,GE,LE,STR,CHAR,TYPE,KEY,ADD_A,ADD_E,MIN_M,MIN_E,MUL_E,DIV_E,IF,ELSE,FOR,WHILE,DO,BREAK,CONTINUE,RETURN
};
struct SYNBL  //符号表
{
    string name;
    int type;//0:bool,1:char,2:int,3:real
    int cat; //0:函数。1：变量 3：常量 4:临时变量
    int offset;//偏移地址
    int index;// 当字符表的类型是常量时，offset为-1，index为1时代表指向vector中的number,index为2，指向mychar
    /*offset    index        含义
     -1         1           指向vector中的number
     -1         2           指向mychar
     正数       0           变量的偏移量    待扩张*/

};
extern string Tag_Str[];
extern string keywords[k_w_len];//关键字表
extern string typewords[t_w_len];
extern vector<SYNBL> idwords;//字符表
extern vector<string> strwords;//存放字符串的常量表
extern vector<string> mychar;//存放字符的常量表
extern vector<double> number;//存放整数与小数的常量表
extern vector<SYNBL> temp;//变量表
class Token     //所有token类型的父类，单个字符的tag值既是标号值也是ascll码值
{
    private:
        int tag;  //标号 用来区分界符，常量，标识符，关键字等
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
        virtual string  get_var(){}
};
class Num: public Token//  是整数，小数的token
{
    private:
        int value;//相当于指针，用来代表在number数组中的具体位置
    public:
        Num(int t,int v ):Token(t),value(v){};
        int get_numindex()
        {
            return value;
        }
        double get_numvalue()
        {
            return number[value];
        }

};
class Word: public Token   //标识符、类型、关键字、字符串的token
{
    private:
        int lexeme;//用来代表在各个数组中的位置
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
class Char: public Token //char 类型token
{
private:
    int value;//指针
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
class temp_var:public Token  //变量类型的token
{
private:
    int var;//指针
public:
    temp_var(int t,int v):Token(t),var(v){};
    int get_var_value()
    {
        return var;
    }
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
    Token* res;
};
int find_key(string x);  //词法分析时，当确认时一串字符时，区分标识符、类型、关键字、字符串，建立token 并压入tokenlist
int get_keyindex(string x);//判断是否是关键字，是返回位置，否则返回-1；
int get_strindex(string x);
int get_typeindex(string x);
int get_idindex(string x);
int get_charindex(string x);
int str2num(string x);
int str2real(string x);
int get_tempindex(int x);//建立临时变量的token
int lexer();
//全局变量
extern vector<Token*> token_list;
extern vector<q> QT;//四元式
extern int c;// 记录当前度、读过的token个数
extern stack<Token*> sem;//语义栈
int type_change(Token* t1,Token *t2);//为临时变量赋类型值
bool startMath();
bool start_E();
bool start_F();
bool start_T();
bool start_F();
bool start_A();
bool start_B();
bool act(int temp);
bool act_2();
/*********************表达式**************************/
bool startLogic();
bool act_logic(int temp);
/********************逻辑表达式***********************/
bool startWhile();
bool act_while_wh();
bool act_while_do();
bool act_while_we();
/********************while****************************/
bool startIf();
bool act_if_if();
bool act_if_el();
bool act_if_ie();
/***********************IF****************************/
bool startSuffix();
bool act_suffix_in();
bool act_suffix_de();
/**********************后缀表达式**********************/
void q_out();
#endif // LEXER_H_INCLUDED
