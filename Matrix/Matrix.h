#pragma once
#include <vector>
#include <list>
#include <iostream>
#include <stdlib.h>


namespace zvlib
{
	// A 2D matrix object created by the STL Vector class
	typedef std::vector<std::vector<double>> Mat; 
	typedef std::vector<double> n_Row;
	typedef long double zVal;
	class Matrix  : public Mat
	{
		private:
			const std::vector<std::vector<double> > uVec = {{1,0},{0,1}};
			Mat ans;
		
		//public: //public data types
		
		public://public methods
			Matrix(Mat vals = {{1,0},{0,1}});
			~Matrix();
			Mat Add(Mat& a, Mat& b);
			Mat Subtract(Mat& a, Mat& b);
			Mat Multiply(Mat& a, Mat& b);
			Mat Divide(Mat& a, Mat& b);
			void printVec(Mat& b);
			bool isUnit(Mat& a);
			Mat scalarMul(Mat& a, int b);//Function for multiplying the matrix by a scalar
			Mat scalarDiv(Mat& a, int b);//Function for dividing the matrix by a scalar
			void setVal(Mat nVal);
	};
} // namespace zvlib
