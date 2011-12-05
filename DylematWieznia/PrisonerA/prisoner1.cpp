#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <time.h>
 
using namespace std;

int main(int argc, char** argv[])
{	
	string prisoner1_choice = "prisoner1_choice.txt";
	ofstream prisoner1;
	prisoner1.open(prisoner1_choice.c_str(), ios::app);
	
	srand( time(NULL) );
	
		if ((rand() % 100)%2) {
			prisoner1 << "F";
		}
		else prisoner1 << "U";
	prisoner1.close();

}