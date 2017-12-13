#include "stdio.h"
#include "string.h"
#define MAXTRLEN 255
typedef unsigned char SString[MAXTRLEN+1];

void StrAssign(SString &T,char *s);//���ַ���s����T��
int Index_KMP(SString S,SString T,int pos);//KMP�����ַ���λ�õ��㷨
void get_next(SString T,int next[]);
void get_nextval(SString T,int nextval[]);
void main()//��ں���
{
	SString S,T;
	char s[30];
	int n=0;
	printf("���������ַ���S\n");
	gets(s);
	StrAssign(S,s);//�Ƚ��ַ������ƺ��֪������һ������ǳ���
	printf("������ģʽ�ַ���T\n");
	gets(s);
	StrAssign(T,s);
	n=Index_KMP(S,T,1);
	printf("%d\n",n);
	if(n)
		printf("T��S�����ַ������±�λ��Ϊ%d\n",n);
	else
		printf("T����S�����ַ���");
}
int Index_KMP(SString S,SString T,int pos)//����ģʽ�ַ���T��next���������ַ���S�е�pos���ַ�֮���λ��KMP�㷨�����У�T�ǿ�
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
void get_next(SString T,int next[])//��ģʽ��T��next����ֵ����������next
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
void get_nextval(SString T,int nextval[])//��ģʽ��T��next��������ֵ����������nextval
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


void StrAssign(SString &T,char *s)//����s��T
{
	int n,i;
	n=strlen(s);//�󳤶ȣ��������㷨��Ӧ����������֪����һ������ǳ���
	T[0]=n;
	for(i=0;i<n;i++)
		T[i+1]=s[i];
}