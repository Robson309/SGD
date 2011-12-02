// PrisonerA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "prisoner.h"

int _tmain(int argc, _TCHAR* argv[])
{

	Prisoner prisonerA;
	prisonerA.readTestimoniesFromFile("../data/counterOfTestimonies.txt");
	prisonerA.writeAnswersToFile("../data/answerOfPrisonerA.txt");

	system("pause");
	return 0;
}

