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
<<<<<<< HEAD

	char recvbuf[DEFAULT_BUFLEN];
=======
	
	//char *sendbuf = "this is a test";
	char recvbuf[DEFAULT_BUFLEN];

	// Send an initial buffer
	/*iResult = send(ConnectSocket, sendbuf, (int) strlen(sendbuf), 0);
	if (iResult == SOCKET_ERROR) {
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}*/
	
	//printf("Bytes Sent: %ld\n", iResult);
	// shutdown the connection for sending since no more data will be sent
	// the client can still use the ConnectSocket for receiving data
	/*iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}*/
>>>>>>> origin/robson

	// odebranie liczby losowan
	int rozmiar;
	int liczbarund = 0;
	cout << "przed odebranie liczby losawan" << endl;
<<<<<<< HEAD
	rozmiar = recv(ConnectSocket,  (char *)&liczbarund, sizeof(liczbarund), 0);
	cout << "liczba rund: " << liczbarund << endl;

	//send tru lub false
	char *jeden = "1";
	char *zero ="0";
	srand((unsigned) time(0));
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
		przeciwnik[i]=recvbuf[0];
		Sleep(15);
	}

	cout << "Przeciwnik ";
	for (int i=0; i<liczbarund; i++) {
		cout << przeciwnik[i];
=======
	rozmiar = recv(ConnectSocket, recvbuf, recvbuflen, 0);
	cout << "liczba rund ";
	for (int i=0; i<rozmiar; i++) {
		cout << recvbuf[i];
>>>>>>> origin/robson
	}
	cout << endl;
	//odebranie informacji o wyniku
	char wynik[50];
	rozmiar=recv(ConnectSocket, wynik, sizeof(wynik), 0);
	for (int i=0; i<rozmiar; i++) {
		cout << wynik[i];
	}
<<<<<<< HEAD
	cout << endl;
=======
	cout << "liczba jako int" << liczbarund << endl;

	// Send an initial buffer
	char *sendbuf = "this is a test";
	cout << "iResult" << iResult << endl;

	//send tru lub false
	char *sendbuf = "true";
	send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	

	//cout << "sizeof" << rozmiar << endl;
	//cout << "po odebraniu liczby" << endl;

	//cout << "po odebraniu liczby losawan" << liczba_rund;
	
	// Receive data until the server closes the connection
	/*do {
		iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0){
			printf("Bytes received: %d\n", iResult);
			cout << recvbuf << endl;
		}
		else if (iResult == 0)
			printf("Connection closed\n");
		else
			printf("recv failed: %d\n", WSAGetLastError());
	} while (iResult > 0);
	
	// shutdown the send half of the connection since no more data will be sent
	iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}*/

>>>>>>> origin/robson
	// cleanup
	closesocket(ConnectSocket);
	WSACleanup();

	cout << "Koniec gry.";
	getchar();
    return 0;
}