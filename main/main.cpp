#include<iostream>
#include"../headers/lexer.h"
#include"../headers/functionAnalysis.h"
using namespace std;
extern int lexer();
int c=0;
vector<q> QT;
stack<Token*> sem;
vector<Env*> env;

bool grammer_error=true;
int main(){
    lexer();
    /*for(int i=0;i<token_list.size();i++){
        cout<<token_list[i]->get_tag()<<";";
    }
    cout<<endl;*/
    //startMath();

   functionAnalysis();

     for(int i=0;i<idwords.size();i++)
    {
        cout<<"<<"<<"���ƣ�"<<idwords[i].name<<","<<"����1(0.���� 1.��ʱ���� 2.����3.����)�� "<<idwords[i].cat<<"����2(0.bool 1.char 2.int 3.real)�� "<<","<<idwords[i].type<<","<<" ���ݶ�ƫ������"<<idwords[i].offset<<","<<"����ʱ�õ���ָ�룺"<<idwords[i].index<<">>"<<endl;
    }
    cout<<"/**************************************************************��ʱ�������ű�******************************************************************/"<<endl;
   for(int i=0;i<temp.size();i++)
   {
       cout<<"<<"<<"���ƣ�"<<temp[i].name<<","<<"����1(0.���� 1.��ʱ���� 2.����3.����)�� "<<temp[i].cat<<","<<"����2(0.bool 1.char 2.int 3.real)�� "<<temp[i].type<<","<<" ���ݶ�ƫ������"<<temp[i].offset<<","<<"����ʱ�õ���ָ�룺"<<temp[i].index<<">>"<<endl;
   }
    return 0;

}
