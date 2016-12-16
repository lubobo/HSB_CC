#include<iostream>
#include<stack>
#include"../headers/lexer.h"
using namespace std;
extern int lexer();
void functionAnalysis(){        //函数语义分析入口
    bool startFunAssi();
    if(startFunAssi()){
        if(token_list[c]->get_tag()==125){
            cout<<"yes"<<endl;
        }else{
            cout<<"shit"<<endl;
        }
    }else{
        //cout<<token_list[c]->get_tag()<<endl;
        cout<<"worning"<<endl;
    }
}
bool startFunAssi(){             //函数定义模块
    void nextW();
    bool startParaAssign();
    bool startFunBlo();
    if(token_list[c]->get_tag()==TYPE){
        cout<<"TYPE:"<<token_list[c]->get_tag()<<endl;
        nextW();
        if(token_list[c]->get_tag()==ID){
            cout<<"ID:"<<token_list[c]->get_tag()<<endl;
            nextW();
            if(token_list[c]->get_tag()=='('){
                cout<<"(:"<<token_list[c]->get_tag()<<endl;
                nextW();
                startParaAssign();
                if(token_list[c]->get_tag()==')'){
                    cout<<"):"<<token_list[c]->get_tag()<<endl;
                    nextW();
                    if(token_list[c]->get_tag()=='{'){
                        cout<<"{:"<<token_list[c]->get_tag()<<endl;
                        nextW();
                        startFunBlo();
                        if(token_list[c]->get_tag()=='}'){
                            cout<<"}"<<token_list[c]->get_tag()<<endl;
                            //nextW();
                            return true;
                        }else{
                            return false;
                        }
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

/*********************************参数声明模块****************************/
bool startParaAssign(){         //参数声明模块
    bool startState();
    bool startStateClo();
    void nextW();
    cout<<"参数"<<token_list[c]->get_tag()<<endl;
    if(token_list[c]->get_tag()==41){
        return 1;
    }else if(startState()&&token_list[c]->get_tag()!=41){           //需判断startState
        startStateClo();
    }
}
bool startState(){              //声明模块
    bool startInit();
    bool startValue1();
    bool startValue2();
    void nextW();
    cout<<"声明"<<token_list[c]->get_tag()<<endl;
    if(token_list[c]->get_lexeme_str()=="const"){
        nextW();
        if(token_list[c]->get_tag()==TYPE){
            nextW();
            startValue1();
        }
    }else if(token_list[c]->get_tag()==TYPE){
        nextW();
        startValue2();
    }else{
        //nextW();
    }
}
bool startValue1(){             //变量分析X1模块
    bool startRight();
    //bool startMath();
    void GEQ1();
    void nextW();
    cout<<"X1："<<token_list[c]->get_tag()<<endl;
    if(token_list[c]->get_tag()==ID){
        nextW();
        if(token_list[c]->get_tag()=='='){
            sem.push(token_list[c-1]);
            nextW();
            sem.push(token_list[c-2]);
            startRight();
            GEQ1();             //'四元式=产生式'
            nextW();
            q_out();
        }
    }
}
bool startValue2(){             //变量分析X2模块
    void nextW();
    bool startRight();
    //bool startMath();
    void GEQ1();
    cout<<"X2："<<token_list[c]->get_tag()<<endl;
    if(token_list[c]->get_tag()==ID){
        nextW();
        if(token_list[c]->get_tag()=='='){
            sem.push(token_list[c-1]);
            nextW();
            sem.push(token_list[c-2]);
            startRight();
            GEQ1();
            nextW();
            q_out();
        }
    }else{
        //nextW();
        return 1;
    }
}
bool startRight(){             //右值模块
    bool startMath();
    cout<<"右值"<<token_list[c]->get_tag()<<endl;
    startMath();
}
bool startStateClo(){           //声明闭包模块
    bool startState();
    void nextW();
    cout<<"声明闭包"<<token_list[c]->get_tag()<<endl;
    if(token_list[c]->get_tag()==','){
        nextW();
        if(startState()){
            if(startStateClo()){
                return true;
            }else{
                return false;
            }
        }
    }else{
        nextW();
        return true;
    }
}

/*********************************函数块模块******************************/
bool startFunBlo(){                //函数块模块
    bool startStates();
    bool startFunBC();
    cout<<"函数块"<<token_list[c]->get_tag()<<endl;
    startStates();
    startFunBC();
}
bool startStates(){                //声明语句闭包模块
    bool startValue1();
    bool startState1();
    bool startValue2();
    bool startState2();
    void nextW();
    cout<<"声明闭包语句"<<token_list[c]->get_tag()<<endl;
    if(token_list[c]->get_lexeme_str()=="const"){
        nextW();
        if(token_list[c]->get_tag()==TYPE){
            nextW();
            startValue1();
            startState1();
            if(token_list[c]->get_tag()==';'){
                nextW();
            }
        }
    }else if(token_list[c]->get_tag()==TYPE){
        nextW();
        startValue2();
        startState2();
        if(token_list[c]->get_tag()==';'){
            nextW();
        }
    }else{
        nextW();
    }
}
bool startState1(){                //声明语句闭包1模块
    bool startValue1();
    void nextW();
    cout<<"声明闭包语句1:"<<token_list[c]->get_tag()<<endl;
    if(token_list[c]->get_tag()==','){
        nextW();
        startValue1();
        //return true;
    }else{
        //nextW();
        return 1;
    }
}
bool startState2(){                //声明语句闭包2模块
    bool startValue2();
    void nextW();
    cout<<"声明闭包语句2:"<<token_list[c]->get_tag()<<endl;
    if(token_list[c]->get_tag()==','){
        nextW();
        startValue2();
        //return true;
    }else{
        //nextW();
        return 1;
    }
}
bool startFunBC(){                 //函数块闭包模块
    bool startAssiFun();
    bool startFor();
    bool startIf();
    bool startReturn();
    void nextW();
    cout<<"函数块闭包"<<token_list[c]->get_tag()<<endl;
    if(startAssiFun()){            //需判断赋值函数
        startFunBC();
        nextW();
    }else{
        //nextW();
        return 1;
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
    cout<<"赋值函数"<<token_list[c]->get_tag()<<endl;
    if(token_list[c]->get_tag()==ID){
        nextW();
        startAssi();                //需判断赋值或函数调用模块
        if(token_list[c]->get_tag()=='='){
            startAssi();
        }
    }
}
bool startAssi(){                   //赋值函数调用模块
    bool startRight();
    void GEQ1();
    void nextW();
    cout<<"赋值函数调用"<<token_list[c]->get_tag()<<endl;
    if(token_list[c]->get_tag()=='='){
        sem.push(token_list[c-1]);
        nextW();
        sem.push(token_list[c-2]);
        startRight();
        GEQ1();
        nextW();
        if(token_list[c+1]->get_tag()==';'){
            nextW();
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
void nextW(){                       //取下一值模块
    c++;
}
void GEQ1(){
    //cout<<sem.top()->get_tag()<<endl;
    Token *n=sem.top();
    cout<<sem.top()->get_tag()<<endl;
    sem.pop();
    Token *m=sem.top();
    cout<<sem.top()->get_tag()<<endl;
    sem.pop();
    //cout<<"("<<"="<<","<<n->get_tag()<<","<<"_"<<","<<m->get_tag()<<")"<<endl;
    //q_out();
    /***************四元式存储***************/
    q fuck;
    fuck.op="=";
    fuck.temp_1=n;
    fuck.temp_2=m;
    fuck.res=new temp_var(-1,get_tempindex());
    sem.push(fuck.res);
    QT.push_back(fuck);
    /***************符号表存储***************/
    string v="t",a;
    int i=temp.size();
    if(i==0){
        v+="0";
    }
    while(i!=0){
        a+='0'+i%10;
        i=i/10;
    }
    for(int i=a.size()-1;i>=0;i--){
        v+=a[i];
    }
    SYNBL symbol;
    symbol.name=v;
    temp.push_back(symbol);
}
