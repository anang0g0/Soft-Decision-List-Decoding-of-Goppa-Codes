
main()
{
  unsigned int n,m,l,x,z,i,j,stack[16500];
  
  
  z=0;stack[0]=1;n=0;
  
  scanf("%u %u",&i,&x);
  printf("%u %u\n",i,x);
  
  while (++z < x+1){
    j=-1;
    while (++j < n+1){
      stack[j]=stack[j]*i;
  
    }
    j=-1; l=n+1;
    while (++j < l)
      {	 
	if (stack[j] > 9999)
	  {
	    m=stack[j]/10000;
	    if (j==n)
	      stack[j+1]=0;
	    stack[j+1]=stack[j+1]+m;
	    stack[j]=stack[j]%10000;
	    if (j==n)
	      n++;
	  }
      }
  }
/*  n=n+1; */

  /* printf("%u\n",n); */
   while (n < -1){
    printf("%u ",stack[n]);
    n--;
  }  
  printf("\n");
  
}

  
