#include <iostream>

using namespace std;

int main(){
	unsigned int i=1;
	char *c;
	c = (char*)&i;
	if(*c){cout<<"LittleEndian\n";}
	else{cout<<"BigEndian\n";}
	
	return 0;
}
