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
<<<<<<< .merge_file_smCdu6
<<<<<<< .merge_file_kjq2gS
<<<<<<< .merge_file_k2fJcw
	cout << "liczba rund: " << liczbarund << endl;
=======
=======
>>>>>>> .merge_file_Zmq2gI
=======
>>>>>>> .merge_file_PJhTQS
	cout << "liczba rund" << liczbarund << endl;

	// Send an initial buffer
	cout << "iResult" << iResult << endl;
>>>>>>> .merge_file_1fWfxl

	//send tru lub false
	char *jeden = "1";
	char *zero ="0";
	srand((unsigned) time(0));
<<<<<<< .merge_file_smCdu6
<<<<<<< .merge_file_kjq2gS
<<<<<<< .merge_file_k2fJcw
	char *przeciwnik = new char[liczbarund];
	for(int i =0;i<liczbarund;i++){
		if ((rand() % 5)%2) {
			send( ConnectSocket, "1", 1, 0 );
			cout << "Losowanie " << i << "wyslano " << jeden << endl;
		}
		else {
			send( ConnectSocket, "0", 1, 0 );
			cout << "Losowanie " << i << "wyslano " << zero << endl;
		}
		recv(ConnectSocket, recvbuf, recvbuflen, 0);
		cout << "Odebrano " << recvbuf[0] << endl;
=======
	char przeciwnik[100];
	for(int i =0;i<liczbarund;i++){
		if ((rand() % 5)%2) {
			send( ConnectSocket, "1", 1, 0 );
			cout << "losowanie " << i << "wyslano " << jeden << endl;
		}
		else {
			send( ConnectSocket, "0", 1, 0 );
=======
	char przeciwnik[100];
	for(int i =0;i<liczbarund;i++){
		if ((rand() % 5)%2) {
			send( ConnectSocket, "1", 1, 0 );
			cout << "losowanie " << i << "wyslano " << jeden << endl;
		}
		else {
			send( ConnectSocket, "0", 1, 0 );
>>>>>>> .merge_file_Zmq2gI
=======
	char przeciwnik[100];
	for(int i =0;i<liczbarund;i++){
		if ((rand() % 5)%2) {
			send( ConnectSocket, "1", 1, 0 );
			cout << "losowanie " << i << "wyslano " << jeden << endl;
		}
		else {
			send( ConnectSocket, "0", 1, 0 );
>>>>>>> .merge_file_PJhTQS
			cout << "losowanie " << i << "wyslano " << zero << endl;
		}
		recv(ConnectSocket, recvbuf, recvbuflen, 0);
		cout << "odebrano " << recvbuf[0] << endl;
<<<<<<< .merge_file_smCdu6
<<<<<<< .merge_file_kjq2gS
>>>>>>> .merge_file_1fWfxl
=======
>>>>>>> .merge_file_Zmq2gI
=======
>>>>>>> .merge_file_PJhTQS
		przeciwnik[i]=recvbuf[0];
		Sleep(15);
	}

<<<<<<< .merge_file_smCdu6
<<<<<<< .merge_file_kjq2gS
<<<<<<< .merge_file_k2fJcw
	cout << "Przeciwnik ";
	for (int i=0; i<liczbarund; i++) {
		cout << przeciwnik[i];
	}
	cout << endl;
	//odebranie informacji o wyniku
	char wynik[50];
	rozmiar=recv(ConnectSocket, wynik, sizeof(wynik), 0);
=======
=======
>>>>>>> .merge_file_Zmq2gI
=======
>>>>>>> .merge_file_PJhTQS
	cout << "przeciwnik"<< przeciwnik <<endl;

	//odebranie informacji o wyniku
	char wynik[50];
	rozmiar=recv(ConnectSocket, wynik, 50, 0);
<<<<<<< .merge_file_smCdu6
<<<<<<< .merge_file_kjq2gS
>>>>>>> .merge_file_1fWfxl
=======
>>>>>>> .merge_file_Zmq2gI
=======
>>>>>>> .merge_file_PJhTQS
	for (int i=0; i<rozmiar; i++) {
		cout << wynik[i];
	}
	cout << endl;
	// cleanup
	closesocket(ConnectSocket);
	WSACleanup();

<<<<<<< .merge_file_smCdu6
<<<<<<< .merge_file_kjq2gS
<<<<<<< .merge_file_k2fJcw
	cout << "Koniec gry.";
=======
	cout << "koniec gry";
>>>>>>> .merge_file_1fWfxl
=======
	cout << "koniec gry";
>>>>>>> .merge_file_Zmq2gI
=======
	cout << "koniec gry";
>>>>>>> .merge_file_PJhTQS
	getchar();
    return 0;
}