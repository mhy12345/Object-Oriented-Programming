#include "Matrix.h"
#include <iostream>
#include <exception>
#include <fstream>
using namespace std;

Matrix::Matrix(const char* filename)
{
	load(filename);
}

const Matrix Matrix::multiply(const Matrix &bb)const
{
	if (!mat)
		throw runtime_error("Matrix not initialize...");
	assert(this->m == bb.n);
	Matrix res(this->n,bb.m);
	for (int i=0; i<res.n; i++)
		for (int j=0; j<res.m; j++)
			for (int k=0; k<this->m; k++)
				res.mat[i*res.m+j] += mat[i*m+k] * bb.mat[k*bb.m+j];
	return res;
}

void Matrix::display()const
{
	if (!mat)
		throw runtime_error("Matrix not initialize...");
	cout<<"=======MATRIX of ("<<n<<", "<<m<<")========="<<endl;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			cout<<mat[i*m+j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}

void Matrix::display_product()const
{
	display();
}

void Matrix::load(const char* filename)
{
	if (!mat)
		free(mat),mat=NULL;
	ifstream fin(filename);
	if (!fin)
		throw runtime_error("File not found");
	fin>>n>>m;
	mat = (int*)calloc(n*m,sizeof(int));
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			fin>>mat[i*m+j];
	fin.close();
}
void Matrix::save_product(const char* filename)
{
	ofstream fout(filename);
	fout<<n<<" "<<m<<endl;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
			fout<<mat[i*m+j]<<"\t";
		fout<<endl;
	}
}
