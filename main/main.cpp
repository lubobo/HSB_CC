#include<iostream>
#include"../headers/lexer.h"
#include"../headers/functionAnalysis.h"
#include"../headers/objCode.h"
using namespace std;
extern int lexer();
int c=0;
vector<q> QT;
stack<Token*> sem;
vector<Env*> env;

bool grammer_error=true;
int main(){
    lexer();
    /*for(int i=0;i<token_list.size();i++){
        cout<<token_list[i]->get_tag()<<";";
    }
    cout<<endl;*/
    functionAnalysis();
    cout<<"***************符号表***************"<<endl;
    for(int i=0;i<idwords.size();i++){
        cout<<"名称："<<idwords[i].name<<endl;
        cout<<"(0.函数 1.临时变量 2.变量3.常量):"<<idwords[i].cat<<endl;
        cout<<"(0.bool 1.char 2.int 3.real):"<<idwords[i].type<<endl;
        cout<<"数据段偏移量:"<<idwords[i].offset<<endl;
        cout<<"常量时用到的指针:"<<idwords[i].index<<endl;
        cout<<endl;
    }
    cout<<"*************临时变量符号表***************"<<endl;
    for(int i=0;i<temp.size();i++){
       cout<<"名称:"<<temp[i].name<<endl;
       cout<<"(0.函数 1.临时变量 2.变量3.常量):"<<temp[i].cat<<endl;
       cout<<"(0.bool 1.char 2.int 3.real):"<<temp[i].type<<endl;
       cout<<" 数据段偏移量:"<<temp[i].offset<<endl;
       cout<<"常量时用到的指针:"<<temp[i].index<<endl;
       cout<<endl;
    }
    cout<<"******************后端********************"<<endl;
    createObj();
    return 0;
}
