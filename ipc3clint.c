#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define BUF_LEN 256
int main()
{
	int srvfd;
	int clifd;
	char txmsg[BUF_LEN];
	char rxmsg[BUF_LEN];
        int cnt;
   srvfd=open("srvfifo",O_WRONLY);
    if(!srvfd)
    {
	 printf("error in opening server fifo\n");
          return (1);
    }
printf("Connected to server \n");
printf("Enter some message to send to server\n");
fgets(txmsg,BUF_LEN,stdin);
write(srvfd,txmsg,strlen(txmsg)+1);
printf("Sent given message to server \n");
clifd=open("clififo",0600);
	if(clifd<0)
	{
		if(mkfifo("clififo",0600))
		{
			printf("Error in creating client FIFO\n");
			return(1);
		}
		else
		{
		  clifd=open("clififo",O_RDONLY);
	          printf("Create client FIFO\n");
	        }
	}
  printf("waiting for response message from server\n");
   cnt=read(clifd,rxmsg,BUF_LEN);
   puts(rxmsg);
   close(srvfd);
   close(clifd);
}   

