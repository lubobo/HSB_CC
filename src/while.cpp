#include<iostream>
#include"../headers/lexer.h"
using namespace std;
bool startWhile()
{
    bool startFunBlo();
    //cout<<"while"<<token_list[c]->get_tag()<<endl;
    if(c<token_list.size())   //�ж��ǲ���Խ��
    {
         int temp=token_list[c]->get_tag();
         //cout<<token_list[c]->get_tag()<<endl;
         if(temp==KEY&&token_list[c]->get_lexeme_str()=="while")//while
         {

             c++;
             if(!act_while_wh())//����һ
             {

                 return false;
             }

                if(c<token_list.size()&&token_list[c]->get_tag()==40)//������
                {
                   c++;
                   if(startLogic())
                   {

                       if(c<token_list.size()&&token_list[c]->get_tag()==41)//������
                       {
                           c++;
                           if(!act_while_do())//������
                           {
                               return false;
                           }
                           if(c<token_list.size()&&token_list[c]->get_tag()=='{') //����Ĵ�����
                           {
                               c++;
                               if(startFunBlo())
                               {
                                   if(c<token_list.size()&&token_list[c]->get_tag()=='}')//����Ĵ�����
                                   {
                                       c++;
                                       if(!act_while_we())
                                       {
                                           return false;
                                       }
                                       return true;
                                   }
                                   else
                                   {
                                       cout<<"WHILE_error1"<<endl;
                                        return false;
                                   }
                               }
                               else
                                return false;
                           }
                           else
                           {
                            cout<<"WHILE_error2"<<endl;
                            return false;
                           }


                       }
                       else
                        {
                            cout<<"WHILE_error3"<<endl;
                            return false;
                        }
                   }
                   else
                    return false;
                }
                else
                {
                    cout<<"WHILE_error4"<<endl;
                    return false;
                }
         }
         else
         {
             cout<<"WHILE_error5"<<endl;
             return false;
         }
    }
    else
    {
       cout<<"WHILE_error6"<<endl;
       return false;
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
