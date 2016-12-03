#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>
#include<vector>
#include"../headers/lexer.h"
using namespace std;
struct route_node{
    char c;
    int next_state=0;
};
struct record{
   route_node* r_state;
   int size0;
};
record state[38];
route_node s1[17],s2[4],s3[5],s4[3],s5[3],s6[3],s7[4],s8[3],s9[2],s10[3],s11[2],s12[3],s13[2],s14[2],s15[2],s16[2],s17[2],s18[3],s19[3],s20[3],s21[4],s22[4],s23[3],s24[3],s25[2],s26[2],s27[2],s28[2],s29[2],s30[2],s31[2],s32[2],s33[2],s34[2],s35[5],s36[3],s37[3];
string KT[15]={"main","void","if","else","for","while","do","break","continue","return","int","char","float","double","const"};
void  auto_machine(){
    state[1].r_state=s1;
    state[1].size0=16;
    s1[1].c='0';
    s1[1].next_state=2;
    s1[2].c='1';
    s1[2].next_state=3;
    s1[3].c='\'';
    s1[3].next_state=9;
    s1[4].c='"';
    s1[4].next_state=11;
    s1[5].c='>';
    s1[5].next_state=4;
    s1[6].c='<';
    s1[6].next_state=5;
    s1[7].c='=';
    s1[7].next_state=6;
    s1[8].c='&';
    s1[8].next_state=18;
    s1[9].c='|';
    s1[9].next_state=19;
    s1[10].c='!';
    s1[10].next_state=20;
    s1[11].c='+';
    s1[11].next_state=21;
    s1[12].c='-';
    s1[12].next_state=22;
    s1[13].c='*';
    s1[13].next_state=23;
    s1[14].c='/';
    s1[14].next_state=24;
    s1[15].next_state=25;
    state[2].r_state=s2;
    state[2].size0=4;
    s2[1].c='0';
    s2[1].next_state=2;
    s2[2].c='1';
    s2[2].next_state=2;
    state[3].r_state=s3;
    state[3].size0=5;
    s3[1].c='1';
    s3[1].next_state=3;
    s3[2].c='.';
    s3[2].next_state=8;
    s3[3].c='e';
    s3[3].next_state=35;
    s3[4].next_state=0;
    state[4].r_state=s4;
    state[4].size0=3;
    s4[1].c='=';
    s4[1].next_state=13;
    state[5].r_state=s5;
    state[5].size0=3;
    s5[1].c='=';
    s5[1].next_state=14;
    state[6].r_state=s6;
    state[6].size0=3;
    s6[1].c='=';
    s6[1].next_state=15;
    state[7].r_state=s7;
    state[7].size0=4;
    s7[1].c='1';
    s7[1].next_state=7;
    s7[2].c='e';
    s7[2].next_state=35;
    state[8].r_state=s8;
    state[8].size0=3;
    s8[1].c='1';
    s8[1].next_state=7;
    s8[2].next_state=-1;
    state[9].r_state=s9;
    state[9].size0=2;
    s9[1].next_state=10;
    state[10].r_state=s10;
    state[10].size0=3;
    s10[1].c='\'';
    s10[1].next_state=16;
    s10[2].next_state=-1;
    state[11].r_state=s11;
    state[11].size0=2;
    s11[1].next_state=12;
    state[12].r_state=s12;
    state[12].size0=3;
    s12[1].c='"';
    s12[1].next_state=17;
    s12[2].next_state=12;
    state[18].r_state=s18;
    state[18].size0=3;
    s18[1].c='&';
    s18[1].next_state=26;
    state[19].r_state=s19;
    state[19].size0=3;
    s19[1].c='|';
    s19[1].next_state=27;
    state[20].r_state=s20;
    state[20].size0=3;
    s20[1].c='=';
    s20[1].next_state=28;
    state[21].r_state=s21;
    state[21].size0=4;
    s21[1].c='+';
    s21[1].next_state=29;
    s21[2].c='=';
    s21[2].next_state=30;
    state[22].r_state=s22;
    state[22].size0=4;
    s22[1].c='-';
    s22[1].next_state=31;
    s22[2].c='=';
    s22[2].next_state=32;
    state[23].r_state=s23;
    state[23].size0=3;
    s23[1].c='=';
    s23[1].next_state=33;
    state[24].r_state=s24;
    state[24].size0=3;
    s24[1].c='=';
    s24[1].next_state=34;
    state[35].r_state=s35;
    state[35].size0=5;
    s35[1].c='1';
    s35[1].next_state=37;
    s35[2].c='+';
    s35[2].next_state=36;
    s35[3].c='-';
    s35[3].next_state=36;
    s35[4].next_state=-1;
    state[36].r_state=s36;
    state[36].size0=3;
    s36[1].c='1';
    s36[1].next_state=37;
    s36[2].next_state=-1;
    state[37].r_state=s37;
    state[37].size0=3;
    s37[1].c='1';
    s37[1].next_state=37;
    state[13].r_state=s13;
    state[14].r_state=s14;
    state[15].r_state=s15;
    state[16].r_state=s16;
    state[17].r_state=s17;
    state[25].r_state=s25;
    state[26].r_state=s26;
    state[27].r_state=s27;
    state[28].r_state=s28;
    state[29].r_state=s29;
    state[30].r_state=s30;
    state[31].r_state=s31;
    state[32].r_state=s32;
    state[33].r_state=s33;
    state[34].r_state=s34;
    for(int i=13;i<=17;i++){
        state[i].size0=2;
    }
    for(int i=25;i<=34;i++){
        state[i].size0=2;
    }
}
int lexer(){
    int state_to_code(int x,string temp_s);
    int  check_state(int i,char t);
    string int2string(int x);
    auto_machine();
    FILE *fp;
    fp = fopen("test/1.txt", "r");
    char ch,temp_ch;
    int state=1,state_before;
    int line=1;
    string temp_str="";
    while((ch=getc(fp))!=EOF){
        if(state==1){
            if(ch=='\n'||ch==' '||ch=='\t'){
                if(temp_ch=='\n'){
                    line++;
                }
                continue;
            }
        }
        temp_ch=ch;
        state_before=state;
        if(ch>='0'&&ch<='9'){
            ch='1';
        }
        if(state_before==1||state_before==2){
            if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
                ch='0';
            }
        }
        state=check_state(state,ch);
        if(state){
            if(state==-1){
              cout<<"No. "<<line<<"line"<<": "<<"error"<<endl;
              return 0;
            }
            temp_str+=temp_ch;
        }else{
            int code=state_to_code(state_before,temp_str);
            if(code==-1){
                cout<<"No. "<<line<<"line"<<": "<<"error"<<endl;
                return 0;
            }
            if(code<=9){
                string temp_string=int2string(code);
                cout<<"<"<<temp_str<<","<<temp_string<<">"<<endl;
            }else{
              cout<<"<"<<temp_str<<","<<code<<">"<<endl;
            }
            if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
                ch='0';
            }
            if(ch!=' '&&ch!='\t'&&ch!='\n'){
                state=check_state(1,ch);
                temp_str="";
                temp_str+=temp_ch;
            }else{
                if(ch=='\n'){
                  line++;
                }
            temp_str="";
            state=1;
          }
        }
    }
    if(temp_str==""){
      return 1;
    }else{
        int code0=state_to_code(state,temp_str);
        if(code0==-1){
            cout<<"No. "<<line<<"line"<<": "<<"error"<<endl;
            return 0;
        }else{
            if(code0<=9){
               string temp_string=int2string(code0);
               cout<<"<"<<temp_str<<","<<temp_string<<">"<<endl;
            }else{
              cout<<"<"<<temp_str<<","<<code0<<">"<<endl;
            }
        }
    }
    return 1;
}
int  check_state(int i,char t){
    route_node *temp=state[i].r_state+1;
    int j=2;
    while(j<state[i].size0&&(*temp).c!=t){
        temp++;
        j++;
    }
    return (*temp).next_state;
}
int state_to_code(int x,string temp_s){
    int code;
    int temp_x;
    switch(x){
        case 2:
            code=find_key(temp_s);
            break;
        case 3:
            token_list.push_back(new Num(NUM,str2num(temp_s)));
            code=NUM;//整数
            break;
        case 7:
        case 37:
            cout<<"fuck"<<str2real(temp_s)<<endl;
            token_list.push_back(new Real(REAL,str2real(temp_s)));
            code=REAL;// 小数
            break;
        case 4:
            temp_x=(temp_s[0]-'0')+48;
            token_list.push_back(new Token(temp_x));
            code=temp_x;//>
            break;
        case 5:
            temp_x=(temp_s[0]-'0')+48;
            token_list.push_back(new Token(temp_x));
            code=temp_x;//<
            break;
        case 6:
            temp_x=(temp_s[0]-'0')+48;
            token_list.push_back(new Token(temp_x));
            code=temp_x;//=
            break;
        case 13:
            token_list.push_back(new Token(GE));
            code=GE;//>=
            break;
        case 14:
            token_list.push_back(new Token(LE));
            code=LE;//<=
            break;
        case 15:
            token_list.push_back(new Token(EQ));
            code=EQ;//==
            break;
        case 16:
            token_list.push_back(new Char(CHAR,get_charindex(temp_s)));
            code=CHAR;//字符
            break;
        case  17:
            token_list.push_back(new Word(STR,get_strindex(temp_s)));
            code=STR;//字符串
            break;
        case 21:
            temp_x=(temp_s[0]-'0')+48;
            token_list.push_back(new Token(temp_x));
            code=temp_x;//+
            break;
        case 22:
            temp_x=(temp_s[0]-'0')+48;
            token_list.push_back(new Token(temp_x));
            code=temp_x;//-
            break;
        case 23:
            temp_x=(temp_s[0]-'0')+48;
            token_list.push_back(new Token(temp_x));
            code=temp_x;//*
            break;
        case 24:
            temp_x=(temp_s[0]-'0')+48;
            token_list.push_back(new Token(temp_x));
            code=temp_x;//'/'
            break;
        case 25:
            temp_x=(temp_s[0]-'0')+48;
            token_list.push_back(new Token(temp_x));
            code=temp_x;//任意单字符
            break;
        case 26:
            token_list.push_back(new Token(AND));
            code=AND;
            break;
        case 27:
            token_list.push_back(new Token(OR));
            code=OR;
                break;
        case 28:
            token_list.push_back(new Token(NE));
            code=NE;
            break;
        case 29:
            token_list.push_back(new Token(ADD_A));
            code=ADD_A;
            break;
        case 30:
            token_list.push_back(new Token(ADD_E));
            code=ADD_E;
            break;
        case 31:
            token_list.push_back(new Token(MIN_M));
            code=MIN_M;
            break;
        case 32:
            token_list.push_back(new Token(MIN_E));
            code=MIN_E;
            break;
        case 33:
            token_list.push_back(new Token(MUL_E));
            code=MUL_E;
            break;
        case 34:
            token_list.push_back(new Token(DIV_E));
            code=DIV_E;
            break;
        default :
            code=-1;
    }
    return code;
}
int find_key(string x){
    int temp;
    temp=get_keyindex(x);
    if(temp==-1){
        temp=get_typeindex(x);
        if(temp==-1){
            temp=get_idindex(x);
            token_list.push_back(new Word(ID,temp));
            return ID;
        }else{
            token_list.push_back(new Word(TYPE,temp));
            return TYPE;
        }
    }else{
        token_list.push_back(new Word(KEY,temp));
        return KEY;
    }
}
int get_keyindex(string x){
    for(int i=0;i<=9;i++){
        if(keywords[i]==x)
            return i;
    }
    return -1;
}

int get_typeindex(string x){
    for(int i=0;i<t_w_len;i++){
        if(typewords[i]==x){
            return i;
        }
    }
    return -1;
}
int get_idindex(string x){
    for(int i=0;i<idwords.size();i++){
        if(idwords[i]==x)
            return i;
    }
    idwords.push_back(x);
    return idwords.size()-1;

}
int get_strindex(string x){
    for(int i=0;i<strwords.size();i++){
        if(x==strwords[i])
            return i;
    }
    strwords.push_back(x);
    return strwords.size()-1;
}
int str2num(string x){
    int temp=0;
    for(int i=0;i<=x.size();i++){
        temp=temp*10+(x[i]-'0');
    }
    return temp;
}
double str2real(string x){
    double temp;
    int n=0,p=0,m=0,e=1;
    int i=0;
    int flag=0;
    while(x[i]!='e'&&i<x.size()){
        if(x[i]=='.'){
            flag=1;
             i++;
             continue;
        }
        n=10*n+(x[i]-'0');
        if(flag){
            m++;
        }
        i++;
    }
    if(i==x.size()){
        temp=n*pow(10,-m);
        return temp;
    }else{
        i++;
        for(int j=i;j<x.size();j++){
           if(x[j]=='-'){
               e=-1;
               continue;
           }
           else if(x[j]=='+'){
               continue;
           }else{
               p=10*p+(x[j]-'0');
           }
        }
        int  temp_e=e*p-m;
        return temp=n*pow(10,temp_e);
    }
}
int get_charindex(string x){
    for(int i=0;i<mychar.size();i++){
        if(x==mychar[i]){
            return i;
        }else{
            mychar.push_back(x);
            return mychar.size()-1;
        }
    }
}
string int2string(int x){
    string temp_x="0";
    char temp_c='0'+x;
    temp_x+=temp_c;
    return temp_x;
}
