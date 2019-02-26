#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int Send[10],receive[10];
void sender(int i);
void receiver(int i);
int main()
{
 int n,i,k;
 printf("\t\tSimple Stop Wait\n");
 printf("Enter size: ");
 scanf("%d",&n);
 printf("Enter data: \n");
 for(i=0;i<n;i++)
 {
 	scanf("%d",&Send[i]);
 }
 printf("Sending data......\n");
 for(i=0;i<n;i++)
 {
 	sender(i);
 	receiver(i);
 }
 printf("Data sent\n");
 printf("Received data\n");
 for(i=0;i<n;i++)
 {
 	printf("%d, ",receive[i]);
 }
 k=1;
 for(i=0;i<n;i++)
 {
 	if(receive[i]!=Send[i])
 {
 	k=0;
 	break;
 }
 }
 if(k==0)
 printf("\nError in transmission!");
 else
 printf("\nTransmission complete!");
}
void sender(int i)
{
 printf("Sent frame %d\n",i);
}
void receiver(int i)
{
 int r;
 printf("Receiving frame %d\n",i);
 r=(rand()%(10-0+1))+0;
 if(r<9)
 {
 	Sleep(1000);
 	receive[i]=Send[i];
 }
 else
 	Sleep(1000);
}
