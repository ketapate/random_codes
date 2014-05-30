#include <iostream>
#include <stdio.h>
#define MAX 4
using namespace std;

long reverse(long N);
int isPalindrome(long N);

int main(int args, char **argv)
{
   if(args!=2){cout<<"input file?\n";exit(1);}
  
   long N;
   int iterations = -1;
   int palindrome = -1;
   long sum = 0;
   FILE *fp = fopen(argv[1],"r");
   
   if(!fp){cout<<"Couldn't open the file\n";exit(1);}

   while(!feof(fp)){
		sum = 0;
		iterations = 0;
		N=-1;
		fscanf(fp,"%ld",&N);		
		if(N<10000){

			long NN=N;
			while(iterations<=100){

				if(N<0){iterations=101;break;}
				sum = N + reverse(N);
//cout<<"N="<<N<<", reverse N="<<reverse(N)<<", sum="<<sum<<endl;
				//if(sum<0){iterations=101; break;}
				int ret = isPalindrome(sum);
				
				iterations++;
				if(ret==-1){N=sum;}
				else{break;}
			}
			if(iterations>100){//cout<<"No Palindrome found for "<<NN<<endl;continue;
			}
			else{cout<<iterations<<" "<<sum<<endl;}
		}
   }
   
   fclose(fp);
   
   return 0;
}

long reverse(long N){
//cout<<"IN REVERSE for N="<<N<<endl;
	//int neg_flag=0;
	//if(N<0){neg_flag=1;N*=-1;}
    long ret;
    char buf[20];
    int i=0;
//cout<<"REVERSE of N="<<N;
    while(N>0){
        int temp = N%10;
		char buffer[2];
		sprintf(buffer,"%d",temp);
		buf[i++] = buffer[0];
        N = N/10;
    }
	buf[i]='\0';
//cout<<" is "<<buf<<endl;

	ret = atol(buf);
	//if(neg_flag==1){ret*=-1;}
	return ret;
}

int isPalindrome(long N){
//cout<<"IN palindrome for sum="<<N<<endl;
	//int neg_flag=0;
	//if(N<0){neg_flag=1;N*=-1;}
	int digit[20];
	int i=0;
	while(N>0){
		digit[i++]=N%10;
		N=N/10;
	}
	//palindrome for 2 or more digits only
	if(i==1){return -1;}
	
	i--;
	int palindrome_flag=1;
	//compare the digits - outer to inner 
	for(int a=0,b=i;b>i/2;b--,a++){
		//N not palindrome
		if(digit[a] != digit[b]){palindrome_flag=0;return -1;}
	}
	//yes N is palindrome 
	return 1;
	
}
