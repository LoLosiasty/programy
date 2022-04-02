#include<iostream>
#include<math.h>
using namespace std;
long long int fib(unsigned long long int d)
{
	unsigned long long int a=1,b=1,c;
	for(unsigned long long int i=1;i<d;i++)
	{
		c=a+b;
		b=a;
		a=c;
	}
	return a;
}
unsigned long long int rekursja(unsigned long long int dlugoscprzedzialow,unsigned long long int przedzialy,unsigned long long int mozliwosci,unsigned long long int i,unsigned long long int mozliwosciprzedzialu,unsigned long long int l)
{
	if(przedzialy==1)
	{
		if(mozliwosciprzedzialu*fib(dlugoscprzedzialow)==mozliwosci)
		{
			return mozliwosci;
		}
		else
		{
			return 0;
		}
	}
	unsigned long long int a;
	for(;l<=dlugoscprzedzialow/przedzialy;l++)
	{
		a=rekursja(dlugoscprzedzialow-l,przedzialy-1,mozliwosci,i,mozliwosciprzedzialu*fib(l),l);
		if(a==mozliwosci)
		{
			return mozliwosci;
		}
		if(a==1)
		{
			return 1;
		}
	}
	return 0;	
}
int main()
{
	unsigned long long int a,b=1,c,i=1, mozliwosci,dlugosc=1;
	cin>>mozliwosci;
	if(mozliwosci<1 || mozliwosci>pow(10,18))
	{
		return 0;
	}
	for(i;i<mozliwosci;)
	{
		c=i+b;
		b=i;
		i=c;
		dlugosc++;
	}
	if(mozliwosci==i)
	{
		cout<<dlugosc;
		return 0;
	}
	else
	{
		a=mozliwosci;
		b=0;
		for(;a>=1;a/=10)
		{
			b++;
		}
		unsigned long long int dlugoscb=dlugosc;
		for(;dlugosc<=dlugoscb+b+b;dlugosc++)
		{
			for(unsigned long long int ilosczamalowanych=1,dlugoscprzedzialow=dlugosc-1,przedzialy=2;2<=(dlugosc-ilosczamalowanych)/przedzialy;dlugoscprzedzialow--,przedzialy++,ilosczamalowanych++)
			{
			
				if(pow(2,przedzialy-1)*fib(dlugoscprzedzialow-((przedzialy-1)*2))>=mozliwosci && pow(fib(dlugoscprzedzialow/przedzialy),przedzialy-(dlugoscprzedzialow%przedzialy))*pow(fib((dlugoscprzedzialow/przedzialy)+1),dlugoscprzedzialow%przedzialy)/2<=mozliwosci)
				{
					if(rekursja(dlugoscprzedzialow,przedzialy,mozliwosci,dlugoscprzedzialow,1,2)==mozliwosci)
					{
						cout<<dlugosc;
						return 0;
					}
				}
			}		
		}
		cout<<"NIE";
		return 0;		
	}
}
	

