#include<iostream>
#include<string>
#include<math.h>
#include<ctime>
#include <cstdlib>
#include<sstream>
#include<string.h>
#include<stdio.h>

#include"solve.h" 
#include"randomQuestion.h"
using namespace std; 

typedef pair<int,int> p;
char* first(){
	FILE* f;
	char str[10][1000];
	f=fopen("language","r");
	while(fgets(str[0],1000,f)!=NULL){
		printf("%s",str[0]); 
	}
	
	char lan[1000];
	char *a=lan;
	cin>>lan;
	fclose(f);
	
	f=fopen(lan,"r");
	while(f==NULL){
		printf("目前不支持此语言，请重新输入:");
		scanf("%s",lan);
		f=fopen(lan,"r");
	}
	return a;
}
void scan(FILE *f,int n){
	char str[10][1000];
	fgets(str[1],1000,f);
	fgets(str[2],1000,f);
	fgets(str[3],1000,f);
	fgets(str[4],1000,f);
	fgets(str[5],1000,f);
	fgets(str[6],1000,f);
	fgets(str[7],1000,f);
	fgets(str[8],1000,f);
	fgets(str[9],1000,f);
	rewind(f);
	cout<<str[n];
	
	
}
void init(FILE *f){
	
	scan(f,1);
	cout<<endl;
	
}

pair<int,int> run(FILE *fp,int n,FILE *f){
	
	solve a;
	int i;
	int wa=0,ra=0;
	string answer;
	string question;
	string ans;
	string exit("exit");
	char num[10];itoa(n,num,10);
	if (fp!=NULL){
		fputs("n=",fp);
		fputs(num,fp);
		fputs("\n",fp);
	}
	
	for (i=1;i<=n;i++){
		scan(f,2);cout<<"      "<<i<<endl<<endl;
		question=generateExpression();
		cout<<question<<endl;
		scan(f,4);
		cin>>answer;
		scan(f,5);
		ans=a.getAnswer(question);
		cout<<ans<<endl;
		if (answer==ans){
			scan(f,6);
			ra++;
			
		}
		else{
			if (answer==exit){
				break;
			}
			scan(f,7);
			wa++;
		}
		cout<<endl;
		if (fp!=NULL){
			itoa(i,num,10);
			fputs("i=",fp);
			fputs(num,fp);
			fputs("\n",fp);
			fputs(question.c_str(),fp);
			fputs("\n",fp);
			fputs(answer.c_str(),fp);
			fputs("\n",fp);
			fputs(ans.c_str(),fp);
			fputs("\n",fp);
		}
	}
	return make_pair<int,int>(ra,wa);
}
void result(FILE *f,pair<int,int> p){
	scan(f,8);cout<<p.first<<endl;
	scan(f,9);cout<<p.second<<endl;
}



int ReadFile(FILE *f){
	int n=-1;
	char c[1000];
	fgets(c,1000,f);
	n=atoi(c);
	
	return n;

}
