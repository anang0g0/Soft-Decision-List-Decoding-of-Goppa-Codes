#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>

/*
(23,12,7)-Golay Code generator function is
	G(x)=x^11+x^9+x^7+x^6+x^5+x+1.
*/

typedef unsigned long int poly;
poly quo,quo_low,res,res_low;


unsigned int m(unsigned int y, unsigned int z);
void divide(poly a,poly a_low,poly b,poly b_low);
void rev(unsigned int n);


 #define MSB (~(~0UL>>1)) /* �ŏ�ʃr�b�g */
#define N cb(n)
#define M cb(m)


/* [24,12,12]-�g���S�[���C���� */
static char *gt[24]={
  "100000000000",
  "010000000000",
  "001000000000",
  "000100000000",
  "000010000000",
  "000001000000",
  "000000100000",
  "000000010000",
  "000000001000",
  "000000000100",
  "000000000010",
  "000000000001",
  "101000111011",
  "110100011101",
  "011010001111",
  "101101000111",
  "110110100011",
  "111011010001",
  "011101101001",
  "001110110101",
  "000111011011",
  "100011101101",
  "010001110111",
  "111111111110"};

char *ht[12]={
  "110111000101100000000000",
  "011011100011010000000000",
  "101101110001001000000000",
  "010110111001000100000000",
  "001011011101000010000000",
  "000101101111000001000000",
  "100010110111000000100000",
  "110001011011000000010000",
  "111000101101000000001000",
  "011100010111000000000100",
  "101110001011000000000010",
  "111111111110000000000001"};
char *ehc[12]={
  "101000111011100000000000",
  "110100011101010000000000",
  "011010001111001000000000",
  "101101000111000100000000",
  "110110100011000010000000",
  "111011010001000001000000",
  "011101101001000000100000",
  "001110110101000000010000",
  "000111011011000000001000",
  "100011101101000000000100",
  "010001110111000000000010",
  "111111111110000000000001"
};


main(){
  unsigned int x,i,j,b,bb,l,m,n;
  poly p,p_low;
  char t[12];
  
  static char *h743[7]={
    "0111100",
    "1011010",
    "1100110",
    "0001111",
    "0110011",
    "1010101",
    "1101001"
  },
     *H[3]={
       "0001111",
       "0110011",
       "1010101"
     };
  
  for(j=0;j<11;j++){
    for(i=0;i<24;i++){
      l=strtoul(gt[i],(char **)NULL,2); 
      printf("%d",bit(l,j));
    }
    printf("\n");
  }
  
  for(j=0;j<11;j++){
    for(i=0;i<24;i++){
      m=strtoul(ht[i],(char **)NULL,2); 
      printf("%d",bit(m,j));
    }
    printf("\n");
  }
  
}


unsigned int m(unsigned int y, unsigned int z)
{
  unsigned int c;
  
  c=0;
  while(y!=0){
    if(y&1) c ^=z;
    z<<=1; y>>=1;
  }
  return c;
  
}

/*
void write_poly(poly p,poly p_low)
{
	poly q;

	q=MSB;
	while (q>=p_low){
		printf((p & q) ? "1":"0");
		q>>=1;
	}

}
*/

void divide(poly a,poly a_low,poly b,poly b_low)
{
  
  quo=0; quo_low=MSB; res=a; res_low=a_low;
  if(res_low>b_low) return;
  for(; ;){
    if(res & MSB){
      quo|=quo_low; res^=b;
    }
    if(res_low==b_low) break;
    res_low<<=1; res<<=1; quo_low>>=1;
  }

}


void rev(unsigned int n)
{
  char s;
  unsigned short r=31,count=0;
  unsigned int k=0,o,p;
  
  while(n>0){
    o=(n<<31);
    p=31-r;
    k=k|(o>>p);
    count++;
    n=(n>>1);
    r--;
  }
  count=32-count;
  k=(k>>count);

/* printf("%b\n",k); */
  printf("%d\n",k);

}


int itob(int n,char s[])
{
  int i,j,k=0;

  for(i=15,j=0;i>=0;i--,j++){
    s[j]=((n>>i) & 0x0001) + '0';
  }

  for(j=0;j<15;j++){
    if(s[j]-48==1)
      k++;
  }
  return k%2;

}


int bit(int n,int k)
{
  int i,j;
  char s[12];

  for(i=11,j=0;i>=0;i--,j++){
    s[j]=((n>>i) & 0x001) + '0';
  }
  return s[k+1]-48;

}

short cb(unsigned int x)
{
  int i,j;

  i=0;
  while(x>0){
    x=(x>>1); i++;
  }
  return i;

}


/*
gr[23]={1,3,6,12,24,49,99,199,398,797,1594,3189,2282,
	468,936,1872,3744,3392,2688,1280,2560,1024,2048},
hr[11]={7973,15946,31892,63784,127568,255136,510272,1020544,
2041088,4082176,8164352}
*/

/* [24,12,12]-�g���S�[���C���� 
char *egc[12]={
"100000000000110111000101",
"010000000000011011100011",
"001000000000101101110001",
"000100000000010110111001",
"000010000000001011011101",
"000001000000000101101111",
"000000100000100010110111",
"000000010000110001011011",
"000000001000111000101101",
"000000000100011100010111",
"000000000010101110001011",
"000000000001111111111110"
},

*/


/* binary data 
b=0b1101;
bb=0b10110000;
printf("%u %u\n",b,bb);
x=m(b,bb);
printf("%u\n",x);

divide(b,MSB>>31,bb,MSB>>31);

printf("%u\n",quo);
printf("%u\n",res);
*/


/* 
 11*101011100011

x=m(3197,7973)%2;
y=(3197^7973)%2;
z=(3197&7973)%2;
printf("%b %b %b\n",x,y,z);


for(i=0;i<12;i++){x=0; y=0;
for(j=0;j<11;j++){
x=m(gr[i],hr[j])%2;
y=gr[i]^hr[j];
printf("%b %b %b %b\n",x,y,gr[i],hr[j]);
}
}

scanf("%d",&i);
	p=MSB; p_low=MSB>>i;
	while(p_low!=0){
		write_poly(p,p_low); printf("=");
		factorize(p,p_low); printf("\n");
		p +=p_low;
		if(p==0){
			p=MSB; p_low>>=1;
		}
	}
	return -1;
*/
