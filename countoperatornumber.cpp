#include<bits/stdc++.h>
using namespace std;

int main()
{
    
        string name;
        char choice;
        do{
            int count=0;
            cout<<"Enter the string : ";
            cin>>name;
            for(int i=0;i<name.length();i++){
                if(name[i]=='+' || name[i]=='-' || name[i]=='*' || name[i]=='/' || name[i]=='>' || name[i]=='<' 
                || name[i]=='%' || name[i]=='&' || name[i]=='=' || name[i]=='!' || name[i]=='|')
                    count++;
            }
            cout<<"There are "<<count<<" operators in the string"<<endl;
            cout<<"Do you want to continue?(y/n) : ";
            cin>>choice;
        }while(choice=='y'||choice=='Y');

}