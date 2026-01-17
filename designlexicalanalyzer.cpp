#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch) {
    string ops = "+-*/%=><!&|";
    return ops.find(ch) != string::npos;
}

void analyze(string code)
{
    int n=code.length();
    for(int i=0;i<n;)
    {
        if(isspace(code[i]))
        {
            i++;
            continue;
        }
        if(code[i]=='/'&& i+1<n)
        {
            if(code[i+1]=='/')
            {
                while(i<n && code[i]!='\n') i++;
                continue;
            }
        }
        if (code[i + 1] == '*') {
                i += 2;
                while (i + 1 < n && !(code[i] == '*' && code[i + 1] == '/')) i++;
                i += 2; 
                continue;
        }
        if (isalpha(code[i]) || code[i] == '_') {
            string id = "";
            while (i < n && (isalnum(code[i]) || code[i] == '_')) {
                id += code[i++];
            }
            cout << "IDENTIFIER: " << id << endl;
        }
         else if (isdigit(code[i])) {
            string val = "";
            while (i < n && isdigit(code[i])) {
                val += code[i++];
            }
            cout << "CONSTANT: " << val << endl;
        }
         else if (isOperator(code[i])) {
            cout << "OPERATOR: " << code[i++] << endl;
        }
        else {
            i++; 
        }
    }
}

int main()
{
    string name,line;
    char choice;
    do{
        cout<<"Enter your code: ";
        name="";
        while(getline(cin>>ws,line) && line!="#")
        {
            name+=line+"\n";
        }

        analyze(name);

        cout<<"Do you want to continue one more time?(y/n) : ";
        cin>>choice;
    }while(choice=='y'||choice=='Y');
}