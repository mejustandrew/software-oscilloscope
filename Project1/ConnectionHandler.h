#pragma once
#define WIN32_LEAN_AND_MEAN
// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "11000"

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <string>

class ConnectionHandler
{
public:
	ConnectionHandler();
	~ConnectionHandler();

	void Send(std::string input);
private:
	int iResult;
	SOCKET ConnectSocket;
};
