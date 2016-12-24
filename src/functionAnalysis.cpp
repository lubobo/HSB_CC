#include<iostream>
#include<stack>
#include"../headers/lexer.h"
using namespace std;

void functionAnalysis(){        //函数语义分析入口
    void startFunAssi();
    if(grammer_error){
        startFunAssi();
        if(c<token_list.size()&&token_list[c]->get_tag()==125&&grammer_error){

            q_out();
            cout<<"yes"<<endl;
        }else{
            cout<<"shit"<<endl;
        }
    }else{
        cout<<"worning"<<endl;
    }
}
void startFunAssi(){             //函数定义模块
    void nextW();
    void startParaAssign();
    void startFunBlo();
    if(grammer_error&&token_list[c]->get_tag()==TYPE){

        nextW();
        if(grammer_error&&token_list[c]->get_tag()==ID||token_list[c]->get_tag()==KEY){
            SYNBL s;
            s.cat=0;
            s.offset=0;
            s.name="main";
            idwords.push_back(s);
            GEQ_0();
            nextW();
            if(grammer_error&&token_list[c]->get_tag()=='('){
                //cout<<"(:"<<token_list[c]->get_tag()<<endl;
                nextW();
                if(grammer_error){
                    startParaAssign();
                }
                if(grammer_error&&token_list[c]->get_tag()==')'){
                    //cout<<"):"<<token_list[c]->get_tag()<<endl;
                    nextW();
                    if(grammer_error&&token_list[c]->get_tag()=='{'){
                        //cout<<"{:"<<token_list[c]->get_tag()<<endl;
                        env.push_back(new Env(idwords.size()));//压栈
                        nextW();
                        if(grammer_error){
                           startFunBlo();
                        }
                        if(c<token_list.size()&&grammer_error&&token_list[c]->get_tag()=='}'){
                                env.pop_back();
                            //cout<<"}"<<token_list[c]->get_tag()<<endl;
                            //nextW();
                        }else{
                            grammer_error=false;
                        }
                    }else{
                        grammer_error=false;
                    }
                }else{
                    grammer_error=false;
                }
            }else{
                grammer_error=false;
            }
        }else{
            grammer_error=false;
        }
    }else{
        grammer_error=false;
    }
}
/*********************************参数声明模块****************************/
void startParaAssign(){         //参数声明模块
    void startState();
    void startStateClo();
    void nextW();
    //cout<<"参数"<<token_list[c]->get_tag()<<endl;
    if(grammer_error&&token_list[c]->get_tag()==41){

    }else if(grammer_error){
        startState();
        if(grammer_error&&token_list[c]->get_tag()!=41)                  //需判断startState
        startStateClo();
    }
}
void startState(){              //声明模块
    void startInit();
    void startValue1();
    void startValue2();
    void nextW();
    //cout<<"声明"<<token_list[c]->get_tag()<<endl;
    if(grammer_error&&token_list[c]->get_lexeme_str()=="const"){
        nextW();
        if(grammer_error&&token_list[c]->get_tag()==TYPE){
            nextW();
            if(grammer_error){
               startValue1();
               sem.pop();
            }
        }
    }else if(grammer_error&&token_list[c]->get_tag()==TYPE){
        nextW();
        if(grammer_error){
             startValue2();
             sem.pop();
        }
    }
    else
        {
            grammer_error=false;
        }
}
void startValue1(){             //变量分析X1模块
    void startRight();
    void GEQ1();
    void nextW();
    //cout<<"X1："<<token_list[c]->get_tag()<<endl;
    if(grammer_error&&token_list[c]->get_tag()==ID){

        env[env.size()-1]->make_Env(token_list[c]);//在当前栈顶层将Token*与符号表进行拼接
        nextW();
        if(grammer_error&&token_list[c]->get_tag()=='='){
        if(token_list[c-2]->get_tag()==TYPE)  //如果前面是类型
             {

             idwords[token_list[c-1]->get_lexeme()].cat=3;//常量
             idwords[token_list[c-1]->get_lexeme()].type=token_list[c-2]->get_lexeme();
             idwords[token_list[c-1]->get_lexeme()].offset=-(token_list[c-2]->get_lexeme()+1);//  -1 bool -2 char -3 int -4 real
             sem.push(token_list[c-1]);//压栈
             }
             else  //前面是逗号
             {
                Token* temp_sem=sem.top();
                sem.pop();
                idwords[token_list[c-1]->get_lexeme()].cat=3;//常量
                idwords[token_list[c-1]->get_lexeme()].type=idwords[temp_sem->get_lexeme()].type;
                idwords[token_list[c-1]->get_lexeme()].offset=idwords[temp_sem->get_lexeme()].offset;//  -1 bool -2 char -3 int -4 real
                sem.push(token_list[c-1]);//压栈
             }
            nextW();
            if(grammer_error){
                startRight();
            }
            if(grammer_error){
                GEQ1();
            }
        }
    }
}
void startValue2(){             //变量分析X2模块
    void nextW();
    void startRight();
    void GEQ1();
    //cout<<"X2："<<token_list[c]->get_tag()<<endl;
    if(grammer_error&&token_list[c]->get_tag()==ID){
          env[env.size()-1]->make_Env(token_list[c]);
         if(token_list[c-1]->get_tag()==TYPE)  //如果前面是类型
             {
             idwords[token_list[c]->get_lexeme()].cat=2;//变量
             idwords[token_list[c]->get_lexeme()].type=token_list[c-1]->get_lexeme();
             idwords[token_list[c]->get_lexeme()].offset=idwords[0].offset;
             idwords[0].offset=idwords[0].offset+type_size[token_list[c-1]->get_lexeme()];
             sem.push(token_list[c]);//压栈
             }
             else  //前面是逗号
             {
                Token* temp_sem=sem.top();
                sem.pop();
                idwords[token_list[c]->get_lexeme()].cat=2;//变量
                idwords[token_list[c]->get_lexeme()].type=idwords[temp_sem->get_lexeme()].type;
                idwords[token_list[c]->get_lexeme()].offset=idwords[0].offset;
                idwords[0].offset=idwords[0].offset+type_size[idwords[temp_sem->get_lexeme()].type];
                sem.push(token_list[c]);//压栈
            }
          nextW();
        if(grammer_error&&token_list[c]->get_tag()=='='){
            nextW();
            if(grammer_error){
                 startRight();
            }
            if(grammer_error){
               GEQ_2();
            }
        }
    }
    else
    {
        grammer_error=false;
    }
}
void startRight(){             //右值模块
    void startMath();
    //cout<<"右值"<<token_list[c]->get_tag()<<endl;
    if(grammer_error){
       startMath();
    }
}
void startStateClo(){           //声明闭包模块
    void startState();
    void nextW();
    //cout<<"声明闭包"<<token_list[c]->get_tag()<<endl;
    if(grammer_error&&token_list[c]->get_tag()==','){
        nextW();
        if(grammer_error){
            startState();
            if(grammer_error){
                startStateClo();
            }
        }
    }
}
/*********************************函数块模块******************************/
void startFunBlo(){                //函数块模块
    void startStates();
    void startFunBC();
    //cout<<"函数块"<<token_list[c]->get_tag()<<endl;
    if(grammer_error){
     startStates();
    }
    if(grammer_error){
       startFunBC();
    }
}
void startStates(){                //声明语句闭包模块
    void startValue1();
    void startState1();
    void startValue2();
    void startState2();
    void nextW();
    //cout<<"声明闭包语句"<<token_list[c]->get_tag()<<endl;
    if(grammer_error&&token_list[c]->get_tag()==KEY&&token_list[c]->get_lexeme_str()=="const"){
        nextW();
        if(grammer_error&&token_list[c]->get_tag()==TYPE){
            nextW();
            if(grammer_error){
                startValue1();
            }
            if(grammer_error){
                startState1();
            }
            if(grammer_error&&token_list[c]->get_tag()==';'){
                nextW();
                sem.pop();
                if(grammer_error){
                    startStates();
                }
            }
        }
    }else if(grammer_error&&token_list[c]->get_tag()==TYPE){
        nextW();
        if(grammer_error){
            startValue2();

        }
        if(grammer_error){
            startState2();
        }
        if(grammer_error&&token_list[c]->get_tag()==';'){
            nextW();
            sem.pop();
            if(grammer_error){
                startStates();
            }
        }
    }
}
void startState1(){                //声明语句闭包1模块
    void startValue1();
    void nextW();
    //cout<<"声明闭包语句1:"<<token_list[c]->get_tag()<<endl;
    if(grammer_error&&token_list[c]->get_tag()==','){
        nextW();
        if(grammer_error){
            startValue1();
        }
        if(grammer_error){
            startState1();
        }
    }else{
        //nextW();
    }
}
void startState2(){                //声明语句闭包2模块
    void startValue2();
    void nextW();
    //cout<<"声明闭包语句2:"<<token_list[c]->get_tag()<<endl;
    if(grammer_error&&token_list[c]->get_tag()==','){
        nextW();
        if(grammer_error){
            startValue2();
        }
        if(grammer_error){
            startState2();
        }
    }else{
       // nextW();
    }
}
void startFunBC(){                 //函数块闭包模块
    void startAssiFun();
    void startWhile();
    void startIf();
    void startReturn();
    void nextW();
    //cout<<"函数块闭包"<<token_list[c]->get_tag()<<endl;
    if(token_list[c]->get_tag()==ID){
        startAssiFun();
        if(grammer_error){
            startFunBC();
        }
    }
    else if(grammer_error&&token_list[c]->get_tag()==KEY&&token_list[c]->get_lexeme_str()=="while"){
        startWhile();
        if(grammer_error){
            startFunBC();
        }
    }
    else if(grammer_error&&token_list[c]->get_tag()==KEY&&token_list[c]->get_lexeme_str()=="if"){
        startIf();
        if(grammer_error){
            startFunBC();
        }
    }
}
void startAssiFun(){                //赋值函数模块
    void startAssi();
    void nextW();
    //cout<<"赋值函数"<<token_list[c]->get_tag()<<endl;
    if(token_list[c]->get_tag()==ID){
        if(!find_var(token_list[c]))
        {
            cout<<"var_undifined "<<endl;
            grammer_error=false;
        }
        if(!find_const(token_list[c]))
        {
            cout<<"const can't be changed "<<endl;
            grammer_error=false;
        }
        sem.push(token_list[c]);
        nextW();
        if(grammer_error&&token_list[c]->get_tag()=='='){
                nextW();
            startRight();
            if(grammer_error&&token_list[c]->get_tag()==';')
            {
                GEQ_2();
                sem.pop();
                 nextW();
            }
            else
            {
                grammer_error=false;
            }
        }
        else
        {
            grammer_error=false;
        }
    }
    else
    {
        grammer_error=false;
    }
}
/*void startAssi(){                   //赋值函数调用模块
    void startRight();
    void GEQ1();
    void nextW();
    //cout<<"赋值函数调用"<<token_list[c]->get_tag()<<endl;
    if(grammer_error&&token_list[c]->get_tag()=='='){
        sem.push(token_list[c-1]);
        nextW();
        sem.push(token_list[c-2]);
        startRight();
        if(grammer_error)
            GEQ1();
        if(grammer_error&&token_list[c]->get_tag()==';'){
            nextW();
        }else{
            grammer_error=false;
        }
    }else{
        grammer_error=false;
    }
}*/
void nextW(){                       //取下一值模块
    c++;
}
void GEQ1(){
   /***************四元式存储***************/
    q fuck;
    fuck.op="=";
    fuck.temp_1=sem.top();
    sem.pop();
    fuck.temp_2=NULL;
    fuck.res=sem.top();
    //sem.pop();  先留下栈里

    if(fuck.temp_1->get_tag()==-1)   //类型匹配检查
    {
         grammer_error=false;//常量只允许赋值一个数
    }
    else if(fuck.temp_1->get_tag()==NUM)
    {
        if(idwords[fuck.res->get_lexeme()].type==2)//int 类型
        {
              idwords[fuck.res->get_lexeme()].index=fuck.temp_1->get_numindex();
        }
        else if(idwords[fuck.res->get_lexeme()].type==0) //bool
        {
            if(fuck.temp_1->get_numvalue()==0||fuck.temp_1->get_numvalue()==1)
            {
               idwords[fuck.res->get_lexeme()].index=fuck.temp_1->get_numindex();
            }else
            {
                grammer_error=false;
            }
        }
        else
            grammer_error=false;
    }
    else if(fuck.temp_1->get_tag()==REAL)
    {
        if(idwords[fuck.res->get_lexeme()].type!=3)
        {
            grammer_error=false;
        }
        else
        {
            idwords[fuck.res->get_lexeme()].index=fuck.temp_1->get_numindex();
        }
    }
    else if(fuck.temp_1->get_tag()==CHAR)
    {
        if(idwords[fuck.res->get_lexeme()].type!=1)
        {
            grammer_error=false;
        }
        else
        {
            idwords[fuck.res->get_lexeme()].index=fuck.temp_1->get_value();
        }
    }
    else
        grammer_error=false;
   QT.push_back(fuck);
}
void GEQ_0()
{
 q temp_q;
 temp_q.op="Programe";
 temp_q.temp_1=NULL;
 temp_q.temp_2=NULL;
 temp_q.res=NULL;
 QT.push_back(temp_q);
}
void GEQ_2()
{
    q fuck;
    fuck.op="=";
    fuck.temp_1=sem.top();
    sem.pop();
    fuck.temp_2=NULL;
    fuck.res=sem.top();
     //sem.pop();  先留下栈里
    if(fuck.temp_1->get_tag()==-1)   //类型匹配检查
    {
               if(temp[fuck.temp_1->get_var_value()].type>idwords[fuck.res->get_lexeme()].type)
               {
                       if(temp[fuck.temp_1->get_var_value()].type==2&&idwords[fuck.res->get_lexeme()].type==1)
                       {
                       }
                       else
                        grammer_error=false;
               }
    }
    else if(fuck.temp_1->get_tag()==NUM)
    {
        if(idwords[fuck.res->get_lexeme()].type>=2)//int 类型
        {
              //idwords[fuck.res->get_lexeme()].index=fuck.temp_1->get_numindex();
        }
        else if(idwords[fuck.res->get_lexeme()].type==0) //bool
        {
            if(fuck.temp_1->get_numvalue()==0||fuck.temp_1->get_numvalue()==1)
            {
               //idwords[fuck.res->get_lexeme()].index=fuck.temp_1->get_numindex();
            }else
            {
                grammer_error=false;
            }
        }
        else if(idwords[fuck.res->get_lexeme()].type==1&&fuck.temp_1->get_numvalue()<=255)//CHAR
        {

        }
        else
            grammer_error=false;
    }
    else if(fuck.temp_1->get_tag()==REAL)
    {
        if(idwords[fuck.res->get_lexeme()].type!=3)
        {
            grammer_error=false;
        }

    }
    else if(fuck.temp_1->get_tag()==CHAR)
    {
        if(idwords[fuck.res->get_lexeme()].type!=1&&idwords[fuck.res->get_lexeme()].type!=2)
        {
            grammer_error=false;
        }
    }
    else
        grammer_error=false;
   QT.push_back(fuck);
}

