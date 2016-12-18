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
struct SYNBL  //���ű�
{
    string name;
    int type;//0:bool,1:char,2:int,3:real
    int cat; //0:������1������ 3������ 4:��ʱ����
    int offset;//ƫ�Ƶ�ַ
    int index;// ���ַ���������ǳ���ʱ��offsetΪ-1��indexΪ1ʱ����ָ��vector�е�number,indexΪ2��ָ��mychar
    /*offset    index        ����
     -1         1           ָ��vector�е�number
     -1         2           ָ��mychar
     ����       0           ������ƫ����    ������*/

};
extern string Tag_Str[];
extern string keywords[k_w_len];//�ؼ��ֱ�
extern string typewords[t_w_len];
extern vector<SYNBL> idwords;//�ַ���
extern vector<string> strwords;//����ַ����ĳ�����
extern vector<string> mychar;//����ַ��ĳ�����
extern vector<double> number;//���������С���ĳ�����
extern vector<SYNBL> temp;//������
class Token     //����token���͵ĸ��࣬�����ַ���tagֵ���Ǳ��ֵҲ��ascll��ֵ
{
    private:
        int tag;  //��� �������ֽ������������ʶ�����ؼ��ֵ�
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
class Num: public Token//  ��������С����token
{
    private:
        int value;//�൱��ָ�룬����������number�����еľ���λ��
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
class Word: public Token   //��ʶ�������͡��ؼ��֡��ַ�����token
{
    private:
        int lexeme;//���������ڸ��������е�λ��
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
class Char: public Token //char ����token
{
private:
    int value;//ָ��
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
class temp_var:public Token  //�������͵�token
{
private:
    int var;//ָ��
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
struct q   //��Ԫʽ
{
    string op;
    Token* temp_1;
    Token* temp_2;
    Token* res;
};
int find_key(string x);  //�ʷ�����ʱ����ȷ��ʱһ���ַ�ʱ�����ֱ�ʶ�������͡��ؼ��֡��ַ���������token ��ѹ��tokenlist
int get_keyindex(string x);//�ж��Ƿ��ǹؼ��֣��Ƿ���λ�ã����򷵻�-1��
int get_strindex(string x);
int get_typeindex(string x);
int get_idindex(string x);
int get_charindex(string x);
int str2num(string x);
int str2real(string x);
int get_tempindex(int x);//������ʱ������token
int lexer();
//ȫ�ֱ���
extern vector<Token*> token_list;
extern vector<q> QT;//��Ԫʽ
extern int c;// ��¼��ǰ�ȡ�������token����
extern stack<Token*> sem;//����ջ
int type_change(Token* t1,Token *t2);//Ϊ��ʱ����������ֵ
bool startMath();
bool start_E();
bool start_F();
bool start_T();
bool start_F();
bool start_A();
bool start_B();
bool act(int temp);
bool act_2();
/*********************���ʽ**************************/
bool startLogic();
bool act_logic(int temp);
/********************�߼����ʽ***********************/
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
/**********************��׺���ʽ**********************/
void q_out();
#endif // LEXER_H_INCLUDED
