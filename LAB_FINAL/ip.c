#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define ECHOMAX 255
void DieWithError(char *errorMessage);  /* External error handling function */
void Escribe(char buffer1[ECHOMAX+1]);
int main(int argc, char *argv[])
{
    int sock;                        /* Socket descriptor */
    struct sockaddr_in echoServAddr; /* Echo server address */
    struct sockaddr_in fromAddr;     /* Source address of echo */
    unsigned short echoServPort;     /* Echo server port */
    unsigned int fromSize;           /* In-out of address size for recvfrom() */
    char *servIP;                    /* IP address of server */
    char *echoString;                /* String to send to echo server */
    char echoBuffer[ECHOMAX+1];      /* Buffer for receiving echoed string */
    int echoStringLen;               /* Length of string to echo */
    int respStringLen;               /* Length of received response */
    if ((argc < 3) || (argc > 4))    /* Test for correct number of arguments */
    {
        fprintf(stderr,"Usage: %s <Server IP> <Echo Word> [<Echo Port>]\n", argv[0]);
        exit(1);
    }
    servIP = argv[1];           /* First arg: server IP address (dotted quad) */
    echoString = argv[2];       /* Second arg: string to echo */
    if ((echoStringLen = strlen(echoString)) > ECHOMAX)  /* Check input length */
        DieWithError("Echo word too long");
    if (argc == 4)
        echoServPort = atoi(argv[3]);  /* Use given port, if any */
    else
        echoServPort = 7;  /* 7 is the well-known port for the echo service */
    /* Create a datagram/UDP socket */
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        DieWithError("socket() failed");
    /* Construct the server address structure */
    memset(&echoServAddr, 0, sizeof(echoServAddr));    /* Zero out structure */
    echoServAddr.sin_family = AF_INET;                 /* Internet addr family */
    echoServAddr.sin_addr.s_addr = inet_addr(servIP);  /* Server IP address */
    echoServAddr.sin_port   = htons(echoServPort);     /* Server port */
    /* Send the string to the server */
    if (sendto(sock, echoString, echoStringLen, 0, (struct sockaddr *)
               &echoServAddr, sizeof(echoServAddr)) != echoStringLen)
        DieWithError("sendto() sent a different number of bytes than expected");

    /* Recv a response */
    fromSize = sizeof(fromAddr);
    if ((respStringLen = recvfrom(sock, echoBuffer, ECHOMAX, 0,
         (struct sockaddr *) &fromAddr, &fromSize)) == echoStringLen)
        DieWithError("recvfrom() failed");
    if (echoServAddr.sin_addr.s_addr != fromAddr.sin_addr.s_addr)
    {
        fprintf(stderr,"Error: received a packet from unknown source.\n");
        exit(1);
    }
    /* null-terminate the received data */
    echoBuffer[respStringLen] = '\0';

    printf("Received: %s\n", echoBuffer);    /* Print the echoed arg */
    Escribe(echoBuffer);
    close(sock);
    exit(0);
}

void DieWithError (char *errorMessage)
{
	perror(errorMessage);
	exit(1);
}
void Escribe(char buff[ECHOMAX+1]){
  char buffer1[ECHOMAX+1];
  int i=0,j=0,a=0;
  int puntos=0,coma=0;
  for(i=0;i<ECHOMAX+1;i++){
    if(buff[i]==':'){puntos=i+1; }
    if(buff[i]==',' || buff[i]=='}' ){
      coma=i;
      for(j=puntos;j<=coma;j++){
        buffer1[a]=buff[j];
        a++;
      }

     }

  }
  long file_size=strlen(buffer1);
  FILE *file_descriptor1;
  size_t result = 0;
  file_descriptor1 = fopen ("/home/alse/Documents/LAB_FINAL/referencias.txt","w");
  result = fwrite(buffer1, 1 , file_size, file_descriptor1);//escribe buffer1 en el archivo
  fclose(file_descriptor1);
}
