#include<iostream>
#include <windows.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

#include "utils/html.h"

class Music
{
public:

    string title;
    string artist;
    string album;
    string genre;
    string id;
    int duration;

    Music():title(), artist(), album(), genre(), duration(0)
    { }

    void putMusic()
    {
        cout<<"Title : "<<title<<endl;
        cout<<"Artist : "<<artist<<endl;
        cout<<"Album : "<<album<<endl;
        cout<<"Genera : "<<genre<<endl;
        cout<<"Duration : "<<duration<<"mins\n"<<endl;
        cout<<"Songs id : "<<song_id<<endl;
        cout<<"Artist id : "<<artist_id<<endl;
        cout<<"Album id : "<<album_id<<endl;
        cout<<"Genre id : "<<genre_id<<endl;
    }

    void playMedia()
    {
         cout<<"Now playing  ~~~)) ";
         audioHtml(id);
         ShellExecute(NULL, "open", "audio.html",
            NULL, NULL, SW_SHOWNORMAL);
    }

    virtual void showSongs(ifstream& infile, string n)
        {
            char ch;
            string title;
            n = "^&" + n;
            regex e(n);
            while(infile)
            {
                getline(infile, title);
                if(regex_search(title, e))
                {
                    while(infile)
                    {
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

        virtual listing(ifstream& infile)
        {
            string name;
            while(infile)
            {
                getline(infile, name);
                cout<<name<<endl;
            }
        }
};

class Artist : public Music
{
public:
    void listing()
    {
         ifstream infile("Artist.txt", ios::in);
        Music::listing(infile);
    }

    void showSongs(string n)
    {
        string n;
        ifstream infile("sArtist.txt", ios::in);
        Music::showSongs(infile, n);
        }
    }
};

class Album : public Music
{
public:
    void listing()
    {
        ifstream infile("Ablum.txt", ios::in);
        Music::listing(infile);
    }

    void showSongs(string n)
    {
        string n;
        ifstream infile("sAlbum.txt", ios::in);
        Music::showSongs(infile, n);
    }
};

class Genre
{
public:
     void listing()
    {
        ifstream infile("Genre.txt", ios::in);
        Music::listing(infile);
    }

    void showSongs(string n)
    {
        string n;
        ifstream infile("sAlbum.txt", ios::in);
        cout<<"Album no : ";
        cin>>n;
        Music::showSongs(infile, n);
    }
};

int main()
{
  Music m;
  char ch;
  int n;
  int opt;

    cout<<"------- MUSIC APPLICATION ----------"<<endl;
    cout<<"\n1.Listen now"
          "\n2.Music Library"
          "\n3.Add Songs"
          "\n: ";
    cin>> opt; cin.ignore(15, '\n');
    switch(opt)
    {
        int opt1, artist, album, songs, genre;
        case 1: system("cls"); cout<<"Now playing "; break;
        case 2: system("cls");
                cout<<"----- Musics Library --------"<<endl;
                cout<<"\n1.Artist"
                      "\n2.Album"
                      "\n3.Songs"
                      "\n4.Genre"
                      "\n:";
                cin>>opt1; cin.ignore(1, '\n');
                switch(opt1)
                {
                    case 1: system("cls");
                            cout<<"Showing list of Artist"<<endl;
                            cout<<"Choose Artist : "<<endl;
                            cin>>artist;
                            cout<<"Showing list of the songs"<<endl;
                            cin>>songs;
                            cout<<"Playing songs !!!"<<endl;
                            break;

                    case 2: system("cls");
                            cout<<"Showing list of Album"<<endl;
                            cout<<"Choose Album : "<<endl;
                            cin>>artist;
                            cout<<"Showing list of the songs"<<endl;
                            cin>>songs;
                            cout<<"Playing songs !!!"<<endl;
                            break;

                    case 3: system("cls");
                            cout<<"Showing list of the songs"<<endl;
                            cin>>songs;
                            cout<<"Playing songs !!!"<<endl;
                            break;

                    case 4: system("cls");
                            cout<<"Showing list of Genre"<<endl;
                            cout<<"Choose Genre : "<<endl;
                            cin>>artist;
                            cout<<"Showing list of the songs"<<endl;
                            cin>>songs;
                            cout<<"Playing songs !!!"<<endl;
                            break;

                    default: cout<<"Invalid Choice !!! ";
                             break;
                }
                break;

        case 3: system("cls");
                cout<<"Add Your favorite Musics ";
                do
                {
                    m.addMusic();
                   cout<<"Add another song (y/n) : ";
                   cin>>ch; cin.ignore(1, '\n');
                } while(ch == 'y');

                n = Music::diskCount();
                for(int i=0; i<n; i++)
                {
                   cout<<"Music "<<i+1<<endl;
                   m.diskIn(i);
                   m.putMusic();
                }
                break;

        default: cout<<"Invalid Choice !!! ";
                 break;
    }

   return 0;
}
