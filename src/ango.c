#include <stdio.h>
#include <conio.h>

#define RAND_MAX 521
#define EXIT_FAILURE 0
#define EXIT_SUCCESS -1

unsigned int h[256];
static unsigned short Gp[8]={
0b1000000001110100,
0b0100000010110010,
0b0010000011101000,
0b0001000010001011,
0b0000100001010111,
0b0000010000011110,
0b0000001011001101,
0b0000000100101111
};


/* G=[16,8,5] as Subfield Subcode over GF(16) */
static unsigned int ht[8]={
	0b0111001010000000,
	0b1010101001000000,
	0b1110000100100000,
	0b1100110000010000,
	0b0011011100001000,
	0b1000111100000100,
	0b0101110100000010,
	0b0001101100000001
	},
	Gt[16]={
	0b10000000,
	0b01000000,
	0b00100000,
	0b00010000,
	0b00001000,
	0b00000100,
	0b00000010,
	0b00000001,
	0b01110010,
	0b10101010,
	0b11100001,
	0b11001100,
	0b00110111,
	0b10001111,
	0b01011101,
	0b00011011
	};



main(int argc,char *argv[]){

	int c,r,i;
	FILE *infile,*outfile;


for(i=0;i<256;i++)
h[i]=0;

	if(argc<3||argc>4||
		(infile = fopen(argv[1],"rb"))==NULL ||
		(outfile= fopen(argv[2],"wb"))==NULL) {
			printf("usage: crypt infile outfile [key]\n",stderr);
			return 0;
		}
		if(argc==4) srand(atoi(argv[3]));
		while((c=getw(infile)) !=EOF){
/*
		do{
			r=rand()/((RAND_MAX+1U)/256);
		}while(r>=256);
*/
	fputc(dc(c),outfile);
	}

for(i=0;i<256;i++)
printf("h[%d]= %u\n",i,h[i]);

return -1;

}


int an(int c)
{
int i,j,m=0;
char t[16];


hind(c);
for(i=0;i<16;i++)
m=(m<<1)+itob(c&Gt[i],t);
printf("%u %b\n",m,m);

return m;

}


unsigned char dc(unsigned short w)
{
int i,j;
unsigned char a;

/* printf("%b ",w); */
a=(w>>8); hind(a);
/* printf("%b\n",a); */

return a;

}


int itob(int n,char s[])
{
int i,j,k=0;

for(i=15,j=0;i>=0;i--,j++){
s[j]=((n>>i) & 0x0001) + '0';
}

for(j=0;j<16;j++){
if(s[j]-48==1)
k++;
}
return k%2;

}



void hind(unsigned short m)
{

h[m]++;

}



int seki()
{
unsigned int a,b,c;

c=0;
while(a!=0){
if (a & 1) c^=b;
b<<=1; a>>=1;
}
return c;
}

