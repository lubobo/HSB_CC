#include<iostream>
#include"../headers/lexer.h"
using namespace std;
void startIf()
{

    if(c<token_list.size())
    {

        if(token_list[c]->get_tag()==KEY&&token_list[c]->get_lexeme_str()=="if")
        {

            c++;
            if(c<token_list.size()&&token_list[c]->get_tag()=='(')
            {
                c++;

                if(startLogic())
                {
                    if(c<token_list.size()&&token_list[c]->get_tag()==')')
                    {
                        c++;
                        if(!act_if_if())
                        {
                            grammer_error=false;
                        }
                        if(c<token_list.size()&&token_list[c]->get_tag()=='{')
                        {
                            env.push_back(new Env(idwords.size()));
                            c++;
                            if(grammer_error)
                            {
                                startFunBlo();
                            }
                            if(grammer_error)//startFun
                            {
                                if(c<token_list.size()&&token_list[c]->get_tag()=='}')
                                {
                                    env.pop_back();
                                    c++;
                                    if(c<token_list.size()&&token_list[c]->get_tag()==KEY&&token_list[c]->get_lexeme_str()=="else")
                                    {
                                        c++;
                                        if(!act_if_el())
                                        {
                                            grammer_error=false;
                                        }
                                        if(c<token_list.size()&&token_list[c]->get_tag()=='{')
                                        {
                                            env.push_back(new Env(idwords.size()));
                                            c++;
                                            startFunBlo();
                                            if(grammer_error)//startFun
                                            {
                                                if(c<token_list.size()&&token_list[c]->get_tag()=='}')
                                                {
                                                    env.pop_back();
                                                    c++;
                                                    if(!act_if_ie())
                                                    {
                                                        grammer_error=false;
                                                    }
                                                }
                                                else {cout<<"IF_error11"<<endl;grammer_error=false;}
                                            }
                                            else {cout<<"IF_error10"<<endl;grammer_error=false;}
                                        }
                                        else {cout<<"IF_error9"<<endl;grammer_error=false;}
                                    }
                                    else
                                    {
                                        if(!act_if_ie())
                                        {
                                            grammer_error=false;
                                        }
                                    }

                                }
                                else {cout<<"IF_error8"<<endl;grammer_error=false;}

                            }
                            else {cout<<"IF_error7"<<endl;grammer_error=false;}

                        }
                        else {cout<<"IF_error6"<<endl;grammer_error=false;}

                    }
                    else {cout<<"IF_error5"<<endl;grammer_error=false;}

                }
                else {cout<<"IF_error4"<<endl;grammer_error=false;}

            }
            else {cout<<"IF_error3"<<endl;grammer_error=false;}

        }
        else {cout<<"IF_error2"<<endl;grammer_error= false;}

    }
    else {cout<<"IF_error1"<<endl;grammer_error=false;}
}

bool act_if_if()
{
    q temp_q;
    temp_q.op="if";
    temp_q.temp_1=sem.top();
    sem.pop();
    temp_q.temp_2=NULL;
    temp_q.res=NULL;
    QT.push_back(temp_q);
    return true;

}

bool act_if_el()
{
    q temp_q;
    temp_q.op="el";
    temp_q.temp_1=NULL;
    temp_q.temp_2=NULL;
    temp_q.res=NULL;
    QT.push_back(temp_q);
    return true;
}

bool act_if_ie()
{
    q temp_q;
    temp_q.op="ie";
    temp_q.temp_1=NULL;
    temp_q.temp_2=NULL;
    temp_q.res=NULL;
    QT.push_back(temp_q);
    return true;
}
