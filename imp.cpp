#include<iostream>
using namespace std;
int rekursja(int ilosc_x)
{
	if(ilosc_x==1 || ilosc_x==0)return 1;
	else return rekursja(ilosc_x-1)*ilosc_x;
}
int main()
{
	int ilosckrasnali;
	cin>>ilosckrasnali;
	if(ilosckrasnali<2 || ilosckrasnali>100000)	return 0;
	int	ilosc_x=0,x=1,y=1,zapamietanadlugosc[ilosckrasnali],memory[ilosckrasnali+1],uzyte[ilosckrasnali+1];
	for(int *wskaznik1=zapamietanadlugosc,*wskaznik2=memory,a,i=0;i<ilosckrasnali;i++,wskaznik1++,wskaznik2++)
	{
		*wskaznik2=0;
		memory[0]=1;
		memory[ilosckrasnali-1]=-1;
		cin>>a;
		*wskaznik1=a;
		if(uzyte[a]==2)
		{
			cout<<0;
			return 0;
		}
		if(uzyte[a]==1)	
		{
			if(*wskaznik1==*(wskaznik1-2))uzyte[a]=2;
			else return 0;
		}
		else uzyte[a]=1;
		if(*wskaznik1==*(wskaznik1-2) && i>1)
		{
			*wskaznik2=-1;
			*(wskaznik2-2)=1;
		}
	}
	memory[ilosckrasnali]=0;
	for(int *wskaznik1=zapamietanadlugosc,*wskaznik2=memory,i=0;i<ilosckrasnali;i++,wskaznik1++,wskaznik2++)
	{
		if(*wskaznik2==1 && *(wskaznik2+2)==0)
		{
			for(int *wskaznik3=&*wskaznik2,j=i;j<ilosckrasnali;j+=2,wskaznik3+=2)
			{
				if(*(wskaznik3+2)==-1)
				{
					cout<<0;
					return 0;
				}
				if(*(wskaznik3+2)==1)break;
				*(wskaznik3+2)=1;
			}
		}
		if((*(wskaznik1)!=*(wskaznik1+2)&&*(wskaznik2)==1&&*(wskaznik2+2)==-1)||(*wskaznik1!=*(wskaznik1-2) && *wskaznik1!=*(wskaznik1+2) && *(wskaznik2-2)==1 && *(wskaznik2+2)==-1))
		{
			cout<<0;
			return 0;
		}
		if(*(wskaznik1)==*(wskaznik1+2)&&i<ilosckrasnali-2)
		{
			*(wskaznik2)=1;
			*(wskaznik2+2)=-1;
		}
		if(*(wskaznik1+1)==*(wskaznik1+3)&&i<ilosckrasnali-2)
		{
			*(wskaznik2+1)=1;
			*(wskaznik2+3)=-1;
		}
		if(*(wskaznik2-1)==-1&&*(wskaznik2+1)==1|| i==0 && *(wskaznik2+1)==1)
		{
			ilosc_x++;
			continue;
		}
		if(i==0 && *(wskaznik2+1)==0||(*(wskaznik2-1)==-1 && *(wskaznik2+1)==0  && i<ilosckrasnali+1))
		{
			ilosc_x++;
			for(int *wskaznik3=&*wskaznik2,j=i;j<ilosckrasnali;j+=2,wskaznik3+=2)
			{
				if(*(wskaznik3+1)==-1)
				{
					x=1;
					ilosc_x--;
					break;
				}
				if(*(wskaznik3+1)==1) break;
				if(j==ilosckrasnali-1) x--;
				*(wskaznik3+1)=2;
				x++;
			}
		}
		y*=x;
		x=1;
	}
	cout<<rekursja(ilosc_x)*y%1000000007;
	return 0;
}
