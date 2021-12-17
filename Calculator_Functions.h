#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "Stack2.h"

int const N = 500;
using namespace std;

bool isCorrect(char tmp[], int index)
{
    int i = 0, j = 0, k = 0, count = 0, minus = 0;
    bool key = false, key1 = false, key2 = false, key3 = false, c = false; 
    while (i < index)
    {
        if ((tmp[i] == '0' || tmp[i] == '1' || tmp[i] == '2' || tmp[i] == '3' || tmp[i] == '4' || tmp[i] == '5' || tmp[i] == '6' || tmp[i] == '7' || tmp[i] == '8' || tmp[i] == '9') && (tmp[i + 1] == '-' || tmp[i + 1] == '+' || tmp[i + 1] == '*' || tmp[i + 1] == '/' || tmp[i + 1] == '(' || tmp[i + 1] == ')' || i + 1 == index)) j++;
        if (tmp[i] == '-' || tmp[i] == '+' || tmp[i] == '*' || tmp[i] == '/') k++;
        if (tmp[i - 1] == '(' && tmp[i] == '-')minus++;

        if (tmp[i] == '(')
        {
            c = true;
            count++;
        }
        if (tmp[i] == ')' && c == true) count--;
        if (count == 0) c = false;
        i++;
    }
    if (j >= 2 && k >= 1) { key1 = true; }
    if (j == k + 1 - minus) { key2 = true; }
    if (c == false) { key3 = true; }
    if (key1 == true && key2 == true && key3 == true) { key = true; }
    return key;
}

void invers_array(char mainArray[], char tmpArray[], int index)
{
    int  j = index - 1; int i = 0, count = 0;
    for (i=0; i < index; i++)
    {
        if (mainArray[j] == ')') tmpArray[i] = '(';
        else
            if (mainArray[j] == '(') tmpArray[i] = ')';
            else
                if (mainArray[j - 1] != '(' && mainArray[j - 1] != ')' && mainArray[j - 1] != '+' && mainArray[j - 1] != '-' && mainArray[j - 1] != '*' && mainArray[j - 1] != '/' && mainArray[j] != '/' && mainArray[j] != '-' && mainArray[j] != '+' && mainArray[j] != '*' && mainArray[j - 1] != 0)
                {
                    while (mainArray[j - 1] != '(' && mainArray[j - 1] != ')' && mainArray[j - 1] != '+' && mainArray[j - 1] != '-' && mainArray[j - 1] != '*' && mainArray[j - 1] != '/' && j-1>0)
                    {
                        count++;
                        j--;
                    }
                    cout << "Count == " << count << endl;
                    int count1 =  count;
                    while (count >=0)
                    {
                        tmpArray[i+count] = mainArray[j + count];
                        count--;
                    }
                    i = i + count1;
                }
                else
                tmpArray[i] = mainArray[j];
        j--;
    }
}

bool Correct_div(int array[])
{
    if (array[0] == 0) return false;
    else return true;
}

int Prior(string a)
{
    if (a == "-" || a == "+") return 3;
    else
        if (a == "*" || a == "/") return 2;
        else
            if (a == "(" || a == ")") return 1;
            else
                return 0;
}

int input(char tmp[])
{
    ifstream in("input.txt"); int i = 0;
    while (!in.eof())
    {
        in >> tmp[i];
        i++;
    }
    return i - 1;
}

void output_result_queue(Queue& queue)
{
    ofstream result("result.txt", ios::out | ios::app);
    result << "Expression in prefix form" << endl;
    while (queue.size() != 1)
    {
        result << queue.top();
        queue.pop_back();
    }
    result << queue.top();

}

void output_array(char tmp[], int index)
{
    ofstream result("result.txt", ios::out | ios::app);
    result << "Expression in infix form: " << endl;
    for (int i = 0; i < index; i++)
        result << tmp[i];
    result << endl;

}

void converter_to_postfix(Stack& stack, Queue& queue, char tmp[], int index)
{
    ofstream protocol_out("protocol.txt", ios::out | ios::app);
    int i = 0;
    string data{};

    while (i < index)
    {
        cout << tmp[i] << " number " << i << endl;
        protocol_out << tmp[i] << " number " << i << endl;
        //1
        data = tmp[i];
        if (Prior(data) == 0 || (data=="(" && tmp[i+1]=='-'))
        {
            i++;
            cout << "Done 1" << endl;
            protocol_out << "Done 1" << endl;
            if(data == "(")
                if (queue.isEmpty()) { data = tmp[i]; i++; while (tmp[i] != '+' && tmp[i] != '/' && tmp[i] != '*' && tmp[i] != ')' && i != index) { data += tmp[i]; i++; } i++; queue.add(data, true); }

                else { data = tmp[i]; i++; while (tmp[i] != '+'  && tmp[i] != '/' && tmp[i] != '*'  && tmp[i] != ')' && i != index) { data += tmp[i]; i++; } i++; queue.push_back(data, true); }
            else
                if (queue.isEmpty()) { while (tmp[i] != '+' && tmp[i] != '-' && tmp[i] != '/' && tmp[i] != '*' && tmp[i] != '(' && tmp[i] != ')' && i != index) { data += tmp[i]; i++; } queue.add(data, false); }

                else { while (tmp[i] != '+' && tmp[i] != '-' && tmp[i] != '/' && tmp[i] != '*' && tmp[i] != '(' && tmp[i] != ')' && i != index) { data += tmp[i]; i++; } queue.push_back(data, false); }
        }
        else
            //2
            if (Prior(data) == 2 || Prior(data) == 3)
            {
                i++;
                cout << "Done 2" << endl;
                protocol_out << "Done 2" << endl;
                //2.1
                if (stack.isEmpty() || stack.top() == "(")
                {
                    cout << "Done 2.1" << endl;
                    protocol_out << "Done 2.1" << endl;
                    if (stack.isEmpty()) { stack.add(data); }

                    else { stack.push_back(data); }

                }
                else
                    //2.2
                    if (Prior(data) < Prior(stack.top()))
                    {
                        cout << "Done 2.2" << endl;
                        protocol_out << "Done 2.2" << endl;
                        stack.push_back(data);
                    }
                    else
                        //2.3
                        if (Prior(data) >= Prior(stack.top()))
                        {
                            cout << "Done 2.3" << endl;
                            protocol_out << "Done 2.3" << endl;
                            int a = Prior(stack.top());
                            while ((a <= Prior(stack.top())) && (stack.top() != "("))
                            {
                                queue.push_back(stack.top(), false);
                                queue.write();
                                cout << endl;
                                if (stack.size() == 1)
                                {
                                    stack.replacement(data); break;
                                }
                                else
                                {
                                    stack.pop_back();
                                    stack.push_back(data);
                                }
                            }
                        }
            }
            else
                //3
                if (data == "(")
                {
                    i++;
                    cout << "Done 3" << endl;
                    protocol_out << "Done 3" << endl;
                    if (stack.isEmpty()) { stack.add(data); }

                    else { stack.push_back(data); }
                }
                else
                    //4
                    if (data == ")")
                    {
                        i++;
                        cout << "Done 4" << endl;
                        protocol_out << "Done 4" << endl;
                        while (stack.top() != "(")
                        {
                            queue.push_back(stack.top(), false);
                            stack.pop_back();
                        }
                        if (stack.size() == 1) stack.clear(); else stack.pop_back();
                    }
        if (!queue.isEmpty()) queue.write(); else
        {
            cout << "empty";
            protocol_out << "empty";
        }
        cout << endl;
        protocol_out << endl;
        if (!stack.isEmpty()) stack.write(); else
        {
            cout << "empty";
            protocol_out << "empty";
        }
        cout << endl;
        protocol_out << endl;
    }
    if (!stack.isEmpty()) {
        while (stack.size() != 1)
        {
            queue.push_back(stack.top(),false);
            stack.pop_back();
        }
        queue.push_back(stack.top(), false);
    }
}

void calculator_postfix(Stack_int& stack_int, Queue& queue)
{
    ofstream protocol_out("protocol.txt", ios::out | ios::app);
    int i = 0;

    while (i < queue.size())
    {
        cout << queue.output(i) << endl;
        //1
        if (Prior(queue.output(i)) == 0 || queue.check_minus()==true)
        {
            cout << "Done 1" << endl;
            protocol_out << "Done 1" << endl;
            if (stack_int.isEmpty()) { stack_int.add(stoi(queue.output(i))); }

            else { stack_int.push_back(stoi(queue.output(i))); }
        }
        //2
        else
        if (Prior(queue.output(i)) != 0)
        {
            cout << "Done 2" << endl;
            protocol_out << "Done 2" << endl;
            int sup[2]{}; int j;
            if (stack_int.size() == 2)
            {
                sup[0] = stack_int.top();
                stack_int.pop_back();
                sup[1] = stack_int.top();
                stack_int.clear();
            }
            else
            {
                sup[0] = stack_int.top();
                stack_int.pop_back();
                sup[1] = stack_int.top();
                stack_int.pop_back();
            }
            if (queue.output(i) == "+") j = sup[1] + sup[0];
            if (queue.output(i) == "-") j = sup[1] - sup[0];
            if (queue.output(i) == "*") j = sup[1] * sup[0];
            if (queue.output(i) == "/") if (Correct_div(sup)) j = sup[1] / sup[0]; else
            {
                cout << "You can't divide by zero" << endl;
                break;
            }

            if (stack_int.isEmpty()) { stack_int.add(j); }

            else { stack_int.push_back(j); }
        }
        if (!queue.isEmpty()) queue.write(); else
        {
            cout << "empty";
            protocol_out << "empty";
        }
        cout << endl;
        protocol_out << endl;
        if (!stack_int.isEmpty()) stack_int.write(); else
        {
            cout << "empty";
            protocol_out << "empty";
        }
        cout << endl;
        protocol_out << endl;
        i++;
    }
}

