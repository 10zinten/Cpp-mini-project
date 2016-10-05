#include<iostream>
#include<windows.h>  // For window shell function
#include<fstream>    // For handling file
#include<string>
#include<stdlib.h>   // For exit(0)
#include<sstream>    // For converting int to string
#include<regex>      // For creating Regular Expression
using namespace std;

#include "utils/html.h"      // for creating HTML file
#include "utils/random.h"    // For generating Random numbers

class Music
{
public:
     // Virtual function to create list out ARTIST, ALUBM, SONGS, GENRE
    virtual void listing(string fName)
    {
        // Opening file,
        ifstream infile("files/" + fName, ios::in);
        string name;

        // Checking for file Error
        if(!infile)
        { cout<<"Error , can not open the file !!!!!"; exit(0);}

        while(infile)
        {
            // Getting each line for file and Displaying out
            getline(infile, name);
            cout<<name<<endl;
        }
    }

    void playMedia(string id)
    {
        // Command to clear screen
        system("cls");
        cout<<"\n~~~~~~~~~ NOW PLAYING ~~~~~~~~\n"<<endl;

        // Opening file
        fstream infile("files/songs.txt", ios::in);
        //Checking for file error
        if(!infile)
        { cout<<"\n\nERROR, can't open the file\n"; exit(0); }
        string title;

        // Creating Regular Expression of Track ID
        string n = "^" + id;
        regex e(n);
        while(infile)
        {
            getline(infile, title);
            // searching for line beginning with regex
            if(regex_search(title, e))
                cout<<title;
        }
        // Creating HTML Audio Player file with passing track ID
        audioHtml(id);
        // Using Window shell command to Open the HTML file
        ShellExecute(NULL, "open", "audio.html",
        NULL, NULL, SW_SHOWNORMAL);
    }

    // Display all the songs under any Category
    virtual void showSongs(string fName, string n)
        {
            cout<<"\n###### LIST OF SONGS #######\n\n";
            // Opening file
            ifstream infile("files/" + fName, ios::in);
            // Checking for file Error
            if(!infile)
            { cout<<"\n\nERROR, can't open the file"; exit(0); }
            char ch;
            // Creating Regular Expression of track ID
            string title;
            n = "^&" + n;
            regex e(n);
            while(infile)
            {
                getline(infile, title);
                // Searching for line Begins with Regex
                if(regex_search(title, e))
                {
                    while(infile)
                    {   // getting each character Displaying until Encounter Delimiter #
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
};

class Artist : public Music
{
    string artistFile;  // private data member
    string songFile;

public:

    // Constructor to set data with Respective File name;
    Artist()
    {
        artistFile = "artist.txt";
        songFile = "sArtist.txt";
    }

    // Member for overriding Music class listing member with passing file name
    void listing(string lable)
    {
        cout<<"###### LIST OF ARTIST #######\n"<<endl;
        // Calling class Music Member listing
        Music::listing(artistFile);
    }

    // Member for overriding Music class listing member with passing file name and track ID
    void showSongs(string lable, string id)
    {
        Music::showSongs(songFile, id);
    }
};

class Album : public Music
{
    string albumFile;
    string songFile;

public:

    // Constructor to set data with Respective File name;
    Album()
    {
        albumFile = "album.txt";
        songFile =  "sAlbum.txt";
    }

    // Member for overriding Music class listing member with passing file name
    void listing(string lable)
    {
        cout<<"###### LIST OF ALBUM #######\n"<<endl;
        // Calling class Music Member listing
        Music::listing(albumFile);
    }

    // Member for overriding Music class showSongs member with passing file name and track ID
    void showSongs(string label , string id)
    {
        cout<<"ALBUM :"<<endl;
        // Passing file Name and track ID
        Music::showSongs(songFile, id);
    }
};

class Genre : public Music
{
    string genreFile;
    string songFile;
public:

    // Constructor to set data with Respective File name;
    Genre()
    {
        genreFile = "genre.txt";
        songFile = "sGenre.txt";
    }

    // Member for overriding Music class listing member with passing file name
    void listing(string label)
    {
        cout<<"###### LIST OF GENRE #######\n"<<endl;
        // Passing file name to class Music Member listing
        Music::listing(genreFile);
    }

    // Member for overriding Music class showSongs member with passing file name and track ID
    void showSongs(string lable, string id)
    {
        cout<<"GENRE :"<<endl;
        // Passing file Name and track ID
        Music::showSongs(songFile, id);
    }
};

// Converts random integer to string
string intToString()
{
    // Creating object of class sstream
    ostringstream temp;
    temp<<random(); // returns random integer number.

    // convert to string and returns
    return temp.str();
}

int main()
{
    // Create object and pointer to class Music
    Music* m, n;
    char ch;
    int opt;
    string id;

    do
    {
        // Displaying Menu
        system("cls");
        cout<<"\n@@@@@@@@@ MUSIC PLAYER @@@@@@@@"<<endl;
        cout<<"\n\n1.LISTEN NOW"
              "\n\n2.MUSIC LIBRARY"
              "\n\n3.EXIT"
              "\n\n: ";
        cin>> opt; cin.ignore(15, '\n');
        switch(opt)
        {
            // Playing Random song
            case 1: system("cls");
                    id = intToString();
                    n.playMedia(id);
                    break;
            case 2: system("cls");
                    cout<<"\n@@@@@@@@@ MUSIC LIBRARY @@@@@@@@"<<endl;
                    cout<<"\n1.ARTIST"
                          "\n2.ALBUM"
                          "\n3.SONGS"
                          "\n4.GENRE"
                          "\n\n:";
                    cin>>opt; cin.ignore(1, '\n');
                    switch(opt)
                    {
                        case 1: system("cls");
                                m = new Artist;              // Create Artist class Object and address is stored in pointer to class Music
                                m->listing("Artist");        // With late binding call member listing() of the Artist class
                                cout<<"\nArtist no : ";
                                cin>>id;                     // Gets Artist id from user
                                system("cls");
                                m->showSongs("Artist", id);  //With late binding call member showSongs() of the Artist class
                                cout<<"\n\nSong no : ";
                                cin>>id;
                                m->playMedia(id);            // Call PlayMedia member to play song
                                break;

                        case 2: system("cls");
                                m = new Album;             // Create Album class Object and address is stored in pointer to class Music
                                m->listing("Album");       //With late binding call member listing() of the Album class
                                cout<<"\nAlbum no : ";
                                cin>>id;                   // Gets Album id from user
                                system("cls");
                                m->showSongs("Album", id); //With late binding call member showSongs() of the Album class
                                cout<<"\n\nSong no : ";
                                cin>>id;                   // Get songs Id from user
                                m->playMedia(id);          // Call PlayMedia member to play song
                                break;

                        case 3: system("cls");
                                cout<<"\n###### LIST OF SONGS #######\n\n";
                                n.listing("songs.txt");
                                cout<<"Song no :";
                                cin>>id;
                                n.playMedia(id);
                                break;

                        case 4: system("cls");
                                m = new Genre;                // Create Genre class Object and address is stored in pointer to class Music
                                m->listing("Genre");          //With late binding call member listing() of the Genre class
                                cout<<"\nGenre no : ";
                                cin>>id;                      // Gets Album id from user
                                system("cls");
                                m->showSongs("Genre", id);    //With late binding call member showSongs() of the Genre class
                                cout<<"\n\nSong no : ";
                                cin>>id;                      // Get songs Id from user
                                m->playMedia(id);             // Call PlayMedia member to play song
                                break;

                        default: cout<<"Invalid Choice !!! ";
                                 break;
                    }
                    break;

            case 3: exit(0);   // Exit the program

            default: cout<<"Invalid Choice !!! ";
                     break;
        }
        // Ask user to try another songs
        cout<<"\n\nPlay another songs(y/n) : ";
        cin>>ch; cin.ignore('1', '\n');
    } while(ch == 'y' || ch == 'Y');
   return 0;
}
