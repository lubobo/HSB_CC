#include<iostream>
#include"../headers/lexer.h"
using namespace std;
extern int lexer();
int i=0;
bool functionAnalysis(){
    bool startParaAssign();
    for(int i=0;i<token_list.size();i++){
        cout<<token_list[i]->get_tag()<<endl;
    }
    startParaAssign();
}
bool startParaAssign(){
    bool startState();
    bool startStateClo();
    if(startState()){
        startStateClo();
    }
}
bool startState(){
    bool startType();
    bool startA();
    bool startInit();
    startType();
    startA();
    startInit();
}
bool startInit(){
    bool startRight();
    bool startData();
    void nextW();
    if(token_list[i]->get_tag()=='='){
        nextW();
        startRight();
    }
}
bool startData(){
    bool startDig();
    bool startDigClo();
    startDig();
    startDigClo();
}
bool startDigClo(){
    bool startDig();
    void nextW();
    if(token_list[i]->get_tag()==','){
        nextW();
        startDig();
        startDigClo();
    }
}
bool startStateClo(){
    bool startState();
    void nextW();
    if(token_list[i]->get_tag()==','){
        nextW();
        startState();
        startStateClo();
    }
}
bool startStates(){
    bool startState();
    void nextW();
    startState();
    if(token_list[i]->get_tag()==';'){
        nextW();
    }
}
bool startFunBC(){
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
bool startFunBlo(){
    bool startStateClo();
    bool startFunBC();
    startStateClo();
    startFunBC();
}
bool startAssign(){
    bool startRight();
    bool startParaList();
    void nextW();
    if(token_list[i]->get_tag()=='='){
        nextW();
        startRight();
    }else{
        startParaList();
    }
}
bool startParaList(){
    bool startPara();
    bool startParaClo();
    if(startPara()){
        startParaClo();
    }
}
bool startParaClo(){
    bool startPara();
    void nextW();
    if(token_list[i]->get_tag()==','){
        nextW();
        startPara();
        startParaClo();
    }
}
bool startPara(){
    bool startDig();
    bool startString();
    void nextW();
    if(token_list[i]->get_tag()==ID){
        nextW();
    }else if(startDig()){
        nextW();
    }else if(startString()){
        nextW();
    }
}
bool startString(){
    void nextW();
    if(token_list[i]->get_tag()==STR){
        nextW();
    }
}
void nextW(){
    i++;
}
