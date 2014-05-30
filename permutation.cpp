#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1024

int factorial(int n);
void permutate(char* input,bool *used,char* output,int position,int total_count);
int Count=0;
using namespace std;

int main(int argc, char **argv){
	if(argc!=2){
		cout<<"USEAGE: program_name file_name\n";
		exit(1);
	}

	char str[MAX],output[MAX];
	bool used[MAX];
	int position=0;
	FILE *fp;
	fp = fopen(argv[1],"r");
	while(!feof(fp)){
		if(fgets(str,MAX,fp)!=NULL){
			//removing the newline character in the end
			for(int i=0;i<(int)strlen(str);i++){				
				if(isspace(str[i])){
					str[i]='\0';break;
				}
				used[i]=false;
			}
			//cout<<"=>"<<str<<"."<<"len="<<strlen(str)<<", "<<endl;			
			//sorting the input array			
			sort(str,str+strlen(str));
			//cout<<"len of string="<<strlen(str)<<", factorial="<<factorial((int)strlen(str))<<endl;
			Count=0;
			permutate(str,used,output,position,factorial((int)strlen(str)));
		}
	}
	fclose(fp);
	
	return 0;
}


void permutate(char* input,bool* used,char* output,int position,int total_count){
//cout<<"PERM for:"<<input<<","<<output<<","<<position<<endl;
//int a;
//cin>>a;
	int index=0;
	int flag=0,i=0;
	while(i<(int)strlen(input)){
		if(used[i]==false){index=i;flag=1;break;}
		i++;
	}
	if(flag==0){		
		cout<<output;
		Count++;
//cout<<"count="<<Count<<", tot="<<total_count<<endl;		
		if(Count == total_count){cout<<"\n";}
		else{cout<<",";}
	}
	
	else{
		while(index <= (int)strlen(input)-1){
			if(used[index]==true){
				index++;
			}
			else{
				output[position]=input[index];
				output[position+1]='\0';
				used[index]=true;
				permutate(input,used,output,position+1,total_count);
				used[index]=false;
				index++;
				//index=0;
			}
		}
	}
}


int factorial(int n){
	if(n==1||n==0){return 1;}
	return (n*factorial(n-1));
}

