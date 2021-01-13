/* header of common functions */
#include <limits.h>
#include "gf.h"
/* #include "code.h" */


static unsigned int seed=1;
#define M 128
unsigned int es[M],s[M];


typedef unsigned long int poly;
poly quo,quo_low,res,res_low;

 #define MSB (~(~0UL>>1)) /* �ŏ�ʃr�b�g */
 #define N 64

static char *P[31]={
"1000000000000000000000000000000",
"0000000000000000000000010000000",
"0000000001000000000000000000000",
"0000000000001000000000000000000",
"0100000000000000000000000000000",
"0000000000000000000000000000100",
"0000000000000000000100000000000",
"0000100000000000000000000000000",
"0000000000000000000001000000000",
"0000000000010000000000000000000",
"0000000000010000000000000000000",
"0000001000000000000000000000000",
"0000000000000000000010000000000",
"0000000000000000000000000000001",
"0000000000000000000000010000000",
"0010000000000000000000000000000",
"0000001000000000000000000000000",
"0000000000001000000000000000000",
"0000000000000000100000000000000",
"0000000000000000001000000000000",
"0000000000000000000000000100000",
"1000000000000000000000000000000",
"0000000000000000000000100000000",
"0000000000000000000000000100000",
"0000000000000000000000000001000",
"0000000000000000000000000000100",
"0000100000000000000000000000000",
"0010000000000000000000000000000",
"0100000000000000000000000000000",
"0000000000100000000000000000000",
"0000000010000000000000000000000"
};

/* F_2 ��̑������̊���Z */
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
printf("fi%b %b\n",q,y);
q=(q^y);
printf("if%b %b\n",q,y);
	}
y=d;
i=cb(q)-cb(y);
y=(y<<i);
}
printf("%b %b\n",r,q);

}


/* ���r�b�g�������Ԃ� */
int cb(unsigned int x)
{
int i,j;

i=0;
while(x>0){
x=(x>>1); i++;
}
return i;

}


/*
�������̕\��
void write_poly(poly p,poly p_low)
{
	poly q;

	q=MSB;
	while (q>=p_low){
		printf((p & q) ? "1":"0");
		q>>=1;
	}

}


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
*/


/* �r�b�g���] */
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
printf("%b\n",k);
printf("%d\n",k);

}



/* ��M��ɑ΂���V���h���[���v�Z */
unsigned int syn(unsigned int x)
{
int i,j,c;
char t[32];


c=0;
for(j=0;j<15;j++)
c=(c<<1)+itob(x&h31[j],t,31);
printf("%d_%b\n",c,i);

return c;

}



/* �x�N�g���̏d�݌v�Z */
int itob(int n,char s[],int d)
{
int i,j,k=0;


for(i=d-1,j=0;i>=0;i--,j++){
s[j]=((n>>i) & 0x00001) + '0';
}

for(j=0;j<d;j++){
if(s[j]-48==1)
k++;
}
return k;

}


/* �x�N�g���̃p���e�B
int w(int n,char s[],int d)
{
int i,j,k=0;

for(i=0;i<d;i++)
s[i]=0;
for(i=d-1,j=0;i>=0;i--,j++){
s[j]=((n>>i) & 0x00001) + '0';
}

for(j=0;j<d;j++){
if(s[j]-48==1)
k++;
}
return k%2;

}
*/


/* �L���̏�ł̊|���Z */
int mlt(int x,int y)
{
    if(x==0||y==0){
        return(0);
    }
    return ((x+y-2)%(N-1))+1;
}


/* �L���̏�ł̗ݏ� */
int mltn(int n,int x)
{
int i,j;

i=x;
for(j=1;j<n;j++)
i=mlt(i,x);

return i;

}


/* �L���̏�ł̊���Z */
int div(int x,int y)
{
    if(y==0){
	/* printf("y��0\n"); */
	/* exit(1); */
    }
    else if(x==0){
        return 0;
    }
    return ((x-y+(N-1))%(N-1))+1;
  }


/* �L���̏�ł̑����Z */
int add(int x,int y)
{
    int z;

    if(x==0){
        return(y);
    }
    else if(y==0){
        return(x);
    }
    else if(x > y){
        z=(gf[x-y+1]-1)+(y-1);
        z=(z%(N-1))+1;
    }
    else if(x < y){
        z=(gf[y-x+1]-1)+x-1;
        z=(z%(N-1))+1;
    }
    else{
        z=0;
    }
    return(z);
}


/* �����s��̎��s */
void pc()
{
int i,j,c,k,l,syn[256];
char t[16];


for(i=0;i<8;i++){
for(j=0;j<8;j++)
 printf("%d",itob(Gp[i]&h2[j],t,8)); 
printf("\n");
}

for(i=0;i<256;i++){
l=0;
for(j=0;j<16;j++)
l=(l<<1)+itob(Gt[j]&i,t,7);
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



void ev()
{
int i,n;


scanf("%d",&n);
srand(n);
i=0;
while(i<16)
printf("%b\n",strtoul(P[(i++)*rand()%17]),(char **)NULL,2);

}


/* F_2��̑������̊|���Z */
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


/* k�Ԗڂ̃r�b�g���o�� */
int bit(int n,int k)
{
int i,j;
char s[24];

for(i=24,j=0;i>=0;i--,j++){
s[j]=((n>>i) & 0x00001) + '0';
}
return s[k+1]-48;

}


/* �Í��֐��̌Ăяo�� */
/*
unsigned int an(unsigned int m,int k)
{
int i,j;
unsigned l=0;
char t[32];


switch(k)
case 7:
G=bch15
case 8:
G=goppa
case 12:
G=golay
case 16:
G=bch31
case 55:
G=g55


for(i=0;i<k;i++)
l=(l<<1)+itob(m&G[i],t,k);
l=l^z((unsigned int)time(NULL));

return l;

}
*/


/* �Í����֐� */
void ango()
{
int c,r=0,i=0,j=0,txt[32],crp[24];
FILE *fp,*fpp;
char buf[16],t[30];


fpp=fopen("bch15.crp","wb");
	fp=fopen("COPYING","rb");
	while((c=getc(fp)) !=EOF){
		r=0;
		for(i=0;i<15;i++){
		r=(r<<1)+itob(c&strtoul(G[i],(char **)NULL,2),buf,15);
		}
	/* r=(r>>1); */
	putw(r,fpp);
	}
fclose(fpp);

}



/* �����֐�2 */
void decode(unsigned int r)
{
unsigned int c,e,m;


m=syn(r);
e=es[m];
c=r^e;
printf("%b %b %b\n",c,e,r);

}


/* �t�@�C���ɏ����̖��ߍ��� */


/* �E����V�t�g */
unsigned int r2r(unsigned int n,unsigned int r)
{
/* Let n is 16-bit unsigned integer */
while(r>0){
	n=(n>>1)|(n<<15);
	r--;
	}
return n;

}


/* ������V�t�g? */
unsigned int l2l(unsigned int n,unsigned int r)
{
/* Let n is 32-bit unsigned integer */
while(r>0){
	n=(n<<1)|(n>>31);
	r--;
	}
return n;

}


/* ����ȃ\�[�g */
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



/* �g�ݍ��킹�̐��� */
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


/* ������ς���Ƃ��� */
action(void)
{
	int i,j;
	char t[31];
	unsigned int b,l;


b=0;
	for (i=1;i<=k;i++)
		b=b+w[r[i]];

j=itob(model^b,t);
if(j>0){
/* printf("%b %d\n",b,j); */

l=0;
for(i=0;i<8;i++)
	l=(l<<1)+(itob(h2[i]&b,t)%2);

/* printf("%u %b %d\n",l,b,j); */

if(l<N){
	if(s[l]==0){
		s[l]=b;
		printf("%u\n",count); 
		count++;

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



/* �u���֐� */


/* �r�b�g������ */
unsigned rstbit(unsigned int n,int p,int q)
{
	return (n & ((~0 << (p+1)) | ~(~0 << (p-q+1))));
}


/* �r�b�g��̎��o�� */
unsigned int bitget(unsigned int n,int p,int q)
{
	return ((n >> (p-q+1)) & ~(~0 << q));
}



/* �r�b�g�ʒu�v�Z�H */
unsigned int testbit(unsigned int x)
{
unsigned char i,j,l;
unsigned int c=0,
b[15]={
0b100000000000000,
0b10000000000000,
0b1000000000000,
0b100000000000,
0b10000000000,
0b1000000000,
0b100000000,
0b10000000,
0b1000000,
0b100000,
0b10000,
0b1000,
0b100,
0b10,
1
};

l=0;
if(x>b[0]-1){ x=x-b[0]; l++; }
if(x>b[1]-1){ x=x-b[1]; l++; }
if(x>b[2]-1){ x=x-b[2]; l++; }
if(x>b[3]-1){ x=x-b[3]; l++; }
if(x>b[4]-1){ x=x-b[4]; l++; }
if(x>b[5]-1){ x=x-b[5]; l++; }
if(x>b[6]-1){ x=x-b[6]; l++; }
if(x>b[7]-1){ x=x-b[7]; l++; }
if(x>b[8]-1){ x=x-b[8]; l++; }
if(x>b[9]-1){ x=x-b[9]; l++; }
if(x>b[10]-1){ x=x-b[10]; l++; }
if(x>b[11]-1){ x=x-b[11]; l++; }
if(x>b[12]-1){ x=x-b[12]; l++; }
if(x>b[13]-1){ x=x-b[13]; l++; }
if(x>b[14]-1){ x=x-b[14]; l++; }
if(x>b[15]-1){ x=x-b[15]; l++; }
return l%2;



/*
for(i=0;i<7;i++){
	for(j=0;j<8;j++){
	c= G[i]&HT[j];
	 printf("%b ",c); 


 printf("%b_%b ",c,c%2); 
printf("\n");
}
printf("\n");
}
*/

}


/* �r�b�g�񂩂瑽�����̌v�Z */
int b2pl(int n,int x)
{
unsigned int l=0;
int i,j;


printf("%b\n",n);
for(i=0;i<cb(n);i++){
printf("%d ",bit(n,i));
/*
	if(bit(n,i)==1)
	printf("%d ",i);
		l=add(l,mltn(i,x)); 
*/
}
printf("\n");

return l;

}


/* Goppa������ */
unsigned int gpl(int k)
{
int i,z,l=0;


for(z=0;z<64;z++){
l=0;
for(i=3;i<k;i++)
l=add(mltn(i,z),l);
l=add(add(l,mlt(z,z)),add(z,1));
printf("%d ",gf[l]);
}

}


/* �S�b�p�������� */
void gp()
{
unsigned int g,z,k[4],g2[N],g3[N];
int i,j,count=0;


for(z=0;z<N;z++){
k[0]=add(mltn(8,z),mlt(35,mltn(7,z)));
k[1]=add(mlt(13,mltn(6,z)),mlt(54,mltn(5,z)));
k[2]=add(mlt(32,mltn(4,z)),mlt(10,mltn(3,z)));
k[3]=add(add(mlt(mlt(51,z),z),mlt(29,z)),23);

k[0]=add(add(k[0],k[1]),add(k[2],k[3]));

g= gf[mltn(8,z)]^gf[mlt(35,mltn(7,z))]^gf[mlt(13,mltn(6,z))]^
gf[mlt(54,mltn(5,z))]^gf[mlt(32,mltn(4,z))]^gf[mlt(10,mltn(3,z))]^
gf[mlt(mlt(51,z),z)]^gf[mlt(29,z)]^gf[23];

/* printf("%d ",g); */
if(g!=0){
g2[count]=k[0];
g3[count]=z;
count++;
}
}

for(i=0;i<count;i++)
 printf("%d,",gf[div(1,g2[i])]); 
printf("\n");
for(i=0;i<count;i++)
 printf("%d,",gf[div(g3[i],g2[i])]); 
printf("\n");
for(j=2;j<8;j++){
for(i=0;i<count;i++)
 printf("%d,",gf[div(mltn(j,g3[i]),g2[i])]); 
printf("\n");
}
printf("%d\n",count);

}


/* �������̋t�� */
int inv(int l)
{
int i,j;


if(l==0)
printf("���ꂪ�O�ł��B\n");

return div(1,l);

}


void init_rnd(unsigned int x)
{
	seed=x;
}

/* 32bit�����̔��� */
unsigned int urnd(void)
{
	seed=seed*1566083941UL+1;
/* 1812433253UL */
return seed;
}

/* ������������k+1�Ԗڂ̐� */
unsigned int select(unsigned int a[],int n,int k)
{
int i,j,l,r;
unsigned int x,t;


l=0; r=n-1;
while(l<r){
x=a[k]; i=l; j=r;
for(;;){
while(a[i]<x) i++;
while(x<a[j]) j--;
if(i>j) break;
t=a[i]; a[i]=a[j]; a[j]=t;
i++; j--;
}
if(j<k) l=i;
if(k<i) r=j;
}
return a[k];

}


/* �����Ɋ�Â��O���t�̐��� */
unsigned int gi(unsigned int m,int i)
{

printf("%b %b\n",m,i);

return m^(1<<i); /* 1-bit���� */

}




/* �����ɂ��G���[�e�[�u�� */
void nanka()
{
int n,l,b,i,j;
char t[16];
unsigned int count,count2=0;


count=0;
for(i=0;i<M;i++)
es[i]=0;
scanf("%d",&n);
srand(n);
count=0;count2=0;

for(;;){
	b=rand(n);
	l=0;
	for(i=0;i<8;i++)
		l=(l<<1)+(itob(h2[i]&b,t,16)%2);

/* printf("%u %b %d\n",l,b,j); */

	if(l<M+1){
		if(es[l]==0){
			if(itob(b,t,16)==5){
				es[l]=b;
				 printf("%u %d\n",count,itob(b,t,16)); 
				count++;


if(count==M)
printg();

			}
		}
	}
count2++;
if(count==M)
break;
} /* end of for(;;) */

}



/* table putout */
void printt()
{



}



/* (print graph) */
void printg(int count)
{
int i,j;
char t[32];

if(count==M){
	for(i=0;i<M;i++){
		for(j=0;j<M;j++)
			printf("%d ",itob(es[i]^es[j],t,16));
		printf("\n");
	}
}

}


unsigned int swp16(unsigned int m)
{

return ((m << 16 ) | (m >> 16 ));

}



