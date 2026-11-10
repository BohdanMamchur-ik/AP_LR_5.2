#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../AP_LR_ 5.2/AP_LR_ 5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Оголошуємо прототипи функцій із основного файлу
double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);

namespace UnitTest47
{
    TEST_CLASS(UnitTest47)
    {
    public:

        TEST_METHOD(TestFunctionA)
        {
            // Перевіряємо крок рекурсії. 
            // Якщо x = 1.0, n = 1, то множник R = -(1^2 * 1) / 3 = -1/3
            // Відповідно, нове значення 'a' має дорівнювати -0.333333
            double x = 1.0;
            int n = 1;
            double a = 1.0;

            double expected = -1.0 / 3.0;
            double actual = A(x, n, a);

            // Порівнюємо очікуваний і реальний результат з точністю 0.0001
            Assert::AreEqual(expected, actual, 0.0001);
        }

        TEST_METHOD(TestFunctionS)
        {
            // Перевіряємо загальну суму ряду для x = 0.5 з точністю 0.001
            double x = 0.5;
            double eps = 0.001;
            int n = 0;
            double s = 0;

            double actual = S(x, eps, n, s);

            // Еталонне значення беремо з вбудованої функції atan()
            double expected = atan(x);

            // Похибка порівняння має бути не більшою за наш eps (0.001)
            Assert::AreEqual(expected, actual, 0.001);
        }
    };
}