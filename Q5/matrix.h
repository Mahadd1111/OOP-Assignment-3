//Mahad Ahmed 20i0426

class matrix{
int **ptr;
int r;
int c;
public:
matrix(int,int);
//~matrix();
void setmatrix();
void display();
matrix operator+(matrix);
matrix operator-(matrix);
matrix operator*(int);
matrix operator*(matrix);
bool operator==(matrix);
void operator=(matrix);
void set0();
matrix operator++();
matrix operator++(int);
};
