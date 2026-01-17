#include<bits/stdc++.h>
using namespace std;

bool iskeyword(string str) {
    vector<string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while", "class", "namespace"
    };
return find(keywords.begin(), keywords.end(), str) != keywords.end();
}
bool isvalididentifier(string str)
{
    if(str.empty()|| iskeyword(str)) return false;
    if(!(isalpha(str[0]) || str[0]=='_')) return false;
    for(int i=1;i<str.size();i++)
    {
        if(!(isalnum(str[i])|| str[i]=='_'))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string name;
    char choice;

    do{
        cout<<"Enter the string: ";
        cin>>name;


        if(isvalididentifier(name))
        {
            cout<<"Input is a valid identifier"<<endl;

        }
        else{
            if(iskeyword(name))
            {
                cout<<"Input is researved keyword"<<endl;
            }
            else{
                cout<<"Input is invalid"<<endl;
            }
        }
        cout<<"Do you want to check another time?(y/n): ";
        cin>>choice;
    }while(choice=='y'||choice=='Y');
    
}