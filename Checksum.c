//Sender side and Receiver side as 2 functions

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct array
{
int arr[50];
};
struct array convert(char a[])
 {
int n=strlen(a),i,j=0;
struct array y;
printf("\n message converted to hexdecimal: \n");
for(i=0;i<strlen(a);i++)
{
char hex[20];
int k;
if(i+1<=strlen(a)){
sprintf(hex , "%02X%02X", a[i] & 0xff,a[i+1] &0xff);
  y.arr[j]= (int)strtol(hex, NULL,16);
}
else
{
sprintf(hex , "%04X", a[i] & 0xff);
y.arr[j]= (int)strtol(hex, NULL,16);
}
printf("%s \n",hex);
i++;j++;
}
return y;
}
int checksum(int arr[],int n)
{
int sum=0;
for(int i=0;i<n;i++)
{
sum=sum+arr[i];
if(sum>0XFFFF)
{
sum = sum/0X10000+sum%0X10000;
}
}
sum=0XFFFF-sum;
return sum;
}
int sender(char s[])
{
struct array x=convert(s);
int n = strlen(s);
n=(n+1)/2+1;
int cksum= 0;
x.arr[n-1]=cksum;
cksum=checksum(x.arr,n);
x.arr[n-1]=cksum;
printf("\n wrapped sum\n");
for (int i=0;i<n;i++)
{
printf("%X \n",x.arr[i]);
}
return cksum;
  }
int receiver(char s[],int cksm)
{
struct array x=convert(s);
int n = strlen(s);
n=(n+1)/2+1;
int cksum= 0;
x.arr[n-1]=cksm;
cksum=checksum(x.arr,n);
printf("\n with checksum\n");
 for (int i=0;i<n;i++)
{
printf("%X \n",x.arr[i]);
}
if(cksum==0)
{
printf("message sucessfully recived at the recever 
side");
}
else
{
printf(" message is corrupted");
 }
}
int main()
{
char msg[50],recmsg[50];
int checksumr;
printf("\n ------SENDER SIDE------");
printf("\n enter message : ");
scanf("%s",msg);
checksumr=sender(msg);
printf("\n -------RECEIVER SIDE-------");
printf("\n received message : ");
scanf("%s",recmsg);
receiver(recmsg,checksumr);
return 0;
}
