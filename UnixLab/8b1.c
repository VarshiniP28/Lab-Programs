// C program to implement one side of FIFO 
// This side writes first, then reads 
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
	int fd; 

	char * myfifo = "/tmp/myfifo"; 


	mkfifo(myfifo, 0666); 
        printf("FIFO file created.\n");
        printf("Waiting for P2 to connect.\n");
	char arr1[80], arr2[80]; 
	while (1) 
	{ 
		
		fd = open(myfifo, O_WRONLY); 

		printf(">>");
		fflush(stdout);
		fgets(arr2, 80, stdin); 


		write(fd, arr2, strlen(arr2)+1); 
		close(fd); 

		printf("waiting for other process to write\n");
		fd = open(myfifo, O_RDONLY); 

		
		read(fd, arr1, sizeof(arr1)); 

		printf("User2: %s\n", arr1); 
		close(fd); 
	} 
	return 0; 
} 

