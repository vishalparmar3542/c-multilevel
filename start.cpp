#include<iostream>
#include<string.h>
#include<vector>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
int start=1;

class user
{
    string name;

   string password;
   string incryption();

   string id;
   public:

    int registration();
    int deleteuser();
    int changedata();
    int printobj();
    friend int showalluser();
    friend  int userintofile(user);
    friend int menue();
    int login();

   int  module2()
   {

   }
};
   int user::login()
   {
       cout<<"\n\t\t\t     enter your id : ";
       cin>>id;
       cout<<"\n\t\t\t   enter your password : ";
       cin>>password;
       password=incryption();
       user second;
 ifstream in("IDpass.txt");
 while(in)
 {
 in>>second.name;
 in>>second.id;
 in>>second.password;
 if(second.id==id && second.password==password)
 {  cout<<"\t\t\t -------LOGIN succesfuLl-------- ";
 second.printobj();
 cout<<"\t\t\t enter any char to exit";
 getch();
 in.close();
 system("cls");
 return 0;
 }
 }
 cout<<"\t\t\t user ID or pass is wrong please try again(press any key )"<<endl;
 getch();
in.close();
system("cls");

   }
int user::printobj()
{
    cout<<"\n\t\tname is : "<<name;
     cout<<"\t \tid is :"<<id;
      cout<<"\t\tpass is :"<<password<<endl;
}
 string user:: incryption()
{
    for(int i=0;i<password.length();i++)
        password[i]=password[i]+780+i;
        return password;
}


int user::registration()
{   string temppass;
    cout<<"\t\t\tenter your name: "<<endl<<"\t\t\t";
    cin>>name;
    cout<<"\t\t\tenter your id: "<<endl<<"\t\t\t";
    cin>>id;

 user second;
 ifstream in("IDpass.txt");
 while(in)
 {
 in>>second.name;
 in>>second.id;
 in>>second.password;
 if(second.id==id)
 {
     cout<<"\t\t\t ID already exist choose another\n";
    // system("cls");
     user::registration();
 }

 }
in.close();



    again:
      cout<<"\t\t\tenter your  password: "<<endl<<"\t\t\t";
    cin>>password;
    cout<<" \t\t\t re-enter your password: "<<endl<<"\t\t\t";
    cin>>temppass;
    if(password==temppass)
    {

            password=incryption();

        cout<<"\t\t\t--------------------1st stage in done--------------------"<<endl;
        cout<<"\t\t\t! kindly remember your ID and password for future login's"<<endl;
        module2();

    }else
    {
        cout<<"\t\t\t! password do  not match enter agian"<<endl;
       system("cls");
         goto again;
    }

}
int userintofile(user obj)
      {    cout<<"\t\t\t------entering into file-----------"<<endl;
        fstream fout("IDpass.txt",ios::app);
         fout<<obj.name<<endl;
         fout<<obj.id<<endl;
        fout<<obj.password<<endl;
      }
int showalluser()
{
user second;
 ifstream in("IDpass.txt");
 while(in)
 {
 in>>second.name;
 in>>second.id;
 in>>second.password;
 second.printobj();

 }
in.close();
return 0;
}





int menue()

{   if(start==1)
   {
       cout<<"\t|||||||||||||||||||||||||||----------WELCOME----------------||||||||||||||||||||||||||||| "<<endl;
       start++;
   }
    int ch=0;
    cout<<"\t\t\t ___________________________________________"<<endl;
    cout<<"\t\t\t|_____________ENTER YOUR CHOICE____________|"<<endl;
    cout<<"\t\t\t|--------------enter 1 for LOGIN-----------|"<<endl;
    cout<<"\t\t\t|---------enter 2 for REGISTRATION---------|"<<endl;
    cout<<"\t\t\t|--------enter 3 for login as ADMIN--------|"<<endl;
    cout<<"\t\t\t|__________________________________________|"<<endl<<"\t\t\t";
    cin>>ch;
    system("cls");
    if((ch>0) && (ch<4))
   {
       return ch;
   }else{

       cout<<"\n\t\t\twrong choice !!!  enter again"<<endl;
       menue();
   }

}
int adminlogin()
{
   showalluser();
}


int main()
{

user first;

int ch=menue();
switch(ch)
{
case 1:
         first.login();
         main();

         break;
case 2:
       first.registration();
        userintofile(first);
        cout<<"\n\t\t\t press any key to continue"<<endl;
        cout<<"\t\t\t";getch();
        system("cls");
       main();
       break;
case 3:
       adminlogin();

       cout<<"\t\t\t  enter any key to continue";
       getch();
       system("cls");
       main();
       break;
deafult:
    cout<<"\n\t\tinvalid!!!!"<<endl;

}



return 0;




}
