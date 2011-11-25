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
	int liczbarund = 10;
	cout << "test";
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
	
	char recvbuf[DEFAULT_BUFLEN];
	//int iResult;
	int iSendResult;
	int recvbuflen = DEFAULT_BUFLEN;
	//wyslanie inforamcji o liczbie rund
	cout << "przed wyslaniem liczby rund";
	int iliczba_rund;
	    // Send an initial buffer
	char *rundki = "dziesiec";
	send( ClientSocket[0], rundki, (int)strlen(rundki), 0 );
	send( ClientSocket[1], rundki, (int)strlen(rundki), 0 );
	cout << ClientSocket[0] << endl;
	cout << ClientSocket[1] << endl;

	// Receive until the peer shuts down the connection
	/*do {
		iResult = recv(ClientSocket[id_socket], recvbuf, recvbuflen, 0);
		if (iResult > 0) {
			printf("Bytes received: %d\n", iResult);
			for(int i=0; i<iResult; i++){
				cout << recvbuf[i];
			}
			cout << endl;
			// Echo the buffer back to the sender
			iSendResult = send(ClientSocket[id_socket], recvbuf, iResult, 0);
			if (iSendResult == SOCKET_ERROR) {
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(ClientSocket[id_socket]);
				WSACleanup();
				return 1;
			}
			printf("Bytes sent: %d\n", iSendResult);
		} else if (iResult == 0)
			printf("Connection closing...\n");
		else {
			printf("recv failed: %d\n", WSAGetLastError());
			closesocket(ClientSocket[id_socket]);
			WSACleanup();
			return 1;
		}
	} while (iResult > 0);*/

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

	cout << "ubba";
	getchar();
	return 0;
}