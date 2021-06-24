#ifndef	_MathRR_H_
#define	_MathRR_H_
#include<stdio.h>
#include <stdlib.h>
#define max 10001
extern void Ghep_cap(long nu[][max],long nam[][max],long chong[max],int n);
extern void DFS(int u,int u2,int d, int output[], int n,int *h,long a[][max]);
extern void tinhpost(int u,int d,int dd[],long a[][max],long post[], long pre[]);
extern int TPLT(int d,long a[][max],long post[]);
#endif

int check(int m, int n,int k, long chong[],long nu[][max])
{
	int i,j;
	int vt1, vt2;
	int dem=0;
	for(i=1; i<=n; i++)
	{
		if(nu[m][i]==k) {vt1 = i;dem++;}
		if(nu[m][i]==chong[m]){vt2=i;dem++;}
		if(dem==2) break;
	}
	if(vt1<vt2) return 1;
	else return -1;
}
//ghép cặp
void Ghep_cap(long nu[][max],long nam[][max],long chong[max],int n) {
int d_nam[max]={0};
int next[max]={1};
int i,j;
	for(i=1; i<= n; i++){ chong[i]=-1;next[i]=1;}
      int d=n;
	  while(d!=0)
	  {
	  	for(i=1; i<=n; i++)
	  	{
	  		if(d_nam[i]==0)
	  		{
	  			int k = next[i];
	  				if(chong[nam[i][k]]==-1)//neu ban nu chua co chong
                        {
                            d--;
                            chong[nam[i][k]]=i;//chong cua ban nu la ban nam i
                            d_nam[i]=1; // ban nam i da xet
                        }
                    else
                         {
                            if(check(nam[i][k],n,i,chong,nu)==1)
                               {
                                    int h = chong[nam[i][k]];
                                    d_nam[h]=0;
                                    chong[nam[i][k]]=i;
                                    d_nam[i]=1;
                                }
                        }
			    next[i]++;
			  }}}}
int dd[max];
//Tìm kiếm theo chiều sâu
void DFS(int u,int u2,int d, int output[], int n,int *h,long a[][max])
{ dd[u]=1;
  output[n] = u;
  if(u==u2)
  {
    *h = n;
    //printf("%d %d %d",u,output[*h], *h);
    return;
  }
  int i;
  for(i=1; i<d; i++)
  {if(dd[i]==0&&a[i][u]==1) if(*h==-1)DFS(i,u2,d,output,n+1,h,a);}
}
int clock=0;
void pref(int u,long pre[])
{
	clock++;
	pre[u]= clock;
}
void postt(int u,long post[])
{
	clock++;
	post[u]=clock;
}
void tinhpost(int u,int d,int dd[],long a[][max],long post[], long pre[])
{
  dd[u]=1;
  pref(u,pre);
  int i;
  for(i=1; i<d; i++)
  { if(dd[i]==0&&a[i][u]==1) tinhpost(i,d,dd,a,post,pre);}
  postt(u,post);
}
void DAG (int u,int d,int dd[],int* ts,long a[][max])
{
	dd[u]=1;
	(*ts)++;
    int i;
  for(i=1; i<d; i++)
  { if(dd[i]==0&&a[u][i]==1) DAG(i,d,dd,ts,a);}
}
//tìm thành phần liên thông mạnh
int TPLT(int d,long a[][max],long post[])
{
	int i,j;
    int tong=0;
    int dem =d-1;
    int dd[max]={0};
    while(dem>0)
	{
         int maxx=0;
         int k;
         int ts=0;
         for(j=1;j<d;j++) if(post[j]>maxx&&dd[j]==0) { maxx=post[j];k=j;}
         DAG(k,d,dd,&ts,a);
         tong++;
         dem=dem-ts;
    }
	return tong;

}

