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
};

int main()
{
   Music m;
   m.playMedia();
   return 0;
}
