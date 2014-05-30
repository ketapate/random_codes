#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1024

void find_min(int n,int k,int a,int b,int c,int r);

using namespace std;

int main(int argc, char** argv){
	if(argc!=2){
		cout<<"USEAGE: program_name file_name\n";
		exit(1);
	}
	
	int a,b,c,r,k,n;
	FILE *fp = fopen(argv[1],"r");
	while(!feof(fp)){
		fscanf(fp,"%d,%d,%d,%d,%d,%d\n",&n,&k,&a,&b,&c,&r);
		find_min(n,k,a,b,c,r);
	}
	fclose(fp);
	return 0;
}

void find_min(int n,int k,int a,int b,int c,int r){
	/*cout<<n<<",";
	cout<<k<<",";
	cout<<a<<",";
	cout<<b<<",";
	cout<<c<<",";
	cout<<r<<"\n";
	*/
	//printf("=>%d,%d,%d,%d,%d,%d\n",n,k,a,b,c,r);
	
	//cout<<"Series for the first "<<k<<" elements is:\n";
	int m[n],m_dup[k];
	for(int i=0;i<n;i++){m[i]=0;}
	for(int i=0;i<k;i++){m_dup[i]=0;}
	
	m[0]=a;
	m_dup[0]=a;
	for(int i=1;i<k;i++){
		m[i] = (b*m[i-1] + c)%r;
		m_dup[i]=m[i];
	}
	
	/*
	for(int i=0;i<k;i++){
		cout<<m[i]<<",";
	}
	cout<<endl;
	*/
	
	
	sort(m_dup,m_dup+k);
	
	/*
	cout<<"SORTED:\n";
	for(int i=0;i<k;i++){
		cout<<m_dup[i]<<",";
	}
	cout<<endl;
	*/
	int lower,higher;
	lower = -1;
	higher = m_dup[0];
	int index = 0;
	int i=k;
	while(i<n){
//cout<<"low="<<lower<<", higer="<<higher<<", index="<<index<<endl;	
//int z;
//cin>>z;
		if(higher-lower>1){
			m[i++]=lower+1;
			
			/*
			cout<<"new m:\n";
			for(int j=0;j<i;j++){
				cout<<m[j]<<",";
			}
			cout<<endl;
			*/
			
			
			//copy new k elements in m_dup
			int start_index=i-k;
			for(int j=0;j<k;j++){m_dup[j]=m[start_index+j];}
			
			
			/*
			cout<<"new m_dup:\n";
			for(int j=0;j<k;j++){
				cout<<m_dup[j]<<",";
			}
			cout<<endl;
			*/
			
			
			sort(m_dup,m_dup+k);
			
			lower = -1;
			higher = m_dup[0];
			index = 0;			
		}
		else{
			lower = higher;			
			index++;
			if(index==i){
				higher++;
				m[i++]=higher;
				/*
				cout<<"new m:\n";
				for(int j=0;j<i;j++){
					cout<<m[j]<<",";
				}
				cout<<endl;
				*/
			}
			else{higher = m_dup[index];}
		}
	}
	
	cout<<m[n-1]<<endl;
	/*
	cout<<"REMAINING values:\n";
	for(int i=k;i<n;i++){
		cout<<m[i]<<",";
	}
	cout<<endl;
	*/
	
}
