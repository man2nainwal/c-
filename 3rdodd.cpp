#include <iostream>
using namespace std;

int readnumEXP();
void Hcf_Lcm(int , int,int *, int *);
int gcd(int ,int);

int main()
{
	int num1,num2,num3,num4,num5;
	int hcf,lcm;
	num1 = readnumEXP();
	num2 = readnumEXP();
	num3 = readnumEXP();
	num4 = readnumEXP();
	num5 = readnumEXP();
	Hcf_Lcm(num1,num2,&hcf,&lcm);
	Hcf_Lcm(num3,1,&hcf,&lcm);
	Hcf_Lcm(num4,1,&hcf,&lcm);
	Hcf_Lcm(num5,1,&hcf,&lcm);
	cout<<"two number entered are "<<num1<<" "<<num2<<endl;
	cout<<"hcf and lcm are "<<hcf<<" "<<lcm<<"respectively\n";
 	return 0;
}

void Hcf_Lcm(int a,int b,int *hcf,int *lcm)
{
	int c;
	static int x;
	if(x==0)
	{
		c=a*b;
		*hcf = gcd(a,b);
		*lcm = c/(*hcf);
		x=1;
	}
	else
	{
		c = a * (*lcm);
		b = *hcf;
		*hcf = gcd(a,b);
		b = *lcm;
		int temp = gcd(a,b);
		*lcm = c/temp;
	}
}

int readnumEXP()
{
	int num;
	while(1){

		try
		{
			cout<< "Enter a number between 10-999"<<endl;
			cin>>num;
			if((num >= 10) && (num <= 999))
				break;
			else
				throw num;
		}
		catch(int num)
		{
			cout<< "Entered number " << num<<" is invalid : "<<endl;
		}
	}
	return num;
}
int gcd(int a,int b)
{
	while(a!=b)
		{
			if(a>b)
				a=a-b;
			else
				b=b-a;
		}
		return a;
}