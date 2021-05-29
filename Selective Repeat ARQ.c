#include<stdio.h>
void main()
{
int m,j=0,d,sliding_window,frame_number;
printf("\n<--Give sliding window size input-->\n");
scanf("%d",&sliding_window);
printf("\n Enter No.of frames to be sent: ");
scanf("%d",&frame_number);
int Frames_arr[frame_number];
printf("\n <--Frames to be sent--> \n");
for(m=0;m<frame_number;m++)
{
printf(" Frame value of %d : ",m+1);
scanf("%d",&Frames_arr[m]);
}
printf("\n 1.No frame loss here\n\n");
m=0;
while((j*sliding_window)<frame_number && m<frame_number)
{
d=(m-(j*sliding_window))/sliding_window;
if(d==0)
{
printf("\nSender: frame %d sent ",Frames_arr[m]);
m++;
}
else {
printf("\n\nwindow needs to be moved ");
j++;
}
}
m=0;
j=0;
while((j*sliding_window)<frame_number && m<frame_number)
{
d=(m-(j*sliding_window))/sliding_window;
if(d==0)
{
printf("\nreceiver: frame %d received 
",Frames_arr[m]);
m++;
}
else
j++;
}
m=0;
j=0;
printf("\n 2.second frame is getting lost\n\n");
while((j*sliding_window)<frame_number && m<frame_number)
{
d=(m-(j*sliding_window))/sliding_window;
if(d==0)
{
printf("\nsender : frame %d sent ",Frames_arr[m]);
if(m==1)
printf("\nsender : frame %d sent ",Frames_arr[m]);
m++;
}
else
{
printf("\n\n Window has to be moved ");
j++;
}
}
m=0,j=0;
while((j*sliding_window)<frame_number&&m<frame_number)
{
d=(m-(j*sliding_window))/sliding_window;
if(d==0)
{
if(m!=1)
printf("\nreceiver : frame %d received 
",Frames_arr[m]);
if(m==1){
printf("\nreceiver : frame %d not received 
",Frames_arr[m]);
}
m++;
}
else
{
if(m==3)
printf("\neceiver : frame %d 
received\n",Frames_arr[1]);
j++;
}
}
}