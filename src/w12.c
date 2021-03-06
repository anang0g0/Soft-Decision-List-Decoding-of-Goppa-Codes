#include <stdio.h>
#include "code.h"


/* CodeBreaking Test Sample for BCH-Goppa */

#define len 1025
#define N 128 /* number of error pattarn condition 1 */
#define M 128 /* number of error pattern condition 2 */

int n,k,r[len];
unsigned int count,count2;
unsigned int se[256],to[256],h[256];


static unsigned int v[32]={ /* The set of unit vector. */
1,2,4,8,16,32,64,128,256,512,
1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,
1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,
268435456,536870912,1073741824,2147483648};

unsigned int model; /* =0b1001001001001001; */

/* 100100001000010000100001; */

/* unsigned int Ht=0b0000000000000010001111000010011; */

/* [15,7,5]-BCH 
static char *G15[7]={
"100000011000101",
"010000011100010",
"001000001110001",
"000100010111000",
"000010001011100",
"000001001110000",
"000000100011001"
},*H15[8]={
"110100010000000",
"111011001000000",
"011101000100000",
"001111100010000",
"000110100001000",
"100010000000100",
"010000000000010",
"101000100000001"
};
*/

/* [16,8,5]-Goppa's H 
static short Gt[16]={128,64,32,16,8,4,2,1,116,178,232,139,87,30,205,47};
static unsigned short h2[8]={32884,16562,8424,4235,2135,1054,717,303};
*/

/* [24,12,8]-Golay code's H is [A_k|I_k] 
static unsigned int ehc[12]={
101000111011100000000000,
110100011101010000000000,
011010001111001000000000,
101101000111000100000000,
110110100011000010000000,
111011010001000001000000,
011101101001000000100000,
001110110101000000010000,
000111011011000000001000,
100011101101000000000100,
010001110111000000000010,
111111111110000000000001
};
static unsigned int H[15]={
0000000000000010001111000010011,
0000000000000100011110000100110,
0000000000001000111100001001100,
0000000000010001111000010011000,
0000000000100011110000100110000,
0000000001000111100001001100000,
0000000010001111000010011000000,
0000000100011110000100110000000,
0000001000111100001001100000000,
0000010001111000010011000000000,
0000100011110000100110000000000,
0001000111100001001100000000000,
0010001111000010011000000000000,
0100011110000100110000000000000,
1000111100001001100000000000000
};
char *v[7]={
"1101000",
"1010010",
"0001110",
"1000101",
"0100011",
"0011001",
"0110100"
};
char *s[7]={
"1101000",
"1000101",
"0100011",
"1010010",
"0011001",
"0110100",
"0001110"
};

*/

unsigned int s[N],es[M];
/*
* 秘密鍵暗号なのでこれらの鍵は公開されない。重みを固定したエラーベクトルによって
* 暗号化されるが受信者は予め送信者と乱数を共有している必要はない。これは、
* 誤り訂正を用いているためでエラーのビット位置が変化しても復号は一意である事を
* 利用する。これによって独立した乱数系列を持つ通信路が出来ると同時にゼロ知識対話
* 証明が可能となる事を意味する。秘密鍵完全暗号の設計に対してゼロ知識性を導入でき
* た。
*/


main(){
int i,j,kkk=0,h,l;
unsigned int em=0;
char t[31];


count=0;count2=0;
for(i=0;i<N;i++)
s[i]=0;

 /* 1001001001001001; */
/* 100100001000010000100001; */
model=strtoul("1001001001001001",(char **)NULL,2);

printf("-----test condition 1-----\n");
printf(" [16,8,5]-Goppa Code\n");
for(i=0;i<8;i++)
printf("%u\n",h2[i]);
printf("\n");
printf("----Testing Parametors----\n");
printf("The number of error pattern N=2^7=%d < 256=2^8\n",N);
printf("If you Choose error-vector's pattern randomely then\n");
n=16; 		/* code length */

 printf("O(knNlogN)=114688\n"); 

printf("and If you Choose error-vector's weight fixed for example w=5 \n");


k=5;
 printf("O(k^2nN)= 131072\n"); 


/*
	printf("enter n (<%d); ",len);scanf("%d",&n);
	if (n>=len){
		printf("too large") ;exit(1);
	}
	printf("enter k(<%d) ;",n+1);scanf("%d",&k);
	if(k>n){
		printf("too large");exit(1);
	}
*/


printf("%u\n",model); /* If you need to use the (adaptive) error pattern. */
	printf("\noutput:\n\n");
	 comb(1); 

if(count<N)
 printf("Can't fill the table! %u < %u\n",count,count2); 

nanka(); /* generate error pattern randomely */

srand((unsigned int)time(NULL)); /* timing function */
printf("Print the error-syndrome table condition [1] and [2]\n");
for(i=0;i<N;i++){
printf("%u %u\n",s[i],es[i]);
/* printf("%u %u\n",s[rand()%128],es[rand()%128]); */ /* take for coding. */
 se[i]=0;to[i]=0;
}



/* s[] and es[] is set of error vector and consists N verticies graph, consider m=0  */
q2(N,es);printf("\n");
printf("w>0\n\n"); /* graph condition1 */
printf("{\n");
for(i=0;i<M;i++){printf("{");
	for(j=0;j<M;j++)
		printf("%d,",itob(es[i]^es[j],t)); /* print graph matrix */
		printf("},\n");
}
printf("}\n\n");


printf("w=%d\n",k); /* graph condition2 */
printf("{\n");
for(i=0;i<M;i++){
		printf("\n");
	for(j=0;j<M;j++)
		printf("%d,",itob(s[i]^s[j],t)); /* print differential of error patterns. */
		printf("},\n");
}
printf("}\n\n");



/* construct differential graph Gamma_i using unit vector {v_i}^k */
printf("We needs 8 differential graph for k=8.\n");

for(i=0;i<8;i++){
for(j=0;j<16;j++) /* generate differential text */
em=(em<<1)+ itob(v[i]&Gt[j],t)%2;

printf("v_%d m_%d= %u\n",i+1,v[i],em);
gi(em);
em=0;
}






}



/* 重み一定のベクトル生成 */
comb(int m)
{
	int i;
	if (m>k)
		action();
	else
		for (i=r[m-1]+1;i<=n-k+m;i++){
			r[m]=i;comb(m+1);
 if(count==N) break; 
		}

}


/* 符号を変えるところ */
action(void)
{
	int i,j;
	char t[31];
	unsigned int b,l;


b=0;
	for (i=1;i<=k;i++)
		b=b+v[r[i]];

j=itob(model^b,t);
if(j>0){
if(itob(b,t)==k){
/* printf("%b %d\n",b,j); */

l=0;
for(i=0;i<8;i++)
	 l=(l<<1)+(itob(h2[i]&b,t)%2); 

/* printf("%u %b %d\n",l,b,j); */

if(l<N){
	if(s[l]==0){
		s[l]=b;
		printf("%u\n",count); 
		count++; /* counting roop for teble */

/* print graph */
		if(count==N)
		{
			for(i=0;i<N;i++)
				printf("%d %u %d\n",i,s[i],itob(s[i],t));
		}

	}
}
count2++;
}
}

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


/* 乱数によるエラーテーブル */
void nanka()
{
int n,l,b,i,j;
char t[16];


for(i=0;i<M;i++)
es[i]=0;
srand(n=(unsigned int)time(NULL)); /* timing function */
/*
scanf("%d",&n);
srand(n);
*/
printf("selected rand seed %d\n",n);
count=0;count2=0;

for(;;){
	b=rand(n);
	l=0;
	for(i=0;i<8;i++)
		l=(l<<1)+(itob(h2[i]&b,t)%2);

/* printf("%u %b %d\n",l,b,j); */

	if(l<M+1){ 				/* syndrome vector space */
		if(es[l]==0){
			if(itob(b,t)>0){	/* vector weight condition 1 */
				es[l]=b;
				 printf("%u %d\n",count,itob(b,t)); 
				count++;
/* (print graph) 
if(count==M){
	printg();
}
*/
			}
		}
	}
count2++;
if(count==M)
break;
}	 /* end of for(;;) */


}



void printg()
{
int i,j;
char t[32];


for(i=0;i<M;i++){
	for(j=0;j<M;j++)
		printf("%d,",itob(es[i]^es[j],t));
	printf("\n");
}

}



/* using table for making i th_diff graph */
void gi(int m)
{
int i,j,h,kkk=0,l;
unsigned int n;


/* n=(unsigned int)time(NULL); */
srand(m);

for(i=0;i<N;i++)
se[i]=0;	/* 全て初期化 */

for(i=0;;i++){
	h=0;l= rand()%N;
	for(j=0;j<N;j++){
		if(se[j]==es[l]) /* 同一のエラーを選ばない */
			h=1; /* フラグ */
	}
	if(h==0){
		printf("%d %d\n",kkk,l);
		se[kkk]=es[l]; /* 選んだエラーを記録 */
		kkk++;
		if(kkk==N){ /* もしテーブルが埋まったら */
			printf("%d\n",i);/* corrected by i times. */
			break;
		/*
			for(j=0;j<i;j++)
				printf("%u %u\n",se[j],s[j]);
		*/
		}
	}

}
printf("end of %d seed= %u\n",m,m);
}


/* breaking if condition is (i */
void bingo(unsigned int m[],unsigned int mm[]) /* cyphertext and it's difference */
{
int i,j,count=0,flg[2][N];
unsigned int d,e,f,em[N];


for(i=0;i<2;i++){
for(j=0;j<N;j++)
flg[i][j]=0;
}

for(i=0;i<N;i++)
em[i]=m[i]^mm[0];

q2(N,em); /* 差分の一致する要素が存在するか */
printf("\n");

for(i=0;i<N;i++){
	if(flg[0][i]!=1){
		d=m[i]^mm[j];

	for(j=0;j<N;j++){
		if(flg[1][j]!=1)
			e=m[i+1]^mm[j];
			if(e==d){
				printf("bingo! %u %d times\n",e,j);
				count++; flg[0][i]=1; flg[1][j]=1;
			}
	}
	if(count>0){
		printf("same pattern exsists %d at %d\n",count,i);
		count=0;
	}
}


}



int an(int c)
{
int i,j,m=0;
char t[16];


hind(c);
for(i=0;i<16;i++)
m=(m<<1)+itob(c&Gt[i],t);
printf("%u\n",m); /* binary trans..? */

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



void pc()
{
int i,j,c,k,l,syn[256];
char t[16];


for(i=0;i<8;i++){
for(j=0;j<8;j++)
 printf("%d",itob(Gp[i]&h2[j],t)); /* 8-bit */
printf("\n");
}

for(i=0;i<256;i++){
l=0;
for(j=0;j<16;j++)
l=(l<<1)+itob(Gt[j]&i,t); /* 7-bit */
syn[i]=l;
}


/*
for(i=0;i<16;i++){
for(k=0;k<4;k++){ 
printf("%b ",GH[k][i]);

 c=0; 
for(j=0;j<16;j++){
if(bit(Gp[i],j)==1){
c=GH[k][j];
 printf("%d ",c); 
}
}
printf("\n");

 printf("%d\n",c);
 printf("%d ",c); 
}
printf("\n");
}
*/
}


/* 復号関数2 */
void decode(unsigned int r)
{
unsigned int c,e,m;


m=syn(r);
e=es[m];
c=r^e;
printf("%b %b %b\n",c,e,r);

}


/* 差分に基づくグラフの生成 */
unsigned int gii(unsigned int m,int i)
{

/* printf("%b %b\n",m,i); */

return m^(1<<i); /* 1-bit差分 */

}



/* 受信語に対するシンドローム計算 */
unsigned int syn(unsigned int x)
{
int i,j,c;
char t[32];


c=0;
for(j=0;j<15;j++)
c=(c<<1)+itob(x&h31[j],t); /* 31-bit */
/* printf("%d_%b\n",c,i); */

return c;

}


/* F_2 上の多項式の割り算 */
void pd(unsigned int p,unsigned int d)
{
unsigned int x,y,r,q,i,j;

q=p; y=d;
r=0;
i=cb(q)-cb(y);
y=(y<<i);

while(y > 0){
if(cb(q)==cb(y)){
r=r + (1<<i);
printf("fi%u %u\n",q,y); /* needs binary representation */
q=(q^y);
printf("if%u %u\n",q,y); /* needs binary representation */
	}
y=d;
i=cb(q)-cb(y);
y=(y<<i);
}
printf("%u %u\n",r,q); /* needs binary representation */

}


/* 何ビット整数か返す */
int cb(unsigned int x)
{
int i,j;

i=0;
while(x>0){
x=(x>>1); i++;
}
return i;

}


/* 安定なソート */
void qsrt(int *l,int *r)
{
int *p=l,*q=r,w,x,i,j;


x= *(l+(r-l>>1));
do{
while(*p<x)
p++;
while(*q>x)
q--;
if(p>q)
break;
w=*p;*p=*q;*q=w;
} while(++p<= --q);

if(l<q)
qsrt(l,q);
if(p<r)
qsrt(p,r);

if(q-p==4){
for(i=0;i<16;i++)
printf("%d ",*l++);
printf("\n");
}

}


void q2(int n,int a[])
{
int i,j,l,r,p;
int lstack[32],rstack[32];
int x,t;

l=0; r=n-1; p=0;
for(;;){
if(r-l<= 10){
if(p==0) break;
p--;
l=lstack[p];
r=rstack[p];
}
x=a[(l+r)/2];
i=l; j=r;
for(;;){
while(a[i]<x) i++;
while(x<a[j]) j--;
if(i>=j) break;
t=a[i]; a[i]=a[j]; a[j]=t;
i++; j--;
}
if(i-l>r-j){
if(i-l> 10){
lstack[p]=l;
rstack[p]=i-1;
p++;
}
l=j+1;
}else{
if(r-j>10){
lstack[p]=j+1;
rstack[p]=r;
p++;
}
r=i-1;
}
}
inssort(n,a);

}


void inssort(int n,int a[])
{
int i,j;
int x;


for(i=1;i<n;i++){
x=a[i];
for(j=i-1;j>=0 && a[j]>x;j--)
a[j+1]=a[j];
a[j+1]=x;
}
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");

}


