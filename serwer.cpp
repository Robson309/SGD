// server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;
WSADATA wsaData;

int _tmain(int argc, _TCHAR* argv[])
{
<<<<<<< .merge_file_6UjI16
<<<<<<< .merge_file_BWYYpP
<<<<<<< .merge_file_Eq715z
	//trzeba podac liczbe rund
	int liczbarund = 200;
	char *graczzero = new char[liczbarund];
	char *graczjeden = new char[liczbarund];
=======
=======
>>>>>>> .merge_file_Ebs3Rz
=======
>>>>>>> .merge_file_VG7B12
	//trzeba podac liczbe rund oraz okreslic rozmiar tablicz
	char *rundki = "100";
	int liczbarund = 100;
	char graczzero[100];
	char graczjeden[100];
<<<<<<< .merge_file_6UjI16
<<<<<<< .merge_file_BWYYpP
>>>>>>> .merge_file_7P0pyn
=======
>>>>>>> .merge_file_Ebs3Rz
=======
>>>>>>> .merge_file_VG7B12
	int iResult;
	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}
	else {
		cout << "WSAStartup OK" << endl;
	}

	#define DEFAULT_PORT "27015"

	struct addrinfo *result = NULL, *ptr = NULL, hints;
	
	ZeroMemory(&hints, sizeof (hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;
	
	// Resolve the local address and port to be used by the server
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		return 1;
	}
	else {
		cout << "getaddrinfo ok" << endl;
	}
	
	SOCKET ListenSocket = INVALID_SOCKET;
	// Create a SOCKET for the server to listen for client connections
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

	if (ListenSocket == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}
	else {
		cout << "No error at socket" << endl;
	}
	
	 // Setup the TCP listening socket
    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
	else {
		cout << "bind ok no error" << endl;
	}
	freeaddrinfo(result);
	
	if ( listen( ListenSocket, SOMAXCONN ) == SOCKET_ERROR ) {
		printf( "Listen failed with error: %ld\n", WSAGetLastError() );
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	else {
		cout << "Listen OK" << endl;
	}

	SOCKET ClientSocket[1];
	int id_socket = 0;
	do {
		ClientSocket[id_socket] = INVALID_SOCKET;
		// Accept a client socket
		ClientSocket[id_socket] = accept(ListenSocket, NULL, NULL);
		if (ClientSocket[id_socket] == INVALID_SOCKET) {
			printf("accept failed: %d\n", WSAGetLastError());
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
		}
		else {
			cout << "Accept clientsocket" << endl;
			id_socket++;
			cout << id_socket << endl;
		}
		cout << "id socket ="<<id_socket << endl;
	}while(id_socket <= 1);
	id_socket--;
	cout << "po pentli";

	#define DEFAULT_BUFLEN 512
	
	int recvbuflen = DEFAULT_BUFLEN;
	//wyslanie inforamcji o liczbie rund
	cout << "przed wyslaniem liczby rund" << endl;
	int recvresult = 0;
	send (ClientSocket[0], (char*)&liczbarund, sizeof(liczbarund), 0);
	send (ClientSocket[1], (char*)&liczbarund, sizeof(liczbarund), 0);

	//odbieranie true lub false
	char zero[DEFAULT_BUFLEN];
	char jeden[DEFAULT_BUFLEN];
	int zer = DEFAULT_BUFLEN;
	int jed = DEFAULT_BUFLEN;
	cout << "przed odebraniem" << endl;
	for(int i =0;i<liczbarund;i++){
		//odebranie wartosci
		recv(ClientSocket[0], zero, 1, 0);
<<<<<<< .merge_file_6UjI16
<<<<<<< .merge_file_BWYYpP
<<<<<<< .merge_file_Eq715z
		cout << "odebranie" << i << endl;
		cout << "clientzero odebrano" <<zero[0] << endl;
		graczzero[i]= (int)zero[0]-48;
		recv(ClientSocket[1], jeden, 1, 0);
		graczjeden[i]=(int)jeden[0]-48;
		cout << "clientjeden odebrano" <<jeden[0] << endl;
=======
=======
>>>>>>> .merge_file_Ebs3Rz
=======
>>>>>>> .merge_file_VG7B12
		cout << "clientzero odebranie" << i << "odebrano" <<zero[0] << endl;
		graczzero[i]= (int)zero[0]-48;
		recv(ClientSocket[1], jeden, 1, 0);
		graczjeden[i]=(int)jeden[0]-48;
		cout << "clientjeden odebranie" << i << "odebrano" <<jeden[0] << endl;
<<<<<<< .merge_file_6UjI16
<<<<<<< .merge_file_BWYYpP
>>>>>>> .merge_file_7P0pyn
=======
>>>>>>> .merge_file_Ebs3Rz
=======
>>>>>>> .merge_file_VG7B12
		Sleep(150);
		//przeslanie dalej wartosci
		send( ClientSocket[0], jeden, 1, 0 );
		send( ClientSocket[1], zero, 1, 0 );
	}
	//obliczanie wyniku
	//przyjecie ze 1 to fair 0 unfair
	int wynikzero=0;
	int wynikjeden=0;
	for(int i =0;i<liczbarund;i++){
		if ((int)graczzero[i] == 1 && (int)graczjeden[i]==1){
			wynikzero=wynikzero+1;
			wynikjeden=wynikjeden+1;
<<<<<<< .merge_file_6UjI16
<<<<<<< .merge_file_BWYYpP
=======
>>>>>>> .merge_file_VG7B12
		}
		else if ((int)graczzero[i] == 0 && (int)graczjeden[i]==0){
			wynikzero=wynikzero+5;
			wynikjeden=wynikjeden+5;
		}
		else if ((int)graczzero[i] == 1 && (int)graczjeden[i]==0){
			wynikjeden=wynikjeden+10;
		}
		else if ((int)graczzero[i] == 0 && (int)graczjeden[i]==1){
			wynikzero=wynikzero+10;
<<<<<<< .merge_file_6UjI16
		}
=======
		}
		else if ((int)graczzero[i] == 0 && (int)graczjeden[i]==0){
			wynikzero=wynikzero+5;
			wynikjeden=wynikjeden+5;
		}
		else if ((int)graczzero[i] == 1 && (int)graczjeden[i]==0){
			wynikjeden=wynikjeden+10;
		}
		else if ((int)graczzero[i] == 0 && (int)graczjeden[i]==1){
			wynikzero=wynikzero+10;
		}
>>>>>>> .merge_file_Ebs3Rz
=======
		}
>>>>>>> .merge_file_VG7B12
		cout << "wynik zero " << wynikzero << endl;
		cout << "wynik jeden" << wynikjeden << endl;
	}
	cout << "wynik zero " << wynikzero << endl;
	cout << "wynik jeden" << wynikjeden << endl;
	
	//wyslanie informacji o wyniku
	//oraz wyswietlenie zwyciescy
	if (wynikzero>wynikjeden){
<<<<<<< .merge_file_6UjI16
<<<<<<< .merge_file_BWYYpP
<<<<<<< .merge_file_Eq715z
		cout << "Wygral gracz jeden" <<endl;
		send( ClientSocket[0], "Przegrales", (int)strlen("Przegrales"), 0 );
		send( ClientSocket[1], "Wygrales", (int)strlen("Wygrales"), 0 );
	}
	else if (wynikzero<wynikjeden){
		cout << "Wygral gracz zero" <<endl;
		send( ClientSocket[0], "Wygrales", (int)strlen("Wygrales"), 0 );
		send( ClientSocket[1], "Przegrales", (int)strlen("Przegrales"), 0 );
	}
	else {
		cout << "Gra zakonczona remisem." <<endl;
		send( ClientSocket[0], "Remis", (int)strlen("Remis"), 0 );
		send( ClientSocket[1], "Remis", (int)strlen("Remis"), 0 );
=======
=======
>>>>>>> .merge_file_Ebs3Rz
=======
>>>>>>> .merge_file_VG7B12
		cout << "wygral gracz jeden" <<endl;
		send( ClientSocket[0], "przegrales", (int)strlen("przegrales"), 0 );
		send( ClientSocket[1], "wygrales", (int)strlen("wygrales"), 0 );
	}
	else if (wynikzero<wynikjeden){
		cout << "wygral gracz zero" <<endl;
		send( ClientSocket[0], "wygrales", (int)strlen("wygrales"), 0 );
		send( ClientSocket[1], "przegrales", (int)strlen("przegrales"), 0 );
	}
	else {
		cout << "gra zakonczona remisem" <<endl;
		send( ClientSocket[0], "remis", (int)strlen("remis"), 0 );
		send( ClientSocket[1], "remis", (int)strlen("remis"), 0 );
<<<<<<< .merge_file_6UjI16
<<<<<<< .merge_file_BWYYpP
>>>>>>> .merge_file_7P0pyn
=======
>>>>>>> .merge_file_Ebs3Rz
=======
>>>>>>> .merge_file_VG7B12
	}


	// shutdown the send half of the connection since no more data will be sent
	iResult = shutdown(ClientSocket[id_socket], SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ClientSocket[id_socket]);
		WSACleanup();
		return 1;
	}

	// cleanup
	closesocket(ClientSocket[id_socket]);
	WSACleanup();

<<<<<<< .merge_file_6UjI16
<<<<<<< .merge_file_BWYYpP
<<<<<<< .merge_file_Eq715z
	cout << "Koniec gry.";
=======
	cout << "koniec gry";
>>>>>>> .merge_file_7P0pyn
=======
	cout << "koniec gry";
>>>>>>> .merge_file_Ebs3Rz
=======
	cout << "koniec gry";
>>>>>>> .merge_file_VG7B12
	getchar();
	return 0;
}