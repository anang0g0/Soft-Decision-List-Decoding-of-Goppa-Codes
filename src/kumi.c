#include <stdio.h>

#define len 1025
#define N 128 /* number of error pattarn condition 1 */
#define M 128 /* number of error pattern condition 2 */

int n,k,r[len];


unsigned int count,count2;
/* $BAH9g$;$N7W;;(B: $B0lHVCY$$$1$I%^%H%b$KF0$/(B */


main(){


count=0;
  printf("n="); scanf("%d",&n);
  printf("\n");
  printf("k="); scanf("%d",&k);
  printf("\n");
  
  comb(1);
  printf("%u\n",count);

}


comb(int m)
{
  int i;


  if (m>k)
    action();
  else
    for (i=r[m-1]+1;i<=n-k+m;i++){
      r[m]=i; comb(m+1);
    }

}


action(void)
{
  int i,j;
  
/*  $BI=<($7$J$$;~(B
  for (i=1;i<=k;i++)
    printf("%3d",r[i]);
  printf("\n");
*/
  count++;

}

