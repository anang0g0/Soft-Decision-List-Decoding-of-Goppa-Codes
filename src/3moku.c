#include "3moku.h"


char my_stone;
char peer_stone;
char *plane[5]={"+123+","a...|","b...|","c...|","+---+"};
int soc;

void shiw_plane()
{
	int i;
	for(i=0;i<5;i++)
	puts(plane[i]);
}

int get_peer_stone()
{
	char data[10];
	int x,y;

	read(soc,data,2);
	if(data[0]=='q') return -1;
	y=(int)data[0]-(int)'a'+1;
	x=(int)data[1]-(int)'0';
	plane[y][x]=peer_stone;
	return 1;
}

int put_my_stone()
{
	int x,y;
	char data[10];

	while(1)
	{
		gets(data);
		if(data[0]=='q')
		{
			write(soc,data,2);
			return -1;
		}

		if(data[0]<'a' || data[0]>'c'|| data[1]<'1' || data[1]> '3') continue;
		break;
	}

	y=(int)data[0]-(int)'a'+1;
	x=(int)data[1]-(int)'0';
	plane[y][x]=my_stone;
	write(soc,data,2);
}


