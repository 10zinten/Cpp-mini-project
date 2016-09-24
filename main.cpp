#include<iostream>
#include <windows.h>
#include<string>

//testing fetch
using namespace std;

void playMedia(int opt)
{
    char name[] = "";
    if(opt == 1)
       {
           ShellExecute(NULL, "open", "video.html",
            NULL, NULL, SW_SHOWNORMAL);
       }
    else
        {
            ShellExecute(NULL, "open", "audio.html",
                NULL, NULL, SW_SHOWNORMAL);
        }
}

int main()
{

   int opt;
   cout<<"lkfjasdlkjaskdjfssl"<<endl;
   cout<<"Media Player :"<<endl;
   cout<<"1.Play Video\n2.Play Audio\n: ";
   cin>>opt;
   switch(opt)
   {
       case 1: playMedia(opt);
                      break;

       case 2: playMedia(opt);
                      break;

       default: cout<<"Invalid Option";
   }

   return 0;
}
