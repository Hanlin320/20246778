
#include <iostream>
#include<winsock.h>
#pragma comment(lib,"ws2_32.lib")
 
int main()
{
    std::cout << "Hello World!\n";
	WSADATA wsdata;
	std::cout << "start up now ...." << std::endl;
	if (WSAStartup(MAKEWORD(2, 2), &wsdata))
	{
		std::cout << "init socket failed!" << std::endl;
		WSACleanup();
		return FALSE;
	}
	std::cout << "before create socket ...." << std::endl;
	SOCKET s_server, s_accept;
	s_server = socket(PF_INET, SOCK_STREAM, 0);
	if (s_server == INVALID_SOCKET)
	{
		std::cout << "create socket fail" << std::endl;
		WSACleanup();
		return FALSE;
	}
	std::cout << "create socket success...." << std::endl;
	SOCKADDR_IN server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8226);
	server_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
 
	std::cout << "before bind socket ...." << std::endl;
	if (bind(s_server, (SOCKADDR*)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		std::cout << "Binding Socket fail.......!" << std::endl;
		WSACleanup();
		return FALSE;
	}
	std::cout << "bind socket success...." << std::endl;
	std::cout << "before listen socket ...." << std::endl;
	if (listen(s_server, 1) == SOCKET_ERROR)
	{
		std::cout << "Listening Socket fail........!" << std::endl;
		WSACleanup();
		return FALSE;
	}
	std::cout << "listen socket success...." << std::endl;
	sockaddr_in accept_addr; 
	int len = sizeof(SOCKADDR);
	char recv_buf[8192] = { 0 };
	char send_buf[1024] = { 0 };
	while (true)
	{
		std::cout << "wait accept...." << std::endl;
		s_accept = accept(s_server, (SOCKADDR*)&accept_addr, &len);
		if (s_accept == SOCKET_ERROR) {
			std::cout << "Error: accept failed !" << std::endl;
			WSACleanup();
			break;
		}
		std::cout << "建立连接成功...." << std::endl;
		while (true)
		{
			std::cout << "等待客户端数据中...." << std::endl;
			int recv_len = recv(s_accept, recv_buf, sizeof(recv_buf), 0);
			if (recv_len < 0) {
				std::cout << "Error: receive info from server failed !" << std::endl;
				return -1;
			}
			std::cout << "已收到数据，客户端的数据是：" << recv_buf << std::endl;
			std::cout << "给客户端返回数据中..."  << std::endl;
			snprintf(send_buf, sizeof(send_buf), "%s", "我给你返回信息了");
			int sendLen = send(s_accept, (char*)send_buf, sizeof(send_buf), 0);
			if (sendLen < 0) {
				std::cout << "Error: send info to server failed !" << std::endl;
				return -1;
			}
			std::cout << "给客户端返回数据完毕" << std::endl;
		}
		
	}
}
 