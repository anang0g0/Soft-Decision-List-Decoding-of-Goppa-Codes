#include <stdio.h>

typedef unsigned long long int poly;
poly quo,quo_low,res,res_low;

#define MSB (~(~0ULL>>1))

int i,k;


int main(){
	poly p,p_low;

scanf("%d",&i);
	p=MSB; p_low= (MSB>>i);

	while(p_low!=0){
		write_poly(p,p_low); printf("=");
		factorize(p,p_low); printf("\n");
		p +=p_low; 
		if(p==0){
			p=MSB; p_low>>=1;
		}
	}
	return -1;
}



void write_poly(poly p,poly p_low)
{
	poly q;

	q=MSB;
	while (q>=p_low){
		printf((p & q) ? "1":"0");
		q>>=1;
	}
}

void divide(poly a,poly a_low,poly b,poly b_low)
{
int i;
	quo=0; quo_low=MSB; res=a; res_low=a_low;
	if(res_low>b_low) return;
	for(;;){
		if(res & MSB){
			quo|=quo_low; res^=b;
		}
		if(res_low==b_low) break;
		res_low<<=1; res<<=1; quo_low>>=1;
/* printf("%d ",i); */
	}
}

void factorize(poly p,poly p_low)
{
	poly d,d_low;

	d=MSB; d_low=MSB>>1;
	while(d_low>p_low){
		divide(p,p_low,d,d_low);
		if(res==0){	/* break; */
			write_poly(d,d_low); printf("*");
			p=quo; p_low=quo_low;
		}else{
			d +=d_low;
			if(d==0){
				d=MSB; d_low>>=1;
			}
		}
	}
	write_poly(p,p_low);
}






