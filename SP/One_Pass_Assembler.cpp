#include<bits/stdc++.h>

#include<iostream>

#include<map>

#include<iterator>

using namespace std;

struct symbol_table {
    int address;
    string symbol;
};

struct literal_table {
    int address;
    string literal;
};
enum e_usflcnst {
    Aksan = 0,
        Mandy = 1,
        Sahriani = 2,
        start = 4
};
class Assembler {
    public:
        int LOC;
    map < string, pair < string, string > > opcode;
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
    void updateLOC(int, vector < string > );
    int getAddress(string);
    void PrintTable();

    private:
        bool check_for_start(string);
        int check_for_type(string);
        void write_to_file(vector<string>);
        int check_for_the_symbol(string);
        bool check_if_exists(string);
        void Handle_LTORG();
};

Assembler::Assembler() {

    opcode.insert(pair < string, pair < string, string > > ("END", make_pair("AD", "02")));
    opcode.insert(pair < string, pair < string, string > > ("START", make_pair("AD", "01")));
    opcode.insert(pair < string, pair < string, string > > ("ORIGIN", make_pair("AD", "03")));
    opcode.insert(pair < string, pair < string, string > > ("EQL", make_pair("AD", "04")));
    opcode.insert(pair < string, pair < string, string > > ("LTORG", make_pair("AD", "05")));
    opcode.insert(pair < string, pair < string, string > > ("DC", make_pair("DL", "01")));
    opcode.insert(pair < string, pair < string, string > > ("DS", make_pair("DL", "02")));
    opcode.insert(pair < string, pair < string, string > > ("STOP", make_pair("IS", "00")));
    opcode.insert(pair < string, pair < string, string > > ("ADD", make_pair("IS", "01")));
    opcode.insert(pair < string, pair < string, string > > ("SUB", make_pair("IS", "02")));
    opcode.insert(pair < string, pair < string, string > > ("MULT", make_pair("IS", "03")));
    opcode.insert(pair < string, pair < string, string > > ("MOVER", make_pair("IS", "04")));
    opcode.insert(pair < string, pair < string, string > > ("MOVEM", make_pair("IS", "05")));
    opcode.insert(pair < string, pair < string, string > > ("COMP", make_pair("IS", "06")));
    opcode.insert(pair < string, pair < string, string > > ("BC", make_pair("IS", "07")));
    opcode.insert(pair < string, pair < string, string > > ("DIV", make_pair("IS", "08")));
    opcode.insert(pair < string, pair < string, string > > ("READ", make_pair("IS", "09")));
    opcode.insert(pair < string, pair < string, string > > ("PRINT", make_pair("IS", "10")));
    symbol_count = 0;
    literal_count = 0;

    map < string, pair < string, string > > ::iterator it;

    // cout<<" "<<opcode["START"].first;
    // cout<<" "<<opcode["START"].second;

    // for(it=opcode.begin();it!=opcode.end();it++)
    //     cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<" "<<endl;
}

bool Assembler::isLiteral(string s) {
    if (s[0] == '=')
        return true;
    return false;
}

bool Assembler::isSymbol(string s) {
    if(s.length() == 1)
        return true;
    return false; 

}

bool Assembler::isConstant(string s) {
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

int Assembler::getAddress(string symbol) {
    for (int i = 0; i < symbol_count; i++) {
        if (s[i].symbol == symbol)
            return s[i].address;
    }

    return 0;
}

void Assembler::updateLOC(int LOC, vector < string > v) {
    if (v[1] == "ORIGIN") {
        for (int i = 0; i < v[2].length(); i++) {
            if (v[i] == "+" || v[i] == "-") {
                int address = getAddress(v[2].substr(0, i - 1));
                this -> LOC = address + stoi(v[1].substr(i + 1, v[2].length() - i));
            }
        }
    } else
        this -> LOC++;
}

int Assembler::check_for_the_symbol(string sym)
{
    for(int i = 0 ; i < symbol_count ; i++)
    {
        if(s[i].symbol == sym)
        {
            return s[i].address;
        }
    }

    return -1;
}



bool Assembler::check_if_exists(string sym)
{
    for(int i = 0 ; i < symbol_count ; i++)
    {
        if(s[i].symbol == sym)
        {
            return true;
        }
    }

    return false;
}




bool Assembler::check_for_start(string source_code) {
    string line , start_word , start_address;
    vector < string > v;
    ifstream myfile(source_code);
    getline(myfile, line);
    istringstream ss(line);
    ss >> start_word;

    if (start_word == "START") {
        ss >> start_address;
        if (isConstant(start_address))
        {
            // if valid start address
            this -> LOC = LOC = stoi(start_address);
            cout << "\n\n(" << opcode[start_word].first << " , " << opcode[start_word].second << ")" << " (C ," << start_address << ")" << endl;

        }
        else
            return false;

        return true;
    }
    return false;
}


int Assembler::check_for_type(string str)
{

    if(isLiteral(str))
        return 1;
    
    if(isConstant(str))
        return 3;
    
    if(isSymbol(str))
        return 2;
    
    return 0;
}

void Assembler::Handle_LTORG()
{
    for(int i = 0 ; i < literal_count ; i++)
    {
        // if address is default address then assign current location counter address
        if(l[i].address == 0) 
        {
            cout << "(" << opcode["LTORG"].first << " , " << opcode["LTORG"].second << ")" << " (DL , 02) (C ,"<<l[i].literal<< ")  " <<this->LOC<<endl;
            l[i].address = this->LOC;
            this->LOC++;
        }

    }
}










int Assembler::Symbol_Table() {
    // Program File Name :
    cout << endl << "Enter Assembly Program File Name :";
    // cin>>Assembly_Program;

    //Open a Souce Code file
    string line, source_code("input.txt");
    vector < string > v;
    bool flag = true;
    vector < string > update_loc;

    // cout<<"\nEnter Souce Code file name :  ";
    // cin>>source_code;

    if (!check_for_start(source_code)) {
        cout << "Error: Invalid Start ";
        return 0;
    }

    ifstream myfile(source_code);
        
    while (getline(myfile, line)) {

        if(flag)
        {
            // to skip first line from souce code as we already process in check_for_start() method
            flag = false;
            continue;
        }

        istringstream ss(line);

        do {
            string word;
            ss >> word;
            v.push_back(word);

        } while (ss);

        cout<<"\n\n";
        for(auto x : v )
            cout<<" "<<x;
        cout<<"\n\n";


        if(opcode.count(v[0]) > 0)
        {   
            //opcode.count will give true or false if we have corresonding entry in OPCODE map or not
            //if MOVEM AREG B i.e. V[0] we have IS 
            //   v[0]  v[1] v[2]
            
            switch(check_for_type(v[2])) // check for start as it is having only two value v[0] v[1]
            {   

                case 0:
                    //As LTORG doesn't have v[2] if will return 0 so handle LTORG
                    cout<<"\n\n\n";
                    cout<<"\n\n\n";
                    this->Handle_LTORG();
                    break;
                
                case 1:
                    // if it is literal
                    cout << "(" << opcode[v[0]].first << " , " << opcode[v[0]].second << ")" << " (L ," << this->literal_count << ")" << " " <<this->LOC << endl;
                    l[literal_count].literal = v[2];
                    l[literal_count].address = 0;
                    literal_count++;
                    break;
                case 2:
                    // if it is symbol
                    cout << "(" << opcode[v[0]].first << " , " << opcode[v[0]].second << ")" << " (S ," << symbol_count << ")" << " " << this->LOC << endl;
                     // for processsing a lable but we have to print it's value before incrementing counter , also we have to increment counter to allocate for next symb
                    s[symbol_count].symbol = v[2];
                    symbol_count++;
                    break;

                case 3:
                    // if it is constant 
                    cout << "(" << opcode[v[0]].first << " , " << opcode[v[0]].second << ")" << " (C ," << v[2] << ")" << " " << this->LOC << endl;
                    break;
                
            }
            
            updateLOC(LOC, v);

        // if v[0] is not some statment then it must be EQU for Label
        }else if(v[1] == "EQU"){
            
            // Assign address of it's v[2] field it's lable at v[1]
            // handle Lable EQU A+1 
            int address = check_for_the_symbol(v[2]);

            if(address == -1)
            {
                cout<<"Error EQU : Invalid Symbol "<<v[2];
                return 0;
            }

            if(! check_if_exists(v[0]))
            {
                s[symbol_count].symbol = v[0]; 
                s[symbol_count].address =address;
                symbol_count++;
            }
        } 
        else {

            // v[0] i.e. label in symbol table and add address to label
            s[symbol_count].symbol = v[0]; 
            s[symbol_count].address = this->LOC;
                    symbol_count++;

            switch(check_for_type(v[3])) 
            {
                // if *Lable* MOVEM AREG B i.e. V[0] we have Label put it into ST
                case 1:
                    // if it is literal
                    cout <<"(" <<v[0] <<" , "<<symbol_count-1<< ")(" << opcode[v[1]].first << " , " << opcode[v[1]].second << ")" << " (L ," << literal_count << ")" << " " <<this->LOC << endl;
                    l[literal_count].literal = v[3];
                    l[literal_count].address = 0;
                    literal_count++;
                    break;
                case 2:
                    // if it is symbol
                    cout <<"(" <<v[0] <<" , "<<symbol_count-1<< ")(" << opcode[v[1]].first << " , " << opcode[v[1]].second << ")" << " (S ," << symbol_count << ")" << " " <<this->LOC << endl;
                    s[symbol_count].symbol = v[3];
                    symbol_count++;
                    break;

                case 3:
                    // if it is constant 
                    cout <<"(" <<v[0] <<" , "<<symbol_count<< ")(" << opcode[v[1]].first << " , " << opcode[v[1]].second << ")" << " (L ," << v[3] << ")" << " " <<this->LOC << endl;
                    break;
            }

           
            updateLOC(LOC, v);
        }


      

        v.clear();
    }

    return 1;
}

void Assembler::PrintTable() {
    for (int i = 0; i < symbol_count; i++) {
        cout << s[i].symbol << "  " << s[i].address << endl;
    }

    cout << endl << endl << endl;

    for (int i = 0; i < literal_count; i++) {
        cout << l[i].literal << "  " << l[i].address << endl;
    }
}

int main() {

    Assembler * Obj = new Assembler;
    Obj -> Symbol_Table();
 //   Obj -> PrintTable();

}
