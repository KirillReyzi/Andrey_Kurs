#include "Calculator_Functions.h"


int main()
{
    ofstream protocol_out("protocol.txt",  ios::trunc & (ios::out | ios::app));
    ofstream result("result.txt", ios::trunc);
    char tmp[N];
    int i=0;
    Stack stack;
    Queue queue;
    Stack_int stack_int;

    i=input(tmp);
    if (!isCorrect(tmp, i))
    {
        cout << "incorrect entry" << endl;
        protocol_out << "incorrect entry" << endl;
    }
    else
    {
        output_array(tmp, i);

        converter_to_postfix(stack, queue, tmp, i);

        cout << queue.size() << endl;
        protocol_out << queue.size() << endl;

        queue.write();
        queue.output_result();
        cout << endl;
        protocol_out << endl;
        stack.~Stack();
        cout << "----------------------------------------" << endl;
        protocol_out << "----------------------------------------" << endl;
        calculator_postfix(stack_int, queue);
        stack_int.output_result();
    }
}


