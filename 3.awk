BEGIN {
ctcp=0;
cudp=0;
rtcp=0;
rudp=0;
}
{
pkt=$5;
event=$1;

if(pkt=="cbr") 
{ 	cudp++;
	if(event=="r")
	{	rudp++;
	}
}
if(pkt=="tcp") 
	{ ctcp++;
	if(event=="r")
		{rtcp++;
		}
	}
}
END {
printf("No of packets sent\nTcp : %d\nUdp : %d\n",ctcp,cudp);
printf("No of packets received\nTcp : %d\nUdp : %d\n",rtcp,rudp);
}
