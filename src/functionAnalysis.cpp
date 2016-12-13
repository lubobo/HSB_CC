#include<iostream>
#include<stack>
#include"../headers/lexer.h"
using namespace std;
extern int lexer();
extern int y=0;
void functionAnalysis(){        //函数语义分析入口
    bool startParaAssign();
    startParaAssign();
}
bool startParaAssign(){         //参数声明模块
    bool startState();
    bool startStateClo();
    void nextW();
    if(startState()){
        startStateClo();
    }else{
        nextW();
    }
}
bool startState(){              //声明模块
    bool startInit();
    bool startValue1();
    bool startValue2();
    void nextW();
    if(token_list[c]->get_tag()==TYPE&&token_list[c]->get_lexeme_str()=="const"){
        nextW();
        if(token_list[c]->get_tag()==TYPE){
            nextW();
            startValue1();
        }
    }else if(token_list[c]->get_tag()==TYPE){
        nextW();
        startValue2();
    }else{
        return false;
    }
}
bool startValue1(){             //变量分析X1模块
    bool startRight();
    void GEQ1();
    void nextW();
    if(token_list[c]->get_tag()==ID){
        nextW();
        if(token_list[c]->get_tag()=='='){
            sem.push(token_list[c-1]);
            nextW();
            sem.push(token_list[c]);
            startRight();
            GEQ1();             //'四元式=产生式'
            y++;
        }else{
            return false;
        }
    }
}
bool startValue2(){             //变量分析X2模块
    void nextW();
    bool startInit();
    if(token_list[c]->get_tag()==ID){
        nextW();
        startInit();
    }else{
        return false;
    }
}
bool startInit(){               //赋初值模块
    bool startRight();
    bool startData();
    void nextW();
    void GEQ1();
    if(token_list[c]->get_tag()=='='){
        sem.push(token_list[c]);
        nextW();
        sem.push(token_list[c]);
        startRight();
        GEQ1();
        y++;
    }else{
        nextW();
    }
}
bool startRight(){             //右值模块
    bool startMath();
    startMath();
}
bool startStateClo(){           //声明闭包模块
    bool startState();
    void nextW();
    if(token_list[c]->get_tag()==','){
        nextW();
        startState();
        startStateClo();
    }else{
        nextW();
    }
}
bool startFunBlo(){             //函数块模块
    bool startStates();
    bool startFunBC();
    startStates();
    startFunBC();
}
bool startStates(){             //声明语句闭包模块
    bool startValue1();
    bool startState1();
    bool startValue2();
    bool startState2();
    void nextW();
    if(token_list[c]->get_tag()==TYPE&&token_list[c]->get_lexeme_str()=="const"){
        nextW();
        if(token_list[c]->get_tag()==TYPE){
            nextW();
            startValue1();
            startState1();
            if(token_list[c]->get_tag()==';'){
                nextW();
            }else{
                return false;
            }
        }
    }else if(token_list[c]->get_tag()==TYPE){
        nextW();
        startValue2();
        startState2();
        if(token_list[c]->get_tag()==';'){
            nextW();
        }else{
            return false;
        }
    }else{
        nextW();
    }
}
bool startState1(){             //声明语句闭包1模块
    bool startValue1();
    void nextW();
    if(token_list[c]->get_tag()==','){
        nextW();
        startValue1();
    }else{
        nextW();
    }
}
bool startState2(){             //声明语句闭包2模块
    bool startValue2();
    void nextW();
    if(token_list[c]->get_tag()==','){
        nextW();
        startValue2();
    }else{
        nextW();
    }
}
bool startFunBC(){              //函数快闭包模块
    bool startAssiFun();
    bool startFor();
    bool startIf();
    bool startReturn();
    void nextW();
    if(startAssiFun()){
        startFunBC();
    }else{
        nextW();
    }/*else if(startFor()){
        startFunBC();
    }else if(startIf()){
        startFunBC();
    }else if(startReturn()){
        startFunBC();
    }*/
}
bool startAssiFun(){                //赋值函数模块
    bool startAssi();
    void nextW();
    if(token_list[c]->get_tag()==ID){
        nextW();
        startAssi();
    }else{
        return false;
    }
}
bool startAssi(){                   //赋值函数调用模块
    bool startRight();
    void GEQ1();
    void nextW();
    if(token_list[c]->get_tag()=='='){
        sem.push(token_list[c-1]);
        nextW();
        sem.push(token_list[c]);
        startRight();
        GEQ1();
        y++;
        if(token_list[c]->get_tag()==';'){
            nextW();
        }else{
            return false;
        }
    }
}
void nextW(){                       //取下一值模块
    c++;
}
void GEQ1(){
    Token *n=sem.top();
    sem.pop();
    Token *m=sem.top();
    sem.pop();
    cout<<"("<<"="<<","<<n->get_tag()<<","<<"_"<<","<<"t"<<y<<")"<<endl;
    q fuck;
    fuck.op="=";
    fuck.temp_1=n;
    fuck.temp_2=m;
    fuck.res=new temp_var(-1,get_tempindex());
    sem.push(fuck.res);
    QT.push_back(fuck);
    SYNBL symbol;
    symbol.name=(string)("t"+y);
    temp.push_back(symbol);
}
