
static int gf[8] = {0, 1, 2, 4, 3, 6, 7, 5};


main(){

char *s,t[23],*itob(),c;
int n,i,f1,l,j;
char m[3];

for(i=0;i<8;i++)
printf("%b -> %d(weight)\n",gf[i],itob(gf[i],t));

}


char *itob(n,s)
int n;
char s[];
{
int i,j,k=0;

for(i=15,j=0;i>=0;i--,j++){
s[j]=((n>>i) & 0x0001) + '0';
}
/* s[j]='\0'; */
for(j=0;j<16;j++){
printf("%d ",s[j]-48);
if(s[j]-48==1)
k++;
}
return(k);
}

