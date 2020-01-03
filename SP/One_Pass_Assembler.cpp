#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<iterator>
using namespace std;

class Assembler
{
    public:
        map<string,pair<string,string> >temp;
        string Assembly_Program;
        Assembler();
        void Symbol_Table();


};

Assembler::Assembler()
{


    temp.insert(pair<string,pair<string,string> >("END",make_pair("AD","02")));
    temp.insert(pair<string,pair<string,string> >("START",make_pair("AD","01")));
    temp.insert(pair<string,pair<string,string> >("ORIGIN",make_pair("AD","03")));
    temp.insert(pair<string,pair<string,string> >("EQL",make_pair("AD","04")));
    temp.insert(pair<string,pair<string,string> >("LTORG",make_pair("AD","05")));
    temp.insert(pair<string,pair<string,string> >("DC",make_pair("DL","01")));
    temp.insert(pair<string,pair<string,string> >("DS",make_pair("DL","02")));
    temp.insert(pair<string,pair<string,string> >("STOP",make_pair("IS","00")));
    temp.insert(pair<string,pair<string,string> >("ADD",make_pair("IS","01")));
    temp.insert(pair<string,pair<string,string> >("SUB",make_pair("IS","02")));
    temp.insert(pair<string,pair<string,string> >("MULT",make_pair("IS","03")));
    temp.insert(pair<string,pair<string,string> >("MOVER",make_pair("IS","04")));
    temp.insert(pair<string,pair<string,string> >("MOVEM",make_pair("IS","05")));
    temp.insert(pair<string,pair<string,string> >("COMP",make_pair("IS","06")));
    temp.insert(pair<string,pair<string,string> >("BC",make_pair("IS","07")));
    temp.insert(pair<string,pair<string,string> >("DIV",make_pair("IS","08")));
    temp.insert(pair<string,pair<string,string> >("READ",make_pair("IS","09")));
    temp.insert(pair<string,pair<string,string> >("PRINT",make_pair("IS","10")));

    map<string,pair<string,string> >::iterator it;
for(it=temp.begin();it!=temp.end();it++)
    cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<" "<<endl;
}





void Assembler::Symbol_Table()
{
    // Program File Name :
    cout<<endl<<"Enter Assembly Program File Name :";
    cin>>Assembly_Program;

    //Open a Souce Code file
    ifstream Program(Assembly_Program.c_str());

    int i=1;
    for( string instruction ; getline(Program, instruction) ; ){

        vector<string> strings;
        istringstream f(instruction);
        string s;
        while (getline(f, s, ' ')) {
           if(i == 1)
           {

           }
           cout <<" "<<s <<"  "<<i<< endl;
           strings.push_back(s);
           string[1];
       }
    }
}

int main()
{
    Assembler *Obj = new Assembler;
    Obj->Symbol_Table();
}
