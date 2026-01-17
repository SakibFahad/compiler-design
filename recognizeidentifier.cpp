#include<bits/stdc++.h>
using namespace std;

bool isidentifier(string input)
{
    if(input.empty()) return false;
    int flag=0;
    for(char c:input)
    {
        if(flag==0)
        {
            if(isalpha(c)||c=='_')
            {
                flag=1;
            }
            else return false;
        }
        else if(flag==1)
        {
            if(isalnum(c)||c=='_')
            {
                flag=1;
            }
            else return false;
        }
    }
    return (flag==1);
}

int main()
{
    string name;
    char choice;
    do{
        cout<<"enter a string to check if it is a valid identifier : ";
        cin>>name;
        if(isidentifier(name))
        {
            cout<<"Given string is a valid identifier."<<endl;
        }
        else cout<<"Given string is not a valid identifier."<<endl;

        cout<<"Do you want to check another string (y/n): ";
        cin>>choice;

    }while(choice=='y'||choice=='Y');
}
