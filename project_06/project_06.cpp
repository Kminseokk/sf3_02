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
#include <algorithm> //소문자변환
#include <cmath>

using namespace std;

class Calculator {
public:
    static double result;

    Calculator(double n1, double n2) : num1(n1), num2(n2) {}

    virtual void performOperation() = 0;
    virtual ~Calculator() {}

protected:
    double num1;
    double num2;
};

double Calculator::result = 0.0;

class Addition : public Calculator {
public:
    Addition(double n1, double n2) : Calculator(n1, n2) {}

    void performOperation() override {
        result = num1 + num2;
    }
};

class Subtraction : public Calculator {
public:
    Subtraction(double n1, double n2) : Calculator(n1, n2) {}

    void performOperation() override {
        result = num1 - num2;
    }
};

class Multiplication : public Calculator {
public:
    Multiplication(double n1, double n2) : Calculator(n1, n2) {}

    void performOperation() override {
        result = num1 * num2;
    }
};

class Division : public Calculator {
public:
    Division(double n1, double n2) : Calculator(n1, n2) {}

    void performOperation() override {
        if (num2 != 0) {
            result = num1 / num2;
        }
        else {
            cout << "오류: 0으로 나눌 수 없습니다." << endl;
        }
    }
};

string toLower(const std::string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main() {
    Calculator* calc = nullptr;

    //double cal_Result = 0; // 굳이 필요없음. Calculator::result
    bool finish_Flag = false;
    bool calc_Flag = false;

    while (true) {
        double num1, num2;
        string user_Input;
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ " << endl;

        // 근데 result에 값이 이미 있다면 안해도되는 경우이기에 if문을 먼저 
        // 먼저 반복문 실행하고, 반복문에서 이게 숫자인지 판별하고, 그리고 나서 숫자라면, 값 넣고,,,,
        if (Calculator::result == 0) {
            while (!calc_Flag) { //트루값이 되면 반복문 종료.
                cout << "첫 번째 숫자를 입력하세요: ";
                cin >> user_Input;

                calc_Flag = true; //만약 밑에 포문을 거쳐서 숫자가 맞다면 true 유지해서 while문 종료
                for (char c : user_Input) {
                    if (!isdigit(c)) {
                        calc_Flag = false; //요기에 왔다면 숫자가 아닌 값이라는 의미.
                        break;
                    }
                }
                if (!calc_Flag) {
                    cout << "첫 번쨰 숫자에 입력한 값이 숫자가 아닙니다. 다시 입력하세요." << endl;
                }

                if (calc_Flag) { //숫자라는 의미이므로, 입력한 스트링값을 int로 바꿔서 num1에 저장
                    num1 = stoi(user_Input);
                }
            }
        }
        else {
            num1 = Calculator::result; //첫 입력 이후 재입력 받을 필요가 없으므로.
        }

        if (calc) {
            delete calc;
        } //메모리 누수 방지.

        calc_Flag = false;
        string oper;
        while (!calc_Flag) { //트루값이 되면 반복문 종료.
            cout << "연산을 선택하세요 (+, -, *, /): "; // ★★ 연산이 아닌 값을 넣었을 경우 예외 처리 해야함!!!! ★★            
            cin >> oper;

            //calc_Flag = true; //밑에 이프문을 거쳐서 연산자가 아니라면 false 넣을거임.
            if (oper == "+" || oper == "-" || oper == "*" || oper == "/" ) {
                calc_Flag = true;
            }
            else {
                cout << "연산자가 아닙니다. 다시 입력해주세요." << endl;
            }
        }

        calc_Flag = false;
        while (!calc_Flag) { //트루값이 되면 반복문 종료.
            cout << "두 번째 숫자를 입력하세요: ";
            cin >> user_Input;

            calc_Flag = true; //만약 밑에 포문을 거쳐서 숫자가 맞다면 true 유지해서 while문 종료
            for (char c : user_Input) {
                if (!isdigit(c)) {
                    calc_Flag = false;
                    break;
                }
            }
            if (!calc_Flag) {
                cout << "첫 번쨰 숫자에 입력한 값이 숫자가 아닙니다. 다시 입력하세요." << endl;
            }

            if (calc_Flag) { //숫자라는 의미이므로, 입력한 스트링값을 int로 바꿔서 num1에 저장
                num2 = stoi(user_Input);
            }
        }

        if (oper == "+") {
            calc = new Addition(num1, num2);
        }
        else if (oper == "-") {
            calc = new Subtraction(num1, num2);
        }
        else if (oper == "*") {
            calc = new Multiplication(num1, num2);
        }
        else if (oper == "/") {
            calc = new Division(num1, num2);
        }
        else {
            cout << "예상하지 못한 오류입니다. line 151." << endl;
            continue; // 다시 연산자를 선택하도록 반복
        }

        //switch (op) { op가 char 형태이면 이걸 사용할 수 있음.
        //case '+':
        //    calc = new Addition(num1, num2);
        //    break;
        //case '-':
        //    calc = new Subtraction(num1, num2);
        //    break;
        //case '*':
        //    calc = new Multiplication(num1, num2);
        //    break;
        //case '/':
        //    calc = new Division(num1, num2);
        //    break;
        //default:
        //    cout << "유효하지 않은 연산입니다." << endl;
        //    continue; // 다시 연산자를 선택하도록 반복
        //}

        if (calc) {
            calc->performOperation();
        }

        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ " << endl;
        cout << "현재 결과: " << Calculator::result << endl;
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ " << endl;
        //cal_Result = Calculator::result;

        /////////////// 현재 이부분 안됨.. 아니 왜 안댐 ㅋㅋ 
        while (1) {
            cout << "연산을 계속 하시겠습니까? (Y / AC / EXIT) : ";
            string operation;
            cin >> operation;

            if (toLower("Y") == toLower(operation)){
                //(operation == "Y" || operation == "y") {
                if (calc) {
                    calc->performOperation();
                    break;
                }
                else {
                    cout << "선택된 작업이 없습니다." << endl;
                }
            }
            else if (toLower("AC") == toLower(operation)) {
                cout << "\n값이 초기화 되었습니다.\n" << endl;
                Calculator::result = 0.0;
                delete calc;
                calc = nullptr;
                break;
            }
            else if (toLower("EXIT") == toLower(operation)){        
                    //(operation == "EXIT") {  
                    //기존의 형태에서 사용자가 뭘 입력하든 반응하도록.
                delete calc;
                finish_Flag = true; //종료 포인트를 잡기위한 깃발. 없으면 종료안함.
                break;
            }
            else {
                cout << "유효하지 않은 명령입니다." << endl;
            }
        }

        if (finish_Flag) { //종료 포인트를 잡기위한 깃발.
            break;
        }

    }

    return 0;
}
