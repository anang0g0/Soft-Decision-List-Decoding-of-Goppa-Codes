/* when are two goppa codes equal? */
/* プログラムって 400k byteもいるんですか？ */
#include <stdio.h>
#include "gfall.c"

#define N 64
#define M 6

static char *f[8]={
"10001011","10001001",
"10101011","10100001",
"10101001","10100011",
"10101011","10000011"
};
static char *ff[10]={
"11010000000000001","10000000000000010",
"11010101010101011","10100000000000111",
"11000000000001011","10000001000100011",
"10101010000010001","10000100010100011",
"10000100010101011","10100001001001001"
};

/*
static unsigned int gf[N] = 
  {0, 1, 2, 4, 8, 16, 5, 10, 20, 13, 26, 17, 7, 14, 28, 29, 31, 27, 19, 3, 6, 
   12, 24, 21, 15, 30, 25, 23, 11, 22, 9, 18};

static unsigned int gf[N] = 
  {0, 1, 2, 4, 8, 16, 32, 3, 6, 12, 24, 48, 35, 5, 10, 20, 40, 19, 38, 15, 
   30, 60, 59, 53, 41, 17, 34, 7, 14, 28, 56, 51, 37, 9, 18, 36, 11, 22, 44, 
   27, 54, 47, 29, 58, 55, 45, 25, 50, 39, 13, 26, 52, 43, 21, 42, 23, 46, 
   31, 62, 63, 61, 57, 49, 33};
*/
/*
static int gf[256] = 
  {0, 1, 2, 4, 8, 16, 32, 64, 128, 29, 58, 116, 232, 205, 135, 19, 38, 76, 
   152, 45, 90, 180, 117, 234, 201, 143, 3, 6, 12, 24, 48, 96, 192, 157, 39, 
   78, 156, 37, 74, 148, 53, 106, 212, 181, 119, 238, 193, 159, 35, 70, 140, 
   5, 10, 20, 40, 80, 160, 93, 186, 105, 210, 185, 111, 222, 161, 95, 190, 
   97, 194, 153, 47, 94, 188, 101, 202, 137, 15, 30, 60, 120, 240, 253, 231, 
   211, 187, 107, 214, 177, 127, 254, 225, 223, 163, 91, 182, 113, 226, 217, 
   175, 67, 134, 17, 34, 68, 136, 13, 26, 52, 104, 208, 189, 103, 206, 129, 
   31, 62, 124, 248, 237, 199, 147, 59, 118, 236, 197, 151, 51, 102, 204, 
   133, 23, 46, 92, 184, 109, 218, 169, 79, 158, 33, 66, 132, 21, 42, 84, 
   168, 77, 154, 41, 82, 164, 85, 170, 73, 146, 57, 114, 228, 213, 183, 115, 
   230, 209, 191, 99, 198, 145, 63, 126, 252, 229, 215, 179, 123, 246, 241, 
   255, 227, 219, 171, 75, 150, 49, 98, 196, 149, 55, 110, 220, 165, 87, 174, 
   65, 130, 25, 50, 100, 200, 141, 7, 14, 28, 56, 112, 224, 221, 167, 83, 
   166, 81, 162, 89, 178, 121, 242, 249, 239, 195, 155, 43, 86, 172, 69, 138, 
   9, 18, 36, 72, 144, 61, 122, 244, 245, 247, 243, 251, 235, 203, 139, 11, 
   22, 44, 88, 176, 125, 250, 233, 207, 131, 27, 54, 108, 216, 173, 71, 142};
*/
int count,L[N],G[N],g[N][N];


main(){
int i,j,a,k;


for(i=0;i<6;i++){
  printf("%u\n",strtoul(ff[i],(char **)NULL,2));
  count=0;
  for(j=0;j<N;j++){
    a=b2pl(strtoul(ff[i],(char **)NULL,2),j);
    /* printf("%d %d\n",a,count); */
    if(a>0){
      G[count-1]=a;
      /* printf("%d ",a); */
    }
  }
  printf("%d\n",count);
  /*
     for(k=0;k<count;k++)
     printf("%d ",GF64[inv(G[k])]);
     */
  vandermonde(); 
  /* q2(count,G); */
  printf("\n");
  vin();
}

}


/* k番目のビット取り出し */
int bit(int n,int k)
{
  int i,j;
  char s[9];
  
  
  for(i=6,j=0;i>=0;i--,j++){
    s[j]=((n>>i) & 0x00001) + '0';
  }
  return s[k+1]-48;
  
}


vandermonde()
{
  int i,j;
  
  
  for(i=0;i<count;i++){
    g[0][i]=GF64[div(1,G[i])]; 
    printf("%d ",g[0][i]); 
  }
  printf("\n");
  for(i=0;i<count;i++){
    g[1][i]=GF64[div(L[i],G[i])]; 
    printf("%d ",g[1][i]); 
  }
  printf("\n");
  for(j=2;j<16;j++){
    for(i=0;i<count;i++){
      g[j][i]=GF64[div(mltn(j,L[i]),G[i])]; 
      printf("%d ",g[j][i]); 
    }
    printf("\n");
  }
  
}


/* バイナリ表現 */
vin(){
  int i,j,k;
  
  
  printf("vin\n");
  for(i=0;i<16;i++){
    for(k=0;k<6;k++){
      /* printf("bin"); */
      for(j=0;j<count;j++) 
	printf("%d",bit(g[i][j],k));
      printf(",\n");
    }
  }
  
}


/* ビット列から多項式の計算 */
int b2pl(int n,int x)
{
  unsigned int l=0;
  int i,j;
  
  
  /* printf("%b\n",n); */
for(i=0;i<cb(n);i++){
  /* printf("%d ",bit(n,i)); */
  if(bit(n,i)==1){
    /* printf("%d ",cb(n)-i-1); */
	 l=add(l,mltn(cb(n)-i-1,x)); 
       }
}
  if(l!=0){
    L[count]=x;
    count++;
  }
  return l;
  
}


/* 任意の次数をもつ多項式 (0<i<n 次数の項をランダムに選ぶ) */
int mpl(int n,int x)
{
  unsigned int l=0;
  int i,j;
  
  
  /* どうやってn個決めるか？ */
  for(i=n;i>-1;i--){
	 l=add(l,mltn(i,x)); 
       }
  if(l!=0){
    L[count]=x;
    count++;
  }
  return l;
  
}


/* 係数の選択 (monic) */




/* パラメータの決定 (k=n-mt) */


/* 交錯法 */


/* 標準行列に変換 (Gauss) */




/* バイナリ変換 (Fourier Trans) */




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


/* 有限体上での掛け算 */
int mlt(int x,int y)
{
  if(x==0||y==0){
    return(0);
  }
  return ((x+y-2)%(N-1))+1;
}


/* 有限体上での累乗 */
int mltn(int n,int x)
{
  int i,j;
  
  
  if(n==0) return 1;
  
  i=x;
  for(j=1;j<n;j++)
    i=mlt(i,x);
  
  return i;
  
}


/* 有限体上での足し算 */
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
    z=(GF64[x-y+1]-1)+(y-1);
    z=(z%(N-1))+1;
  }
  else if(x < y){
    z=(GF64[y-x+1]-1)+x-1;
    z=(z%(N-1))+1;
  }
  else{
    z=0;
  }
  return(z);
}


/* 有限体上での割り算 */
int div(int x,int y)
{
  if(y==0){
    /* printf("yが0\n"); */
    /* exit(1); */
  }
  else if(x==0){
    return 0;
  }
  return ((x-y+(N-1))%(N-1))+1;
}


/* 多項式の逆数 */
int inv(int l)
{
  int i,j;
  
  
  if(l==0)
    printf("分母が０です。\n");
  
  return div(1,l);
  
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


