#include<bits/stdc++.h>
#include <vector>

using namespace std;

class Tape
{
	public:
		int num_of_program;
		int size_of_tape;
		vector<int> program;
		vector<vector<int>>tape;
		Tape(int , int);
		Stored_Program();

};

Tape::Tape(int num_of_program , int size_of_tape)
{
	this->num_of_program = num_of_program;
	this->size_of_tape = size_of_tape;

	int temp;

	cout<<"\nEnter the Size of each Prgram : \n\n";
	for(int i = 0 ; i < num_of_program ; i++)
	{	
		cout<<"\nEnter Size of "<<i+1<<" Program :  ";
		cin>>temp;
		program.emplace_back(temp);
	}
}

void Tape::Stored_Program()
{
	for(int i = 0 ; i < num_of_program ; i++)
	{
		for(int j = 0 ; j < 3 ; j++ )
		{
			int status = stored_into_tape(tape[j],program[i]);	
		}
		

		if(!status)
			cout<<"Error : Memory is full for "<< program[i];
	}
}


int main()
{
	int size_of_tape , num_of_program;
	

	cout<<"\nEnter Size of Tape : ";
	cin>>size_of_tape;

	cout<<"\nEnter Nummber of Program : ";
	cin>>num_of_program;

	Tape *t = new Tape( num_of_program  ,size_of_tape );

}
