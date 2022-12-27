#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace std;

const int PORT = 8080;
const int BUFFER_SIZE = 1024;

int main() {
    // 创建套接字
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        cerr << "创建套接字失败！" << endl;
        exit(1);
    }

    // 绑定服务器地址
    struct sockaddr_in serverAddr;
    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(serverSocket, (struct sockaddr *)&serverAddr,
             sizeof(serverAddr)) == -1) {
        cerr << "绑定服务器地址失败！" << endl;
        exit(1);
    }

    // 开始监听
    if (listen(serverSocket, 5) == -1) {
        cerr << "开始监听失败！" << endl;
        exit(1);
    }

    // 接受客户端
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    while (true) {
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr,
                                  &clientAddrLen);
        if (clientSocket == -1) {
            cerr << "接受客户端失败！" << endl;
            continue;
        }

        char buffer[BUFFER_SIZE];
        int received = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (received == -1) {
            cerr << "接受数据失败！" << endl;
            continue;
        }

        cout << "接收到数据：" << buffer << endl;

        // 回声
        send(clientSocket, buffer, received, 0);
        close(clientSocket);
    }

    // 关闭套接字
    close(serverSocket);

    return 0;
}
