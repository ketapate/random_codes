#include <iostream>
#include <string.h>

using namespace std;
void prime(unsigned long N);
struct List{
	unsigned long value;
	List* next;
};

int main(int args, char** argv){
	if(args!=2){cout<<"input file?\n";exit(1);}
	
	FILE *fp = fopen(argv[1],"r");
	unsigned long N;	
	char buf[1024];
	while(!feof(fp)){
		N=0;
		memset(buf,' ',1);
		fgets(buf,1024,fp);		
		if(isspace(buf[0])){continue;}
//cout<<buf;

		N = strtoul(buf,NULL,10);
//printf("N=%lu\n",N);
//cout<<N<<endl;
		if(N==0){continue;}
		prime(N);
		cout<<endl;
	}
	fclose(fp);

	return 0;
}

void prime(unsigned long N){
	List *L,*root,*prev;
	L = new List;
	L->value = 2;
	L->next = NULL;
	root=L;
        prev=L;
	unsigned long i,j;
	int not_prime_flag=0;
	for(i=3;i<N;i=i+2){
		L=root;
		not_prime_flag=0;
		while(L!=0){
			if(i%L->value == 0){not_prime_flag=1; break;}
			prev=L;
			L = L->next;
		}
		if(not_prime_flag == 0){
			L = new List;
			L->value = i;
			L->next = NULL;
			prev->next = L;
		}
	}

	//cout<<"ALL PRIMES\n";
	L = root;
	while(L->next!=0){cout<<L->value<<",";	L=L->next;}
	cout<<L->value;
	
	//freeing memory	
	prev = root;
	root = root->next;
	int count=0;
	while(prev!=0){delete prev;	prev=root;	if(root!=0){root=root->next;}}
}
