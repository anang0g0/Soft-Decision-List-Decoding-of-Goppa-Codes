main(){
unsigned int d,q,x,n;


scanf("%d",&n);
x=n;

while(x>=4 && x%2==0){
	 printf("2*"); 
 x /=2;
	}
	d=3; q=x/d;
	while(q>=d){
		if(x % d==0){
			 printf("%d*",d); 
 x=q;
		}
		else d +=2;
		q=x/d;
	}
	printf("%d\n",x);


}

