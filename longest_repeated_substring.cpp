#include <iostream>
#include <string.h>
#define MAX 1024
using namespace std;

string trim(char buf[MAX]);

int main(int args, char **argv){
	if(args!=2){cout<<"Input file?\n";exit(1);}
	char buf[MAX],str_buf[MAX],substr_buf[MAX];
	string str,str2;
	size_t pos;
	int MAX_LEN = 0;
	string longest_substr;
	FILE *fp = fopen(argv[1],"r");
//int count=0;	
	while(!feof(fp)){
		memset(buf,'\n',1);
		fgets(buf,MAX,fp);
		MAX_LEN = 0;
		longest_substr="";
		if(buf[0]=='\n'){continue;}
//cout<<buf;

		for(int i=0;i<strlen(buf)-1;i++){
//cout<<"i="<<i<<endl;
			int j,k;
			for(j=i,k=0;j<strlen(buf);j++,k++){
				str_buf[k]=buf[j];
			}
			str_buf[k]='\0';
			str = str_buf;
//cout<<"->"<<str<<endl;
			//substring of varying lenghts
			int total_len = strlen(str_buf);
			for(int len=1;len<total_len;len++){				
				for(j=0,k=0;j<total_len;j++,k++){
					if(k>=len){break;}
					substr_buf[k] = str_buf[j];					
//cout<<"-->j="<<j<<", k="<<k<<", len="<<len<<", str_buf="<<str_buf[j]<<endl;					
				}
				substr_buf[k]='\0';
				str2 = substr_buf;
				str2 = trim(str2);
//cout<<"==>"<<str2<<endl;
				int new_pos = str2.length();
				pos = str.find(str2,new_pos);
				if(pos!=string::npos){
					if(MAX_LEN < str2.length()){
						MAX_LEN = str2.length(); 
						longest_substr = str2;
//cout<<"MAX_LEN="<<MAX_LEN<<", str="<<str2<<", new_pos="<<new_pos<<endl;						
					}
				}
			}			
		}
		if(MAX_LEN==0){cout<<"NONE\n";}
		else{
			//testing for spaces only substr
			int flag=0;
			for(unsigned int i=0;i<longest_substr.length();i++){
				if(!isspace(longest_substr[i])){flag=1;}
			}
			if(flag==0){
				cout<<"NONE";
			}
			else{				
				cout<<longest_substr;
			}
			if(!feof(fp)){cout<<endl;}
		}
		/*
		count++;
		if(count==2){goto out;}
		*/
	}
out:	
	fclose(fp);

	return 0;
}

string trim(string str){
	char buf[MAX];
	int k=0;
	//removing leading spaces
	for(unsigned int i=0;i<str.length();i++){					
		if(!isspace([i])){
			k=0;
			while(i<longest_substr.length()){
				new_sub[k++]=longest_substr[i++];
			}
			new_substr[k]='\0';
			break;
		}
	}
	
	//removinf trailing spaces
	for(unsigned int i=longest_substr.length()-1;i>=0;i--){					
		if(!isspace(substr[i])){
			k=0;
			while(i>=0){
				new_sub[k++]=longest_substr[i--];
			}
			new_substr[k]='\0';
			break;
		}
	}				
	
	str = new_buf;
	return str;
}
