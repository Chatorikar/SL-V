#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Assembler
{
    public:
        string Assembly_Program;
        void Symbol_Table();

};





void Assembler::Symbol_Table()
{
    cout<<endl<<"Enter Assembly Program File Name :";
    cin>>Assembly_Program;


    ifstream Program(Assembly_Program.c_str());

    for( string instruction ; getline(Program, instruction) ; )
    {
        cout<<"Ok";
    }
}

int main()
{
    Assembler *Obj = new Assembler;
    Obj->Symbol_Table();
}
