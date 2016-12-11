#include<iostream>
#include"../headers/lexer.h"
#include"../headers/functionAnalysis.h"
using namespace std;
extern int lexer();
int main(){
    //lexer();
    /*for(int i=0;i<token_list.size();i++){
        cout<<token_list[i]->get_tag()<<endl;
    }*/
    lexer();
    functionAnalysis();
    return 0;
}
