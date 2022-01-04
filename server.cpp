#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>



using namespace std;

int main()
{


    int socketConn = socket(AF_INET, SOCK_STREAM, 0);
    int newSocketConn, valRead;
    sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    char *msg = "Hello server oi";

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(5000);

    if(!socketConn){
        cout << "socket failed";
    }

    if(bind(socketConn, (struct sockaddr*)&address, sizeof(address)) == -1) {
        cout << "bind failed";
    }

    if(listen(socketConn, 1) == -1){
        cout << "listen failed";
    }

    newSocketConn = accept(socketConn, (struct sockaddr*)&address, (socklen_t*)&addrlen);

    if(newSocketConn == -1){
        cout << "accpet failed";
    }

    valRead = read(newSocketConn, buffer, 1024);
    cout << buffer << endl;
    send(newSocketConn, msg, 15, 0);
    cout << "Hello message sent" << endl;


    return 0;
}
