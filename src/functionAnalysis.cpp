#include<iostream>
#include"../headers/lexer.h"
#include"../src/gra_analyze.cpp"
using namespace std;
extern int lexer();
int i=0;
bool functionAnalysis(){        //函数语义分析入口
    bool startParaAssign();
    for(int i=0;i<token_list.size();i++){
        cout<<token_list[i]->get_tag()<<endl;
    }
    startParaAssign();
}
bool startParaAssign(){         //参数声明模块
    bool startState();
    bool startStateClo();
    if(startState()){
        startStateClo();
    }
}
bool startState(){              //声明模块
    bool startType();
    bool startA();
    bool startInit();
    bool startValue1();
    bool startValue2();
    void nextW();
    if(token_list[i]->get_tag()=='const'){
        nextW();
        startType();
        startValue1();
    }else if(startType()){
        startValue2();
    }else{
        return false;
    }
}
bool startValue1(){             //变量分析X1模块
    bool startValue();
    bool startRight();
    void GEQ1();
    void nextW();
    if(startValue()){
        if(token_list[i]->get_tag()=='='){
            nextW();
            startRight();
            GEQ1();             //'四元式=产生式'
        }else{
            return false;
        }
    }
}
bool startValue2(){             //变量分析X2模块
    bool startValue();
    bool startInit();
    if(startValue()){
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
    if(token_list[i]->get_tag()=='='){
        nextW();
        startRight();
        GEQ1();
    }
}
bool startRight(){             //右值模块
    bool startAssign();
    startAssign();
}
bool startStateClo(){           //声明闭包模块
    bool startState();
    void nextW();
    if(token_list[i]->get_tag()==','){
        nextW();
        startState();
        startStateClo();
    }
}
bool startFunBlo(){             //函数块模块
    bool startStates();
    bool startFunBC();
    startStates();
    startFunBC();
}
bool startStates(){             //声明语句闭包模块
    bool startType();
    bool startValue1();
    bool startStates1();
    bool startValue2();
    bool startStates2();
    void nextW();
    if(token_list[i]->get_tag()=='const'){
        nextW();
        startType();
        startValue1();
        startStates1();
        if(token_list[i]->get_tag()==';'){
            nextW();
        }else{
            return false;
        }
    }
}
bool startState1(){             //声明语句闭包1模块
    bool startValue1();
    void nextW();
    if(token_list[i]->get_tag()==','){
        nextW();
        startValue1();
    }else{
        return false;
    }
}
bool startState2(){             //声明语句闭包2模块
    bool startValue2();
    void nextW();
    if(token_list[i]->get_tag()==','){
        nextW();
        startValue2();
    }else{
        return false;
    }
}
bool startFunBC(){              //函数快闭包模块
    bool startAssiFun();
    bool startFor();
    bool startIf();
    bool startReturn();
    if(startAssiFun()){
        startFunBC();
    }else if(startFor()){
        startFunBC();
    }else if(startIf()){
        startFunBC();
    }else if(startReturn()){
        startFunBC();
    }
}
bool startAssiFun(){                //赋值函数模块
    bool startValue();
    bool startAssi();
    if(startValue()){
        startAssi();
    }else{
        return false;
    }
}
bool startAssi(){                   //赋值函数调用模块
    bool startRight();
    void nextW();
    if(token_list[i]->get_tag()=='='){
        nextW();
        startRight();
        if(token_list[i]->get_tag()==';'){
            nextW();
        }else{
            return false;
        }
    }
}
void nextW(){                       //取下一值模块
    i++;
}
