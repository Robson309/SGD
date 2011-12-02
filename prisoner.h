#ifndef PRISONER_H
#define PRISONER_H

#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "CfgReader.h"

using namespace std;

class Prisoner: public CfgReader{

public:
	void writeAnswersToFile(string file);
};

#endif