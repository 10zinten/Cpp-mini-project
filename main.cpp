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
};

int main()
{
   Music m;
   m.playMedia();
   return 0;
}
