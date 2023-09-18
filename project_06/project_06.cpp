////////////////////////////////////////////////////////////////////////////
//      :: C++ 프로젝트 06 번 문제 ::
//      게산기 만들기.
//      클래스 상속, 정적 멤버, 업 캐스팅, 가상 함수를 사용하여 다음과 
//      Y : 도출된 결과를 이용한 후속 계산
//      AC : 이전 기록 초기화
//      EXIT : 종료
// 
///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>

using namespace std; // std 네임스페이스를 생략

class Calculator {
public:
    static double result;

    virtual void performOperation() = 0;
    virtual ~Calculator() {}
};

double Calculator::result = 0.0;

class Addition : public Calculator {
public:
    void performOperation() override {
        double num2;
        cout << "두 번째 숫자를 입력하세요: ";
        cin >> num2;
        result += num2;
    }
};

class Subtraction : public Calculator {
public:
    void performOperation() override {
        double num2;
        cout << "두 번째 숫자를 입력하세요: ";
        cin >> num2;
        result -= num2;
    }
};

class Multiplication : public Calculator {
public:
    void performOperation() override {
        double num2;
        cout << "두 번째 숫자를 입력하세요: ";
        cin >> num2;
        result *= num2;
    }
};

class Division : public Calculator {
public:
    void performOperation() override {
        double num2;
        cout << "두 번째 숫자를 입력하세요: ";
        cin >> num2;
        if (num2 != 0) {
            result /= num2;
        }
        else {
            cout << "오류: 0으로 나눌 수 없습니다." << endl;
        }
    }
};

int main() {
    Calculator* calc = nullptr;

    while (true) {
        double num1;
        cout << "첫 번째 숫자를 입력하세요: ";
        cin >> num1;

        if (calc) {
            delete calc;
        }
        cout << "연산을 선택하세요 (+, -, *, /): ";
        char op;
        cin >> op;

        switch (op) {
        case '+':
            calc = new Addition();
            break;
        case '-':
            calc = new Subtraction();
            break;
        case '*':
            calc = new Multiplication();
            break;
        case '/':
            calc = new Division();
            break;
        default:
            cout << "유효하지 않은 연산입니다." << endl;
            break;
        }

        if (calc) {
            Calculator::result = num1;
            calc->performOperation();
        }

        cout << "현재 결과: " << Calculator::result << endl;


        /////////////// 현재 이부분 안됨..
        cout << "작업을 선택하세요(Y / AC / EXIT) : ";
        string operation;
        cin >> operation;

        if (operation == "Y" || "y") {
            if (calc) {
                calc->performOperation();
            }
            else {
                cout << "선택된 작업이 없습니다." << endl;
            }
        }
        else if (operation == "AC") {
            Calculator::result = 0.0;
            delete calc;
            calc = nullptr;
        }
        else if (operation == "EXIT") {
            delete calc;
            break;
        }
        else {
            
        }
    }

    return 0;
}
