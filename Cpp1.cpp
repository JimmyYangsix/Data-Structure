#include "stdio.h"
#include "string.h"
#define MAXTRLEN 255
typedef unsigned char SString[MAXTRLEN+1];

void StrAssign(SString &T,char *s);//把字符串s复制T中
int Index_KMP(SString S,SString T,int pos);//KMP找子字符串位置的算法
void get_next(SString T,int next[]);
void get_nextval(SString T,int nextval[]);
void main()//入口函数
{
	SString S,T;
	char s[30];
	int n=0;
	printf("请输入主字符串S\n");
	gets(s);
	StrAssign(S,s);//先将字符串复制后就知道，第一个存的是长度
	printf("请输入模式字符串T\n");
	gets(s);
	StrAssign(T,s);
	n=Index_KMP(S,T,1);
	printf("%d\n",n);
	if(n)
		printf("T是S的子字符串，下标位置为%d\n",n);
	else
		printf("T不是S的子字符串");
}
int Index_KMP(SString S,SString T,int pos)//利用模式字符串T的next函数在主字符串S中第pos个字符之后的位置KMP算法。其中，T非空
{
	int i,j;
	int next[10];
	i=pos;
	j=1;
	get_next(T,next);
	while(i<S[0]&&j<T[0])
	{
		if(j==0||S[i]==T[j])
		{
			i++;
			j++;
		}
		else
		{
			j=next[j];
		}
	}
	if(j>=T[0])
		return  i-T[0];
	else
		return 0;
}
void get_next(SString T,int next[])//求模式串T的next函数值并存入数组next
{
	int i,j;
	i=1;
	j=0;
	next[1]=0;
	while(i<T[0])
	{
		if(j==0||T[i]==T[j])
		{
			i++;
			j++;
			next[i]=j;
		}
		else
			j=next[j];
	}
}
void get_nextval(SString T,int nextval[])//求模式串T的next函数修正值并存入数组nextval
{
	int i,j;
	i=1;
	j=0;
	nextval[i]=0;
	while(i<T[0])
	{
		if(j==0||T[i]==T[j])
		{
			i++;
			j++;
			if(T[i]!=T[j])
				nextval[i]=j;
			else
				nextval[i]=nextval[j];
		}
		else
			j=nextval[j];
	}
}


void StrAssign(SString &T,char *s)//复制s到T
{
	int n,i;
	n=strlen(s);//求长度，可以与算法对应起来，可以知道第一个存的是长度
	T[0]=n;
	for(i=0;i<n;i++)
		T[i+1]=s[i];
}