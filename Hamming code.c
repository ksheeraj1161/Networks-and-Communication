//Input- No of bits in the data word
//Calculate the no of redundant bits
//then Start calculating the redundant bits
//Hamming code- ODD parity
//Output - Codeword
//Sender side Receiver side
//flip any one bit and calculate the syndrome bits
//do as 2 function as c as sender and receiver
//for any input u should manual calculation in word document
//data word should be input

#include <stdio.h>
#include <math.h>
int ham_code(int position,int n,int codeword[])
{
int count=0,i,j;
i=position-1;
while(i<n)
{
for(j=i;j<i+position;j++)
{
if(j<n)
count=count+codeword[j];
}
i=i+2*position;
}
if(count%2 == 0)
  return 0;
else
return 1;
}
int sender(int a)
{
int i,n,j,k;
int data[a];
printf("Enter input data word: \n");
for(i=0;i<a;i++)
{
scanf("%d",&data[i]);
}
int l=0,r=0;
while(a>(int)pow(2,l)-(l+1))
{
r++;l++;
}
printf("Number of Redundancy bits:%d\n",r );
n = r + a;
int codeword[n];
j=k=0;
for(i=0;i<n;i++)
{
if(i==((int)pow(2,k)-1))
{
codeword[i]=0;
k++;
}
else
{
codeword[i]=data[a-1-j];
j++;
}
}
printf("\n Redundancy bits:\n");
for(i=0;i<r;i++)
{
int position = (int)pow(2,i);
int value = ham_code(position,n,codeword);
printf("r%d:%d\n",position,value );
codeword[position-1]=value;
  }
printf("Hamming Encoded Word(codeword): ");
for(i=n-1;i>=0;i--)
printf("%d ",codeword[i]);
return r;
}
void receiver(int t,int r){
int i;
int n=t+r;
printf("Enter Received Hamming Encoded 
Word(codeword): \n");
int received[n];
for(i=0;i<n;i++)
scanf("%d",&received[n-i-1]);
int error_pos = 0;
printf("Syndrome bits:\n");
for(i=0;i<r;i++)
{
int position = (int)pow(2,i);
int value = ham_code(position,n,received);
printf("s%d :%d\n",position,value );
if(value == 1)
error_pos+=position;
}
if(error_pos == 0)
printf("Message is correct\n");
else
{
printf("Error detected at bit position: 
%d\n",error_pos);
printf("Corrected Word: \n");
for(i=0;i<n;i++)
{
if(n-i==error_pos)
printf("%d ",received[n-i-1]^1 );
else
printf("%d ",received[n-i-1] );
}
 }
printf("\n");
}
int main()
       {
int w,re;
printf("\n Enter length of data word: ");
scanf("%d",&w);
printf("\n-----SENDER SIDE-----\n");
re=sender(w);
printf("\n\n-----RECEIVER SIDE-----\n");
receiver(w,re);
return 0;
}
