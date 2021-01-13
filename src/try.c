#include <stdio.h>
#include <ctype.h>

struct bn{
	int num;struct bn *ptr[27];
};
struct in{
	int num;char *key;
};
typedef struct bn *brptr;
typedef struct in *infptr;

main()
{
	FILE *fp;
	char fn[25],word[100],*malloc();
	brptr root;infptr q,fo();
	printf("input file: ");scanf("%s",fn);
	fp=fopen(fn,"r");
	if(fp==NULL)
		error("fill not available");
	root=NULL;
	while (get(fp,word)>0)
		ins(&root,word,0);
	fclose(fp);
	printf("\ncontents of trie:\n");
	if(root != NULL)
		pt(root);
	while(printf("\nenter a word,or type stopsearch to stop: "),get(stdin,word),
			strcmp(word,"STOPSEARCH")){
				q=fo(root,word);
				if(q==NULL)
					printf("key not found\n");
				else
					printf("key found:count field=%d\n",q->num);
			}
}
pt(p)
brptr p;
{
	infptr ip;
	brptr q;
	int k;
	ip=(infptr) p;
	if(p->num)
		printf("%5d %s\n",ip->num,ip->key);
	else
		for(k=0;k<27;k++)
			if(q=p->ptr[k],q !=NULL)
			pt(q);
}

infptr fo(p,word)
brptr p;char *word;
{
	int i=0,k;
	char ch;
	infptr ip;
	while(p !=NULL && p->num==0){
		ch=word[i++];
		k=ch?ch-'A'+1:0;
		if(k<0||k>26)
			return NULL;
		p=p->ptr[k];
	}
	ip=(infptr)p;
	return p==NULL ? NULL:	strcmp(word,ip->key)==0 ? ip:NULL;
}

ins(pp,word,i)
brptr *pp;char *word;int i;
{
	char ch,ch1;
	brptr p,p1,nb(),ni();
	infptr ip;
	int k,k1;
	p=*pp;ip=(infptr)p;
	ch=word[i];
	k=ch?ch-'A'+1:0;
	if(k<0||k>26)
		error("invalid char");
	if(p==NULL)
		*pp=(brptr)ni(word);
	else if(p->num==0)
		ins(& p->ptr[k],word,i+1);
	else if(strcmp(word,ip->key)==0)
		ip->num++;
	else{
		*pp=p1=nb();
		ch1=ip->key[i];
		k1=ch1?ch1-'A'+1:0;
		p1->ptr[k1]=p;
		ins(& p1->ptr[k],word,i+1);
	}
}

brptr nb()
{
	char *malloc();
	brptr p;
	int k;
	p=(brptr)malloc(sizeof(struct bn));
	if(p==NULL)
		error("not enough memory");
	p->num=0;
	for(k=0;k<27;k++)
		p->ptr[k]=NULL;
		return p;
}

brptr ni(word)
char *word;
{
	char *pch,*malloc();
	infptr ip;
	ip=(infptr)malloc(sizeof(struct in));
	pch=malloc(strlen(word)+1);
	if(ip==NULL||pch==NULL)
		error("not enough memory");
	strcpy(pch,word);
	ip->num=1;
	ip->key=pch;
	return (brptr)ip;
}

int get(fp,str)
FILE *fp;char *str;
{
	int ch,i=0;
	while(ch=getc(fp),ch !=EOF && !isalpha(ch));
	while(isalpha(ch)){
		str[i++]=toupper(ch);ch=getc(fp);
	}
	str[i]='\0';
	return i;
}

error(str)
char *str;
{
	printf("\nerror:%s\n",str);exit(1);
}
