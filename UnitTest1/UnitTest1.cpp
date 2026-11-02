#include "pch.h"
#include "CppUnitTest.h"

#define main LabProgramMain
#include "../lab_07.2IT/lab_07.2IT.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab72Tests
{
    TEST_CLASS(MatrixTests)
    {
    public:

        TEST_METHOD(TestMinInRow)
        {
            int row0[] = { 8, -4, 3, 0 };
            int row1[] = { 7, 2, 9, -6 };
            int* a[] = { row0, row1 };

            Assert::AreEqual(-4, MinInRow(a, 0, 4));
            Assert::AreEqual(-6, MinInRow(a, 1, 4));
        }

        TEST_METHOD(TestSumRowMins)
        {
            int row0[] = { 8, -4, 3, 0 };
            int row1[] = { 7, 2, 9, -6 };
            int row2[] = { 5, 1, 4, 2 };
            int* a[] = { row0, row1, row2 };

            // Мінімуми: -4, -6, 1. Сума: -9.
            Assert::AreEqual(-9, SumRowMins(a, 3, 4));
        }

        TEST_METHOD(TestSingleColumn)
        {
            int row0[] = { -5 };
            int row1[] = { 0 };
            int row2[] = { 8 };
            int* a[] = { row0, row1, row2 };

            Assert::AreEqual(3, SumRowMins(a, 3, 1));
        }
    };
}