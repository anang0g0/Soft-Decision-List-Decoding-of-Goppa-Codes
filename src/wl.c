#include <stdlib.h>


main(){

/* wali(strtoul("10110000",(char *)NULL,2),strtoul("1101",(char *)NULL,2)); */

pd(strtoul("10110000",(char *)NULL,2),strtoul("1101",(char *)NULL,2));

}


/* F_2 上の多項式の割り算 */
void pd(unsigned int p,unsigned int d)
{
  unsigned int x,y,r,q,j;
  int i;
  char t[16];
  
  
  q=p; y=d;
  r=0;
  i=cb(q)-cb(y);
  y=(y<<i);
  
  while(y > 0){
    if(cb(q)==cb(y)){
      r=r + (1<<i);
      printf("fi");
      itob(q,t); printf(" q-y1 "); itob(y,t);
      
      q=(q^y);
      itob(q,t); printf(" q-y2 "); itob(y,t);
    }
    y=d;
    i=cb(q)-cb(y);
    y=(y<<i);
    printf("%u %i\n",y,i);
    if(i<0)
    break;
  }
  /* return q; */
printf("rq");  itob(r,t); itob(q,t); 

}


void wali(unsigned int x,unsigned int y)
{
  unsigned int c=0,i,j=0,k,q=0;
  char t[16];


  while(x>y-1){
    c=x; i=0;
    while(c>y){
      c=(x>>i);
      i++;
      itob(c,t);
    }
    c=(x>> i-1)^y;
    /* printf("%u %u\n",c,x>> i-1); */
    k=((c^y)<<(i-1))^x;
    x=k^((c^y)<<(i-2)); 
    j++;
    itob(x,t); printf(" ");
    itob(k,t);
printf("\n");


itob(q,t);
    if(k==x)
      {j++; break;}
    j << 1;
    printf("%u %u\n",(c^y)<<(i-2),((c^y)<<(i-1))^x);

  }

 /* cout << Itoa(j,2) << " " << Itoa(x,2) << endl; */

}



/* 何ビット整数か返す */
short cb(unsigned int x)
{
int i,j;

i=0;
while(x>0){
x=(x>>1); i++;
}
return i;

}


/* ２進表示 */
int itob(int n,char s[])
{
int i,j,k=0;

for(i=15,j=0;i>=0;i--,j++){
s[j]=((n>>i) & 0x0001) + '0';
}

for(j=0;j<16;j++)
printf("%d",s[j]-48);
printf("\n");

}
