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
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        cerr << "创建套接字失败！" << endl;
        exit(1);
    }

    // 连接服务器
    struct sockaddr_in serverAddr;
    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
    if (connect(clientSocket, (struct sockaddr *)&serverAddr,
                sizeof(serverAddr)) == -1) {
        cerr << "连接服务器失败！" << endl;
        exit(1);
    }

    // 接收用户输入
    string message;
    cout << "请输入要发送的信息：" << endl;
    getline(cin, message);

    // 向服务器发送数据
    if (send(clientSocket, message.c_str(), message.length(), 0) == -1) {
        cerr << "发送数据失败！" << endl;
        exit(1);
    }

    // 接收服务器回声
    char buffer[BUFFER_SIZE];
    int received = recv(clientSocket, buffer, BUFFER_SIZE, 0);
    if (received == -1) {
        cerr << "接收数据失败！" << endl;
        exit(1);
    }

    cout << "收到服务器回声：" << buffer << endl;

    // 关闭套接字
    close(clientSocket);

    return 0;
}
