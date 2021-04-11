// hamming code - calculate only the no of redundant bits 2^r>= k+r+1
//input = k, k= no of bits in the data word.
//calculate the no of bits in the code word

#include <stdio.h>
#include <math.h>
void main()
{
int n,i=0,p_n = 0,c_l ;
printf("Enter no of bits in Data Word: ");
scanf("%d",&n);
while(n > (pow(2,i) - (i+1)) )
{
 p_n++;
 i++;
}
c_l = p_n + n;
printf("No of redundant bits: %d\n",p_n);
printf("No of bits in the code word: %d\n",c_l);
}
