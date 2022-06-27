// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "./include/Point.h"

int main( void )
{
    Point a(0 , 0);
    Point b(5 , 0);
    Point c(0 , 5);

    {
        Point point0(0 , 0);
        
        std::cout << "Is point " << point0 
                  << "   inside the triangle ]a, b, c[ ? " 
                  << ( bsp(a, b, c, point0) ? "True" : "False" ) 
                  << std::endl;
    }

    {
        Point point1(0 , 3);

        std::cout << "Is point " << point1 
                  << "   inside the triangle ]a, b, c[ ? " 
                  << ( bsp(a, b, c, point1) ? "True" : "False" ) 
                  << std::endl;
    }


    {
        Point point2(-1 , -1);

        std::cout << "Is point " << point2 
                  << " inside the triangle ]a, b, c[ ? " 
                  << ( bsp(a, b, c, point2) ? "True" : "False" ) 
                  << std::endl;
    }    
    
    {
        Point point3(10 , 10);

        std::cout << "Is point " << point3 
                  << " inside the triangle ]a, b, c[ ? " 
                  << ( bsp(a, b, c, point3) ? "True" : "False" ) 
                  << std::endl;
    }
    
    {
        Point point4(1 , 1);

        std::cout << "Is point " << point4 
                  << "   inside the triangle ]a, b, c[ ? " 
                  << ( bsp(a, b, c, point4) ? "True" : "False" ) 
                  << std::endl;
    }
    
    {
        Point point5(2 , 2);

        std::cout << "Is point " << point5 
                  << "   inside the triangle ]a, b, c[ ? " 
                  << ( bsp(a, b, c, point5) ? "True" : "False" ) 
                  << std::endl;
    }
    
    {
        Point point6(1 , 3);

        std::cout << "Is point " << point6 
                  << "   inside the triangle ]a, b, c[ ? " 
                  << ( bsp(a, b, c, point6) ? "True" : "False" ) 
                  << std::endl;
    }

    return 0;
}
