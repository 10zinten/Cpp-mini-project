#include<iostream>
#include <windows.h>
#include<cstring>
#include<fstream>
using namespace std;

#include "utils/html.h"

class Music
{
    char title[20];
    char artist[20];
    char album[40];
    char genre[10];
    int duration;

public:
    Music():title(), artist(), album(), genre(), duration(0)
    { }

    void playMedia()
    {
         cout<<"Now playing  ~~~)) ";
         audioHtml(title);
         ShellExecute(NULL, "open", "audio.html",
            NULL, NULL, SW_SHOWNORMAL);
    }

    void addMusic()
    {
        cout<<"Add Details of your favorite Music : "<<endl;
        cout<<"Title : "; cin.get(title, 20); cin.ignore(1, '\n');
        cout<<"Artist : "; cin.get(artist, 20); cin.ignore(1, '\n');
        cout<<"Album : "; cin.get(album, 40); cin.ignore(1, '\n');
        cout<<"Genre : "; cin>>genre; cin.ignore(1, '\n');
        cout<<"Duration : "; cin>>duration; cin.ignore(1, '\n');
    }

    void DisplayMusic()
    {
        cout<<"Title : "<<title<<endl;
        cout<<"Artist : "<<artist<<endl;
        cout<<"Album : "<<album<<endl;
        cout<<"Genera : "<<genre<<endl;
        cout<<"Duration : "<<duration<<"mins\n"<<endl;
    }
    void diskIn(int);
    void diskOut();
    static int diskCount();

};

void Music::diskIn(int mn)
{
    cout<<"Read song from Disk"<<endl;
    ifstream infile;
    infile.open("SONGSLIB.DAT", ios::binary);
    infile.seekg( mn*sizeof(Music) );
    infile.read( (char *)this, sizeof(*this) );
}

void Music::diskOut()
{
    cout<<"Saving song in disk"<<endl;
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
   char ch;

   do
   {
       m.addMusic();
       m.diskOut();
       cout<<"Add another song (y/n) : ";
       cin>>ch; cin.ignore(1, '\n');
   } while(ch == 'y');

   int n = Music::diskCount();
   for(int i=0; i<n; i++)
   {
       cout<<"Music "<<i+1<<endl;
       m.diskIn(i);
       m.DisplayMusic();
   }
   cout<<endl;
   m.playMedia();

   return 0;
}
