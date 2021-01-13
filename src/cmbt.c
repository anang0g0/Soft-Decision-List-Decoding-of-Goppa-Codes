#include <stdio.h>
#include </usr/include/math.h>

/* $BAH9g$;$N?t$N7W;;(B: sqrt() $B$,F0$+$J$$!)(B */


enum	term {deno,nume};
int	a[1049];
double	c,x,y;
int	n,r,q,e,s,b,d;
long long int l;
void	mp(),deco(),cv(),pv();


main(){
  int i;
  
  printf("\n n="); scanf("%d",&n);
  printf("\n r="); scanf("%d",&r);
  
  for(i=1;i<=n;i++) a[i]=0;
  mp(n,nume);
  mp(r,deno);
  mp(n-r,deno);
  
  deco(); cv();
  
  printf("\n c=%16.13fE+%3d",c,e);
  printf("\n c="); pv(); printf("\n");

}     
     
     
void	mp(int k,enum term t)
{
  int i;
  
  if((k>0) && (k<=n))
    {
      switch(t)
	{
	case	deno:
	  for(i=1;i<=k;i++) a[i]--;
	  break;
	case	nume:
	  for(i=1;i<=k;i++) a[i]++;
	}
    }
  else printf("\n invalid number k=%6d",k);
}


void deco()
{
  int	i,j,k,flag;


  for(i=n;i>=4;i--)
    if(a[i]!=0)
      {
	j=2; k=(int)(sqrt((double)i)+1.5);
	flag=0;
	while((flag!=1) && (j<k))
	  {
	    if((i%j)==0) flag=1;
	    else j=(j==2)? 3: j+2;
	  }
	if(flag)
	  {
	    a[j]+=a[i]; j=i/j; a[j]+=a[i]; a[i]=0;
	  }
      }
}


void cv()
{
  int i,j;
  
  c=1.0; e=0;
  for(i=1;i<=n;i++)
    {
      if(a[i]>0) for(j=1;j<=a[i]; j++) c*=i;
      if(a[i]<0) for (j=1;j<=a[i];j++) c/=i;
      while(c>=10.0)
	{
	  c/=10.0; e++;
	}
    }
}


void pv()
{
  int i;
  printf("1");
  for(i=2;i<=n;i++)
    {
      if(a[i]>1) printf("*%d^%d",i,a[i]);
      if(a[i]==1) printf("*%d",i);
    }
}


