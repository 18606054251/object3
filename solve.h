#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
//��Ҫ������ǰ�����ں󣬷���Ҫ��Ϊ����� 
class solve
{
	public:
		
		void setQues(string a)
		{
			this->ques=a;
		}
		
		string getAnswer(string s)//s:�ܵ���Ŀ 
		{
			int pr;//������ָ��
			int pl;//������ָ�� 
			int i;
			//����ȥ�� 
			change=false;
			while(s.find(')',0)!=string::npos)
			{
				pr=s.find(')',0);
				pl=s.rfind('(',pr-1);
				if (s[pl-1]=='/') 
				{
					change=true;//Ԥ��5/(1/2)������ 
				} 
				setQues(s.substr(pl+1,pr-pl-1));
				init();
				s.replace(pl,pr-pl+1,count()); 
				change=false;
			}
			//�������������� 
			setQues(s);
			
			init();
			string answer=count();
			string re;
			char ch[10];
			//��Ϊ�����

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
				//Լ�� 
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
				//�ٷ��� 
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
		
		bool change;//�����ж������ŵ����� 
		
		string ques;//��ǰ�������������Ŀ 
		
		string fu;//����� 
		
		vector<int> num;//���� 
		
		//�����ŵĳ�ʼ�� ��������������ֵķ��� 
		void init(void)
		{
			//��� 
			num.clear();
			fu.clear(); 
						
			int i;
			for (i=0;i<=ques.size();i++)
			{
				
				
				if (ques[i]<'0')
				{
					//�������� 
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
		
		//�����ż��� 
		string count(void)
		{
			int p1,p2;//point
			int begin=0; 
			//�˳�����
			while(fu.find('*',begin)!=string::npos||fu.find('/',begin)!=string::npos)
			{
				p1=fu.find('*',begin);
				p2=fu.find('/',begin);
				if (p1==string::npos) p1=10000;
				if (p2==string::npos) p2=10000;
				//�˺���ǰ 
				if (p1<p2)
				{
					fu.erase(p1,1);
					//���ǰ���Ƿ��� 

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
				//������ǰ 
				else
				{
					
					//ǰ���Ƿ��� 
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



			//�Ӽ�����
			while(fu.find('+',0)!=string::npos||fu.find('-',0)!=string::npos)
			{
				p1=fu.find('+',0);
				p2=fu.find('-',0);
				if (p1==string::npos) p1=10000;
				if (p2==string::npos) p2=10000;
				//�Ӻ���ǰ
				
				if(p1<p2)
				{
					//���Ƿ��� 
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
						//�����Ƿ��� 
						if (fu[p1-1]!='/'&&fu[p1+1]!='/')
						{
							num[p1]=num[p1+1]+num[p1];
							num.erase(num.begin()+p1+1);
						
						}
						//����һ���Ƿ���
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
				//������ǰ 
				else
				{
					//���Ƿ��� 
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
						//�����Ƿ��� 
						if (fu[p2-1]!='/'&&fu[p2+1]!='/')
						{
							num[p2]=num[p2]-num[p2+1];
							num.erase(num.begin()+p2+1);
							

						}
						//����һ���Ƿ���
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
			
			//����
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


