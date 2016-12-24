#include<iostream>
#include"../headers/lexer.h"
using namespace std;

bool startLogic()
{
    startMath();
    if(grammer_error)
    {
        if(c<token_list.size())//ÅÐ¶ÏcÔ½Ã»Ô½½ç
        {
            int temp=token_list[c]->get_tag();
        if(temp==EQ||temp==NE||temp==GE||temp==LE||temp=='>'||temp=='<')
        {
            c++;
            startMath();
            if(grammer_error)
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
if(temp_q.temp_2->get_tag()==ID&&temp_q.temp_2->get_lexeme()==0) //token未定义
{
          if(!find_var(temp_q.temp_2))//  查找元素是否定义
          {
              cout<<"var_undefined"<<endl;
              return false;
          }

}
sem.pop();
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
temp_q.res=new temp_var(-1,get_tempindex(0));//都是bool型
sem.push(temp_q.res);
QT.push_back(temp_q);
}
