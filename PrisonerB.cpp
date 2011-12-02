// PrisonerB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "prisoner.h"


int _tmain(int argc, _TCHAR* argv[])
{

	Prisoner prisonerB;
	prisonerB.readTestimoniesFromFile("../data/counterOfTestimonies.txt");
	prisonerB.writeAnswersToFile("../data/answerOfPrisonerB.txt");

	system("pause");
	return 0;
}

