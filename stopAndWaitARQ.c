#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
int Send[20];
int receive[20];
int ack=1;
void sender(int i);
int receiver(int i);
int main()
{
 int size,i,k;
 printf("\t\tStop and Wait ARQ\n");
 printf("Enter size of packet: ");
 scanf("%d",&size);
 printf("Enter data: \n");
 for(i=0;i<size;i++)
 {
 	scanf("%d",&Send[i]);
 }
 printf("Sending data...........\n");
 for(i=0;i<size;i++)
 {
 	sender(i);
 	k=receiver(i);
 	if(k>10)
 		i--;
 }
 printf("\n----------------------------------------\nReceived data is\n");
 for(i=0;i<size;i++)
 	printf("%d, ",receive[i]);
}
void sender(int i)
{
 if(ack==1)
 {
 printf("-----------------------------------------------------\nCurrent Frame : %d\n",Send[i]);
 Sleep(1000);
 }
}
int receiver(int i)
{
 int j;
 receive[i]=Send[i];
 printf("Received Frame : %d\n",receive[i]);
 j=(rand()%(15-5+1))+5;
 if(j>10)
 {
 ack=0;
 printf("Acknowledge Not Received!\n");
 }
 else
 {
 ack=1;
 printf("Acknowledge Received!\n");
 }
 return j;
}
