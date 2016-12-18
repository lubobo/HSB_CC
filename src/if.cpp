#include<iostream>
#include"../headers/lexer.h"
using namespace std;
bool startIf()
{
    bool startFunBlo();
    //cout<<"if"<<token_list[c]->get_tag()<<endl;
    if(c<token_list.size())
    {
        int temp=token_list[c]->get_tag();
        //cout<<token_list[c]->get_lexeme_str()<<endl;
        if(temp==KEY&&token_list[c]->get_lexeme_str()=="if")
        {
            //cout<<"1"<<endl;
            c++;
            if(c<token_list.size()&&token_list[c]->get_tag()=='(')
            {
                //cout<<"2"<<endl;
                c++;
                if(startLogic())
                {
                    //cout<<"3"<<endl;
                    if(c<token_list.size()&&token_list[c]->get_tag()==')')
                    {
                        //cout<<"4"<<endl;
                        c++;
                        if(!act_if_if())
                        {
                            return false;
                        }
                        if(c<token_list.size()&&token_list[c]->get_tag()=='{')
                        {
                            c++;
                            if(startFunBlo())//startFun
                            {
                                if(c<token_list.size()&&token_list[c]->get_tag()=='}')
                                {
                                    c++;
                                    if(c<token_list.size()&&token_list[c]->get_tag()==KEY&&token_list[c]->get_lexeme_str()=="else")
                                    {
                                        c++;
                                        if(!act_if_el())
                                        {
                                            return false;
                                        }
                                        if(c<token_list.size()&&token_list[c]->get_tag()=='{')
                                        {
                                            c++;
                                            if(startFunBlo())//startFun
                                            {
                                                if(c<token_list.size()&&token_list[c]->get_tag()=='}')
                                                {
                                                    c++;
                                                    if(!act_if_ie)
                                                    {
                                                        return false;
                                                    }
                                                    return true;
                                                }
                                                else {cout<<"IF_error"<<endl;return false;}
                                            }
                                            else {cout<<"IF_error"<<endl;return false;}
                                        }
                                        else {cout<<"IF_error"<<endl;return false;}
                                    }
                                    else
                                    {
                                        if(!act_if_ie())
                                        {
                                            return false;
                                        }
                                        return true;
                                    }

                                }
                                else {cout<<"IF_error"<<endl;return false;}

                            }
                            else {cout<<"IF_error"<<endl;return false;}

                        }
                        else {cout<<"IF_error"<<endl;return false;}

                    }
                    else {cout<<"IF_error"<<endl;return false;}

                }
                else {cout<<"IF_error"<<endl;return false;}

            }
            else {cout<<"IF_error"<<endl;return false;}

        }
        else {cout<<"IF_error"<<endl;return false;}

    }
    else {cout<<"IF_error"<<endl;return false;}
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
