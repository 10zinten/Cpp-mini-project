#include<iostream>
#include<fstream>
#include<string>
#include<regex>
using namespace std;

void open(ifstream& infile, string n)
{
    char ch;
    string title;
    n = "^&" + n;
    regex e(n);
    while(infile) {
        getline(infile, title);
        if(regex_search(title, e)) {
            while(infile){
                infile.get(ch);
                if(ch != '#')
                    cout<<ch;
                else
                    break;
            }
            break;
        }
    }
}


int main()
{

    string n;
    ifstream infile("sGenre .txt", ios::in);
    cout<<"Genre no : ";
    cin>>n;
    open(infile, n);
    return 0;
}
