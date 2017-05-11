#include<math.h>
#include<ctime>
#include<sstream>
#include<stdlib.h>
#include<string>

#include<string>
using namespace std;
int randomNumber(int start, int end)
{
    return start+(end-start)*rand()/(RAND_MAX + 1.0);
}

string randomOperation()
{
	int n;
	n=randomNumber(1,5);
	string aa;
	if (n==1)
	aa='+';
	if (n==2)
	aa='-';
	if (n==3)
	aa='*';
	if (n==4)
	aa='/';
	return aa;
}

string generateExpression()
{
	srand(unsigned(time(0)));
	string theQuestion;
	int num[5];
	string a_1[5];
	int i,t,k;
	
	for (i=1;i<=4;i++)
	{
		num[i]=randomNumber(1,11);
	}
	
	for (i=1;i<4;i++)
	{
		a_1[i]=randomOperation();
		
		
		
	}
	for(i=1;i<=3;i++)
	{
		if(a_1[i]=="-")
		{
			for (;num[i]<=num[i+1];)
			{
		    	num[i+1]=randomNumber(0,10);/*这里故意弄成生成0-9的随机数和条件弄成  (number[t]<number[t+1])  是防止发生1-1；10-10；等等的情况 */ 
				if (num[i]==0)
				{
					num[i]=randomNumber(1,11);/*这个if的作用是当number[t]=0时，number[t+1]最小也只是0，会陷入死循环，所以，防止number[t]=0.*/
				}
			}
		}
    }
    
    for (i=1;i<=3;i++)
    {
    	if(a_1[i]=="/")
		{	
       		double theMiddle,a,b;//这个theMiddle是用来判断除法会不会出现小数啊，之类的。
		    int theMiddle_1;
			a=(double)(num[i]);
	    	b=(double)(num[i+1]);
	    	theMiddle=a/b;
	    	theMiddle_1=(int)(theMiddle);	
			for(;theMiddle!=theMiddle_1;)
			{
				num[i+1]=randomNumber(1,11);
		   		b=(double)(num[i+1]);
		    	theMiddle=a/b;
		   		theMiddle_1=(int)(theMiddle);
			}
		}
	}
	
	a_1[4]='=';
	
	string theNumber[5];
		for(int m=1;m<=4;m++)
		{
			for (int n=0;n<=10;n++)
			{
				if (num[m]==n)
				{
	    			ostringstream oss;
			        oss << n;
		    		theNumber[m]=oss.str();
		    	}
			}
		}//将得到的int类型转化为string型。 
	
	int brackets;//brackets是括号的意思，我们一样通过随机数来确定括号。 
	brackets=randomNumber(1,20);/*如果brackets==1代表前两个数字括号；以此类推得到其他情况的括号。为了让括号出现的概率降低把随机数的范围扩大了。*/
	if (brackets==1) 
	theQuestion="("+theNumber[1]+a_1[1]+theNumber[2]+")"+a_1[2]+theNumber[3]+a_1[3]+theNumber[4]+a_1[4];
	else if (brackets==2) 
	theQuestion=theNumber[1]+a_1[1]+"("+theNumber[2]+a_1[2]+theNumber[3]+")"+a_1[3]+theNumber[4]+a_1[4];
	else if (brackets==3) 
	theQuestion=theNumber[1]+a_1[1]+theNumber[2]+a_1[2]+"("+theNumber[3]+a_1[3]+theNumber[4]+")"+a_1[4];
	else if (brackets==4) 
	theQuestion="("+theNumber[1]+a_1[1]+theNumber[2]+a_1[2]+theNumber[3]+")"+a_1[3]+theNumber[4]+a_1[4];
	else if (brackets==5) 
	theQuestion=theNumber[1]+a_1[1]+"("+theNumber[2]+a_1[2]+theNumber[3]+a_1[3]+theNumber[4]+")"+a_1[4];
	else 
	theQuestion=theNumber[1]+a_1[1]+theNumber[2]+a_1[2]+theNumber[3]+a_1[3]+theNumber[4]+a_1[4];
	
	return theQuestion;
	
}
