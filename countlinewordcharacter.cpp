#include<bits/stdc++.h>
using namespace std;

int main()
{
    string filename;
    char choice;
    do{
        cout<<"Enter the filename: ";
        cin>>filename;

        ifstream file(filename);

        if(!file){
            cout<<"Error opening file;"<<endl;
        }
        else{
            int characters=0,lines=0,words=0;
            string line;

            while(getline(file,line))
            {
                lines++;
                characters+=line.length()+1;
                stringstream ss(line);
                string word;
                while(ss>>word)
                {
                    words++;
                }
            }
            file.close();
             cout << "\n--- File Analysis Results ---" << endl;
            cout << "Total Lines     : " << lines << endl;
            cout << "Total Words     : " << words << endl;
            cout << "Total Characters: " << characters << endl;

            cout<<"Do you want to continue(y/n): ";
            cin>>choice;

        }
        cout<<"Do you want to continue(y/n): ";
        cin>>choice;

    }while(choice=='Y'||choice=='y');
}