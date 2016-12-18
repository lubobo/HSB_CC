#include<iostream>
#include"../headers/lexer.h"
using namespace std;

bool startLogic()
{
    //cout<<"logic"<<token_list[c]->get_tag()<<endl;
    if(startMath())
    {
        if(c<token_list.size())
        {
            int temp=token_list[c]->get_tag();
        if(temp==EQ||temp==NE||temp==GE||temp==LE||temp=='>'||temp=='<')
        {
            c++;
            if(startMath())
            {
                if(!act_logic(temp))
                {
                   return true;
                }
                else
                    return false;
            }
            else
                return false;
        }
        else
        {
            cout<<"logic_error"<<endl;
            return false;
        }
        }
      else
      cout<<"logic_error"<<endl;
      return false;
    }
    else
    {
        return false;
    }
}
bool act_logic(int temp)
{
    q temp_q;
    switch(temp)
    {
    case EQ:
        temp_q.op="==";
        break;
    case NE:
        temp_q.op="!=";
        break;
    case GE:
        temp_q.op=">=";
        break;
    case LE:
        temp_q.op="<=";
        break;
    case 62:
        temp_q.op=">";
        break;
    case 60:
        temp_q.op="<";
        break;
    }
    temp_q.temp_2=sem.top();
    sem.pop();
    temp_q.temp_1=sem.top();
    sem.pop();
    temp_q.res=new temp_var(-1,get_tempindex(type_change(temp_q.temp_1,temp_q.temp_2)));
    sem.push(temp_q.res);
    QT.push_back(temp_q);
}
