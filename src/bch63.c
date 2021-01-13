#include <stdio.h>

/* [63,16,23]-BCH */
static unsigned short gt63[63]={
1,3,6,12,25,51,102,205,411,822,
1644,3289,6578,13156,26313,52627,39718,13900,27800,55600,
45665,25794,51589,37643,9751,19503,39006,12477,24955,49911,
34286,3037,6074,12148,24297,48595,31655,63310,61085,56635,
47734,29932,59865,54194,42853,20170,40341,15147,30294,60588,
55640,45744,25952,51904,38272,11008,22016,44032,22528,45056,
24576,49152,32768};




main(){
  unsigned int x,y,z,w;
  char t[64];
  int i,j,count=0;
  FILE *fp,*fo;
  short s;
unsigned long long int H=strtoul("11",(char **)NULL,2)*strtoul("1011",(char **)NULL,2)*strtoul("1100001",(char **)NULL,2)*strtoul("1110011",(char **)NULL,2);


printf("%u\n",H);
   /* fo=fopen("d:63.key","wb"); */
   /*  fp=fopen("bch63.c","rb"); */

     for(i=0;i<63;i++){
/*  printf("%d\n",putw(gt63[i],fp)); */
    /* i2b(gt63[i],t); */
     }

i2b(H,t);


/* 1011001110111110011=368115 */


printf("%u\n",H);
   /* fo=fopen("d:63.key","wb"); */
   /*  fp=fopen("bch63.c","rb"); */

     for(i=0;i<63;i++){
/*  printf("%d\n",putw(gt63[i],fp)); */
    /* i2b(gt63[i],t); */
     }

i2b(H,t);
for(i=0;i<47;i++){
printf("%u\n",H);
H=H<<1;
}


/*     
  while((s=getw(fp))!=EOF)
    printf("%u\n",(unsigned)s);
 
  fclose(fp);
*/

  /*
     x=seki(seki(0103,0127),seki(0147,0111));
     i2b(x,t);printf("\n");
     printf("%b\n",x);
     y=seki(seki(015,0155),seki(seki(0133,0165),07));
     i2b(y,t);printf("\n");
     printf("%b\n",y);
     */

  /* sd(); */
  
}


unsigned seki(unsigned int a ,unsigned int b)
{
  unsigned int c;

  c=0;
  while(a!=0){
    if (a & 1) c^=b;
    b<<=1; a>>=1;
  }
  return c;
}


void i2b(unsigned long long int n,char s[64])
{
  int i,j;
  
  
  for(i=46,j=0;i>-1;i--,j++)
    s[j]=((n >> i) & 0x00001)+'0';

  for(j=0;j<47;j++)
    printf("%u",s[j]-48);
printf("\n");

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
  return k;

}


void sd()
{
  unsigned short n,es=0;
  int i,j;
  char t[16];
  
  
  scanf("%u",&n);
  printf("%u %d\n",n,itob(n,t));
  for(;;){
    for(i=0;i<16;i++)
      es=(es<<1)+itob(gt63[i]&n,t);
    for(i=16;i<63;i++)
      printf("%d",itob(gt63[i]&n,t));
    printf("\n");
    n=es;
  }
  
}


