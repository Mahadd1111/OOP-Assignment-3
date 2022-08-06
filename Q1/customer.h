//Mahad Ahmed 20i0426 Header File for Customer class
#include<string>
#include<iostream>
#include "items.h"
using namespace std;

class customer{
	int id;
	string name;
	items past[2]; 
public:
        customer() { }
	void setcustomer(int,string,items,items);
	int getid();
	string getname();
	items getpast(int x);
};
