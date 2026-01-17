#include<bits/stdc++.h>
using namespace std;


void checkcomment(string str){
    int n=str.length();
    if(n<2)
    {
        cout<<"This line has no comment"<<endl;
        return;
    }
    if(str[0]=='/')
    {
        if(str[1]=='/')
        {
            cout<<"Single line comment"<<endl;
        }
        else if(str[1]=='*')
        {
            if(n>=4&&str[n-2]=='*'&&str[n-1]=='/')
            {
                cout<<"Multiple line comment"<<endl;
            }
            else{
                cout<<"Invalid comment"<<endl;
            }
        }
        else{
            cout<<"No comment"<<endl;
        }
        
    }
    else{
            cout<<"No comment"<<endl;
        }


}

int main()
{
    string line;
    char choice;
    do{
        cout<<"Enter the string: ";
        getline(cin>>ws,line);
        checkcomment(line);
        cout<<"Do you want to check another time?(y/n):  ";
        cin>>choice;
    }while(choice=='y'||choice=='Y');
    
}