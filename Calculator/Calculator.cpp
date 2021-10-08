#include <iostream>
#include <string>
using namespace std;

double getOperand(string message) {
    double _value;
    string value;
    cout << message;
    cin >> value;
    try {
        _value = stod(value);
    }
    catch (invalid_argument) {
        cout << "Incorrect number!Please try again!" << endl;
        _value = getOperand(message);
    }
    catch (out_of_range) {
        cout << "Too big number!Please try again!" << endl;
        _value = getOperand(message);
    }
    return _value;
}

char getOperator(string message) {
    char value;
    cout << message;
    cin >> value;
    return value;
}

void calculate(double operand1, double operand2, char operation) {
    
    if (operand2 == 0 && operation == '/') {
        cout << "Dividing by zero!Try again!";
        exit(0);
    }
    
    switch (operation) {
        case '+': {
            cout << "Result : " << operand1 + operand2;
            break;
        }
        case '-': {
            cout << "Result : " << operand1 - operand2;
            break;
        }
        case '*': {
            cout << "Result : " << operand1 * operand2;
            break;
        }
        case '/': {
            cout << "Result : " << operand1 / operand2;
            break;
        }
        default: {
            cout << "Undefined operator!Please try again!" << endl;
            char operation = getOperator("Enter operator : ");
            calculate(operand1, operand2, operation);
        }
    }
}
   

int main()
{
    double operand1 = getOperand("Enter first operand : ");
    double operand2 = getOperand("Enter second operand : ");
    char operation = getOperator("Enter operator : ");
    calculate(operand1, operand2, operation);
}

