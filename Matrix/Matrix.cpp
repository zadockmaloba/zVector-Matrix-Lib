#include "Matrix.h"  

namespace zvlib
{

    Matrix::Matrix(Mat vals) 
    {
        this->setVal(vals);
    }
    Matrix::~Matrix() 
    {
    }
    void Matrix::setVal(Mat nVal) 
    {
        for(n_Row r : nVal){
            for(double c : r) r.push_back(c); this->push_back(r);
        }
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
            }
            //m.erase(m.begin()+2);
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
            m.erase(m.begin()+2);
            ans.push_back(m);
            m.clear();
        }
        if(ans.size() > b.size() || ans[0].size() > b[0].size()){
            int col_diff=ans[0].size()-a[0].size(), row_diff=ans.size()-a.size();
            for(int i=0; i<ans.size(); i++){    
                for(int j=0; j<col_diff; j++){
                    ans[i].pop_back();
                }
            }
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
    zvlib::Matrix matobj({{2,2},{3,3}});
    zvlib::Matrix *mtrx = new zvlib::Matrix();
    mtrx->printVec(matobj);
    zvlib::Mat a = {{2,2,2},
                    {4,4,4}};
    zvlib::Mat b = {{1,2,1},
                    {2,3,1}};

    zvlib::Mat qa ={{2,4,5},{1,4,25}};
    zvlib::Mat qb ={{13,24,15},{14,11,65}};

    zvlib::Mat na={{11,3},{7,11}};
    zvlib::Mat nb={{8,0,1},{0,3,5}};

    zvlib::Mat ans= mtrx->Multiply(nb, na);
    mtrx->printVec(ans);
    std::cout<<mtrx->Multiply(a,b)[0][0];
    delete(mtrx);
}