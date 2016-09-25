#include<iostream>
#include <windows.h>
#include<string>
#include<fstream>
using namespace std;

class Music
{
    char title[20];
    char artist[20];
    char album[40];
    char genera[10];
    int duration;

public:
    void playMedia()
    {
         ShellExecute(NULL, "open", "audio.html",
            NULL, NULL, SW_SHOWNORMAL);
    }

    void addMusic()
    {
        cout<<"Add Details of your favorite Music : "<<endl;
        cout<<"Title : "; gets(title);
        cout<<"Artist : "; gets(artist);
        cout<<"Album : "; gets(album);
        cout<<"Genera : "; gets(genera);
        cout<<"Duration : "; cin>>duration;
    }

    void diskIn(int);
    void diskOut();
    static int diskCount();
};

void Music::diskIn(int mn)
{
    ifstream infile;
    infile.open("SONGSLIB.DAT", ios::binary);
    infile.seekg( mn*sizeof(Music) );
    infile.read( (char *)this, sizeof(*this) );
}

void Music::diskOut()
{
    ofstream outfile;
    outfile.open("SONGSLIB.DAT", ios::app | ios::binary);
    outfile.write( (char*)this, sizeof(*this) );
}

int Music::diskCount()
{
    ifstream infile;
    infile.open("SONGSLIB.DAT", ios::binary );
    infile.seekg(0, ios::end );

    return (int)infile.tellg() / sizeof(Music);
}

int main()
{
   Music m;
   m.playMedia();
   return 0;
}
