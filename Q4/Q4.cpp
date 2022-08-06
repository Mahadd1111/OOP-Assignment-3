//Mahad Ahmed 20i0426
#include<iostream>
using namespace std;
#include"array.h"
#include<stdlib.h>

//constructor
arrayint::arrayint(int n){
static int fun=0;
x=n;
a=new int [x];
        for(int i=0;i<x;i++){
        srand(i+fun);
        a[i]=rand()%10;
        fun++;
        }
}

void arrayint::print(){
        for(int i=0;i<x;i++){
        cout<<a[i]<<"\t";
        }
cout<<endl;
}

//copy array
void arrayint::copy(arrayint arr2){
for(int i=0;i<x;i++){
this->a[i]=arr2.a[i];
}
}

//make null
void arrayint::makenull(){
        for(int i=0;i<x;i++){
        a[i]=NULL;
        }
}

//initialise function
void arrayint::initialise(int n){
x=n;
a=new int[x];
        for(int i=0;i<x;i++){
        a[i]=n;
        }
}

//sum function
int arrayint::sum(){
int sum=0;
        for(int i=0;i<x;i++){
        sum+=a[i];
        }
return sum;
}

//avg function
float arrayint::average(){
float average=(float)sum()/(float)x;
return average;
}

//contains function
bool arrayint::contains(int n){
bool flag=false;
        for(int i=0;i<x;i++){
                if(a[i]==n){
                flag=true;
                }
        }
return flag;
}

//finding number at index
int arrayint::getindexof(int n){
bool flag=false;
int index;
        for(int i=0;i<x;i++){
                if(a[i]==n){
                flag=true;
                index=i;
                }
        }
        if(flag==true){
        return index;
        }
        else{
        return -1;
        }
}

//getting the element at an index
int arrayint::getelement(int n){
n=n+1;
        if(n>x){
        return -1;
        }
        else{
        return a[n-1];
        }
}

void arrayint::getsubarray(int sub[],int s,int f){
        for(int i=s;i<f+1;i++){
        sub[i]=this->a[i];
        }
        for(int i=s;i<f+1;i++){
        cout<<sub[i]<<"\t";
        }
cout<<endl;

}

//sorting the array
int* arrayint::sort(){
int temp;
        for(int p=0;p<x;p++){
                for(int i=0;i<x-1;i++){
                        if(a[i]>=a[i+1]){
                        temp=a[i];
                        a[i]=a[i+1];
                        a[i+1]=temp;
                        }
                }
        }
return a;
}

//reversing the array values
int* arrayint::reverse(){
int s=0;
int f=x-1;
int temp;
        while(s<f){
        temp=a[s];
        a[s]=a[f];
        a[f]=temp;
        s++;
        f--;
        }
return a;
}

//get pointer
int* arrayint::geta(){
return a;
}

//get size of array
int arrayint::getx(){
return x;
}

//overloading + operator
arrayint arrayint::operator+(arrayint a2){
int size=this->x + a2.getx();
arrayint obj(size);
        for(int i=0;i<this->x;i++){
        obj.a[i]=this->a[i];
        }
        for(int i1=this->x,j1=0;i1<size;i1++,j1++){
        obj.a[i1]=a2.a[j1];
        }
return obj;
}

//overloading * operator
arrayint arrayint::operator*(arrayint a2){
arrayint obj(x);
        for(int i=0;i<this->x;i++){
        obj.a[i]=this->a[i] * a2.a[i];
        }
return obj;
}

//overloading == operator
bool arrayint::operator==(arrayint a2){
bool flag=true;
        if(this->x == a2.getx()){
                for(int i=0;i<x;i++){
                        if(this->a[i]!=a2.a[i]){
                        flag=false;
                        }
                }
        }
        else{
        cout<<"ERROR: Array sizes are different"<<endl;
        return false;
        }
return flag;
}

//overloading > operator
bool arrayint::operator>(arrayint a2){
        if(this->sum()>a2.sum()){
        return true;
        }
        else{
        return false;
        }
}

int main(){
cout<<"Checking Parameterized Constructor: "<<endl;
arrayint c(5);
c.print();
cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Checking Copy function: "<<endl;
arrayint y(5);
arrayint z(5);
cout<<"Before: ";
y.print();
cout<<"Array to copy: ";
z.print();
y.copy(z);
cout<<"After: ";
y.print();
cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Checking makenull function:"<<endl;
c.makenull();
c.print();
cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Checking Initialise function with a test value 5:"<<endl;
arrayint d(5);
d.initialise(5);
d.print();
cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Checking sum function and average function:"<<endl;
arrayint m(5);
cout<<"Array is: ";
m.print();
cout<<"Sum is: "<<m.sum()<<endl;
cout<<"Average is: "<<(float)m.average()<<endl;
cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Checking if array contains the given argument as element (3 in this case)"<<endl;
cout<<"Array is: ";
m.print();
cout<<"Does it contain 3 (number to find)?"<<boolalpha<<m.contains(3)<<endl;
cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Checking at which index number given parameter (element=2) is located, if not found, it will print -1"<<endl;
arrayint b(5);
cout<<"Array is: ";
b.print();
cout<<"It is located at Index: "<<b.getindexof(2)<<endl;
cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Checking the element at a certain index (3 in this case) , if the index is invalid, it will print -1:"<<endl;
cout<<"Array is: ";
b.print();
cout<<"Element is: "<<b.getelement(3)<<endl;
cout<<"-------------------------------------------------------------------------------------"<<endl;
cout<<"Checking and getting Sub Array by sending 5 and 9 as perimeters"<<endl;
arrayint f(10);
cout<<"Array is: ";
f.print();
cout<<"Sub Array is: "<<endl;
int narr[5];
f.getsubarray(narr,5,9);
cout<<"--------------------------------------------------------------------------------------"<<endl;
cout<<"Checking sorting function"<<endl;
arrayint g(6);
cout<<"Array is: ";
g.print();
int* narr2=new int[6];
narr2=g.sort();
cout<<"Sorted Array is: ";
        for(int i=0;i<6;i++){
        cout<<narr2[i]<<"\t";
        }
cout<<endl;
cout<<"--------------------------------------------------------------------------------------"<<endl;
cout<<"Checking reversing function"<<endl;
arrayint e(6);
cout<<"Array is: ";
e.print();
int* narr3=new int[6];
narr3=e.reverse();
cout<<"Reversed Array is: ";
        for(int i=0;i<6;i++){
        cout<<narr3[i]<<"\t";
        }
cout<<endl;
cout<<"--------------------------------------------------------------------------------------"<<endl;
cout<<"Checking overloaded + operator"<<endl;
arrayint s1(5);
cout<<"Array 1 is: ";
s1.print();
arrayint s2(5);
cout<<"Array 2 is: ";
s2.print();
arrayint s3=s1+s2;
cout<<"Summed array is: ";
s3.print();
cout<<"--------------------------------------------------------------------------------------"<<endl;
cout<<"Checking overloaded * operator"<<endl;
arrayint s4(5);
cout<<"Array 1 is: ";
s4.print();
arrayint s5(5);
cout<<"Array 2 is: ";
s5.print();
arrayint s6=s4*s5;
cout<<"Multiplied array is: ";
s6.print();
cout<<"--------------------------------------------------------------------------------------"<<endl;
cout<<"Checking overloaded == operator and > operator"<<endl;
arrayint s7(5);
cout<<"Array 1 is: ";
s7.print();
arrayint s8(5);
cout<<"Array 2 is: ";
s8.print();
bool f1=(s8==s7);
bool f2=(s7>s8);
cout<<"Are they the Same?"<<boolalpha<<f1<<endl;
cout<<"Is Array1>Array2?"<<boolalpha<<f2<<endl;
cout<<"--------------------------------------------------------------------------------------"<<endl;
cout<<"PROGRAM FINISHED"<<endl;
return 0;
}


