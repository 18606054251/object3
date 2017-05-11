#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
//答案要整数在前分数在后，分数要化为真分数 
class solve
{
	public:
		
		void setQues(string a)
		{
			this->ques=a;
		}
		
		string getAnswer(string s)//s:总的题目 
		{
			int pr;//右括号指针
			int pl;//左括号指针 
			int i;
			//括号去除 
			change=false;
			while(s.find(')',0)!=string::npos)
			{
				pr=s.find(')',0);
				pl=s.rfind('(',pr-1);
				if (s[pl-1]=='/') 
				{
					change=true;//预防5/(1/2)这样的 
				} 
				setQues(s.substr(pl+1,pr-pl-1));
				init();
				s.replace(pl,pr-pl+1,count()); 
				change=false;
			}
			//最后的无括号运算 
			setQues(s);
			
			init();
			string answer=count();
			string re;
			char ch[10];
			//化为真分数

     		if (fu[0]=='/')
			{

				if (num[0]%num[1]==0)
				{
					num[0]=num[0]/num[1];
					memset(ch,0,sizeof(ch));
					sprintf(ch,"%d",num[0]);
					re.append(ch);
					return re;
				}
				//约分 
				int up=num[0];
				if (num[0]<0) up=0-up;
				for( i=1;i<=up;i++)
				{

					if (num[0]%i==0&&num[1]%i==0)
					{
						num[0]=num[0]/i;
						up=up/i;
						num[1]=num[1]/i;
						i=1;
					}

				} 
				//假分数 
				if (num[0]>num[1]||-num[0]>num[1])
				{
					int pa=num[0]/num[1];
					num[0]=num[0]%num[1];
					memset(ch,0,sizeof(ch));
					sprintf(ch,"%d",pa);
					re.append(ch);
					if (num[0]>0)
					{
						re.append(1,'+');
					}
					memset(ch,0,sizeof(ch));
					sprintf(ch,"%d",num[0]);
					re.append(ch);
					re.append(1,'/');
					memset(ch,0,sizeof(ch));
					sprintf(ch,"%d",num[1]);
					re.append(ch);
					return re; 
				}
				else
				{
					memset(ch,0,sizeof(ch));
					sprintf(ch,"%d",num[0]);
					re.append(ch);
					re.append(1,'/');
					memset(ch,0,sizeof(ch));
					sprintf(ch,"%d",num[1]);
					re.append(ch);
					return re;
				}
			}
			 
			return answer;
		}
		
		solve (void)
		{
			
		}
		
		bool change;//用来判断有括号的连除 
		
		string ques;//当前运算的无括号题目 
		
		string fu;//运算符 
		
		vector<int> num;//数字 
		
		//无括号的初始化 进行运算符和数字的分离 
		void init(void)
		{
			//清空 
			num.clear();
			fu.clear(); 
						
			int i;
			for (i=0;i<=ques.size();i++)
			{
				
				
				if (ques[i]<'0')
				{
					//运算符添加 
					if (ques[i]=='*')
					{
						fu.append(1,'*');
						
					}
					if (ques[i]=='/')
					{
						fu.append(1,'/');
						
					}
					if (ques[i]=='+')
					{
						fu.append(1,'+');
						
					}
					if (ques[i]=='-')
					{
						fu.append(1,'-');
						
					}
				}
				else
				{
					
					string shu; 
					 
					while (ques[i]>='0')
					{
						shu.append(1,ques[i]);
						i++; 
					}
					i--;
					num.push_back(atoi(shu.c_str()));	
					
				}
			}
			
		} 
		
		//无括号计算 
		string count(void)
		{
			int p1,p2;//point
			int begin=0; 
			//乘除运算
			while(fu.find('*',begin)!=string::npos||fu.find('/',begin)!=string::npos)
			{
				p1=fu.find('*',begin);
				p2=fu.find('/',begin);
				if (p1==string::npos) p1=10000;
				if (p2==string::npos) p2=10000;
				//乘号在前 
				if (p1<p2)
				{
					fu.erase(p1,1);
					//如果前面是分数 

					if (p1!=0&&fu.at(p1-1)=='/')
					{
						num[p1-1]=num[p1-1]*num[p1+1];
						num.erase(num.begin()+p1+1); 
					}
					else
					{
						num[p1]=num[p1]*num[p1+1];
						num.erase(num.begin()+p1+1);
					} 
				}
				//除号在前 
				else
				{
					
					//前面是分数 
					if (p2!=0&&fu.at(p2-1)=='/')
					{
						num[p2]=num[p2]*num[p2+1];
						num.erase(num.begin()+p2+1); 
						fu.erase(p2,1);
					}
					else
					{
						begin=p2+1;
						
					} 
				}
			}



			//加减运算
			while(fu.find('+',0)!=string::npos||fu.find('-',0)!=string::npos)
			{
				p1=fu.find('+',0);
				p2=fu.find('-',0);
				if (p1==string::npos) p1=10000;
				if (p2==string::npos) p2=10000;
				//加号在前
				
				if(p1<p2)
				{
					//都是分数 
					if (p1!=0&&p1!=fu.size()-1&&fu.at(p1-1)=='/'&&fu.at(p1+1)=='/')
					{
						

						num[p1-1]=num[p1-1]*num[p1+2]+num[p1]*num[p1+1];
						num[p1]=num[p1]*num[p1+2]; 
						num.erase(num.begin()+p1+1);
						num.erase(num.begin()+p1+1);
						fu.erase(p1,1);
						fu.erase(p1,1);
					}
					else
					{
						//都不是分数 
						if (fu[p1-1]!='/'&&fu[p1+1]!='/')
						{
							num[p1]=num[p1+1]+num[p1];
							num.erase(num.begin()+p1+1);
						
						}
						//其中一个是分数
						if (fu[p1-1]=='/')
						{
							num[p1-1]=num[p1-1]+num[p1]*num[p1+1];
							num.erase(num.begin()+p1+1);
							
						}
						if (fu[p1+1]=='/')
						{
							num[p1+1]=num[p1+1]+num[p1]*num[p1+2];
							num.erase(num.begin()+p1);
							
						} 
						fu.erase(p1,1);
					}

				}
				//减号在前 
				else
				{
					//都是分数 
					if (p2!=0&&p2!=fu.size()-1&&fu.at(p2-1)=='/'&&fu.at(p2+1)=='/')
					{
						num[p2-1]=num[p2-1]*num[p2+2]-num[p2]*num[p2+1];
						num[p2]=num[p2]*num[p2+2];

						num.erase(num.begin()+p2+1);
						num.erase(num.begin()+p2+1);
						fu.erase(p2,1);
						fu.erase(p2,1); 
					}
					else
					{
						//都不是分数 
						if (fu[p2-1]!='/'&&fu[p2+1]!='/')
						{
							num[p2]=num[p2]-num[p2+1];
							num.erase(num.begin()+p2+1);
							

						}
						//其中一个是分数
						if (fu[p2-1]=='/')
						{
							num[p2-1]=num[p2-1]-num[p2]*num[p2+1];
							num.erase(num.begin()+p2+1);
							
						}
						if (fu[p2+1]=='/')
						{
							num[p2+1]=num[p2]*num[p2+2]-num[p2+1];

							num.erase(num.begin()+p2);
							
						}
						fu.erase(p2,1); 
					}
				}
				
			} 
			
			//返回
			string re;
			char ch[10];
			memset(ch,0,sizeof(ch));
			sprintf(ch,"%d",num[0]);
			re.append(ch);
			if(fu[0]=='/') 
			{
				if (change)
				{
					re.append(1,'*');
				}
				else
				{
					re.append(1,'/');
				}
				char pa[10];
				memset(pa,0,sizeof(pa));
				sprintf(pa,"%d",num[1]);
				re.append(pa);
			}
			return re;
		}
}; 


