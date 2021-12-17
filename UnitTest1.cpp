#include "pch.h"
#include "CppUnitTest.h"
#include "..//Calculator_Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(subtraction_test)
		{
			char array[] = { '9','-','7' };
			string arr1;
			string arr2;
			string arr3;
			int a{}, b{};
			Stack stack;
			Queue queue;
			Stack_int stack_int;
			converter_to_postfix(stack, queue, array, 3);
			arr1 = queue.output(0);
			arr2 = queue.output(1);
			arr3 = queue.output(2);
			if (arr1 == "9" && arr2 == "7" && arr3 == "-") a = 1;
			calculator_postfix(stack_int, queue);
			if (stack_int.top() == 2) b = 1;
			Assert::IsTrue(a + b == 2);
		}
		TEST_METHOD(complex_function_test)
		{
			char array[] = { '5', '*', '6', '+', '(', '2', '-', '9',')'};
			string arr[] = { "5","6", "*", "2","9", "-", "+" };
			int a{}, b{};
			Stack stack;
			Queue queue;
			Stack_int stack_int;

			converter_to_postfix(stack, queue, array, 9);

			for (int i = 0; i < 7; i++)
				if (arr[i] == queue.output(i)) a = 1;
				else a = 0;

			calculator_postfix(stack_int, queue);
			if (stack_int.top() == 23) b = 1;
			Assert::IsTrue(a + b == 2);
		}
	//23 + 34
		TEST_METHOD(sum_of_numbers_test)
		{
			char array[] = { '2','3','+','3','4' };
			string arr[] = { "23","34","+"};
			int a{}, b{};
			Stack stack;
			Queue queue;
			Stack_int stack_int;

			converter_to_postfix(stack, queue, array, 5);

			for (int i = 0; i < 3; i++)
				if (arr[i] == queue.output(i)) a = 1;
				else a = 0;

			calculator_postfix(stack_int, queue);
			if (stack_int.top() == 57) b = 1;
			Assert::IsTrue(a + b == 2);
		}
		//2/0
		TEST_METHOD(division_by_zero_test)
		{
			char array[] = { '2','/','0'};
			string arr[] = { "2","0","/" };
			int a{}, b{};
			Stack stack;
			Queue queue;
			Stack_int stack_int;

			converter_to_postfix(stack, queue, array, 3);

			for (int i = 0; i < 3; i++)
				if (arr[i] == queue.output(i)) a = 1;
				else a = 0;

			calculator_postfix(stack_int, queue);
			if (stack_int.top() == 0) b = 1;
			Assert::IsTrue(a + b == 2);
		}
		//18/(-9)
		TEST_METHOD(division_with_different_signs_test)
		{
			char array[] = { '1','8','/','(','-','9',')'};
			string arr[] = { "18","-9","/" };
			int a{}, b{};
			Stack stack;
			Queue queue;
			Stack_int stack_int;

			converter_to_postfix(stack, queue, array, 7);

			for (int i = 0; i < 3; i++)
				if (arr[i] == queue.output(i)) a = 1;
				else a = 0;

			calculator_postfix(stack_int, queue);
			if (stack_int.top() == -2) b = 1;
			Assert::IsTrue(a + b == 2);
		}
	};
}
