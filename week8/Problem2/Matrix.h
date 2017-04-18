#ifndef MATRIX_H
#define MATRIX_H
#include <cstdlib>
#include <memory>
#include <cassert>
#include <fstream>
#include <string>
using std::string;

class Matrix
{
	private:
		int n,m;
		int *mat;
	public:
		Matrix():n(0),m(0),mat(NULL){}
		Matrix(int n,int m):n(n),m(m){
			mat = (int*)calloc(n*m,sizeof(int));
		}
		Matrix(const string &filename);
		~Matrix(){
			if (mat)
				free(mat);
		}
		const Matrix multiply(const Matrix &bb)const;//矩阵乘法
		void display_product()const;
		void display()const;
		void load(const string& filename);//从文件导入
		void save_product(const string& filename);//保存至文件
};

#endif
