main()
{


	int sum(),m,j,i=1,ary[1000],nn=0,l=0,count=0;
	ary[0]=1;

	for (i=1;i<101;i++)
	{l=nn+1;
		for(j=0;j < nn+1;j++)
		ary[j]=ary[j]*i;

		j=-1;
		for (j=0;j<l;j++)
		{
			if (ary[j] > 9999)
			{
				m=ary[j]/10000;
					if (j==nn)
					{nn++;
					ary[j+1]=0;
					}
				ary[j+1]=ary[j+1]+m;
				ary[j]=ary[j]%10000;
			}
		}
	}
	printf("%d\n",sum(nn,ary));

}

int sum(nn,ary)
int nn,ary[100];

{
	int i;
	int s=0;
	for(i=0;i<nn+1;i++)
	s+=ary[i];
	return(s);
}

