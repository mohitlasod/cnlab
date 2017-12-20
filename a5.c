#include<stdio.h>
#include<string.h>

char dw[32],cw[32],rem[32],div[32];
int ldw,ldiv,i,j,k;

void xor()
{
	for(k=0;k<ldiv;k++)
		if(rem[k]==div[k])
			rem[k]='0';
		else
			rem[k]='1';
}


void crc()
{
	for(i=0;i<ldiv;i++)
		rem[i]=dw[i];


	do
	{
		if(rem[0]=='1')
			xor();

		for(j=0;j<ldiv-1;j++)
			rem[j]=rem[j+1];

		rem[j]=dw[i++];

		//printf("\nRemainder: %s",rem);
		
	}while(i<=(ldiv+ldw-1));

	printf("\nFinal Remainder : %s\n",rem);
}

void main()
{
	do
	{
	printf("\nEnter the 17-bit Divisor: ");
	scanf("%s",div);
	ldiv=strlen(div);
	}while(ldiv!=17);

	printf("\nEnter the Dataword: ");
	scanf("%s",dw);
	ldw=strlen(dw);

	for(i=ldw;i<(ldiv+ldw-1);i++)
		dw[i]='0';

	dw[i]='\0';
	printf("\nPadded Dataword: %s\n",dw);


	crc();
	for(i=ldw,j=0;i<(ldw+ldiv-1);i++,j++)
		dw[i]=rem[j];

	printf("\nAugmented Codeword: %s\n",dw);

	printf("\nDo you want to introduce Error?(1:yes/0:no): ");
	scanf("%d",&i);

	if(i==1)
	{
		do
		{
			printf("\nEnter a valid position: ");
			scanf("%d",&j);
		}while(!(j>=1 && j<=(ldiv+ldw-1)));

		if(dw[j-1]=='0')
			dw[j-1]='1';
		else if(dw[j-1]=='1')
			dw[j-1]='0';


	}


	printf("\nReceived Codeword: %s\n",dw);

	crc();
	for(i=ldw,j=0;i<(ldw+ldiv-1);i++,j++)
		dw[i]=rem[j];

	for(i=ldw;i<(ldw+ldiv-1);i++)
		if(dw[i]=='1')
		{
			printf("\nError in Transmission!\n");
			return;
		}

	printf("\nNo Error in Transmission!\n");


}
	
