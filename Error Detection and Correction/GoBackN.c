#include<stdio.h>
int send(int data[], int pos, int trans[], int w, int size)
{
//W=5
int i;
for (i=pos;i<pos+w;i++)
{
trans[i-pos]=data[i];
}
printf("\n");
printf("\nData being transmitted is: ");
for (i=0;i<w;i++)
{
if (trans[i]<size)
{
printf("%d,", trans[i]);
}
}
}
int receive(int trans[],int rec[],int pos, int w,int size)
{
int i, ackframe;
for(i=pos;i<pos+w;i++)
{
rec[i]=trans[i-pos];
}
printf("\n");
//display received
printf("\nReceived data is: ");
for (i=0;i<pos+w;i++)
{
if (rec[i]>size)
{
exit(1);
}
printf("%d,", rec[i]);
}
printf("\nWhich frame do you want acknowledged: ");
scanf("%d", &ackframe);
if (ackframe>pos+w-1 || ackframe<pos)
{
printf("\n\nFRAME EXCEEDS LIMIT. LAST FRAME SENT IS BEING ACKNOWLEDGED\n");
ackframe=pos+w-1;
}
printf("\nAcknowledgement Received for position: %d", ackframe);
return ackframe+1;
}
int main()
{
//filling data with first n whole numbers
printf("\t\tGo Back N\n");
int size, w;
printf("Enter data size: ");
scanf("%d",&size);
printf("\nEnter window size: ");
scanf("%d",&w);
int i,no=0,data[size],rec[size], pos=0;
for (i=0;i<size;i++)
{
data[i]=no;
no++;
}
//frames
int trans[w];
//displaying data
printf("\nData is: ");
for (i=0;i<size;i++)
{
printf("%d,", data[i]);
}
while (pos<size)
{
//sending
send(data, pos, trans, w, size);
//received
pos=receive(trans, rec, pos, w, size);
}
return 0;
}

