#include<iostream>
#include<stack>
#include"../headers/lexer.h"
using namespace std;

extern int lexer();

void functionAnalysis(){        //函数语义分析入口
    bool startParaAssign();
    /*for(int c=0;c<token_list.size();c++){
        cout<<token_list[c]->get_tag()<<endl;
    }*/
    startParaAssign();
}
bool startParaAssign(){         //参数声明模块
cout<<1<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
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
cout<<2<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
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
cout<<3<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
    bool startRight();
    void GEQ1();
    void nextW();
    if(token_list[c]->get_tag()==ID){
        nextW();
        if(token_list[c]->get_tag()=='='){
            sem.push(token_list[c]);
            nextW();
            sem.push(token_list[c]);
            startRight();
            GEQ1();             //'四元式=产生式'
        }else{
            return false;
        }
    }
}
bool startValue2(){             //变量分析X2模块
cout<<4<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
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
cout<<5<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
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
    }else{
        nextW();
    }
}
bool startRight(){             //右值模块
cout<<6<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
    bool startMath();
    startMath();
}
bool startStateClo(){           //声明闭包模块
cout<<7<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
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
cout<<8<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
    bool startStates();
    bool startFunBC();
    startStates();
    startFunBC();
}
bool startStates(){             //声明语句闭包模块
cout<<9<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
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
cout<<10<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
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
cout<<11<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
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
cout<<12<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
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
cout<<13<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
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
cout<<14<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
    bool startRight();
    void GEQ1();
    void nextW();
    if(token_list[c]->get_tag()=='='){
        sem.push(token_list[c]);
        nextW();
        sem.push(token_list[c]);
        startRight();
        GEQ1();
        if(token_list[c]->get_tag()==';'){
            nextW();
        }else{
            return false;
        }
    }
}
void nextW(){                       //取下一值模块
cout<<15<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
    c++;
}
void GEQ1(){
cout<<16<<endl;
cout<<'\"'<<token_list[c]->get_tag()<<'\"'<<endl;
    Token *n=sem.top();
    sem.pop();
    Token *m=sem.top();
    sem.pop();
    cout<<"("<<"="<<","<<n<<","<<"_"<<","<<m<<")"<<endl;
}
