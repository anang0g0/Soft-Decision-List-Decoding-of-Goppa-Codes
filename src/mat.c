#include <stdio.h>
#include <math.h>

#define M 6
#define N 6

double x[M][N]={
/*
6,5,4,3,2,1,
5,5,4,3,2,1,
4,4,4,3,2,1,
3,3,3,3,2,1,
2,2,2,2,2,1,
1,1,1,1,1,1
*/
  0,1,1,1,0,1,0,0,
  1,0,1,1,0,0,1,0,
  1,1,1,0,1,0,0,0,
  1,0,0,0,1,0,1,1,
  0,1,0,1,0,1,1,1,
  0,0,0,1,1,1,1,0,
  1,1,0,0,1,1,0,1,
  0,0,1,0,1,1,1,1
};

double y[M][N],z[M][N];

main(){
double det;
int n,m,id;

m=M; n=N;
p_ary5(x,m,n);

id=inv_mat2(x,m,n,&det,0.0001); p_ary5(x,m,n);

printf("\ndet = %f id=%d\n",det,id);
}


inv_mat2(double *a,int m,int n,double *det,double eps)
{
double *p,*q,w,piv;
int i,j,k,*index,ipv,idx;

if((index=(int *)malloc(m*2))==NULL)
  {
    printf("\n\n !!! out ou memory\n\n");
    exit();
}

*det=1.0;
p=a;
for(k=0;k<m;k++)
  {
    piv=eps; ipv= -1;
    q=a+k*n;
    for(i=k;i<m;i++)
      {
	if(fabs(piv)<fabs(*(q+k) ))
	  {
	    piv=*(q+k); ipv=i;
	  }
	q+=n;
      }
    index[k]=ipv;
    if(ipv < 0) { free((char *)index); return 1;}
    if(ipv != k)
      {
	for(j=0;j<n;j++)
	  dswap(a+ipv*n+j,p+j);
	*det=-(*det);
      }
    *det *= piv; *(p+k)=1;
    for(j=0;j<n;j++)
      *(p+j)/=piv;
    q=a;
    for(i=0;i<m;i++)
      {
	if(i!=k)
	  {
	    w=*(q+k); *(q+k)=0.0;
	    for(j=0;j<n;j++)
	      *(q+j)-= *(p+j)*w;
	  }
	q+=n;
      }
    p+=n;
  }
for(j=0;j<m-1;j++)
  {
    k=m-j-2; idx=index[k];
    if(idx != k)
      {
	p=a;
	for(i=0;i<m;i++)
	  {
	    dswap(p+idx,p+k);
	    p+=n;
	  }
      }
  }
free((char *)index);
return 0;
}


p_ary5(double *b,int n,int m)
{
int i,j;

printf("\n");
for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
      printf("%f ",*(b+i*n+j));
    printf("\n");
 }
}

dswap(double *a,double *b)
{
double t;

t=*a; *a=*b; *b=t;

}
