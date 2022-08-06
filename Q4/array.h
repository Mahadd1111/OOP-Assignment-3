//Mahad Ahmed 20i0426
#include<iostream>
using namespace std;

class arrayint{
int *a;
int x;
public:
arrayint(){

}
arrayint(int); //parameterised constructor; it should create an integer array of the given size.
void copy(arrayint); //the array passed as argument should be copied into the calling array
void makenull(); //the calling object should be cleared, i.e. all locations made empty
void initialise(int); //all values in the calling array should be initialised to the argument passed.
int sum(); //returns the sum of all values of the array
float average(); //returns the average of all values of the array
bool contains(int); //checks if the array contains the integer passed as argument
int getindexof(int); //returns the index of the integer passed as argument; if it does not exist in the array, returns -1
int getelement(int); //returns the element at the index int of the calling array.
void getsubarray(int[],int, int); //returns a sub-array of the calling array, i.e. the elements between the index given in the first and second argument. For example, getsubarray(5, 9)// should return an array of the elements between location 5 and 9 of the calling array.
int* sort(); //sorts the values in ascending order
int* reverse(); //reverses the array values
void print();
int getx();
int* geta();
arrayint operator+(arrayint);
arrayint operator*(arrayint);
bool operator==(arrayint);
bool operator>(arrayint);
};
