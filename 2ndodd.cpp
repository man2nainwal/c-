#include <iostream>
using namespace std;

int readnum();
void reverse(int);
void perfect(int);
int readnumEXP();

int main()
{
	int num,op;
	cout<<"Enter choice for reading number :\n1. validation loop only (default) \n2.validation loop with exception handling\n";
	cin>>op;
	switch(op)
	{
		case 2:
				num = readnumEXP();
				break;
		default:
			num = readnum();
	}
	//num = readnum();
	reverse(num);
	return 0;
}

/*
	function readnum is for taking an input in range 10-999, with only validation loop.
*/
int readnum()
{
	int num;
	while(1)
	{
		cout<<"Enter a number between 10-999 : ";
		cin>>num;
		if((num>=10) && (num<=999))
			break;
		else
			cout<<"invalid input, reenter the number:"<<endl;
	}
	return num;
}

/*
	function reverse is to reverse a value which stored in num.
*/
void reverse(int num)
{
	int rev=0,rem,temp;
	cout<<"\noriginal number is "<<num<<endl;
	while(num>=1)
	{
		rem = num%10;
		rev = (rev * 10)+ rem;
		num = num/10;
	}
	cout<<"reverse number is "<<rev<<endl;
	cout<<"\nNow checking reverse number is perfect or not ..."<<endl;
	perfect(rev);
}

/*
	function perfect is to check whether num is perfect or not.
*/
void perfect(int num)
{
	int sum=0,i=1;
	while (i < num) {
      if (num % i == 0) {
         sum = sum + i;
      }
      i++;
   }
 
   if (sum == num)
      cout << num <<" is a Perfect Number\n";
   else
      cout << num << "is Non Perfect Number\n";
}

/*
	function readnumEXP is to read number in range 10-999, with validation loop + exception handling.
*/
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