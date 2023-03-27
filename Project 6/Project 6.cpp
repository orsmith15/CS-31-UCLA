#include <iostream>
using namespace std;
double average(int data[], int size); 
int a[] = { 1, 2, 3, 4, 5 };


int main()
{

	char* pC = NULL; // Line 1 
	pC = new char;   //      2 
	//cerr << *pC  << endl;
	*pC = 'x';       //      3 
	    //      4


	cerr << "-----------------------------" << endl;



	int c = 0;
	//declaration 
	int * pointer = &c;//a pointer requires an address, cannot be given just or an int; needs an address
	cerr <<"pointers store an address. pointer = " << pointer << endl;// pointer gets assigned an address inside the box
	cerr << " * pointer walks the arrow to the box that the pointer stores (pointers value). * pointer = " << *pointer << endl;// *pointer refers to the actual value (walking the arrow) 
	bool a= (* pointer == c);//true 
	cerr << endl << endl;
	*pointer = 5;
	cerr << "*pointer = 5 --> changes the box that the pointer points to" << endl;
	cerr << "*pointer = 5"<< endl << "c = " << c << endl << "pointer = " << pointer << endl<<"&c == pointer. &c = " << &c <<endl<< "          pointer = " << pointer <<endl<<"*pointer = " << *pointer << endl;
	cerr << "also pointers have their own addresses. pointers address is: " << &pointer << endl;



	cerr << endl << endl << endl << endl<<"---------------------------------"<<endl;
	
	
	


	int arr[4] = { 0, 1, 2, 3 };
	int* ptr = arr;
	cerr << arr << endl;
	cerr << &arr[0] << endl;
	cerr << *ptr << endl;

	*ptr = arr[1];  
	ptr += 1;// Line 1: set arr[0] to 1
	*ptr = arr[0] * 10; // Line 2: set arr[1] to 10
	cerr << "arr[1]= " << arr[1] << endl;
	
	ptr += 1;
	cerr << "ptr= " << ptr << endl;
	ptr[0] = arr[1] * 10;   // Line 3: set arr[2] to 100
	cerr << "arr[2]= " << arr[2] << endl;
	ptr[1] = 1000;          // Line 4: set arr[3] to 1000
	cerr << "arr[3]= " << arr[3] << endl;
	return(0);

}
