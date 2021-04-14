//Sender side and Receiver side as 2 functions

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* xor(char *a, char *b){
int i, length=strlen(a);
char *result;
result = (char *)malloc(sizeof(char)*length);
for (i=0;i<length;i++){
if(a[i]==b[i])
{result[i]='0';}
else
{result[i]='1';}
}
return(result);
}
char* mod2div(char *dividend,char *divisor){
int dividend_length = strlen(dividend);
int divisor_length = strlen(divisor);
int i;
  char *tmp;
tmp = (char *)malloc((divisor_length1)*sizeof(char));
for(i=0;i<divisor_length;i++){
tmp[i] = dividend[i];
}
int index=divisor_length;
char* zero;
while (index < dividend_length)
{
if (tmp[0] == '1')
{
tmp = xor(divisor, tmp);
for(i=0;i<divisor_length-1;i++)
tmp[i]=tmp[i+1];
tmp[divisor_length-1]=dividend[index];
}
else
{
zero = (char *)malloc(sizeof(char)*(divisor_length));
for(i=0;i<divisor_length;i++)
{zero[i]='0';}
tmp = xor(zero, tmp);
for(i=0;i<divisor_length-1;i++)
tmp[i]=tmp[i+1];
tmp[divisor_length-1]=dividend[index];
}
index += 1;
}
if (tmp[0] == '1')
{
tmp = xor(divisor, tmp);
}
else
{
zero = (char 
*)malloc(sizeof(char)*(divisor_length));
for(i=0;i<divisor_length;i++)
{zero[i]='0';}
tmp = xor(zero, tmp);
}
char *crc;
  divisor_length--;
crc = (char *)malloc((divisor_length)*sizeof(char));
for(i=0;i<divisor_length;i++)
crc[i]=tmp[i+1];
crc[divisor_length]='\0';
printf("remainder: %s\n", crc);
return(crc);
}
char* append_data(char *message,char *append_with,int 
zeros){
int i;
int message_length = strlen(message);
int append_with_length = strlen(append_with);
char *result;
append_with_length--;
result = (char 
*)malloc((message_length+append_with_length)*sizeof(char))
;
for(i=0;i<strlen(message);i++)
result[i]=message[i];
if(zeros==1){
for(i=0;i<append_with_length;i++)
result[message_length+i]='0';
}
else{
append_with_length++;
for(i=0;i<append_with_length;i++)
result[message_length+i]=append_with[i];
}
result[message_length+append_with_length]='\0';
return(result);
}
void sender(char dataword[],char divisor[])
{
char *appended_data=append_data(dataword,divisor,1);
printf("Appended data: %s\n", appended_data);
char *crc = mod2div(appended_data,divisor);
char *codeword = append_data(dataword,crc,0);
printf("codeword: %s\n",codeword);
}
void receiver(char received_codeword[],char divisor[])
{
  char *received_crc = mod2div(received_codeword,divisor);
int i;
for(i=0;i<strlen(divisor)-1;i++){
if(received_crc[i]!='0'){
printf("Message is corrupted\n");
exit(0);
}
}
printf("Message is correct \n");
}
int main(){
int i;
int dataword_length,divisor_length;
printf("Enter dataword Length: ");
scanf("%d",&dataword_length);
char dataword[dataword_length];
printf("Enter dataword: ");
scanf("%s",dataword);
printf("Enter length of divisor: ");
scanf("%d",&divisor_length);
char divisor[divisor_length];
printf("Enter divisor(generator polynomial): ");
scanf("%s",divisor);
printf("\n-----SENDER SIDE-----\n");
sender(dataword,divisor);
printf("\n-----RECEIVER SIDE-----\n");
char received_codeword[dataword_length+divisor_length-1];
printf("Enter received dataword: ");
scanf("%s",received_codeword);
receiver(received_codeword,divisor);
return 0;
}
  
  
