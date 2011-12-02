// Arbiter.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include<fstream>
#include<iostream>
#include <time.h>
#include "CfgReader.h"

using namespace std;

class Arbiter: public CfgReader{

public:

	/*int counterOfTestimonies(){

	int counter = 0;
	cout << "\nHow many testimonies do you want?" << endl;
	cin >> counter;
	cout << "\nYou declarated " << counter << " testimonies." << endl;

	return counter;

	}
*/
	void processAnswers(string fileA,
		string fileB){
		
		ifstream ifsA(fileA);
		ifstream ifsB(fileB);

		char a1 = 0;
		char a2 = 0;
		float sentenceA = 0;
		float sentenceB = 0;

		for (int i = 1; i <= counter_; i++){
			ifsA >> a1;
			ifsB >> a2;

			if ( a1 == 'F' && a2 == 'F' ){
				sentenceA += 0.5;
				sentenceB += 0.5;
			} else if ( a1 == 'F' && a2 == 'U' ){
				sentenceA += 10;
				sentenceB += 0;
			} else if ( a1 == 'U' && a2 == 'F' ){
				sentenceA += 0;
				sentenceB += 10;
			} else if ( a1 == 'U' && a2 == 'U' ){
				sentenceA += 5;
				sentenceB += 5;
			}					
		}

		ifsA.close();
		ifsB.close();

		cout << "Prisoner A: " << sentenceA << " years." << endl
			<< "Prisoner B: " << sentenceB << " years." << endl;

	}

	/*void writeTestimoniesToFile(string file, int counter){

		ofstream ifs(file);
		if (ifs.fail())
			cout << "Cannot open this file!";

		ifs << counter;
		ifs.close();
	}*/

		
};

int _tmain(int argc, _TCHAR* argv[]){

	int counter_ = 0;
	cout << "How many testimonies do you want?" << endl;
	cin >> counter_;
	cout << "The number of testimonies is: " << counter_ << endl;
	Arbiter arbiter;
	arbiter.writeTestimoniesToFile("../data/counterOfTestimonies.txt", counter_);
	//tutaj nastepuja zeznania
	arbiter.readTestimoniesFromFile("../data/counterOfTestimonies.txt");
	arbiter.processAnswers("../data/answerOfPrisonerA.txt",
		"../data/answerOfPrisonerB.txt");

	system("pause");
	return 0;
}

