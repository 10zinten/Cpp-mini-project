#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<sstream>
#include<regex>
using namespace std;

#include "utils/html.h"
#include "utils/random.h"

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
    }

    void playMedia(string id)
    {
        cout<<"Now playing  ~~~)) ";
        audioHtml(id);
        ShellExecute(NULL, "open", "audio.html",
        NULL, NULL, SW_SHOWNORMAL);
    }

    virtual void showSongs(string fName, string n)
        {
            cout<<"###### LIST OF SONGS #######";
            ifstream infile("files/" + fName, ios::in);
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

        virtual void listing(string fName)
        {
            ifstream infile("files/" + fName, ios::in);
            string name;
            if(!infile)
            { cout<<"Error , can not open the file !!!!!"; exit(0);}
            while(infile)
            {
                getline(infile, name);
                cout<<name<<endl;
            }
        }
};

class Artist : public Music
{
    string artistFile;

public:
    void listing(string aName)
    {
        artistFile = "artist.txt";
        cout<<"###### LIST OF ARTIST #######"<<endl;
        Music::listing(artistFile);
    }

    void showSongs(string sName, string n)
    {
        Music::showSongs(sName, n);
    }
};


class Album : public Music
{
    string albumFile;

public:
      void listing(string lable)
    {
        albumFile = "album.txt";
        cout<<"###### LIST OF ALBUM #######"<<endl;
        Music::listing(albumFile);
    }

    void showSongs(string sName, string n)
    {
        Music::showSongs(sName, n);
    }
};

class Genre : public Music
{
    string genreFile;
public:
      void listing(string label)
    {
        genreFile = "genre.txt";
        cout<<"###### LIST OF GENRE #######"<<endl;
        Music::listing(genreFile);
    }

    void showSongs(string sName, string n)
    {
        Music::showSongs(sName, n);
    }
};

string intToString()
{
    ostringstream temp;
    temp<<random();

    return temp.str();
}

int main()
{
    Music* m;
    char ch;
    int n;
    int opt;
    string id;

    do
    {
        system("cls");
        cout<<"\n@@@@@@@@@ MUSIC PLAYER @@@@@@@@"<<endl;
        cout<<"\n\n1.Listen now"
              "\n\n2.Music Library"
              "\n: ";
        cin>> opt; cin.ignore(15, '\n');
        switch(opt)
        {
            case 1: system("cls");
                    cout<<"Now playing ";
                    id = intToString();
                    m->playMedia(id);
                    break;
            case 2: system("cls");
                    cout<<"\n@@@@@@@@@ MUSIC LIBRARY @@@@@@@@"<<endl;
                    cout<<"\n1.ARTIST"
                          "\n2.ALBUM"
                          "\n3.SONGS"
                          "\n4.GENRE"
                          "\n:";
                    cin>>opt; cin.ignore(1, '\n');
                    switch(opt)
                    {
                        case 1: system("cls");
                                m = new Artist;
                                m->listing("artist");
                                cout<<"\nArtist no : ";
                                cin>>id;
                                system("cls");
                                m->showSongs("sArtist.txt", id);
                                cout<<"\n\nSong no : ";
                                cin>>id;
                                m->playMedia(id);
                                break;

                        case 2: system("cls");
                                m = new Album;
                                m->listing("album");
                                cout<<"\nAlbum no : ";
                                cin>>id;
                                system("cls");
                                m->showSongs("sAlbum.txt", id);
                                cout<<"\n\nSong no : ";
                                cin>>id;
                                m->playMedia(id);
                                break;

                        case 3: system("cls");
                                cout<<"#### SONGS #####";
                                m->listing("songs.txt");
                                cout<<"Song no :";
                                cin>>id;
                                m->playMedia(id);
                                break;

                        case 4: system("cls");
                                m = new Genre;
                                m->listing("genre.txt");
                                cout<<"\nGenre no : ";
                                cin>>id;
                                system("cls");
                                m->showSongs("sGenre.txt", id);
                                cout<<"\n\nSong no : ";
                                cin>>id;
                                m->playMedia(id);
                                break;

                        default: cout<<"Invalid Choice !!! ";
                                 break;
                    }
                    break;

            default: cout<<"Invalid Choice !!! ";
                     break;
        }
        cout<<"\n\nPlay another songs(y/n) :";
        cin>>ch; cin.ignore('1', '\n');
    } while(ch == 'y' || ch == 'Y');
   return 0;
}
