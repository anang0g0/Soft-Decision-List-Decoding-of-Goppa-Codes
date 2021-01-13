
/* (6,3,3)-Hamming Code シンドロームテーブル */

#include <stdio.h>

static int C[7]={/* 同じ検査行列を持つ符号 */
		0b001110, /* c1=(001110) */
		0b010101, /* c2=(010101) */
		0b100011, /* c3=(100011) */
		0b011011,
		0b101101,
		0b110110,
		0b111000
		};
Ct[6]={/* 組織符号を選んでみる */
	0b001,
	0b010,
	0b100,
	0b110,
	0b101,
	0b011
	};

static char R[6]={7,2,1,5,3,2};


/*
Et[8]={
01 00 00 00
01 01 01 10
01 10 11 10
01 11 10 10
01 00 00 01
01 01 01 11
01 10 11 11
01 11 10 11
};
*/
	H[3]={ 0b011100,0b101010,0b110001};

/* 点の組を要素に持つ配列
	Ht[3][6]={
		{0,1,1},
	 	{1,0,1},
		{1,1,0},
		{1,0,0},
	 	{0,1,0},
		{0,0,1}
	};

P[6]={ 
	0b100000,
	0b010000,
	0b001000,
	0b000100,
	0b000010,
	0b000001
	};
*/

/* エラーベクトル */
Z[8]={1,2,4,8,16,32,0,6};

z2[8]={0,1,2,4,8,16,32,6};
z3[8]={6,4,1,2,16,8,0,32};
z4[8]={32,0,8,16,6,8,4,1};

/* 軟判定可能なエラー */
/*
z2[8]={3,5,6,9,10,12,33,17};
z3[8]={17,18,20,24,0,1,2,3};
z4[8]={32,31,30,29,28,27,37,0,1,20};
*/

ze[6]={6,0,5,3,6,1};


/* 平文 */
static char m=5;


main(){
int i,j,k;
char t[16],a,b,c;




for(i=0;i<6;i++)
printf("%u",w(5&ze[i]));
printf("\n");

for(i=0;i<6;i++)
printf("%u",w(4&ze[i]));
printf("\n");
for(i=0;i<6;i++)
printf("%u",w(7&ze[i]));
printf("\n");
for(i=0;i<6;i++)
printf("%u",w(1&ze[i]));
printf("\n");


 hmm(); 
/* syn(); */

}



void hmm()
{
	int i,j,k,n,z,l;
	char t[16];
	FILE *fp;


scanf("%d",&n);
srand(n);

/* fp=fopen("txt.dat","wb"); */

for(l=0;l<50;l++){
for(i=0;i<8;i++){
printf("%d_",m); /* 平文表示 */
k=0;
for(j=0;j<6;j++){
k=k+w(m&Ct[j],t);
k=(k<<1);
}
k=(k>>1);
printf("%b_",k); /* 符号化 */
z=Z[rand()%13];
k=k^z;
printf("%d_%b\n",k,z); /* 暗号化とエラー */
/* fputc(k,fp); */
}
}

}





void syn()
{
int i,j;
char s[16];

/* 変換パターンの例
1 001
10 010 -> 1100
100 100 -> 1010
1000 110 -> 110
10000 101 -> 101
100000 011 -> 11
1001 111
0 000
*/

for(i=0;i<13;i++){
printf("%b ",Z[i]);
for(j=0;j<3;j++)
printf("%d",w(Z[i]&H[j],s));
printf("\n");
}
/*
printf("\n");
for(i=0;i<20;i++){
printf("%b ",zz[i]);
for(j=0;j<3;j++)
printf("%d",w(zz[i]&H[j],s));
printf("\n");
}
*/

}



/* 0,1を返す */
unsigned char w(int syn)
{
char *s,t[23],*itob(),c;
int n,i,f1,l,j;
char m[3];


n=itob(syn,t);
return n%2;

}

/* 重み計算 */
unsigned char itob(unsigned int n,char s[])
{
int i,j,k=0;

for(i=15,j=0;i>=0;i--,j++){
s[j]=((n>>i) & 0x0001) + '0';
}

for(j=0;j<16;j++){
if(s[j]-48==1)
k++;
}
return k;
}


/* 多倍長かけ算のつもり
int mm(int a[][],int b[][])
{
	int i,j,k,c[][]

for(i=0;i<N;i++){
	for(j=0;j<N;j++){
		for(k=0;k<N;k++)
		c[i][j]+=a[i][k]*b[k][j];
		}
	}

}
*/



/* make graph */
mgr()
{
int i,j,k,e[4][13];
char t[32];

for(i=0;i<4;i++){
for(j=0;j<8;j++){
for(k=0;k<8;k++)
printf("%u",itob(e[i][j]^e[i][k],t));
printf("\n");
}
printf("\n");
}

/*
001010
100100
111001
101110

100111
101010
000001
001101
*/

/* show key */
for(i=0;i<8;i++){
e[0][i]=Z[i]^0b101101;
e[1][i]=z2[i]^0b001110;
e[2][i]=z3[i]^0b111000;
e[3][i]=z4[i]^0b100011;
}
printf("%b\n",e[0][0]^e[1][0]);
printf("%b\n",e[0][0]^e[2][0]);
printf("%b\n",e[0][0]^e[3][0]);


}

