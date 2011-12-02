#ifndef CFGREADER_H
#define CFGREADER_H
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

using namespace std;

class CfgReader{
public:
	CfgReader():counter_(0){}

	int writeTestimoniesToFile(string file, int counter_){
		ofstream ofs(file);
		if (ofs.fail())
			cout << "Cannot open this file!";

		ofs << counter_;
		ofs.close();

		return counter_;
	}

	int readTestimoniesFromFile(string file){

		ifstream ifs(file);
		if (ifs.fail())
			cout << "Cannot open this file!";
		ifs >> counter_;
		ifs.close();

		return counter_;
	}
protected:
	int counter_;

};
#endif