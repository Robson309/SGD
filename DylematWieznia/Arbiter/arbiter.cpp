#include <iostream>
#include <string>
#include <fstream>
#include <time.h>


using namespace std;

void sleep(long d)
{
clock_t start=clock();
while(clock() - start < d); 
}

int zliczaj (int u, int v) {
	
	v=v+u;
	return v;
};

int wynik (char a, char b,int &k1, int &k2) {
	int w1,w2;

	if (a=='F' && b=='F') {	w1=1; w2=1; 
							//cout<<"Kara: "<<w1<<" dla kazdego"<<endl; 
							};
	if (a=='F' && b=='U') {	w1=10; w2=0; 
							//cout<<"Kara: "<<w1<<" lat dla wieznia A; "<<w2<<" dla wieznia B"<<endl; 
							};
	if (a=='U' && b=='F') {	w1=0; w2=10; 
							//cout<<"Kara: "<<w1<<" lat dla wieznia A; "<<w2<<" lat dla wieznia B"; 
							};
	if (a=='U' && b=='U') {	w1=5; w2=5; 
							//cout<<"Kara: "<<w1<<" lat dla kazdego"<<endl; 
							};

	
	k1=zliczaj(w1,k1);
	k2=zliczaj(w2,k2);
	
	return 0;
};


int main(int argc, char** argv[])
{
	char a,b;
	int j,k1,k2;
	streamoff pozycja;
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
	sleep(1000);
	cout<<"Jezeli takowe istnialy, zostaly usuniete."<<endl;
	cout<<"========================================="<<endl;
	
	
	cout << endl<<"Ile kolejek?"<<endl;
	cin >> j;
	cout<<endl<<"Wyczekuje decyzji wiezniow.";
	sleep(1000);
	cout<<".";
	sleep(1000);
	cout<<"."<<endl;
	sleep(1000);
	cout<<"Decyzje podjete!"<<endl<<endl;

	cout<<endl;
	cout<<"_________________________________\n";
	cout<<"| Wiezien A\t | Wiezien B\t |\n";
	for (int i=1; i<=j; i++) {

	system("PrisonerA.exe");
	system("PrisonerB.exe");
	//system("PAUSE");
	

	ifstream checkChoiceA(prisoner1_choice.c_str(), ios::in|ios::ate);
	pozycja=checkChoiceA.tellg();
	checkChoiceA.seekg(pozycja-1);
	checkChoiceA.get(a);
	checkChoiceA.close();
	//cout<<"Wybor wieznia A: " << a <<endl<<endl;

	ifstream checkChoiceB(prisoner2_choice.c_str(), ios::in|ios::ate);
	pozycja=checkChoiceB.tellg();
	checkChoiceB.seekg(pozycja-1);
	checkChoiceB.get(b);
	checkChoiceB.close();
	//cout<<"Wybor wieznia B: " << b <<endl<<endl;
	wynik(a,b,k1,k2);
	cout<<"|  "<<a<<"\t\t |  "<<b<<"\t\t |\n";
	//cout<<endl<<endl<<"Posumowanie kolejki:"<<endl<<"Kara A: "<<k1<<endl<<"Kara B: "<<k2<<endl;
	
	}
	cout<<"_________________________________\n";
	cout<<endl<<endl<<"Posumowanie:"<<endl<<"Kara A: "<<k1<<endl<<"Kara B: "<<k2<<endl;
	system("PAUSE");
	return 0;
}