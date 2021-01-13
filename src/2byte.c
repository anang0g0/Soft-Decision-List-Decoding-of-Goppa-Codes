#include <stdio.h>
#include <fcntl.h>

#define RE 8132

int buf[RE/2];
unsigned char bf[RE];



main(){
  read_test("test.1");
  write_test("test.2");
  printf("\n");
  read_test("test.2");

printf("\n");
/* read_smpl("test.2"); */

}

int write_test(char *name)
{
  int fd,n;
  
  fd=creat(name,0x8001);
  n=write(fd,(char *)buf,RE);
  close(fd);
}

int read_test(char *name)
{
  int fd,n,i;
  
  fd=open(name,0x8000);
  n=read(fd,(char *)buf,RE);
  printf("\n data size n=%5d \n",n);
  
  for(i=0;i<n/2;i++){
    if(buf[i]>0)
    printf("%8d",buf[i]);
  }
  close(fd);
  
}

void read_smpl(char *name)
{
  int fd,n,i,count=0;
  
  fd=open(name,0x8000);
  
  n=read(fd,bf,RE);

  for(i=0;i<n;i+=2){
    if(btoi(&bf[i])>0)
    printf("%8d",btoi(&bf[i]));
  
  }
  close(fd);
printf("n= %d\n",n);  
  
}

int btoi(unsigned char *c)
{
  return (int)(*c+256**(c+1));
}

