#include <iostream>
#include "sys/socket.h"
#include "Ping.h"

using namespace std;

int main()
{

    int socketConn = socket(AF_INET, SOCK_STREAM, 0);

    return 0;
}
