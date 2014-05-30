#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1024

void max_beauty(char *);

using namespace std;

int main(int argc, char** argv){
	if(argc!=2){
		cout<<"USEAGE: program_name file_name\n";
		exit(1);
	}
	
	char input[MAX];
	FILE *fp;
	fp = fopen(argv[1],"r");
	while(!feof(fp)){
		fgets(input,MAX,fp);
		//cout<<"=>"<<input<<"."<<endl;
		max_beauty(input);
	}
	fclose(fp);
	
	return 0;
}

void max_beauty(char input[]){
	int L[26];
	memset(L,0,sizeof(L));
	
	int len = (int)strlen(input);
	//cout<<"input="<<input<<", LEN="<<len;
	long sum = 0;
	int index;
	for(int i=0;i<len;i++){
		//check if the character is A-Z or a-z
		if(input[i]>='A' && input[i]<='Z'){
			index = input[i]-'A';
			L[index]++;
		}
		else if(input[i]>='a' && input[i]<='z'){
			index = input[i]-'a';
			L[index]++;
		}
	}
	/*
	cout<<"count of all the letters\n";
	for(int i=0;i<26;i++){
		cout<<L[i]<<",";
	}
	*/
	const int N = sizeof(L)/sizeof(int);
	sort(L,L+N);	
	/*
	cout<<"Sorted\n";
	for(int i=0;i<26;i++){
		cout<<L[i]<<",";
	}
	*/
	//calculate the beauty value
	for(int i=26;i>=1;i--){
		if(L[i-1]==0){break;}
		sum += i*L[i-1];	//letter value multiplied with the count
	}
	cout<<sum<<endl;
}
