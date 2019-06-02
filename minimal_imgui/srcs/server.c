/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 13:49:16 by nihuynh           #+#    #+#             */
/*   Updated: 2019/06/02 20:08:22 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX 80
#define PORT 8080

void func(int clientfd)
{
    char    buff[MAX];
    size_t  n;

    while (42)
    {
        n = 0;
        while (n < MAX && (buff[n++] = getchar()) != '\n')
            ;
        write(clientfd, buff, n);
        if (strncmp("exit", buff, 4) == 0)
        {
            printf("Server Exit...\n");
            break;
        }
        bzero(buff, MAX);
        read(clientfd, buff, sizeof(buff));
        printf("New packet: %s", buff);
    }
}

int init_server(void)
{
    int serverfd;
    struct sockaddr_in servaddr;

    bzero(&servaddr, sizeof(servaddr));
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    if ((bind(serverfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("socket bind failed...\n");
        exit(0);
    }
    printf("Socket ready...\n");
    return (serverfd);
}

int new_connect(int serverfd)
{
	int                 clientfd;
	socklen_t           len;
	struct sockaddr_in  cli;

    if ((listen(serverfd, 5)) != 0)
	{
        printf("Listen failed...\n");
        exit(0);
    }
    printf("Server listening..\n");
    len = sizeof(cli);
    clientfd = accept(serverfd, (struct sockaddr*)&cli, &len);
    if (clientfd < 0) {
        printf("server acccept failed...\n");
        exit(0);
    }
    printf("server acccept the client...\n");
    return (clientfd);
}

int main(void)
{
    int serverfd;
	int clientfd;

    serverfd = init_server();
    clientfd = new_connect(serverfd);
    func(clientfd);
    close(clientfd);
    close(serverfd);
}
