/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 13:48:44 by nihuynh           #+#    #+#             */
/*   Updated: 2019/06/02 19:36:38 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX		80
#define PORT	8080
#define IP		"127.0.0.1"

void func(int listenfd)
{
	char    buff[MAX];
	size_t  n;

	while (42)
	{
		bzero(buff, sizeof(buff));
		read(listenfd, buff, sizeof(buff));
		printf("From Server : %s", buff);
		if ((strncmp(buff, "exit", 4)) == 0)
		{
			printf("Client Exit...\n");
			break;
		}
		bzero(buff, sizeof(buff));
		printf("Enter the string : ");
		n = 0;
		while ((buff[n++] = getchar()) != '\n')
			;
		write(listenfd, buff, sizeof(buff));
	}
}

int connect_to(const char *ip)
{
	int listenfd;
	struct sockaddr_in servaddr;

	bzero(&servaddr, sizeof(servaddr));
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd == -1)
	{
		printf("socket creation failed...\n");
		exit(0);
	}
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(ip);
	servaddr.sin_port = htons(PORT);
	if (connect(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0)
	{
		printf("connection with the server failed...\n");
		exit(0);
	}
	return (listenfd);
}

int main(void)
{
	int listenfd;

	listenfd = connect_to(IP);
	func(listenfd);
	close(listenfd);
}
