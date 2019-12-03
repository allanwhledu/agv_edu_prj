#include <stdio.h>   
#include <sys/types.h>   
#include <sys/socket.h>   
#include <netinet/in.h>   
#include <unistd.h>   
#include <errno.h>   
#include <string.h>   
#include <stdlib.h>
#include <iostream>
#include <arpa/inet.h>
  
#define SERV_PORT   7838
  
int main()  
{  
  int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sock_fd < 0)  
  {  
    perror("socket");  
    exit(1);  
  }  
  
  struct sockaddr_in addr_serv;  
  int len;  
  memset(&addr_serv, 0, sizeof(struct sockaddr_in));
  addr_serv.sin_family = AF_INET;
  addr_serv.sin_port = htons(SERV_PORT);
  addr_serv.sin_addr.s_addr = htonl(INADDR_ANY);  
  len = sizeof(addr_serv);  
    
  if(bind(sock_fd, (struct sockaddr *)&addr_serv, sizeof(addr_serv)) < 0)  
  {  
    perror("bind error:");  
    exit(1);  
  }  
  
    
  int recv_num;  
  int send_num;  
  char send_buf[1024]; //= "i am server!";
  char recv_buf[1024];
  struct sockaddr_in addr_client;  


  short vx = 1000;
  short vy = 0;
  short va = 0;
  void* tempP1 = &vx;
  void* tempP2 = &vy;
  void* tempP3 = &va;

  char* velxChar = (char*)&vx;
  char* velyChar = (char*)&vy;
  char* velaChar = (char*)&va;

  send_buf[0] = (char)0x53;
  send_buf[1] = (char)0x4A;
  send_buf[2] = (char)0x54;
  send_buf[3] = (char)0x55;

  send_buf[4] = velxChar[1];
  send_buf[5] = velxChar[0];
  send_buf[6] = velyChar[1];
  send_buf[7] = velyChar[0];
  send_buf[8] = velaChar[1];
  send_buf[9] = velaChar[0];
  send_buf[10] = (char)0x01;

  while(1)  
  {  
    printf("server wait:\n");  
    recv_num = recvfrom(sock_fd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&addr_client, (socklen_t *)&len);  
    if(addr_client.sin_addr.s_addr == inet_addr("192.168.1.14"))
    {
        std::cout<<"i am alienware"<<std::endl;
        exit(1);
    }
//    if(addr_client.sin_addr.s_addr == inet_addr("192.168.1.200"))
//    {
//        std::cout<<"i am agv"<<std::endl;
//        exit(1);
//    }

    if(recv_num < 0)  
    {  
      perror("recvfrom error:");  
      exit(1);  
    }  
  
    recv_buf[recv_num] = '\0';  
    printf("server receive %d bytes: %s\n", recv_num, recv_buf);  
  

    send_num = sendto(sock_fd, send_buf, 11, 0, (struct sockaddr *)&addr_client, len);
      
    if(send_num < 0)  
    {  
      perror("sendto error:");  
      exit(1);  
    }  
  }  
    
  close(sock_fd);  
    
  return 0;  
}
