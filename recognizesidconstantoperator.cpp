#include<bits/stdc++.h>
using namespace std;

typedef enum {start,id,constant,op,invalid} state; 

void check(string str)
{
    state crstate=start;
    int i=0;
    while(str[i]!='\0')
    {
        char c=str[i];
        switch(crstate){
            case start:
                if(isalpha(c)||c=='_') crstate=id;
                else if(isalnum(c)) crstate=constant;
                else if(strchr("+-*/=%&><|",c)) crstate=op;
                else crstate=invalid;
                break;
            case id:
                if(!isalpha(c)|| c=='_') crstate=invalid;
                break;
            case constant:
                if(!isalnum(c)) crstate=invalid;
                break;
            case op:
                if(!strchr("+-*/=><&%!|",c)) crstate=invalid;
                break;
            case invalid:
                break;
        }
        if(crstate==invalid) break;
        i++;
    }
    if(crstate==id) cout<<str<<" is a id"<<endl;
    else if(crstate==constant) cout<<str<<" is a constant"<<endl;
    else if(crstate==op) cout<<str<<" is a operator"<<endl;
    else cout<<str<<" is an invalid  thing"<<endl;
}

int main()
{
    string name;
    char choice;
    do{
        cout<<"Enter a string : ";
        cin>>name;

        check(name);

        cout<<"Do you want to check another time?(y/n) : ";
        cin>>choice;
    }while(choice=='y'||choice=='Y');
    
}