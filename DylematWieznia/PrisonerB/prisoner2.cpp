#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;


int main(int argc, char** argv[])
{
	string prisoner2_choice = "prisoner2_choice.txt";
	ofstream prisoner2;

	prisoner2.open(prisoner2_choice.c_str(), ios::app);
		//srand( time(NULL) );
	//--always UNFAIR
		//if ((rand() % 2)%2) prisoner2 << "F";
			//else 
	prisoner2 << "U";

	prisoner2.close();

}