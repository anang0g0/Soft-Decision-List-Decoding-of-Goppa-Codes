#include <stdio.h>
#include <math.h>

float a,b,c,d,e,g;

main(){
	float	f();

	FILE	*fp;
	int	i,j,nx,ny,k,l;
	float	xmin,xmax,ymin,ymax,hx,hy,x,y,zc,xxs,yxs,zxs;

	fp=fopen("func.dat","w");
	printf("f(x,y)=");
	printf("a.x.x+b.y.y+c.x.y+d.x+e.y+g\n");
	printf("A,B,C,D,E,G: ");
	scanf("%f %f %f %f %f %f",&a,&b,&c,&d,&e,&g);
	printf("xmin,xmax,ymin,ymax: ");
	scanf("%f %f %f %f",&xmin,&xmax,&ymin,&ymax);
	printf("nx,ny: ");
	scanf("%d %d",&nx,&ny);
	hx=(xmax-xmin)/nx;hy=(ymax-ymin)/ny;
	printf("central z-value: ");scanf("%f",&zc);
	printf("length of positive axes to be drawn");
	printf("(x,y,z): ");
	scanf("%f %f %f",&xxs,&yxs,&zxs);
	x=(xmin+xmax)/2;y=(ymin+ymax)/2;

	fprintf(fp,"%f %f %f\n",x,y,zc);
	for(i=0;i<=nx;i++){
		for(j=0;j<=ny;j++){
			x=xmin+i*hx;y=ymin+j*hy;
			fprintf(fp,"%d %f %f %f\n",j*(nx+1)+i+1,x,y,f(x,y));
		}
	}
	k=(nx+1)*(ny+1);
	fprintf(fp,"%d %f %f %f\n",++k,0.,0.,0.);
	fprintf(fp,"%d %f %f %f\n",++k,xxs,0.,0.);
	fprintf(fp,"%d %f %f %f\n",++k,0.,yxs,0.);
	fprintf(fp,"%d %f %f %f\n",++k,0.,0.,zxs);

	fprintf(fp,"faces:\n");
	for(i=0;i<nx;i++){
		for(j=0;j<ny;j++){
			k=j*(nx+1)+i+1;l=k+nx+1;
			fprintf(fp,"%d %d %d#\n",k,-(l+1),k+1);
			fprintf(fp,"%d %d %d#\n",k+1,l+1,-k);
			fprintf(fp,"%d %d %d#\n",k,-(l+1),l);
			fprintf(fp,"%d %d %d#\n",l,l+1,-k);
		}
	}
	k=(nx+1)*(ny+1);
	fprintf(fp,"%d %d#\n",k+1,k+2);
	fprintf(fp,"%d %d#\n",k+1,k+3);
	fprintf(fp,"%d %d#\n",k+1,k+4);

	fclose(fp);
}

float f(x,y)
float x,y;
{
	return a*x*x+b*y*y+c*x*y+d*x+e*y+g;
}
