#include<iostream>
#include"../headers/lexer.h"
using namespace std;
void startWhile()
{

    //cout<<token_list[c]->get_tag()<<endl;
    if(c<token_list.size())   //ÅÐ¶ÏÊÇ²»ÊÇÔ½½ç
    {


         int temp=token_list[c]->get_tag();
        // cout<<token_list[c]->get_tag()<<endl;
         if(temp==KEY&&token_list[c]->get_lexeme_str()=="while")//while
         {

              c++;
             if(!act_while_wh())//¶¯×÷Ò»
             {

                 grammer_error=false;
             }

                if(c<token_list.size()&&token_list[c]->get_tag()==40)//×óÀ¨ºÅ
                {
                   c++;
                   if(startLogic())
                   {

                       if(c<token_list.size()&&token_list[c]->get_tag()==41)//ÓÒÀ¨ºÅ
                       {
                           c++;
                           if(!act_while_do())//¶¯×÷¶þ
                           {
                               grammer_error=false;
                           }
                           if(c<token_list.size()&&token_list[c]->get_tag()=='{') //×óÃæµÄ´óÀ¨ºÅ
                           {
                               env.push_back(new Env(idwords.size()));
                               c++;
                               startFunBlo();
                               if(grammer_error)
                               {
                                   if(c<token_list.size()&&token_list[c]->get_tag()=='}')//ÓÒÃæµÄ´óÀ¨ºÅ
                                   {
                                       c++;
                                       if(!act_while_we())
                                       {
                                           grammer_error=false;
                                       }
                                     env.pop_back();
                                   }
                                   else
                                   {
                                       cout<<"WHILE_error1"<<endl;
                                        grammer_error=false;
                                   }
                               }
                               else
                                grammer_error=false;
                           }
                           else
                           {
                            cout<<"WHILE_error2"<<endl;
                           grammer_error=false;
                           }


                       }
                       else
                        {
                            cout<<"WHILE_error3"<<endl;
                            grammer_error=false;
                        }
                   }
                   else
                    grammer_error=false;
                }
                else
                {
                    cout<<"WHILE_error4"<<endl;
                    grammer_error=false;
                }
         }
         else
         {
             cout<<"WHILE_error5"<<endl;
             grammer_error=false;
         }
    }
    else
    {
       cout<<"WHILE_error6"<<endl;
     grammer_error=false;
    }
}
bool act_while_wh()
{
    q temp_q;
    temp_q.op="wh";
    temp_q.res=NULL;
    temp_q.temp_1=NULL;
    temp_q.temp_2=NULL;
    QT.push_back(temp_q);
    return true;
}
bool act_while_do()
{
    q temp_q;
    temp_q.op="do";
    temp_q.temp_1=sem.top();
    temp_q.temp_2=NULL;
    temp_q.res=NULL;
    QT.push_back(temp_q);
    return true;
}
bool act_while_we()
{
    q temp_q;
    temp_q.op="we";
    temp_q.res=NULL;
    temp_q.temp_1=NULL;
    temp_q.temp_2=NULL;
    QT.push_back(temp_q);
    return true;
}
