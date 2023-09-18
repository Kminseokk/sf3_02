////////////////////////////////////////////////////////////////////////////
//      :: C++ 프로젝트 04 번 문제 ::
//      마방진 만들기
//      마방진 : 1에서 n제곱까지의 수를 정사각형으로 배열해 가로, 세로, 대각의 합계가 모두 같도록 만든 것
//      1) 1은 첫 행의 가운데에 위치한다.
//      2) 우상단으로 갈 수록 숫자가 1씩 늘어난다
//      3) 우상단으로 이동하는 도중 이미 칸이 채워져 있으면 바로 아래 칸에 다음 숫자가 채워진다
//      4) 첫번째 행에서 우상단으로 이동할 때는 마지막 행의 다음 열로 이동한다.
//      5) 마지막 열에서 우상단으로 이동할 때는 첫번째 열의 이전 행으로 이동한다.
//      6) 첫번째 행의 마지막 열에서는 우상단으로 이동하는 것이 아니라 바로 아래칸으로 이동
// 
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; // 마방진의 차수 (홀수여야 합니다)
    cout << "마방진의 차수를 입력하세요 (홀수만 가능): ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "홀수를 입력하세요." << endl;
        return 1;
    }

    // n x n 크기의 2차원 벡터를 생성하고 0으로 초기화
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    ////////// 구분선 ///////////

    int row = 0; // 행
    int col = n / 2; // 열 (첫 번째 행의 가운데 열부터 시작)

    for (int num = 1; num <= n * n; num++) {
        magicSquare[row][col] = num;

        // 다음 위치 계산 (우상단으로 이동)
        int nextRow = (row - 1 + n) % n;
        int nextCol = (col + 1) % n;

        // 다음 위치가 이미 채워져 있는 경우, 아래로 이동
        if (magicSquare[nextRow][nextCol] != 0) {
            row = (row + 1) % n;
        }
        else {
            row = nextRow;
            col = nextCol;
        }
    }

    // 마방진 출력
    cout << "마방진:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << magicSquare[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}