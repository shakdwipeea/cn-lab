#include<stdio.h>
#include<unistd.h>
#include<string.h>

int crc(char *input,char *output,char *gp,int mode)
{
    int j,k;
    strcpy(output,input);
    if(mode)
    {
        for(j=1; j<strlen(gp); j++)
            strcat(output,"0");
    }
    for(j=0; j<strlen(input); j++) {
        if(*(output+j) == '1') {
            for(k=0; k<strlen(gp); k++)
            {
                if (((*(output+j+k) =='0') && (gp[k] == '0') || (*(output+j+k) == '1') && (gp[k] == '1')))
                    *(output+j+k)='0';
                else
                    *(output+j+k)='1';
            }
        }
    }
    for(j=0; j<strlen(output); j++)
        if(output[j] == '1')
            return 1;
    return 0;
}

int main()
{
    char input[50],output[50];
    char recv[50], gp[50];
    system("clear");
    printf("\n Enter the input message in binary\n");
    scanf("%s",input);
    printf("\n Enter the generator polynomial\n");
    scanf("%s",gp);
    crc(input,output,gp,1);
  
    printf("\n The transmitted message is %s %s\n",input,
            output+strlen (input));
    printf("\n\n Enter the received message in binary \n");
    scanf("%s",recv);
    if(!crc(recv,output,gp,0))
        printf("\n No error in data\n");
    else
        printf("\n Error in data transmission has occurred\n");
}
