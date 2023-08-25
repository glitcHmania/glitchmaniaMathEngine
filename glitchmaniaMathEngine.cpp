// glitchmaniaMathEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GMVector.h"
#include "GMMatrix.h"
#include "GMQuaternion.h"
#include <vector>
using namespace GMEngine;

int main()
{
    float testFloat0 = 0.0f, testFloat1 = 0.0f;
    //Please uncomment the section you want to test and the printing section below for vectors.

    //Vector Tests
        //Constructor Test
    //GMVector vec0;
    //GMVector vec1(1, 2, 3);
    //GMVector vec2(vec1);
    //GMVector vec3 = vec1;

        //Addition Test
    //GMVector vec0(1, 2, 3);
    //GMVector vec1(4, 5, 6);
    //GMVector vec2 = vec0 + vec1;
    //GMVector vec3(5, 5, 5);
    //vec3 += vec0;

        //Subtraction Test
    //GMVector vec0(1, 2, 3);
    //GMVector vec1(4, 5, 6);
    //GMVector vec2 = vec1 - vec0;
    //GMVector vec3(5, 5, 5);
    //vec3 -= vec0;

        //Scalar Multiplication Test
    //GMVector vec0(1, 2, 3);
    //GMVector vec1 = vec0 * 10.0f;
    //GMVector vec2(4, 5, 6);
    //vec2 *= 10.0f;
    //GMVector vec3(5, 5, 5);
    //vec3 *= -5.0f;

        //Scalar Divison Test
    //GMVector vec0(10, 20, 30);
    //GMVector vec1 = vec0 / 10.0f;
    //GMVector vec2(40, 50, 60);
    //vec2 /= 10.0f;
    //GMVector vec3(50, 50, 50);
    //vec3 *= -5.0f;

        //Dot Product Test
    //GMVector vec0(1, 2, 3);
    //GMVector vec1(4, 5, 6);
    //testFloat0 = vec0 * vec1;
    //GMVector vec2(1, 2, 3);
    //GMVector vec3(4, 5, 6);
    //testFloat1 = vec2.dot(vec3);

        //Cross Product Test
    //GMVector vec0(1, 2, 3);
    //GMVector vec1(4, 5, 6);
    //GMVector vec2 = vec0 % vec1;
    //GMVector vec3 = vec0.cross(vec1);

        //Magnitude And Normalization Test
    //GMVector vec0(1, 2, 3);
    //testFloat0 = vec0.getMagnitude();
    //GMVector vec1(4, 5, 6);
    //vec1.normalize();
    //GMVector vec2(7, 8, 9);
    //GMVector vec3 = vec2.getNormalized();

        //Printing
    //std::cout << "vec0 x: " << vec0.x << std::endl;
    //std::cout << "vec0 y: " << vec0.y << std::endl;
    //std::cout << "vec0 z: " << vec0.z << std::endl;
    //std::cout << "vec1 x: " << vec1.x << std::endl;
    //std::cout << "vec1 y: " << vec1.y << std::endl;
    //std::cout << "vec1 z: " << vec1.z << std::endl;
    //std::cout << "vec2 x: " << vec2.x << std::endl;
    //std::cout << "vec2 y: " << vec2.y << std::endl;
    //std::cout << "vec2 z: " << vec2.z << std::endl;
    //std::cout << "vec3 x: " << vec3.x << std::endl;
    //std::cout << "vec3 y: " << vec3.y << std::endl;
    //std::cout << "vec3 z: " << vec3.z << std::endl;
    //std::cout << "testFloat0: " << testFloat0 << std::endl;
    //std::cout << "testFloat1: " << testFloat1 << std::endl;

/////////////////////////////////////////////////////////////////////////////////////

        //Matrix Tests
    //GMMatrix mat(3, 3,{
    //    0, 0, 0,
    //    0, 0, -1,
    //    0, 1, 0 });
    //
    //GMVector vec0(0, 1, 0);
    //GMVector vec1 = mat * vec0;
    //vec1.show();

        //Quaternion Tests
    GMVector vec(0, 1, 0);
    GMVector axis(1, 0, 0);
    auto rotatedVector = vec.rotate(90, axis);
    rotatedVector.show();

    return 0;
}
