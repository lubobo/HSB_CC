#include<iostream>
#include"../headers/lexer.h"
#include<stack>
#include<vector>
#include<math.h>
using namespace std;
int send_value(int x)
{
    int temp;
    switch (x)
    {
    case ID:
        temp=5;
        break;
    case NUM:
    case REAL:
    case CHAR:
        temp=0;
        break;
    case 43:
    case 45:
        temp=1;
        break;
    case 42:
    case 47:
        temp=2;
        break;
    case 40:
        temp=3;
        break;
    case 41:
        temp=4;
        break;
    case 91:
        temp=6;
        break;
    case 93:
        temp=7;
            break;
    default:
        temp=-1;
    }
    return temp;
}

void startMath()
{
    if(start_E())
   {

   }
   else
   {
     grammer_error=false;
   }

}
bool start_E()
{
   if(!start_T())
  {
   return false;
  }
  while(c<=token_list.size()-1&&send_value(token_list[c]->get_tag())==1)
 {
          int temp=token_list[c]->get_tag();

          c++;
          if(start_T()){
            if(!act(temp)){
                return false;
            }
        }
     else
       return false;
 }
 return true;
}
bool start_T()
{
    if(!start_F())
    {
       return false;
    }
    while(c<=token_list.size()-1&&send_value(token_list[c]->get_tag())==2)
    {
            int temp=token_list[c]->get_tag();
            c++;
        if(start_F())
       {
         if(!act(temp))
         {
             return false;
         }
       }
        else
          return false;
    }
  return true;
}
bool  start_F()
{

    if(c<=token_list.size()-1&&send_value(token_list[c]->get_tag())==0)//Èç¹ûÊÇÊý×Ö
    {
           sem.push(token_list[c]);
           c++;
        /*else
        {
            sem.push(token_list[c]->get_realvalue_s());
            c++;
        }*/

        return true;
    }
    else  if(c<=token_list.size()-1&&send_value(token_list[c]->get_tag())==3)
    {
         c++;
        if (!start_E())
        {
            return false;
        }

        if(c<=token_list.size()-1&&send_value(token_list[c]->get_tag())==4)
      {
        c++;
      }
     else
      {
         return false;
      }
    }
    else
    {
        if(!start_A())
        {
            return false;
        }

    }
    return true;
}
bool start_A()
{

    if(c<=token_list.size()-1&&send_value(token_list[c]->get_tag())==5)
    {
         sem.push(token_list[c]);
         c++;
         if(!start_B())
         {
             return false;
         }
         return true;
    }
    else
    {
        return false;
    }
}
bool start_B()
{
    if(c<=token_list.size()-1&&send_value(token_list[c]->get_tag())==6)
    {
        c++;
        if(!start_E())
        {
            return false;
        }
        if(c<=token_list.size()-1&&send_value(token_list[c]->get_tag())==7)
        {   c++;
            if(!act_2())
            {
                return false;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}
bool act(int temp)                  //´æ´¢ËÄÔªÊ½
{
    q temp_q;
    if(temp==43)
       temp_q.op="+";
    else if(temp==45)
        temp_q.op="-";
    else if(temp==42)
        temp_q.op="*";
    else
        temp_q.op="/";
    if(!sem.empty())
    {
      temp_q.temp_2=sem.top();
      if(temp_q.temp_2->get_tag()==ID&&temp_q.temp_2->get_lexeme()==0) //token未定义
      {
          if(!find_var(temp_q.temp_2))//  查找元素是否定义
          {
              cout<<"var_undefined"<<endl;
              grammer_error=false;
              return false;
          }

      }
      sem.pop();
    if(sem.empty())
    {
        return false;
    }
    temp_q.temp_1=sem.top();
    if(temp_q.temp_1->get_tag()==ID&&temp_q.temp_1->get_lexeme()==0) //token未定义
    {
         if(!find_var(temp_q.temp_1))//  查找元素是否定义
          {
              cout<<"var_undefined"<<endl;
              return false;
          }

    }
    sem.pop();
    int result=type_change(temp_q.temp_1,temp_q.temp_2,temp);
    temp_q.res=new temp_var(-1,get_tempindex(result));
    sem.push(temp_q.res);
    QT.push_back(temp_q);
    return true;
    }
    else{
        return false;
    }
}
bool act_2()
{
     /*if(!sem.empty())
     {
    string temp_act=sem.top();
    sem.pop();
    if(sem.empty())
    {
        return false;
    }
    string temp_act2=sem.top();
    sem.pop();
    string new_arrary=temp_act2+"["+temp_act+"]";
    sem.push(new_arrary);
    return true;
     }
     else*/
        return true;

}
void q_out()                    //ÏÔÊ¾ËÄÔªÊ½
{
    for(int i=0;i<QT.size();i++)
    {
        cout<<"("<<QT[i].op<<",";
        if(QT[i].temp_1==NULL){
            cout<<"_"<<",";
        }else{
            if(QT[i].temp_1->get_tag()==-1){
                cout<<QT[i].temp_1->get_var()<<",";
            }
            else if(QT[i].temp_1->get_tag()==ID){
                cout<<QT[i].temp_1->get_lexeme_str()<<",";
            }
            else{
                cout<<QT[i].temp_1->get_numvalue()<<",";
            }
        }
         if(QT[i].temp_2==NULL){
            cout<<"_"<<",";
        }
        else{
            if(QT[i].temp_2->get_tag()==-1){
                cout<<QT[i].temp_2->get_var()<<",";
            }
            else if(QT[i].temp_2->get_tag()==ID){
                cout<<QT[i].temp_2->get_lexeme_str()<<",";
            }
            else{
            cout<<QT[i].temp_2->get_numvalue()<<",";
            }
        }
        if(QT[i].res==NULL){
            cout<<"_"<<")";
        }
        else{
            if(QT[i].res->get_tag()==-1){
                cout<<QT[i].res->get_var()<<")";
            }
            else if(QT[i].res->get_tag()==ID){
                cout<<QT[i].res->get_lexeme_str()<<")";
            }
            else{
                cout<<QT[i].res->get_numvalue()<<")";
            }
        }
        cout<<endl;
    }
}
int  get_tempindex(int x)                   //´æ·ûºÅ±í
{
    string  temp_v="t",temp_a;
    int i=temp.size();
    if(i==0)
    {
        temp_v+="0";
    }
    while(i!=0)
    {
        temp_a+='0'+i%10;
        i=i/10;
    }
    for(int i=temp_a.size()-1;i>=0;i--)
    {
        temp_v+=temp_a[i];
    }
     SYNBL s;
     s.name=temp_v;
     s.cat=1;
     s.type=x;
     temp.push_back(s);
     return temp.size()-1;
}
int type_change(Token* t1,Token* t2,int temp0)
{
   int type_1,type_2,type;

   if(temp0==43||temp0==45||temp0==42)//+与-
   {
        if(t1->get_tag()==REAL)
        {
        type_1=3;      //ÊµÊýÀàÐÍ
        }
        else if(t1->get_tag()==NUM)
        {
        type_1=2;//  ÕûÊýÀàÐÍ
        }
        else if(t1->get_tag()==CHAR)
        {
            type_1=1;
        }
        else if(t1->get_tag()==ID)
        {
        type_1=idwords[t1->get_lexeme()].type;    //±êÊ¶·û
        }
        else if(t1->get_tag()==-1)
        {
            type_1=temp[t1->get_var_value()].type;

        }
        if(t2->get_tag()==REAL)
        {
        type_2=3;      //ÊµÊýÀàÐÍ
        }
        else if(t2->get_tag()==NUM)
        {
        type_2=2;//  ÕûÊýÀàÐÍ
        }
        else if(t2-> get_tag()==CHAR)
        {
            type_2=1;
        }
        else if(t2->get_tag()==ID)
        {
        type_2=idwords[t2->get_lexeme()].type;    //±êÊ¶·û
        }
        else if(t2->get_tag()==-1)
        {
            type_2=temp[t2->get_var_value()].type;

        }
         type=max(type_1,type_2);
           return type;
    }
    else
    {
        return 3;//乘除时都用real
    }
}
 bool find_var(Token *t) //使用标识符的函数
{
        int i;
        for(i=env.size()-1;i>=0;i--)
        {
            int  serach_res=env[i]->serach(t->get_lexeme_str());
            if(serach_res!=-1)
            {
                t->set_lexeme(serach_res);
                return true;
            }
        }
        return false;

}
bool find_const(Token *t)
{
        int i;
        for(i=env.size()-1;i>=0;i--)
        {
            int  serach_res=env[i]->serach_const(t);

            if(serach_res!=0)
            {
                return true;
            }
        }
        return false;
}
