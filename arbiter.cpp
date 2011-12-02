#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int zliczaj (int u, int v) {
	
	v=v+u;
	return v;
};

int wynik (char a, char b,int &k1, int &k2) {
	int w1,w2;

	if (a=='W' && b=='W') {w1=1; w2=1; cout<<"Kara: 5 lat dla kazdego"<<endl; };
	if (a=='O' && b=='W') {w1=10; w2=0; cout<<"Kara: "<<w1<<" lat dla wieznia A; "<<w2<<" dla wieznia B"<<endl; };
	if (a=='W' && b=='O') {w1=0; w2=10; cout<<"Kara: "<<w1<<" lat dla wieznia A; "<<w2<<" lat dla wieznia B"; };
	if (a=='O' && b=='O') {w1=5; w2=5; cout<<"Kara: 1 rok dla kazdego"<<endl; };

	
	k1=zliczaj(w1,k1);
	k2=zliczaj(w2,k2);
	cout<<endl<<"== Kara A: "<<k1<<"\tKara B: "<<k2<<endl;
	return 0;
};


int main(int argc, char** argv[])
{
	char a,b,il;
	int j,k1,k2;
	k1=0;
	k2=0;

	string prisoner1_choice = "prisoner1_choice.txt";
	string prisoner2_choice = "prisoner2_choice.txt";

	cout<<"Sprawdzam czy istniej¹ pliki z wynikami..."<<endl;
	if(ifstream("prisoner1_choice.txt")) remove("prisoner1_choice.txt");
	if(ifstream("prisoner2_choice.txt")) remove("prisoner2_choice.txt");
	cout<<"Jezeli takowe istnialy, zostaly usuniete."<<endl;
	system("PAUSE");
	
	cout << "Ile kolejek?"<<endl;
	cin >> j;
	
	/*string ilosc_kolejek = "ilosc_kolejek.txt";
	ofstream ilosc_kolejek;
	ilosc_kolejek.open(ilosc_kolejek, ios::app);
	ilosc_kolejek << il;
	ilosc_kolejek.close(); */


	for (int i=1; i<=j; i++) {

	cout<<endl<<"Wyczekuje decyzji wiezniow..."<<endl;
	system("PrisonerA.exe");
	system("PrisonerB.exe");
	cout<<"Decyzje podjete!"<<endl<<endl;
	system("PAUSE");
	

	ifstream checkChoiceA(prisoner1_choice.c_str(), ios::in);
	checkChoiceA.get(a);
	checkChoiceA.close();
	cout<<"Wybor wieznia A: " << a <<endl<<endl;

	ifstream checkChoiceB(prisoner2_choice.c_str(), ios::in);
	checkChoiceB.get(b);
	checkChoiceB.close();
	cout<<"Wybor wieznia B: " << b <<endl<<endl;

	wynik(a,b,k1,k2);
	
	cout<<endl<<endl<<"Posumowanie:"<<endl<<"Kara A: "<<k1<<endl<<"Kara B: "<<k2<<endl;
	
	}

	cout<<endl<<endl<<"Posumowanie ostateczne:"<<endl<<"Kara A: "<<k1<<endl<<"Kara B: "<<k2<<endl;
	system("PAUSE");
	return 0;
}