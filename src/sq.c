#include <math.h>

main(){
	unsigned int i;

	scanf("%d",&i);

	printf("%.1f\n",sqrt(i));

/*
	printf("%f\n",sq(i));
	printf("%f\n",lsq(i));
	printf("%f\n",isq(i));
*/
}


double sq(double x)
{
	double s,last;

	if(x>0){
		if(x>1) s=x; else s=1;
		do {
			last=s; s=(x/s+s)/2;
		} while (s<last);
		return last;
	}
	if(x !=0) printf("error\n");
	return 0;
}

long double lsq(long double x)
{
	long double s;

	if(x==0) return 0;
	s=sq(x);
	return (x/s+s)/2;
}

unsigned int isq(unsigned int x)
{
	unsigned int s,t;

	if(x==0) return 0;
	s=1; t=x;
	while(s<t) { s<<=1; t>>=1; }
	do{
		t=s;
		s=(x/s+s)>>1;
	} while(s<t);
	return t;
}


