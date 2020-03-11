#include<bits/stdc++.h>

using namespace std;
// Input  : Program in C
// Output : Uniform symbol table , identifier table 

class Lex
{

    private:
        string input_program;
        map<string , string>terminal;    
    public:
        void lex_analyser();
        Lex();
}; 

Lex::Lex()
{
    fstream file; 
    string terminal_name ,filename , terminal_index; 
  
    filename = "terminal.txt"; 
  
    file.open(filename.c_str()); 
  
    while (file >> terminal_name && file >> terminal_index ) 
    { 
        terminal[terminal_name] = terminal_index;
       
    } 

    for( auto const& x : terminal)
    {
        cout<<x.first << " " << x.second<<" \n";
    }
  
}

void Lex::lex_analyser()
{
    cout<<"Enter Name of C program : ";
    cin>>this->input_program;


}
int main()
{
    Lex *l = new Lex();
}
