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
    NUM=256,REAL,ID,AND,OR,EQ,NE,GE,LE,STR,CHAR,TYPE,KEY,ADD_A,ADD_E,MIN_M,MIN_E,MUL_E,DIV_E,ELSE,FOR,WHILE,DO,BREAK,CONTINUE,RETURN
};
struct SYNBL  //·ûºÅ±í
{
    string name;
    int type=-1;//0:bool,1:char,2:int,3:real
    int cat=-1; //0:º¯Êý¡£1£º±äÁ¿ 3£º³£Á¿ 4:ÁÙÊ±±äÁ¿
    int offset=0;//Æ«ÒÆµØÖ·
    int index=-1;
    int active;// µ±×Ö·û±íµÄÀàÐÍÊÇ³£Á¿Ê±£¬offsetÎª-1£¬indexÎª1Ê±´ú±íÖ¸ÏòvectorÖÐµÄnumber,indexÎª2£¬Ö¸Ïòmychar
    /*offset    index        º¬Òå
     -1         1           Ö¸ÏòvectorÖÐµÄnumber
     -1         2           Ö¸Ïòmychar
     ÕýÊý       0           ±äÁ¿µÄÆ«ÒÆÁ¿    ´ýÀ©ÕÅ*/

};
extern string Tag_Str[];
extern string keywords[k_w_len];//¹Ø¼ü×Ö±í
extern string typewords[t_w_len];
extern vector<SYNBL> idwords;//×Ö·û±í
extern vector<string> strwords;//´æ·Å×Ö·û´®µÄ³£Á¿±í
extern vector<string> mychar;//´æ·Å×Ö·ûµÄ³£Á¿±í
extern vector<double> number;//´æ·ÅÕûÊýÓëÐ¡ÊýµÄ³£Á¿±í
extern vector<SYNBL> temp;//±äÁ¿±í
extern int type_size[4];
extern bool grammer_error;
class Token     //ËùÓÐtokenÀàÐÍµÄ¸¸Àà£¬µ¥¸ö×Ö·ûµÄtagÖµ¼ÈÊÇ±êºÅÖµÒ²ÊÇascllÂëÖµ
{
    private:
        int tag;  //±êºÅ ÓÃÀ´Çø·Ö½ç·û£¬³£Á¿£¬±êÊ¶·û£¬¹Ø¼ü×ÖµÈ
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
        virtual int get_var_value(){}
        virtual void set_lexeme(int x) {}
        int active;
};
class Num: public Token//  ÊÇÕûÊý£¬Ð¡ÊýµÄtoken
{
    private:
        int value;//Ïàµ±ÓÚÖ¸Õë£¬ÓÃÀ´´ú±íÔÚnumberÊý×éÖÐµÄ¾ßÌåÎ»ÖÃ
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
class Word: public Token   //±êÊ¶·û¡¢ÀàÐÍ¡¢¹Ø¼ü×Ö¡¢×Ö·û´®µÄtoken
{
    private:
        int lexeme;
        string name;//ÓÃÀ´´ú±íÔÚ¸÷¸öÊý×éÖÐµÄÎ»ÖÃ
    public:
        Word(int t,int v,string x):Token(t),lexeme(v),name(x){};
        int get_lexeme()
        {
            return lexeme;
        }
        void set_lexeme(int x)
        {
            lexeme=x;
        }
        string get_lexeme_str()
        {
            /*if((this->get_tag())==ID) return idwords[lexeme].name;
            else if((this->get_tag())==TYPE) return typewords[lexeme];
            else if((this->get_tag())==KEY) return keywords[lexeme];
            else return strwords[lexeme];*/
                return name;
        }
};
class Char: public Token //char ÀàÐÍtoken
{
private:
    int value;//Ö¸Õë
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
class temp_var:public Token  //±äÁ¿ÀàÐÍµÄtoken
{
private:
    int var;//Ö¸Õë
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
bool find_const(Token *t);
class Env{
private:
    int start;//记录开始位置
    vector<SYNBL> cur_var;
public:
    Env(int x)
    {
        start=x;
    }
    void make_Env(Token* t)//声明模块使用
    {   int i;
        for(  i=0;i<cur_var.size();i++)
        {
         if(cur_var[i].name==t->get_lexeme_str())
          {
             t->set_lexeme(start+i);
             grammer_error=false;
             cout<<"muldefined_error"<<endl;
             break;
          }
        }
        if(i==cur_var.size())
        {
            SYNBL temp_synbl;
            temp_synbl.name=t->get_lexeme_str();

            cur_var.push_back(temp_synbl);
            idwords.push_back(temp_synbl);
            t->set_lexeme(idwords.size()-1);

        }

    }
    int serach(string y)
    {
        for(int i=0;i<cur_var.size();i++)
        {
            if(cur_var[i].name==y)
                return i+start;
        }
        return -1;
    }
    int serach_const(Token* t)
    {
        for(int i=0;i<cur_var.size();i++)
        {
            if(cur_var[i].name==t->get_lexeme_str())
            {

                if(idwords[i+start].cat==3)
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }

        }
        return 0;
    }
};
struct q   //ËÄÔªÊ½
{
    string op;
    Token* temp_1;
    Token* temp_2;
    Token* res;
};
int find_key(string x);  //´Ê·¨·ÖÎöÊ±£¬µ±È·ÈÏÊ±Ò»´®×Ö·ûÊ±£¬Çø·Ö±êÊ¶·û¡¢ÀàÐÍ¡¢¹Ø¼ü×Ö¡¢×Ö·û´®£¬½¨Á¢token ²¢Ñ¹Èëtokenlist
int get_keyindex(string x);//ÅÐ¶ÏÊÇ·ñÊÇ¹Ø¼ü×Ö£¬ÊÇ·µ»ØÎ»ÖÃ£¬·ñÔò·µ»Ø-1£»
int get_strindex(string x);
int get_typeindex(string x);
int get_idindex(string x);
int get_charindex(string x);
int str2num(string x);
int str2real(string x);
int get_tempindex(int x);//½¨Á¢ÁÙÊ±±äÁ¿µÄtoken
int lexer();
//È«¾Ö±äÁ¿
extern vector<Token*> token_list;
extern vector<q> QT;//ËÄÔªÊ½
extern int c;// ¼ÇÂ¼µ±Ç°¶È¡¢¶Á¹ýµÄtoken¸öÊý
extern stack<Token*> sem;//ÓïÒåÕ»
extern vector<Env*> env;
int type_change(Token* t1,Token *t2,int temp);//ÎªÁÙÊ±±äÁ¿¸³ÀàÐÍÖµ
//int type_change_logic(Token* t1,Token *t2);
void startMath();
bool start_E();
bool start_F();
bool start_T();
bool start_F();
bool start_A();
bool start_B();
bool act(int temp);
bool act_2();
/*********************±í´ïÊ½**************************/
bool startLogic();
bool act_logic(int temp);
/********************Âß¼­±í´ïÊ½***********************/
void startWhile();
bool act_while_wh();
bool act_while_do();
bool act_while_we();
/********************while****************************/
void startIf();
bool act_if_if();
bool act_if_el();
bool act_if_ie();
/***********************IF****************************/
bool startSuffix();
bool act_suffix_in();
bool act_suffix_de();
/**********************ºó×º±í´ïÊ½**********************/
void GEQ_0();
void GEQ_2();
void q_out();
void startFunBlo();
/***********************符号表************************/
bool find_var(Token *t);

#endif // LEXER_H_INCLUDED
