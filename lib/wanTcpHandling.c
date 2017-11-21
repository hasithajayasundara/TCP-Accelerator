//
// Created by root on 11/11/17.
//

#include "../headerFiles/writeInLogger.h"

/*wanHandling constants*/
#define SERVER_PORT 9006

int getSocket(char* ip)
{
    struct sockaddr_in address;
    struct sockaddr_in serv_addr;
    int sock = 0, valread;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET,ip , &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    return sock;
}

void sendTo_ACNode(char *data,int sock){
    send(sock , data , strlen(data) , 0 );
    printf("data sent\n");
}

void receiveFrom_ACNode(int sock,char* buffer){

    read( sock , buffer, 1024);
}
