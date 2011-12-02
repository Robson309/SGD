#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;


int main(int argc, char** argv[])
{
	string prisoner2_choice = "prisoner2_choice.txt";

	ofstream prisoner2;
	prisoner2.open("prisoner2_choice.txt", ios::app);
	prisoner2 << "O" <<endl;
	prisoner2.close();

}