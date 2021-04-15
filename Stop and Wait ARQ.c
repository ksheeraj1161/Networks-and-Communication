/*SENDER SIDE ( function)
1. Enter the No of frames to be sent : N
Let N =15
2. Frame Numbering
0 1 0 1 0 1 0 1 0 1 0 1 0 1 0
3 Menu 
1. Frame t o be send( sent the next frame) - Sleep (2000)
2.Frame Resent ( send the previous frame )- Timer expired , 
ACK lost ,Frame lost
Receiver side ( function)
1. Menu (i) Receive the frame successfully (ii) Frame lost 
GO BACK N ARQ
SENDER SIDE
1. Enter the No of frames to be sent : n (15) and
2. N – Modulo arithmetic(4)
3. Calculate the sender Window Size and Receiver window size
4. Frame Numbering (0 1 2 3 0 1 2 3 0 1 2 3 0 1 2)
5. Sender Window( Sf, Sn and S size)
6. Menu 1 . Frames to be sent ( max window size )
2. Ack Received 
3. Timer out
)*/

#include <stdio.h>
int B[30];
int receiveFrame(int p){
if((p-1)%2==B[p-1]){
printf(" Received Frame & ID = %d\nAcknowledgement for 
the frame number %d \n", B[p-1],p);
return 1;
}
else{
printf("Frame lost\n");
return 0;
}
}
void sendFrame(int m){
for(int i=0; i<m; i++){
if(i%2==0)
B[i] = 0;
else
  B[i] = 1;
}
for(int i=1; i<=m; i++){
printf("Sending Frame Number%d & ID = %d\n",i,B[i1]);
sleep(1);
if(receiveFrame(i))
printf("Acknowledgement Received for the frame %d & 
ID = %d\n\n",i,B[i-1]);
else
printf("Time Out, Frame Lost. Frame ID = %d\nSending 
Frame %d again\n",B[i-1],i);
}
}
void main()
{
int num;
printf(" Number of frames ");
scanf("%d",&num);
sendFrame(num);
}

