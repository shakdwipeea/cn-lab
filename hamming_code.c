#include<stdlib.h>
#include<stdio.h>
char data[5];
int encoded[8], edata[7], syndrome[3];
int hmatrix[3][7]= { 1,0,0,0,1,1,1,
0,1,0,1,0,1,1,
0,0,1,1,1,0,1};
char gmatrix[4][8]={ "0111000", "1010100", "1100010", "1110001"};
int main()
{
int i,j;
system("clear");
printf("Hamming Code --- Encoding\n");
printf("Enter 4 bit data : ");
scanf("%s",data);
printf("Generator Matrix\n");
for(i=0;i<4;i++)
printf("\t %s \n",gmatrix[i]);
printf("Encoded Data : ");
for(i=0;i<7;i++)
{
for(j=0;j<4;j++)
encoded[i]+=((data[j]- '0')*(gmatrix[j][i]- '0'));
encoded[i]=encoded[i]%2;
printf("%d",encoded[i]);
}
printf("\nHamming code --- Decoding\n");
printf("Enter Encoded bits as received : ");
for(i=0;i<7;i++)
scanf("%d",&edata[i]);
for(i=0;i<3;i++)
{
for(j=0;j<7;j++)
syndrome[i]=syndrome[i]+(edata[j]*hmatrix[i][j]);
syndrome[i]=syndrome[i]%2;
}
for(j=0;j<7;j++)
if ((syndrome[0]==hmatrix[0][j])&&(syndrome[1]==hmatrix[1][j])&&
(syndrome[2]==hmatrix[2][j]))
break;
if(j==7)
printf("Data is error free!!\n");
else {
printf("Error received at bit number %d of the data\n",j+1);
edata[j]=!edata[j];
printf("The Correct data Should be : ");
for(i=0;i<7;i++) printf(" %d ",edata[i]);
}
}

