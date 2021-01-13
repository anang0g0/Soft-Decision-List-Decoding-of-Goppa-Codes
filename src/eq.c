/* when are two goppa codes equal? */
#define N 32

static unsigned int gf[N] = 
  {0, 1, 2, 4, 8, 16, 5, 10, 20, 13, 26, 17, 7, 14, 28, 29, 31, 27, 19, 3, 6, 
   12, 24, 21, 15, 30, 25, 23, 11, 22, 9, 18};


main(){
int i,j,g1,g2,x;


for(x=0;x<N;x++){
g1=gf[mltn(6,x)]^gf[mltn(5,x)]^1;
printf("%d,",g1);
if(g1==0)
printf("%d ",x);
}
printf("\n");
for(x=0;x<N;x++){
g2=gf[mltn(6,x)]^gf[x]^1;
printf("%d,",g2);
if(g2==0)
printf("%d ",x);
}
printf("\n");

}


/* —LŒÀ‘Ìã‚Å‚ÌŠ|‚¯ŽZ */
int mlt(int x,int y)
{
    if(x==0||y==0){
        return(0);
    }
    return ((x+y-2)%(N-1))+1;
}


/* —LŒÀ‘Ìã‚Å‚Ì—Ýæ */
int mltn(int n,int x)
{
int i,j;

i=x;
for(j=1;j<n;j++)
i=mlt(i,x);

return i;

}


