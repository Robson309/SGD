// server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <time.h>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;
WSADATA wsaData;

int _tmain(int argc, _TCHAR* argv[])
{	
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

	struct addrinfo *result = NULL,
                *ptr = NULL,
                hints;

	ZeroMemory( &hints, sizeof(hints) );
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	#define DEFAULT_PORT "27015"

	// Resolve the server address and port
	iResult = getaddrinfo("127.0.0.1", DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	SOCKET ConnectSocket = INVALID_SOCKET;

	// Attempt to connect to the first address returned by
	// the call to getaddrinfo
	ptr=result;

	// Create a SOCKET for connecting to server
	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, 
		ptr->ai_protocol);

	if (ConnectSocket == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}
	else {
		cout << "socket OK" << endl;
	}

	// Connect to server.
	iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
	}

	// Should really try the next address returned by getaddrinfo
	// if the connect call failed
	// But for this simple example we just free the resources
	// returned by getaddrinfo and print an error message

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		getchar();
		return 1;
	}
	else {
		cout << "Conect to server OK" << endl;
	}

	#define DEFAULT_BUFLEN 512
	int recvbuflen = DEFAULT_BUFLEN;

	char recvbuf[DEFAULT_BUFLEN];

	// odebranie liczby losowan
	int rozmiar;
	int liczbarund = 0;
	cout << "przed odebranie liczby losawan" << endl;
	rozmiar = recv(ConnectSocket,  (char *)&liczbarund, sizeof(liczbarund), 0);
	cout << "liczba rund: " << liczbarund << endl;

	//send tru lub false
	char *jeden = "1";
	char *zero ="0";
	srand((unsigned) time(0));
	char *przeciwnik = new char[liczbarund];
	//pierwsze zagranie losowe
	int suma=0;
	if ((rand() % 5)%2) {
		send( ConnectSocket, "1", 1, 0 );
		cout << "losowanie pierwsze " << "wyslano " << jeden << endl;
	}
	else {
		send( ConnectSocket, "0", 1, 0 );
		cout << "losowanie pierwsze " << "wyslano " << zero << endl;
	}
	recv(ConnectSocket, recvbuf, recvbuflen, 0);
	suma+=(char)recvbuf[0]-48;
	cout << "odebrano " << recvbuf[0] << endl;
	przeciwnik[0]=recvbuf[0];

	//dalsze zagrania
	for(int i=1;i<liczbarund;i++){
		cout << suma <<" i=" << i;
		//jesli zagral wiecej niz polowe razy unfair
		if ((i/2)<suma) {
			send( ConnectSocket, "0", 1, 0 );
			cout << "losowanie " << i << "wyslano 0 bo za czesto zdradza" << endl;
		}
		else {
			send( ConnectSocket, "1", 1, 0 );
			cout << "wyslano 1 bo jest OK" << endl;
		}
		recv(ConnectSocket, recvbuf, recvbuflen, 0);
		suma+=(char)recvbuf[0]-48;
		cout << "odebrano " << recvbuf[0] << endl;
		przeciwnik[i]=recvbuf[0];
		Sleep(15);
	}

	cout << "Przeciwnik ";
	for (int i=0; i<liczbarund; i++) {
		cout << przeciwnik[i];
	}
	cout << endl;
	//odebranie informacji o wyniku
	char wynik[50];
	rozmiar=recv(ConnectSocket, wynik, sizeof(wynik), 0);
	for (int i=0; i<rozmiar; i++) {
		cout << wynik[i];
	}
	cout << endl;
	// cleanup
	closesocket(ConnectSocket);
	WSACleanup();

	cout << "Koniec gry.";
	getchar();
    return 0;
}