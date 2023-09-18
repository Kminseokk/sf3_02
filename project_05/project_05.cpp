////////////////////////////////////////////////////////////////////////////
//      :: C++ 프로젝트 05 번 문제 ::
//      야구 게임
//      숫자의 자리와 값이 모두 같으면 strike
//      자리는 다르지만 3개의 숫자 중 포함 되어 있으면 ball
// 
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// 1부터 9까지의 서로 다른 난수 3개를 생성하는 함수


vector<int> Computer_num() {
    // 1부터 9까지의 서로 다른 난수 3개를 생성하는 함수

    vector<int> randomNumbers;
    while (randomNumbers.size() < 3) {
        int num = rand() % 9 + 1;
        if (find(randomNumbers.begin(), randomNumbers.end(), num) == randomNumbers.end()) {
            randomNumbers.push_back(num);
        }
    }

    return randomNumbers;
}
int main()
{
    srand(time(NULL));

    vector<int> computerNumbers = Computer_num();
    cout << "컴퓨터가 1부터 9까지의 서로 다른 숫자 3개를 생성했습니다." << endl;

    // 벡터의 모든 요소를 출력합니다.
    cout << "컨닝페이퍼 : ";
    for (auto it = computerNumbers.begin(); it != computerNumbers.end(); ++it) {
        cout << * it << " ";
    }
    cout << "\n\n";
    int attempts = 0; //시도 횟수요

    while (1) {
        vector<int> User_number; //유저가 만드는 번호
        cout << "3개의 숫자를 입력하세요 (1부터 9까지 중복 없이): " << endl;

        for (int i = 0; i < 3; i++) {
            cout << i+1 << "번 째 숫자를 입력해주세요. ";
            int num;
            cin >> num;

            if (num < 1 || num > 9 || find(User_number.begin(), User_number.end(), num) != User_number.end()) {
                //입력 값이 1보다 작거나, 9보다 크거나, 중복값이 있으면 잘못됨.
                cout << "잘못된 입력입니다. 다시 입력하세요. 중복되었는지 혹은 범위를 초과하였는지. \n" << endl;
                i--;
                continue;
            }
            User_number.push_back(num);
        }

        int strike = 0;
        int ball = 0;

        for (int i = 0; i < 3; i++) {
            if (User_number[i] == computerNumbers[i]) { //위치랑 숫자 일치하면 스트라이크.
                strike++;
            }
            else if (find(computerNumbers.begin(), computerNumbers.end(), User_number[i]) != computerNumbers.end()) {
                ball++; //그냥 값만 일치하면 볼.
            }
        }

        cout << "결과: " << strike << " 스트라이크, " << ball << " 볼" << endl;
        attempts++;

        if (strike == 3) {
            cout << " ****정답을 맞추셨습니다. \n **** 시도 횟수: " << attempts << endl;
            break;
        }

    }


}


