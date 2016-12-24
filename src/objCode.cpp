#include<fstream>
#include<iostream>
#include"../headers/lexer.h"
#include"../headers/objCode.h"
using namespace std;
void createObj(){
    for(int j=1;j<temp.size();j++){
        cout<<idwords[j].name<<endl;
    }
    assignMent();
}
void assignMent(){
    obj assi;
    int i=0;
    int j=0;
    int z=0;
    int a=0;
    int x=0;
    string m;
    while(i<idwords.size()){
        if(idwords[i].cat==0){
            m=idwords[i].name;
            a=idwords[i].offset;
        }
        i++;
    }
    //cout<<m<<endl;
    //cout<<a<<endl;
    j=idwords[idwords.size()-1].offset/16;
    z=idwords[idwords.size()-1].offset%16;
    if(z!=0){
        j=j+1;
    }
    //cout<<j<<endl;
    ofstream outfile("test/main.s");
    if(outfile.is_open()){
        outfile<<"      .file   "<<'\"'<<"main.c"<<'\"'<<endl;
        outfile<<"      .def    ___main;  .scl    2;  .type   32;  .endef"<<endl;
        //outfile<<"      .section .rdata,"<<'\"'<<"dr"<<'\"'<<endl;
        //outfile<<"LC0:"<<endl;
        //outfile<<"      .ascii "<<'\"'<<"shit"<<'\\'<<"0"<<'\"'<<endl;
        outfile<<"      .text"<<endl;
        outfile<<"      .globl  __"<<m<<endl;
        outfile<<"      .def    __"<<m<<";  .scl    2;  .type   32; .endf"<<endl;
        outfile<<"_main:"<<endl;
        outfile<<"LEB10:"<<endl;
        outfile<<"      pushl   %ebp"<<endl;
        outfile<<"      movl    %esp ,%ebp"<<endl;
        outfile<<"      andl    $-16 ,%esp"<<endl;
        outfile<<"      subl    $"<<j*16<<" ,%esp"<<endl;
        outfile<<"      call    ___main"<<endl;
        x=j*16-(a-idwords[idwords.size()-1].offset);
        //cout<<x<<endl;
        for(int i=1;i<idwords.size();i++){
            outfile<<"      movl    $"<<QT[i].temp_1->get_numvalue()<<", "<<x<<"(%esp)"<<endl;
            x-=4;
        }
        outfile.close();
    }
    for(int z=0;z<QT.size();z++){
        if(QT[z].op=="+"||QT[z].op=="-"){
            operation(QT[z].op);
        }
    }
}
void operation(string a){
    if(a=="+"){
        cout<<"shit"<<endl;
    }
}
