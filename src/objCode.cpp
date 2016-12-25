#include<fstream>
#include<iostream>
#include"../headers/lexer.h"
#include"../headers/objCode.h"
using namespace std;
vector<R>RDL;
int x=0;
void createObj(){
/*********************定义RDL表*********************/
    R r1;
    r1.name="eax";
    RDL.push_back(r1);
    R r2;
    r1.name="ebx";
    RDL.push_back(r2);
    R r3;
    r1.name="ecx";
    RDL.push_back(r3);
    R r4;
    r1.name="edx";
    RDL.push_back(r4);
/*********************活跃信息生成**********************/
    int z;
    z=QT.size();
    for(int j=1;j<idwords.size();j++){
        idwords[j].active=1;
    }
    for(int i=0;i<temp.size();i++){
        temp[i].active=0;
    }
    for(int i=z-1;i>0;i--){
        for(int j=1;j<idwords.size();j++){
            if(QT[i].temp_2==NULL){
                if(idwords[j].name==QT[i].res->get_lexeme_str()){
                    QT[i].res->active=idwords[j].active;
                    idwords[j].active=1;
                }else if(QT[i].temp_1->get_lexeme_str()==idwords[j].name){
                    QT[i].temp_1->active=idwords[j].active;
                    idwords[j].active=0;
                }
            }
            if(QT[i].temp_2!=NULL){
                if(idwords[j].name==QT[i].temp_1->get_lexeme_str()||idwords[j].name==QT[i].temp_2->get_lexeme_str()){
                    if(idwords[j].name==QT[i].temp_1->get_lexeme_str()){
                        QT[i].temp_1->active=idwords[j].active;
                    }else{
                        QT[i].temp_2->active=idwords[j].active;
                    }
                    idwords[j].active=0;
                }else if(idwords[j].name==QT[i].res->get_lexeme_str()){
                    QT[i].res->active=idwords[j].active;
                    idwords[j].active=1;
                }
            }
        }
    }
    for(int i=z-1;i>0;i--){
        for(int j=0;j<temp.size();j++){
            if(QT[i].temp_2==NULL){
                if(temp[j].name==QT[i].res->get_var()){
                    QT[i].res->active=temp[j].active;
                    temp[j].active=1;
                }else if(QT[i].temp_1->get_lexeme_str()==temp[j].name){
                    QT[i].temp_1->active=temp[j].active;
                    temp[j].active=0;
                }
            }
            if(QT[i].temp_2!=NULL){
                if(temp[j].name==QT[i].temp_1->get_var()||temp[j].name==QT[i].temp_2->get_var()){
                    if(temp[j].name==QT[i].temp_1->get_var()){
                        QT[i].temp_1->active=temp[j].active;
                    }else{
                        QT[i].temp_2->active=temp[j].active;
                    }
                    temp[j].active=0;
                }else if(temp[j].name==QT[i].res->get_var()){
                    QT[i].res->active=temp[j].active;
                    temp[j].active=1;
                }
            }
        }
    }
    /********调用变量初始化**********/
    assignMent();
}
/************************变量初始化*************************/
void assignMent(){
    obj assi;
    int i=0;
    int j=0;
    int z=0;
    int a=0;

    int var=0;
    string m;
    while(i<idwords.size()){
        if(idwords[i].cat==0){
            m=idwords[i].name;
            a=idwords[i].offset;
        }
        i++;
    }
    j=idwords[idwords.size()-1].offset/16;
    z=idwords[idwords.size()-1].offset%16;
    if(z!=0){
        j=j+1;
    }
    ofstream outfile("test/main.s");
    if(outfile.is_open()){
        outfile<<"    .file   "<<'\"'<<"main.c"<<'\"'<<endl;
        outfile<<"    .def    ___main;  .scl    2;  .type   32;  .endef"<<endl;
        //outfile<<"      .section .rdata,"<<'\"'<<"dr"<<'\"'<<endl;
        //outfile<<"LC0:"<<endl;
        //outfile<<"      .ascii "<<'\"'<<"shit"<<'\\'<<"0"<<'\"'<<endl;
        outfile<<"    .text"<<endl;
        outfile<<"    .globl  _"<<m<<endl;
        outfile<<"    .def    _"<<m<<";  .scl    2;  .type   32; .endf"<<endl;
        outfile<<"_main:"<<endl;
        outfile<<"LFB10:"<<endl;
        outfile<<"    pushl   %ebp"<<endl;
        outfile<<"    movl    %esp, %ebp"<<endl;
        outfile<<"    andl    $-16, %esp"<<endl;
        outfile<<"    subl    $"<<j*16<<", %esp"<<endl;
        outfile<<"    call    ___main"<<endl;
        x=j*16-(a-idwords[idwords.size()-1].offset);
        for(int i=1;i<idwords.size();i++){
            if(QT[i].temp_1->get_tag()==256){
                outfile<<"    movl    $"<<QT[i].temp_1->get_numvalue()<<", "<<x<<"(%esp)"<<endl;
                x-=4;
                var=i;
            }
        }
        outfile.close();
    }
    for(int i=var+1;i<QT.size();i++){
        GETR(i);
    }
}
void GETR(int i){
    ofstream outfile("test/main.s",ios::app);
    if(QT[i].temp_1->get_tag()==258){
        for(int j=0;j<RDL.size();j++){
            if(RDL[j].var==""){
                RDL[j].var=QT[i].temp_1->get_lexeme_str();
                RDL[j].flag=1;
                RDL[j].active=QT[i].temp_1->active;
                if(outfile.is_open()){
                    outfile<<"    movl    "<<x<<"(%esp)"<<", "<<"%"<<RDL[j].name<<endl;
                    if(QT[i].temp_2->get_tag()==256){
                        outfile<<"    mov1    $"<<QT[i].temp_2->get_numvalue()<<", %"<<RDL[j].name<<endl;

                        outfile<<"    nop"<<endl;
                        outfile<<"    leave"<<endl;
                        outfile<<"    ret"<<endl;
                        outfile<<"LFE10:"<<endl;
                        outfile<<"    .ident  "<<'\"'<<"HSB_CC: (GUN) 1.1.0"<<endl;
                        outfile.close();
                    }
                }
            }
        }
    }
}
