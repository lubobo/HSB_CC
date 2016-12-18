#include<iostream>
#include"../headers/lexer.h"
using namespace std;

Token *one=new Num(NUM,str2num("1"));
bool startSuffix()
{
    if(c<token_list.size()&&token_list[c]->get_tag()==ID&&idwords[token_list[c]->get_lexeme()].cat==1)
    {
        c++;
        if(c<token_list.size()&&(token_list[c]->get_tag()=='+'||token_list[c]->get_tag()=='-'))
        {
            c++;
            if(c<token_list.size()&&(token_list[c]->get_tag()=='+'||token_list[c]->get_tag()=='-'))
            {
                if(token_list[c]->get_tag()=='+')
                {
                    if(!act_suffix_in())
                    {
                        return false;
                    }
                }
                else if(token_list[c]->get_tag()=='-')
                {
                    if(!act_suffix_de())
                    {
                        return false;
                    }
                }
                c++;
                return true;
            }
            else {cout<<"SUFFIX_error"<<endl;return false;}
        }
        else {cout<<"SUFFIX_error"<<endl;return false;}
    }
    else {cout<<"SUFFIX_error"<<endl;return false;}
}
bool act_suffix_in()
{
    Token *tempcao=token_list[c];
    q temp_q;
    temp_q.op="+";
    temp_q.temp_1=tempcao;
    temp_q.temp_2=one;
    temp_q.res=tempcao;
    QT.push_back(temp_q);
    return true;
}
bool act_suffix_de()
{
    Token *tempcao=token_list[c];
    q temp_q;
    temp_q.op="-";
    temp_q.temp_1=tempcao;
    temp_q.temp_2=one;
    temp_q.res=tempcao;
    QT.push_back(temp_q);
    return true;
}
