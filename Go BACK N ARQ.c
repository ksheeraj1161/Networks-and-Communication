#include<stdio.h>
void main()
{
int ws;
int transmit=0;
int acknowled;
printf("<-- Give window size input -->\n");
scanf("%d",&ws);
while(1){
for(int i=0;i<ws;i++)
{
printf("Frame %d has transfered\n",transmit);
transmit++;
if(transmit == ws)
{
break;
}
}
printf("\nGive the last Acknowledgement received 
input\n");
scanf("%d",&acknowled);
if(acknowled==ws)
{
 break;
}
else
transmit = acknowled;
}
}
