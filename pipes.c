#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char buffer[100];

void client(int read_fd, int write_fd) {
	printf("%s\n", "Enter filenam");
	fflush(stdout);

	fgets(buffer, sizeof(buffer), stdin);

	write(write_fd, buffer, sizeof(buffer));

	while(read(read_fd, buffer, sizeof(buffer)) > 0) {
		printf("%s\n", buffer);
	}
}

void server(int read_fd, int write_fd) {
	FILE *fp;
	char line[100];

	read(read_fd, buffer, sizeof(buffer));

	if (strchr(buffer, '\n')) {
		*strchr(buffer, '\n') = 0;
	}

	fp = fopen(buffer, "r");
	if (fp == NULL) {
		strcpy(buffer, "Can't open");
		write(write_fd, buffer, strlen(buffer));
		exit(1);
	} else {
		while(fgets(line, sizeof(line), fp) != NULL) {
			write(write_fd, line, sizeof(line));
		}

		printf("%s\n", "Server Done");
	}
}

void main() {
	int pipe1[2], pipe2[2];
	int child_pid;
	int status;

	pipe(pipe1);
	pipe(pipe2);

	child_pid = fork();
	if (child_pid > 0) {
		close(pipe1[0]);
		close(pipe2[1]);

		client(pipe2[0], pipe1[1]);
		wait(&status);
		exit(0);
	} else {
		close(pipe1[1]);
		close(pipe2[0]);

		server(pipe1[0], pipe2[1]);
		exit(0);
	}
}
