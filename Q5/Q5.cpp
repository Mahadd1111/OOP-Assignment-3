//Mahad Ahmed 20i0426
#include<iostream>
using namespace std;
#include"matrix.h"

//CONSTRUCTOR
matrix::matrix(int r1,int c1){
r=r1;
c=c1;
ptr=new int*[r];//allocation for rows
        for(int i=0;i<r;i++){//allocation for columns
        ptr[i]=new int[c];
        }
}

//DESTRUCTOR
/*matrix::~matrix(){
cout<<"Destructor Called"<<endl;
        for(int i=0;i<r;i++){
        delete [] ptr[i];
        }
delete [] ptr;
}*/

//initialising matrix
void matrix::setmatrix(){
        int val1;
        for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                cout<<"Enter Row: "<<i+1<<" Column: "<<j+1<<" -> ";
                cin>>val1;
                ptr[i][j]=val1;
                cout<<endl;
                }
        }
}

//Displaying matrix
void matrix::display(){
        for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                cout<<ptr[i][j]<<"\t";
                }
        cout<<endl;
        }
}

//overloading + operator
matrix matrix::operator+(matrix m2){
if( (this->c != m2.c) or (this->r != m2.r)){
cout<<"Invalid Operation"<<endl;
matrix invalidmatrix(0,0);
return invalidmatrix;
} 
else{
matrix newmatrix(this->r,this->c);
        for(int i=0;i<this->r;i++){
                for(int j=0;j<this->c;j++){
                newmatrix.ptr[i][j]=this->ptr[i][j] + m2.ptr[i][j];
                }
        }
return newmatrix;
}

}

//overloading - operator
matrix matrix::operator-(matrix m2){
if( (this->c != m2.c) or (this->r != m2.r)){
cout<<"Invalid Operation"<<endl;
matrix invalidmatrix(0,0);
return invalidmatrix;
} 
else{
matrix newmatrix(this->r,this->c);
        for(int i=0;i<this->r;i++){
                for(int j=0;j<this->c;j++){
                newmatrix.ptr[i][j]=this->ptr[i][j] - m2.ptr[i][j];
                }
        }
return newmatrix;
}

}

//overloading * operator when multiplying matrix and scalar
matrix matrix::operator*(int n){
matrix newmatrix(this->r,this->c);
        for(int i=0;i<this->r;i++){
                for(int j=0;j<this->c;j++){
                newmatrix.ptr[i][j]=this->ptr[i][j] * n;
                }
        }
return newmatrix;
}

//overloading * operator when multiplying two matrices
matrix matrix::operator*(matrix m2){
        if(this->c!=m2.r){
        cout<<"Invalid Operation"<<endl;
        matrix invalidmatrix(0,0);
        return invalidmatrix;
        }
        else{
        matrix newmatrix(this->r,m2.c);
                for(int i=0;i<newmatrix.r;i++){
                        for(int j=0;j<newmatrix.c;j++){
                        newmatrix.ptr[i][j]=0;
                        }
                }
                for(int i = 0; i < this->r;i++){
                        for(int j = 0; j < m2.c;j++){
                            for(int k = 0; k < this->c; ++k)
                            {
                                newmatrix.ptr[i][j] += this->ptr[i][k] * m2.ptr[k][j];
                            }
                        }
                }
        return newmatrix;
        }
}

//overloading == operator
bool matrix::operator==(matrix m2){
bool flag=true;
        if(this->r!=m2.r and this->c!=m2.c){
        return false;
        }
        else{
                for(int i=0;i<this->r;i++){
                        for(int j=0;j<this->c;j++){
                                if(this->ptr[i][j]!=m2.ptr[i][j]){
                                flag=false;
                                }
                        }
                }
        }
return flag;
}

//overloading = operator
void matrix::operator=(matrix m2){
        if(this->c!=m2.c and this->r!=m2.r){
        cout<<"Invalid Operation"<<endl;
        }
        else{
                for(int i=0;i<this->r;i++){
                        for(int j=0;j<this->c;j++){
                        this->ptr[i][j]=m2.ptr[i][j];
                        }
                }
        }
}

//makes all values 0
void matrix::set0(){
        for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                ptr[i][j]=0;
                }
        }

}

//Pre increment operator
matrix matrix::operator++(){
       matrix newmatrix(this->r,this->c);
       for(int i=0;i<this->r;i++){
                for(int j=0;j<this->c;j++){
                        this->ptr[i][j]+=1;
                }
       }
       for(int i=0;i<this->r;i++){
                for(int j=0;j<this->c;j++){
                        newmatrix.ptr[i][j]=this->ptr[i][j];
                }
       }
return newmatrix;
}

//post increment operator
matrix matrix::operator++(int){
       matrix newmatrix(this->r,this->c);
       for(int i=0;i<this->r;i++){
                for(int j=0;j<this->c;j++){
                        newmatrix.ptr[i][j]=this->ptr[i][j];
                }
       }
       for(int i=0;i<this->r;i++){
                for(int j=0;j<this->c;j++){
                        this->ptr[i][j]+=1;
                }
       }
return newmatrix;
}

int main(){
int rows,cols,rows2,cols2;
cout<<"ENTERING VALUES FOR MATRIX 1: "<<endl;
cout<<"Enter Rows: ";
cin>>rows;
cout<<"Enter Columns: ";
cin>>cols;
cout<<endl;
matrix m1(rows,cols);
m1.setmatrix();
cout<<"DISPLAYING MATRIX 1: "<<endl;
m1.display();
cout<<endl;

cout<<"ENTERING VALUES FOR MATRIX 2: "<<endl;
cout<<"Enter Rows: ";
cin>>rows2;
cout<<"Enter Columns: ";
cin>>cols2;
cout<<endl;
matrix m2(rows2,cols2);
m2.setmatrix();
cout<<"DISPLAYING MATRIX 2: "<<endl;
m2.display();

cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"Checking + operator"<<endl;
matrix sum(rows,cols);
sum=m1+m2;
sum.display();
cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"Checking - operator"<<endl;
matrix diff(rows,cols);
diff=m1-m2;
diff.display();
cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"Checking * operator"<<endl;
int scalar;
cout<<"Enter Scalar: ";
cin>>scalar;
cout<<endl;
matrix mul1(rows,cols);
mul1=m1*scalar;
cout<<"Performing matrix 1 * scalar"<<endl;
mul1.display();

matrix mul2(rows2,cols2);
mul2=m2*scalar;
cout<<"Performing matrix 2 * scalar"<<endl;
mul2.display();

matrix mul3(rows,cols2);
mul3=m1*m2;
cout<<"Performing matrix 1 * matrix 2"<<endl;
mul3.display();
cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"Checking == operator"<<endl;
bool equal=(m1==m2);
cout<<"Are they equal? "<<boolalpha<<equal<<endl;
cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"Now checking the assignment operator by Copying matrix1 into a new matrix object, matrix3"<<endl;
matrix m3(rows,cols);
m3.set0();
cout<<"Displaying matrix 3"<<endl;
m3.display();
cout<<"Now Performing Matrix 3=Matrix 1"<<endl;
m3=m1;
m3.display();
cout<<"Updating Matrix one as follows"<<endl;
m1=++m1;
m1.display();
cout<<"Displaying Matrix 3 again: "<<endl;
m3.display();
cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"Performing matrix1++ "<<endl;
m1=m1++;
m1.display();
cout<<"Performing ++matrix2 "<<endl;
m2=++m2;
m2.display();
cout<<"Performing matrix3 = ++matrix1"<<endl;
m3=++m1;
cout<<"Matrix 1 is: "<<endl;
m1.display();
cout<<"Matrix 3 is: "<<endl;
m3.display();
cout<<"________________________________________________________________________________________"<<endl;
cout<<"Performing matrix3 = matrix1++"<<endl;
m3=m1++;
cout<<"Matrix 1 is: "<<endl;
m1.display();
cout<<"Matrix 3 is: "<<endl;
m3.display();
cout<<"PROGRAM ENDED SUCCESSFULLY"<<endl;
}
