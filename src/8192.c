#define N 5633
#define M 6913
#define L 8192

main(){
	int i,j,bit,k[L];

/*
printf("%d\n",0b1011000000001);
printf("%d\n",0b11011000000001);
printf("%d\n",0b10000000000000);
*/

k[0]=0;
bit=1;
j=10;
for(i=1;i<L;i++){
if(bit>L-1){
bit=bit-L;
bit=bit^N;
}
/* printf("%d\n",bit); */
k[i]=bit;
bit=(bit<<1);
}

for(i=0;i<L;i++){
printf("%d ",k[i]);
if(i % 10==0 && i>0)
printf(",\n");
}


}

