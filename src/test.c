#include <stdio.h>
#include "common.c"


 unsigned int /* s[256],*/ c[128]; 
int count2,count;

main(){
int i,j,k;
unsigned int n,l;
char t[32];


printf("[15,7,5]-bch15 gen\n");
for(i=0;i<15;i++)
printf("%u ",bch15[i]);
printf("\n");
printf("256\n");
printf("bch15's H\n");
for(i=0;i<8;i++)
printf("%u ",Ht[i]);
printf("\n");


printf("[16,8,5]-Goppa Code\n");
for(i=0;i<16;i++)
printf("%u ",Gt[i]);
printf("\n");
printf("256\n");
printf("Goppa's H\n");
for(i=0;i<8;i++)
printf("%u ",h2[i]);
printf("\n");


printf("[24,12,8]-Golay Code\n");
for(i=0;i<24;i++)
printf("%u ",golay[i]);
printf("\n");
printf("4096\n");
printf("Golay's H\n");
for(i=0;i<12;i++)
printf("%u ",ehc[i]);
printf("\n");


printf("[31,16,7]-bch31 gen\n");
for(i=0;i<31;i++)
printf("%u ",bch31[i]);
printf("\n");
printf("32768\n");
printf("bch31's H\n");
for(i=0;i<15;i++)
printf("%u ",h31[i]);
printf("\n");


/*
printf("[47,16,17]-Goppa\n");
printf("2147483648\n");
*/


/*
printf("[63,16,23]-bch63 gen\n");
for(i=0;i<63;i++)
printf("%u ",gt63[i]);
printf("\n");
*/


for(i=0;i<128;i++){
l=0;
for(j=0;j<15;j++)
l=(l<<1)+(itob(i&bch15[j],t,7)%2);
c[i]=l;
}

count=0;count2=0;
nanka();

}



/* 乱数によるエラーテーブル 
#define M 128
void nanka()
{
int n,l,b,i,j;
char t[16];


scanf("%d",&n);
srand(n);
for(i=0;i<M;i++)
s[i]=0;

for(;;){
b=rand(n);
l=0;
for(i=0;i<8;i++)
	l=(l<<1)+(itob(Ht[i]&b,t,15)%2);

if(l<M){
	if(s[l]==0){
		if(itob(b,t,15)==5){
			if(b>0){
			s[l]=b;
			 printf("%u %d\n",count,itob(b,t,15)); 
			count++;
			}
			if(count==M){
for(i=0;i<128;i++)
printf("%3d %16b %16b\n",i,c[i],s[i]);
				for(i=0;i<M;i++){
					for(j=0;j<M;j++)
					printf("%d ",itob(s[i]^s[j],t,15));
					printf("\n");
				} exit(1);}
			}
		}
	}
count2++;
}

}
*/

