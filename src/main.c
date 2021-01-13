#include <stdio.h>
#include "common.c"


main(){
unsigned int n,x;
int i;


scanf("%u",&n);
printf("%b\n",n);
/*
printf("%b\n",l2l(n,3));
printf("\n");
printf("%b\n",r2r(n,3));
*/
printf("%d\n",cb(n));
for(i=0;i<cb(n);i++){
if(bit(n,i)==1)
printf("%d %d\n",bit(n,i),i);
}

printf("%u\n",b2pl(n,2));

gpl(32);



}

