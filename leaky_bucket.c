#include<stdio.h>
#include<stdlib.h>
int  main()
{
int drop=0,count=0,minimum,packetsec,capcity;
int packet[25],process,i;                         // clearing screen
printf("enter bucket size : ");  //bucket size
    scanf("%d",&capcity);
printf("\nenter operation rate : "); //opration rate,time to reach destination from temporary node
    scanf("%d",&process);
	while(process>capcity){
	printf("\nOperation rate cannot be more than bucket size. Reenter operation rate :");	
	scanf("%d",&process);
	}
printf("\nenter no of sec to simulate : ");// to see what happens to the bucket
    scanf("%d",&packetsec);
printf("\nSecond Packet Size\n");
for(i=0;i<packetsec;i++)
{
    printf("%d\t ",i+1);
        scanf("%d",&packet[i]);
}
printf("second/packet received/packet sent/packet left/packet dropped\n");
        for(i=0;i<packetsec;i++)
        {
            count+=packet[i];
            if(count>capcity)
            {
                drop=count-capcity;
                count=capcity;
            }
            printf("%d",i+1); //sec
            printf("\t %d",packet[i]); //pkt recvd
            minimum=count<process?count:process;//minimum of count and process
			printf("\t\t%d",minimum); //pkt sent
            count=count-minimum;
            printf("\t\t%d",count); //pkt left
            printf("\t\t%d",drop); //drop
            drop=0;
            printf("\n");
        }
  return EXIT_SUCCESS; //return 0;
}



