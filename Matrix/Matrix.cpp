#include "Matrix.h"  

namespace zvlib
{
    Matrix::Matrix() 
    {
    }
    Matrix::~Matrix() 
    {
    }
    Mat Matrix::Add(Mat& a, Mat& b) 
    {
        ans.clear();
        Mat y;
        std::vector<double> m;
        if( a.size()>=b.size() && a[0].size()>=b[0].size()){
            for(int i =0 ; i<a.size(); i++)//number of rows
            {
                for(int j=0; j<a[i].size(); j++)//number of columns
                {
                    m.push_back(a[i][j] + b[i][j]);
                }
                ans.push_back(m);
                m.clear();
            }
        }
        else if(a.size()<b.size() || a[0].size()<b[0].size()){
            for(int i =0 ; i<b.size(); i++)//number of rows
            {
                for(int j=0; j<b[i].size(); j++)//number of columns
                {
                    m.push_back(a[i][j] + b[i][j]);
                }
                ans.push_back(m);
                m.clear();
            }
        }
        ans.shrink_to_fit();
        return ans;
    }
    Mat Matrix::Subtract(Mat& a, Mat& b) 
    {
        ans.clear();
        Mat y;
        std::vector<double> m;
        if( a.size()>=b.size() && a[0].size()>=b[0].size()){
            for(int i =0 ; i<a.size(); i++)//number of rows
            {
                for(int j=0; j<a[i].size(); j++)//number of columns
                {
                    m.push_back(a[i][j] - b[i][j]);
                }
                ans.push_back(m);
                m.clear();
            }
        }
        else if(a.size()<b.size() || a[0].size()<b[0].size()){
            for(int i =0 ; i<b.size(); i++)//number of rows
            {
                for(int j=0; j<b[i].size(); j++)//number of columns
                {
                    m.push_back(a[i][j] - b[i][j]);
                }
                ans.push_back(m);
                m.clear();
            }
        }
        ans.shrink_to_fit();
        return ans;
    }
    Mat Matrix::Multiply(Mat& a, Mat& b) 
    {
        ans.clear();
        Mat y;
        std::vector<double> m;
        for(int i =0 ; i<a.size()-1; i++)//number of rows
        {
            for(int j=0; j<a[i].size()-1; j++)//number of columns
            {
                   m.push_back((a[i][j] * b[i][j]) + (a[i][j+1] * b[i+1][j]));
                   m.push_back((a[i][j] * b[i][j+1]) + (a[i][j+1] * b[i+1][j+1]));
                   if(m[j] == m[~j]) ;
            }
            //m.push_back((a[i][~1] * b[i][2]) + (a[i][2+1] * b[i+1][2]));
            ans.push_back(m);
            m.clear();
        }
        for(int i =0 ; i<a.size()-1; i++)//number of rows
        {
            for(int j=0; j<a[i].size()-1; j++)//number of columns
            {
                   m.push_back((a[i+1][j] * b[i][j]) + (a[i+1][j+1] * b[i+1][j])); 
                   m.push_back((a[i+1][j] * b[i][j+1]) + (a[i+1][j+1] * b[i+1][j+1]));
            }

            ans.push_back(m);
            m.clear();
        }
        ans.shrink_to_fit();
        return ans;
    }

    Mat Matrix::Divide(Mat& a, Mat& b) 
    {
        return ans;
    }
    void Matrix::printVec(Mat& b) 
    {
        for(int i=0; i<b.size(); i++)//number of rows
        {
            std::cout<<"| ";
            for(int j=0; j<b[i].size(); j++)//number of columns
            {
                std::cout<<b[i][j]<<", ";
            }std::cout<<"|";
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }    
    bool Matrix::isUnit(Mat& a) 
    {
        if(a.size()==2 && a[0].size()==2)
        {
            if (( (a[0][0]*a[1][1])-(a[1][0]*a[0][1]) ) == 1)
            {
                return true;
            }
        }
        else std::cout<<"[WARNING]Can only test for a 2x2 Matrix \n";
        return false;
    }
    Mat Matrix::scalarMul(Mat& a, int b) 
    {
        ans.clear();
        std::vector<double> m;
        for(int i =0 ; i<a.size(); i++)//number of rows
        {
            for(int j=0; j<a[i].size(); j++)//number of columns
            {
                m.push_back(a[i][j] * b);
            }
            ans.push_back(m);
            m.clear();
        }
        ans.shrink_to_fit();
        return ans;
    }
    Mat Matrix::scalarDiv(Mat& a, int b) 
    {
        ans.clear();
        Mat y;
        std::vector<double> m;
        for(int i =0 ; i<a.size(); i++)//number of rows
        {
            for(int j=0; j<a[i].size(); j++)//number of columns
            {
                if(a[i][j] != 0){
                    m.push_back(a[i][j] / b);
                }
                else { m.push_back(0);}
            }
            ans.push_back(m);
            m.clear();
        }
        ans.shrink_to_fit();
        return ans;
    }
}//namespace zvlib

int main()
{
    zvlib::Matrix *mtrx = new zvlib::Matrix();
    zvlib::Mat a = {{2,2,2},
                    {4,4,4}};
    zvlib::Mat b = {{1,2,1},
                    {2,3,1}};

    zvlib::Mat ans= mtrx->Multiply(a, b);
    mtrx->printVec(ans);
    std::cout<<mtrx->Multiply(a,b)[0][0];
    delete(mtrx);
}