
main(){
int i,j;




}


int bsrch(unsigned int x,unsigned int a[],int left,int right)
{
int mid;


while(left<right){
mid=(left+right)/2;
if(a[mid]<x) left=mid+1; else right=mid;
}
if(a[mid]==x) return left;
return -1;

}


void rv1()
{
int i;
double r;

do{
r=0;
for(i=0;i<n;i++){
v[i]=2*rand()-1; r+=v[i]*v[i];
}
}while(r>1);
r=sqrt(r);
for(i=0;i<n;i++) v[i]/=r;

}

/*
void rv2(int n,double v[])
{
int i;
double r;


r=0;
for(i=0;i<n;i++){
v[i]=

}
*/



