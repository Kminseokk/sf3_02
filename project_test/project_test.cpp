#include<iostream>
#include<stdio.h> 
#include<vector>
#include<windows.h> //좌표 핸들러 사용
#include<conio.h> //_getch가 포함되어있는 헤더

// ★★★★ 키보드 값 정의 ★★★★ //
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 // 선택하는 거


void gotoxy(int, int);  // 좌표찍기
int MenuDraw();        // 게임시작 등등 버튼 생성 함수
int keyControl();       // 키보드 입력 값 컨트롤 함수
void infoGame();        //게임정보 출력

using namespace std;

void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오고
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

class MainMenu {
public:
    MainMenu() {
        cout << "\n\n\n\n";
        cout << "\t\t"; cout << "@@@@@@@      @     @     @@@@@@@     @@@@@@@      @@@@@@@         \n";
        cout << "\t\t"; cout << "      @      @     @@    @      @    @      @    @                \n";
        cout << "\t\t"; cout << "      @      @     @     @      @    @      @   @                 \n";
        cout << "\t\t"; cout << "      @      @@@@  @@    @     @     @     @    @     @@@@        \n";
        cout << "\t\t"; cout << "      @        @@@@      @@@@@@      @@@@@@     @        @        \n";
        cout << "\t\t"; cout << "      @       @    @     @     @     @          @       @@        \n";
        cout << "\t\t"; cout << "              @    @     @      @    @           @     @ @        \n";
        cout << "\t\t"; cout << "@@@@@@@@       @@@@      @       @   @            @@@@@  @        \n";
        cout << "\t\t"; cout << "              조작방법 W A S D / 결정 : 스페이스바                \n";

        //cout << "\t\t"; cout << "            게임을 시작하려면 아무키나 누르세요.\n\n\n\n\n";
        //cout << "\t\t"; cout << "       나는 아무생각이 없다 아무런 생각이 없기 때문이다.\n";
        //getchar(); // 아무키 입력 기다림
        //system("cls"); // 콘솔 창 clear
    }
};

int MenuDraw() {
    // 임시 테스트 위치 파악 용도로 사용!
    //gotoxy(2, 2);
    //printf("2, 2 위치입니다.");
    // 임시 테스트 위치 파악 용도로 사용함!
    // [ 이동방향 ]
    // 왼쪽 : x감소
    // 오른 : x증가
    // 아래 : y증가
    // 위쪽 : y감소

    int x = 36;
    int y = 15;
    gotoxy(x-2, y); // 35 , 15
    printf(">  게임 시작 "); //다른 애들보다 x값이 작은건 > 때문에 자연스럽게 보일려고
    gotoxy(x, y+1); // 36 , 16
    printf(" 게임 정보 ");
    gotoxy(x, y+2); // 36, 17
    printf(" 게임 종료");

    while (1) {
        int n = keyControl(); //키값 받기
        switch (n) {
            case UP: {
                if (y > 15) {
                    gotoxy(x-2, y);
                    printf(" ");
                    gotoxy(x-2, --y);
                     printf(">");
                 }
                  break;
              }
             case DOWN: {
                if (y < 17) {
                    gotoxy(x-2, y);
                    printf(" ");
                    gotoxy(x-2, ++y);
                    printf(">");
                }
                break;
            }
            case SUBMIT: {
                return y - 15; // 시작 위치를 빼서 메뉴 선택을 0 , 1 , 2 값으로 좁힘.
            }
        }//스위치문 닫는 곳

    }
}

int keyControl() {
    char temp = _getch(); //입력한 값이 콘솔창에 안나오고 바로 받아짐. 헤더추가 필수

    if (temp == 'w' || temp == 'W') {
        return UP;
    }
    else if (temp == 'a' || temp == 'A') {
        return LEFT;
    }
    else if (temp == 's' || temp == 'S') {
        return DOWN;
    }
    else if (temp == 'd' || temp == 'D') {
        return RIGHT;
    }
    else if (temp == ' ') {
        return SUBMIT;
    }

}

void infoGame() {
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t"; cout << "one, two, three 밤이 깊어져 단둘이 밤이 길어져 \n";
    cout << "\t\t"; cout << "열두시가 뭐가 문제야 일낼라 해, 일낼라 해 \n";
    cout << "\t\t"; cout << "골목길 밤은 깊어지고  달빛이 꽉 차올라 \n";
    cout << "\t\t"; cout << "Ooh-ooh-ooh (이리야)  일낼라 해 (해), 일낼라, 일내 yeah \n";
    cout << "\t\t"; cout << "해가 뜨기 전에 난 너를 떠보고 싶은 오늘 밤 (oh-ooh) \n";
    cout << "\t\t"; cout << "일이 날까 일이나 낼까 별이 빛나는 밤에 너의 눈빛에 취하고 있어 \n";
    cout << "\t\t"; cout << "아닌 척해도 티가 나 점점 일이 날까 일이나 낼까? 모두 잠든 이 밤에 \n";
    cout << "\t\t"; cout << "이 밤은 다크나이트 또 논란이 따라와 화끈하게 don't stop 더, 더 따라봐 (봐)\n";
    cout << "\t\t"; cout << "우린 야만 (야만) 말려봐라 암만 잔뜩 성이 난 야수처럼 으르렁대 \n";

    while (1) { 
        if (keyControl() == SUBMIT) { //스페이스바 누르기 전 까지는 이 정보창에 머무릅니다.
            break;
        }
    }
}

int main(void) {

    //init 시작
    system("mode con cols=100 lines=30 | title 어떻게 C++까지 사랑하겠어 돈을 사랑하는거지"); // 콘솔창 크기 및 제목 설정

    // 커서 깜빡이는거 삭제해버리
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오기
    CONSOLE_CURSOR_INFO consoleCrusor;
    consoleCrusor.bVisible = 0; // 0이나 false 처리하면 커서 숨기기
    consoleCrusor.dwSize = 1; 
    SetConsoleCursorInfo(consoleHandle, &consoleCrusor);

    //init 끝
   
    while (1) {
        MainMenu(); // 메인 메뉴 그리기 생성자 호출
        int menuCode = MenuDraw(); // 게임시작 버튼 생성
        //printf("메뉴 코드는 %d ", menuCode);
        
        if (menuCode == 0) {
            // 게임시작 
        }
        else if (menuCode == 1) {
            infoGame();// 게임정보
        }
        else if (menuCode == 2) {
            cout << "\n\n\n";
            return 0; // 게임 종료
        }
        system("cls"); // 콘솔창을 클린 하란 의미
    }
   


    // ★★ 키 컨트롤 함수 테스트 하는 구간 ★★
    /*int keyCode = keyControl();
    printf(" 입력 값 %d 입니다. ", keyCode);*/

    return 0;
}
