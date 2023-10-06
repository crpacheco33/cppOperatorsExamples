/*
This is a simplified example of a C++ project that uses sockets to create a basic client-server chat 
application. In this example, we'll use a server and a client.
This is the server:
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrSize = sizeof(clientAddr);
    char buffer[1024];

    // Create a socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating socket." << std::endl;
        return 1;
    }

    // Bind the socket to an address and port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080); // Port number
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Bind to any available network interface

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error binding socket." << std::endl;
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Error listening on socket." << std::endl;
        return 1;
    }

    std::cout << "Server is listening on port 8080..." << std::endl;

    // Accept incoming connection
    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrSize);
    if (clientSocket == -1) {
        std::cerr << "Error accepting connection." << std::endl;
        return 1;
    }

    std::cout << "Connected to client." << std::endl;

    // Receive and send messages
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        if (recv(clientSocket, buffer, sizeof(buffer), 0) == -1) {
            std::cerr << "Error receiving message." << std::endl;
            break;
        }
        std::cout << "Client: " << buffer << std::endl;

        std::string message;
        std::cout << "Server: ";
        std::getline(std::cin, message);

        if (send(clientSocket, message.c_str(), message.size(), 0) == -1) {
            std::cerr << "Error sending message." << std::endl;
            break;
        }
    }

    // Close sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
