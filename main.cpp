#include"method.cpp"

//#include"randomQuestion.h"
using namespace std;

int main(int argc,char *argv[])
{	
	
	FILE *f=fopen(first(),"r");

	init(f);
	int n;
	FILE *fp=NULL;
	if (argc==3){
		fp=fopen(argv[1],"r");
		
		if(fp==NULL){
			cout<<"wrong" ;return -1;
		}
		
		n=ReadFile(fp);
		fclose(fp);
		fp=fopen(argv[2],"w");
		
		if (fp==NULL){
			cout<<"wrong";return -1;
		}
	}
	else{
		cin>>n;
	}
	cout<<endl<<n<<endl;
	pair<int,int> p;
	
	p=run(fp,n,f);
	result(f,p);
	return 0;
}
