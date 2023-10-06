/*
This is a simplified example of a C++ project that uses sockets to create a basic client-server chat 
application. In this example, we'll use a server and a client.
This is the client:
*/


#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[1024];

    // Create a socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error creating socket." << std::endl;
        return 1;
    }

    // Connect to the server
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080); // Port number
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server's IP address

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error connecting to server." << std::endl;
        return 1;
    }

    std::cout << "Connected to server." << std::endl;

    // Send and receive messages
    while (true) {
        std::string message;
        std::cout << "Client: ";
        std::getline(std::cin, message);

        if (send(clientSocket, message.c_str(), message.size(), 0) == -1) {
            std::cerr << "Error sending message." << std::endl;
            break;
        }

        memset(buffer, 0, sizeof(buffer));
        if (recv(clientSocket, buffer, sizeof(buffer), 0) == -1) {
            std::cerr << "Error receiving message." << std::endl;
            break;
        }

        std::cout << "Server: " << buffer << std::endl;
    }

    //
