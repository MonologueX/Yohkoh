#include <iostream>       
#include <vector> 
using namespace std; 
int main(void) 
{ 
	vector<int>array; 
	array.push_back(100);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(500);
	vector<int>::iterator itor;
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		if (*itor == 300)
		{
			itor = array.erase(itor);
		}
	}
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		cout << *itor << "";
	}
	return 0;
}
 


//#include <iostream>
//using namespace std;
//
//int func() 
//{ 
//	int i, j, k = 0;   
//	for (i = 0, j = -1; j = 0; i++, j++)   
//	{ 
//		k++; 
//	} 
//	return k; 
//} 
//
//int main() 
//{ 
//	cout << (func());
//	return 0;
//}
