#include<iostream>
#include<fstream>
using namespace std;


void audioHtml(char title[] )
{
     ofstream outfile("audio.html");
     outfile << "<!DOCTYPE html> <html> <head> <meta charset=\"utf-8\"\/><title>Music Player</title></head><body><audio controls autoplay    loop><source src=/\"media/"<<title<<".mp3\" type=\"audio/mpeg\" />If u see this, just update your browser....</audio></body></html>";
}

void videoHtml(char title[])
{
    ofstream outfile("video.html");
     outfile << "<!DOCTYPE html> <html> <head> <meta charset=\"utf-8\"\/><title>Music Player</title></head><body><audio controls autoplay    loop><source src=/\"media/"<<title<<".mp3\" type=\"audio/mpeg\" />If u see this, just update your browser....</audio></body></html>";
}
