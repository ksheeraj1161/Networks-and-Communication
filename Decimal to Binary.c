//convert the decimal to binary , count the no of 1 's in the binary values, add the parity ( Even parity). restrict the binary equivalent to 7 bits. 
//parity bit should be eighth bit. parity bit should be in right most position, again convert into decimal.

#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
void main() 
{ 
long number, decimal_number, remainder, n, base = 1, base1 = 1, binary = 
0, no_of_1s = 0, parity_bit = 0, final_decimal = 0; 
printf("Enter a decimal integer \n"); 
scanf("%ld", &n1); decimal_number = number; 
while (number > 0) { 
remainder = number % 2; 
if (remainder == 1)
{ 
no_of_1s++; 
} 
binary = binary + remainder * base; 
n1 = n1 / 2; 
base = base * 10; } 
if(no_of_1s % 2==0) 
{ 
parity_bit = 0; 
} 
else { 
parity_bit = 1; 
} 
printf("Input number is = %ld\n", decimal_number); 
printf("Its binary equivalent is = %07ld\n", binary);
printf("No.of 1's in the binary n1ber is = %ld\n", no_of_1s);
 int concat(int x, int y) 
 { 
 char str1[20]; 
 char str2[20]; 
 sprintf(str1,"%d",x);
 sprintf(str2,"%d",y); 
 strcat(str1,str2);
 return atoi(str1); 
} 
 int final_binary = concat(binary,parity_bit); 
 printf("The final binary number is =%07d\n",final_binary); 
while( final_binary > 0) 
 { 
n = final_binary % 10; final_decimal = final_decimal + n * base1;
final_binary = final_binary/10; 
 base1 = base1 * 2; 
} 
 printf("The final decimal equivalent number =%ld\n",final_decimal); 
}
