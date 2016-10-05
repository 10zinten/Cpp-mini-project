#include<iostream>
#include<fstream>
#include<string>
using namespace std;


void audioHtml(string title )
{
     ofstream outfile("audio.html");
     outfile << "<!DOCTYPE html> <html> <head> <meta charset=\"utf-8\"/><title>Music Player</title></head><body><audio controls autoplay loop><source src=\"media/"<<title<<".mp3\" type=\"audio/mpeg\" />If u see this, just update your browser....</audio></body></html>";
}

void videoHtml(char title[])
{
    ofstream outfile("video.html");
     outfile << "<!DOCTYPE html><html><head><meta charset=\"utf-8\"/><title>Video</title></head><body><video with=\"640\" height=\"360\" controls autoplay loop><source src=\"media/"<<title<<".mp4\" type=\"video/mp4\" />if u see this, just update your Browser</video></body></html>";
}
