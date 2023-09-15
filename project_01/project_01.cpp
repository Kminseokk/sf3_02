////////////////////////////////////////////////////////////////////////////
//      :: C++ 프로젝트 01 번 문제 ::
//      서로 최소 1개에서 최대 3개의 연속된 숫자를 말하고 
//      31이라는 숫자를 말하는 사람이 지는 게임.
//          1) 사용자는 본인이 입력한 숫자만큼.
//          2) 컴퓨터는 랜덤 숫자만큼.
//          3) 단 사용자, 컴퓨터 모두 1~3사이의 개수만 가능
//
///////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main()
{
    int sum = 0; //31이 되면 
    int User_num, Computer_num; //입력 변수 값, 컴퓨터 값.
    bool User_turn = true; //사용자의 차례인지 결정해줌.

    cout << "나는 별로 안좋아하는 베스킨~ 라빈스~ 써리~ 원~ " << endl;

    while (sum < 31) {
        if (User_turn) {
            cout << "사용자 차례입니다. 1~3 사이의 숫자를 입력하세요: ";
            cin >> User_num;

            cout << "사용자가 말한 숫자!!!! " << endl;

            if (User_num < 1 || User_num > 3) {
                cout << "1에서 3 사이의 숫자만 입력할 수 있습니다." << endl;
                continue;
            }
            else {
                for (int i = 0; i < User_num; i++) {
                    sum += 1;
                    cout << sum << endl; 
                    // 한개씩 올라가듯이 출력해야 하므로 반복문에
                    // sum+1을 대입하며 하나씩 출력한다.
                }
            }            
        }
        else {
            Computer_num = rand() % 3 + 1;
            cout << "\n컴퓨터가 " << Computer_num << "개 를 말했습니다." << endl;
            cout << "사용자가 말한 숫자!!!! " << endl;

            for (int i = 0; i < Computer_num; i++) {
                sum += 1;
                cout << sum << endl;
            }
        }
        User_turn = !User_turn; 
        //트루와 참을 번갈아 가면서 값을 넣어서 사용자 컴퓨터 차례를 번갈아가며 진행.

    }

    cout << "\n";
    if (User_turn) {
        cout << "게임종료! 사용자 승리!" << endl;
    }
    else {
        cout << "게임종료! 컴퓨터 승리!" << endl;
    }

}


