#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"
#include <numeric>
#include "std_lib_facilities.h"
#include <complex>
void mysqrt(double a)
{
	if(a < 0) std::cout << "Nem tudom kiszámolni a gyökét";
	else std::cout << sqrt(a) <<"\n"; 
}
int main()
{

	//1
	std::cout << "char: " << sizeof(char) << " byte\n";
    std::cout << "short: " << sizeof(short) << " byte\n";
    std::cout << "int: " << sizeof(int) << " byte\n";
    std::cout << "long: " << sizeof(long) << " byte\n";
    std::cout << "float: " << sizeof(float) << " byte\n";
    std::cout << "double: " << sizeof(double) << " byte\n";
    std::cout << "int*: " << sizeof(int*) << " byte\n";
    std::cout << "double*: " << sizeof(double*) << " byte \n";
    std::cout << "\n";
    //2

    Numeric_lib::Matrix<int> im1(10);
    Numeric_lib::Matrix<int> im2(100);
    Numeric_lib::Matrix<double> dm1(10);
    Numeric_lib::Matrix<int,2> mi12(10,10);
    Numeric_lib::Matrix<int,3> mi13(10,10,10);

    std::cout << "Matrix<int>(10): " << sizeof(im1) << " byte\n";
   	std::cout << "Matrix<int>(100): " << sizeof(im2) << " byte\n";
    std::cout << "Matrix<double>(10): " << sizeof(dm1) << " byte\n";
    std::cout << "Matrix<int,2>(10,10): " << sizeof(mi12) << " byte\n";
    std::cout << "Matrix<int,3>(10,10,10): " << sizeof(mi13) << " byte\n";
    std::cout << "\n";

    //3

    std::cout << "Matrix<int>(10): " << im1.size() << " byte\n";
    std::cout << "Matrix<int>(100): " << im2.size() << " byte\n";
    std::cout<< "Matrix<double>(10): " << dm1.size() << " byte\n";
    std::cout << "Matrix<int,2>(10,10): " << mi12.size() << " byte\n";
    std::cout << "Matrix<int,3>(10,10,10): " << mi13.size() << " byte\n";
    std::cout << "\n";

    /*4 mysqrt próba

    int a;
    while(std::cin >> a)
    {
    	mysqrt(a);
    }
    */

 	//5
    /*std::cout << "10 float\n";
    Numeric_lib::Matrix<double> dm2(10);
    for(int i = 0; i < dm2.size(); i++)
    {
    	std::cin >> dm2[i];
    }

    cout << dm2 << "\n";*/

    //6

    cout << "Add meg a dimenzókat:\n";
    int x;
    std::cin >> x;
    int y;
    std::cin >> y;
    Numeric_lib::Matrix<int,2> mi21(x,y);
    for(int i = 0; i < x; i++)
    {
    	for(int j = 0; j < y; j++)
    	{
    		if(i == 0 || j == 0) 
    			{
    				mi21(i,j) = i+j;
    			}
    		else
    		{
    			mi21(i,j) = i*j;
    		}
    		
    	}
    } 
    std::cout << mi21 << "\n";

    //7
    std::cout << "10 komp.\n";
    complex<double> cdsum = 0;
    Numeric_lib::Matrix<complex<double>> cdm(10);
    for(int i = 0; i < 10; i++)
    { 
    	std::cin >> cdm(i);
    	cdsum += cdm(i);
    }
    std::cout << cdsum << "\n"; 

    //8

    std::cout << "2x3 matrix elemek:";
    Numeric_lib::Matrix<int,2> m (2,3);
    for(int i = 0; i < 2; i++)
    {
    	for(int j = 0; j < 3; j++)
    	{
    		std::cin >> m(i,j);
    	}
    }
    std::cout << m << "\n";




}