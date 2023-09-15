////////////////////////////////////////////////////////////////////////////
//      :: C++ 프로젝트 02 번 문제 ::
//      타임어택 끝말잇기 게임
//      1) 제한 시간 30초 동안 플레이어는 끝말잇기 규칙에 따라 단어를 입력
//      2) 제한 시간이 종료되면 게임을 종료 시키고, 입력한 단어의 개수를 출력
//      3) 단, 한번 입력된 단어는 입력하지 못하게 하기
//
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>


using namespace std;

int main()
{
    srand(time(0));
    const int timeLimit = 30; // 30초 제한을 걸어둘 조건
    time_t startTime = time(nullptr);
    string lastWord = "airplane"; // 게임 시작 단어를 정의합니다.
    vector<string> usedWords; // 사용된 단어 목록을 저장하는 벡터

    usedWords.push_back(lastWord);
    cout << "시작 단어: " << lastWord << endl;
    cout << "\n";

    while (true) {
        time_t currentTime = time(nullptr);
        int elapsedTime = currentTime - startTime;

        if (elapsedTime >= timeLimit) {
            cout << "시간이 초과되었습니다!" << endl;
            break;
        }

        for (int i = 0; i < usedWords.size(); i++) {
            cout << usedWords[i];
            if (i < usedWords.size() - 1) {
                cout << " > ";
            }
        }

        cout << "\n낱말을 입력하세요: ";

        string inputWord;
        cin >> inputWord;

        cout << "\n";

        if (inputWord.empty() || inputWord.front() != lastWord.back()) {
            cout << "올바른 단어를 입력하세요!" << endl;
            continue;
        }

        // 단어 목록을 직접 확인하여 중복된 단어를 검사합니다.
        bool isRepeated = false;
        for (const string& usedWord : usedWords) {
            if (inputWord == usedWord) {
                isRepeated = true;
                break;
            }
        }

        if (isRepeated) {
            cout << "이미 사용된 단어입니다!" << endl;
            continue;
        }

        // 게임에서 사용할 추가적인 단어 유효성 검사를 수행할 수 있습니다.

        usedWords.push_back(inputWord); // 사용된 단어를 목록에 추가
        lastWord = inputWord;
    }


}
