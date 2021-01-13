
#define N 32
#define M 16

static int a[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
	p[16]={11,13,12,6,17,15,14,8,10,9,11,0,5,3,2,4},
	p8[8]={5,0,1,6,3,2,7,4},
g1[N]={1,1,14,30,29,19,10,22,22,8,19,14,15,25,18,25,11,10,20,8,29,30,11,31,9,6,20,9,18,6,31,15},
g2[N]={1,1,9,11,10,15,22,14,18,31,20,25,22,30,6,9,8,18,8,29,31,6,29,25,19,19,15,20,30,11,14,10},
G[8]={
	0b0111001010000000,
	0b1010101001000000,
	0b1110000100100000,
	0b1100110000010000,
	0b0011011100001000,
	0b1000111100000100,
	0b0101110100000010,
	0b0001101100000001
	};
unsigned int kk[8];
int compare(char **,char **);
int *l;


main(){
	int i,j,n;
	static int tmp[16],t[16],t2[16],t3[8];


n=0;
while(n<32)
printf("%d ",g1[n++]);
printf("\n");
q2(32,g1);
q2(32,g2);

/*
n=0;
qsrt(p,p+(N-1));
for(i=0;i<N;i++)
printf("%d ",l++);
printf("\n");
*/
/*
	for(i=0;i<16;i++)
	printf("%d ",a[i]);
	printf("\n");

	for(i=0;i<16;i++)
	printf("%u ",p[i]);
	printf("\n");

	for(i=0;i<16;i++)
	tmp[p[i]]=a[i];

	for(i=0;i<16;i++)
	printf("%d ",tmp[i]);
	printf("\n");

	for(i=0;i<16;i++)
	t[i]=tmp[p[i]];

	for(i=0;i<16;i++)
	printf("%d ",t[i]);
	printf("\n");

printf("\n");

	for(i=0;i<16;i++){
	n=rv(i);
	printf("%d ",n);
	tmp[i]=n;
	}
	printf("\n");


for(i=0;i<8;i++)
printf("%b\n",G[i]);
printf("\n");

	for(i=0;i<16;i++)
	printf("%u ",p[i]);
	printf("\n");

	for(i=0;i<16;i++)
	t[p[i]]=tmp[i];

	for(i=0;i<16;i++)
	printf("%d ",t[i]);
	printf("\n");

	for(i=0;i<16;i++)
	t2[i]=t[p[i]];

	for(i=0;i<16;i++)
	printf("%d ",t2[i]);
	printf("\n");

 r2g(t);
for(i=0;i<8;i++){
printf("%b\n",kk[p8[i]]);
*/
/*
for(j=0;j<16;j++)
printf("%d",bit(k[p8[i]],j));
printf("\n");
}
printf("\n");
*/
}


int bit(int n,int k)
{
int i,j;
char s[32];

for(i=32,j=0;i>=0;i--,j++){
s[j]=((n>>i) & 0x00001) + '0';
}
return s[k+1]-48;

}


int bit8(int n,int k)
{
int i,j;
char s[16];

for(i=8,j=0;i>=0;i--,j++){
s[j]=((n>>i) & 0x0001) + '0';
}
return s[k+1]-48;

}


int rv(int x)
{
int i,j,c=0;


for(i=0;i<8;i++)
c=(c<<1)+bit(G[i],x);
return c;

}


void r2g(int r[16])
{
int i,j,c;


for(j=0;j<8;j++){
c=0;
for(i=0;i<16;i++){
printf("%d",bit8(r[i],j));
c=(c<<1)+bit8(r[i],j);
}
kk[j]=c;
printf("\n");
}

}


static int compare(char **k1,char **k2)
{
	return (strcmp(*k1,*k2));
}


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

