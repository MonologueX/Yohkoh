#include<iostream> 
using namespace std; 
class Sample
{ 
public:  
	Sample(int x)
	{
		p = &x;
	}  
	~Sample()
	{   
		if(p) 
			delete p;  
	}  
	int show()
	{   
		return *p;  
	} 
private:  
	int* p; 
}; 

int main()
{ 
	Sample S(5); 
	cout<<S.show()<<endl; 
	return 0; 
}

//#include <iostream>
//#include <stdio.h>
//
//struct A
//{ 
//	unsigned a : 19; 
//	unsigned b : 11;    
//	unsigned c : 4; 
//	unsigned d : 29;   
//	char index; 
//};
//
//int main()
//{
//	int size = sizeof(struct A);
//	int a[] = { 1, 2, 3, 4 }; 
//	int *b = a; 
//	*b += 2; 
//	*(b + 2) = 2; 
//	b++; 
//	printf("%d, %d\n", *b, *(b + 2));
//	return 0;
//}

