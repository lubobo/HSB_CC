#include<iostream>
#include"../headers/lexer.h"
#include<stack>
#include<vector>
#include<math.h>
using namespace std;
//stack<Token*> sem;
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

bool startMath()
{

    if(start_E())
   {
      // if(c==token_list.size())
     //  {
            //cout<<"Exp_success"<<endl;
            /*vector<q>::iterator it0=QT.begin();
            cout<<"************"<<"��Ԫʽ"<<"***************"<<endl;
                 for(it0=QT.begin();it0!=QT.end();it0++)
               {
                cout<<"("<<(*it0).op<<","<<(*it0).temp_1<<","<<(*it0).temp_2<<","<<(*it0).res<<")"<<endl;
               }*/

        //}
        /*else
        {
            cout<<"wrong1"<<endl;
        }*/
      return true;
   }
   else
   {
     //cout<<"wrong"<<endl;
     return false;
   }

}
bool start_E()
{
    //cout<<"startMath1"<<endl;
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
    //cout<<"startMath2"<<endl;
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
    //cout<<"startMath3"<<endl;
    if(c<=token_list.size()-1&&send_value(token_list[c]->get_tag())==0)//���������
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
    //cout<<"startMath4"<<endl;
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
    //cout<<"startMath5"<<endl;
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
bool act(int temp)                  //�洢��Ԫʽ
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
      sem.pop();
    if(sem.empty())
    {
        return false;
    }
    temp_q.temp_1=sem.top();//temp��������ջ���Ԫ�����;���
    sem.pop();
    int result=type_change(temp_q.temp_1,temp_q.temp_2);
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
void q_out()                    //��ʾ��Ԫʽ
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
int  get_tempindex(int x)                   //����ű�
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
     s.cat=4;         //��ʱ����;
     s.index=0;       //indexû��
     s.type=x;        //typ����
     temp.push_back(s);
     return temp.size()-1;
}
int type_change(Token* t1,Token* t2)
{
   int type_1,type_2,type;
   if(t1->get_tag()==REAL)
   {
       type_1=3;      //ʵ������
   }
   else if(t1->get_tag()==NUM)
   {
       type_1=2;//  ��������
   }
   else if(t1->get_tag()==ID)
   {
       type_1=idwords[t1->get_lexeme()].type;    //��ʶ��
   }
   if(t2->get_tag()==REAL)
   {
       type_2=3;      //ʵ������
   }
   else if(t2->get_tag()==NUM)
   {
       type_2=2;//  ��������
   }
   else if(t2->get_tag()==ID)
   {
       type_2=idwords[t2->get_lexeme()].type;    //��ʶ��
   }
   type=max(type_1,type_2);
   return type;
}
