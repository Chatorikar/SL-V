#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<iterator>
using namespace std;

struct symbol_table{
    int address;
    string symbol;
};

struct literal_table{
    int address;
    string literal;
};

class Assembler
{
    public:
        int LOC; 
        map<string,pair<string,string> >opcode;
        string Assembly_Program;
        struct symbol_table s[5];
        struct literal_table l[5];
        Assembler();
        int symbol_count;
        int literal_count;
        int Symbol_Table();
        bool isConstant(string);
        bool isLiteral(string);
        bool isSymbol(string);
        void updateLOC(int,vector<string>);
        int getAddress(string);
        void PrintTable();


};

Assembler::Assembler()
{

    opcode.insert(pair<string,pair<string,string> >("END",make_pair("AD","02")));
    opcode.insert(pair<string,pair<string,string> >("START",make_pair("AD","01")));
    opcode.insert(pair<string,pair<string,string> >("ORIGIN",make_pair("AD","03")));
    opcode.insert(pair<string,pair<string,string> >("EQL",make_pair("AD","04")));
    opcode.insert(pair<string,pair<string,string> >("LTORG",make_pair("AD","05")));
    opcode.insert(pair<string,pair<string,string> >("DC",make_pair("DL","01")));
    opcode.insert(pair<string,pair<string,string> >("DS",make_pair("DL","02")));
    opcode.insert(pair<string,pair<string,string> >("STOP",make_pair("IS","00")));
    opcode.insert(pair<string,pair<string,string> >("ADD",make_pair("IS","01")));
    opcode.insert(pair<string,pair<string,string> >("SUB",make_pair("IS","02")));
    opcode.insert(pair<string,pair<string,string> >("MULT",make_pair("IS","03")));
    opcode.insert(pair<string,pair<string,string> >("MOVER",make_pair("IS","04")));
    opcode.insert(pair<string,pair<string,string> >("MOVEM",make_pair("IS","05")));
    opcode.insert(pair<string,pair<string,string> >("COMP",make_pair("IS","06")));
    opcode.insert(pair<string,pair<string,string> >("BC",make_pair("IS","07")));
    opcode.insert(pair<string,pair<string,string> >("DIV",make_pair("IS","08")));
    opcode.insert(pair<string,pair<string,string> >("READ",make_pair("IS","09")));
    opcode.insert(pair<string,pair<string,string> >("PRINT",make_pair("IS","10")));
    symbol_count  = 0;
    literal_count = 0;

    map<string,pair<string,string> >::iterator it;

    // cout<<" "<<opcode["START"].first;
    // cout<<" "<<opcode["START"].second;

    // for(it=opcode.begin();it!=opcode.end();it++)
    //     cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<" "<<endl;
}

bool Assembler::isLiteral(string s)
{
    if(s[0] == '=')
        return true;
    return false; 
}

bool Assembler::isSymbol(string s)
{
    if(s.length() > 0)
        return true;
    return false; 
}




bool Assembler:: isConstant(string s) 
{ 
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            return false; 
  
    return true; 
} 


int Assembler::getAddress(string symbol)
{
    for(int i = 0 ; i < symbol_count ; i++)
    {
        if(s[i].symbol == symbol)
            return s[i].address; 
    }

    return 0;
}

void Assembler::updateLOC(int LOC , vector<string>v)
{
    if(v[1] == "ORIGIN")
    { 
       for(int i = 0; i < v[2].length() ; i++)
        {
            if(v[i] == "+" || v[i] == "-" )
            {
                int address = getAddress(v[2].substr(0,i-1));
                this->LOC = address + stoi(v[1].substr(i+1,v[2].length()-i));
            }
        } 
    }
    else
        this->LOC++;
}

int Assembler::Symbol_Table()
{
    // Program File Name :
    cout<<endl<<"Enter Assembly Program File Name :";
    // cin>>Assembly_Program;

    //Open a Souce Code file
    string line;
    vector<string> v;
    vector<string>update_loc;
    ifstream myfile ("input.txt");
    while (getline(myfile, line))
    {
        istringstream ss(line); 

        do { 
            string word; 
            ss >> word;
            v.push_back(word); 
    
        } while (ss); 

        if(v[1] == "START")
        {
            //where str is your number as std::string.
            LOC = stoi(v[2]); 
            if(isConstant(v[2]))
                cout<<endl<<"("<<opcode[v[1]].first<<" , "<<opcode[v[1]].second<<")"<<" (C ,"<<LOC<<")"<<endl;            
            else{
                cout<<"Error: Invalid Start Address ";
                return 0;
            }
        }

     else if(v[0]=="-")
       {
            if(v[1] == "END")
            {
                cout<<"("<<opcode[v[1]].first<<" , "<<opcode[v[1]].second<<")"<<" "<<LOC<<endl;
                updateLOC(LOC,v);

            }    
            else if(isSymbol(v[3])) // check
            {   

                cout<<"("<<opcode[v[1]].first<<" , "<<opcode[v[1]].second<<")"<<" (S ,"<<symbol_count<<")"<<" "<<LOC<<endl;
                s[symbol_count].symbol = v[3];
                symbol_count++;            
                updateLOC(LOC,v);
            }
            else if(isLiteral(v[3]))
            {
                cout<<"("<<opcode[v[1]].first<<" , "<<opcode[v[1]].second<<")"<<" (L ,"<<literal_count<<")"<<" "<<LOC<<endl;
                l[literal_count].literal = v[3];
                literal_count++; 
                updateLOC(LOC,v);
            }
       }    
       else if(isSymbol(v[0]))
       {
           


            if(v[1] == "END")
            {
                cout<<"("<<opcode[v[1]].first<<" , "<<opcode[v[1]].second<<")"<<" "<<LOC<<endl;

            }    
            else if(isSymbol(v[3]))
            {   
                cout<<"("<<v[0]<<" , "<<symbol_count<<")"<<"("<<opcode[v[1]].first<<" , "<<opcode[v[1]].second<<")"<<" (S ,"<<symbol_count<<")"<<" "<<LOC<<endl;                
                s[symbol_count].symbol = v[0];
                s[symbol_count].address = LOC;
                symbol_count++;            
                
                updateLOC(LOC,v);
                s[symbol_count].symbol = v[3];
                
            }
            else if(isLiteral(v[3]))
            {
                cout<<"("<<v[0]<<" , "<<symbol_count<<"("<<opcode[v[0]].first<<" , "<<opcode[v[0]].second<<")"<<"("<<"("<<opcode[v[1]].first<<" , "<<opcode[v[1]].second<<")"<<" (L ,"<<literal_count<<")"<<" "<<LOC<<endl;
                l[literal_count].literal = v[3];
                literal_count++; 

                s[symbol_count].symbol = v[0];
                s[symbol_count].address = LOC;
                symbol_count++;            
                
                updateLOC(LOC,v);
            
            }            
       }

        v.clear();
    }

   return 1;
}

void Assembler::PrintTable()
{
    for(int i = 0 ; i < symbol_count ; i++)
    {
        cout<<s[i].symbol<<"  "<<s[i].address<<endl;
    }

    cout<<endl<<endl<<endl;


    for(int i = 0 ; i < literal_count ; i++)
    {
        cout<<l[i].literal<<"  "<<l[i].address<<endl;
    }
}

int main()
{

    Assembler *Obj = new Assembler;
    Obj->Symbol_Table();
    Obj->PrintTable();

}
