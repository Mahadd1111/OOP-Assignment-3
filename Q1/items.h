//Mahad Ahmed 20i0426 Header file for Items class
#include<iostream>
#include<string>
#include "categories.h"
using namespace std;

class items{
	string name;
	category c;
public:
        items() { }
	void setitems(string ,category);
	string getname();
	category getc();
};
