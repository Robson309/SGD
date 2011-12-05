#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

void sleep(long d){
	clock_t start=clock();
	while(clock() - start < d); 
}

int zliczaj (int u, int v) {	
	v=v+u;
	return v;
};

int wynik (char a, char b,int &k1, int &k2) {
	int w1,w2;

	if (a=='F' && b=='F') {w1=1; w2=1;}
	if (a=='F' && b=='U') {w1=10; w2=0;}
	if (a=='U' && b=='F') {w1=0; w2=10;}
	if (a=='U' && b=='U') {w1=5; w2=5;}
							
	k1=zliczaj(w1,k1);
	k2=zliczaj(w2,k2);
	
	return 0;
};

int ifin (string fname) {
	char z;
	streamoff pozycja;

	ifstream checkChoice(fname.c_str(), ios::in|ios::ate);
	pozycja=checkChoice.tellg();
	checkChoice.seekg(pozycja-1);
	checkChoice.get(z);
	checkChoice.close();

	return z;
}


int main(int argc, char** argv[])
{
	char a,b;
	int j,k1,k2;
	
	k1=0;
	k2=0;

	string prisoner1_choice = "prisoner1_choice.txt";
	string prisoner2_choice = "prisoner2_choice.txt";

	cout<<"Sprawdzam czy istnieja pliki z wynikami.";
	if(ifstream(prisoner1_choice)) remove("prisoner1_choice.txt");
	if(ifstream(prisoner2_choice)) remove("prisoner2_choice.txt");
	sleep(1000);
	cout<<".";
	sleep(1000);
	cout<<"."<<endl;
	cout<<"Jezeli takowe istnialy, zostaly usuniete."<<endl;
	cout<<"========================================="<<endl;
		
	cout << endl<<"Ile kolejek?"<<endl;
	cin >> j;
	cout<<endl<<"Wyczekuje decyzji wiezniow.";
	sleep(1000);
	cout<<".";
	sleep(1000);
	cout<<"."<<endl;
	cout<<"Decyzje podjete!"<<endl<<endl;

	cout<<endl;
	cout<<"__________________________________\n";
	cout<<" | Wiezien A\t | Wiezien B\t |\n";
	
	for (int i=1; i<=j; i++) {

		system("PrisonerA.exe");
		system("PrisonerB.exe");

		a=ifin(prisoner1_choice);
		b=ifin(prisoner2_choice);
	
		wynik(a,b,k1,k2);
		cout<<"|  "<<a<<"\t\t |  "<<b<<"\t\t |\n";
	}

	cout<<"_________________________________\n";
	cout<<endl<<endl<<"Posumowanie:"<<endl<<"Kara wieznia A: "<<k1<<endl<<"Kara wieznia B: "<<k2<<endl;
	system("PAUSE");
	return 0;
}