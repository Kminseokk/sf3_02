#include<iostream>
#include<stdio.h> 
#include<vector>
#include<windows.h> //좌표 핸들러 사용
#include<conio.h> //_getch가 포함되어있는 헤더

#include"Character.h"

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
int Gaming_select();
using namespace std;

void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오고
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

//int space[8][50] = {  // 세로 15+1(아래벽)칸, 가로 10+2(양쪽 벽)칸  
//    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//};
//
//void DrawMap() {
//    gotoxy(0, 0);
//    for (int i = 0; i < 8; i++) {
//        for (int j = 0; j < 50; j++) {
//            if (space[i][j] == 1) {
//                gotoxy(j * 2, i);
//                printf("■");
//            }
//        }
//    }
//}

void Gaming_info() {
        Character character("김민석");
        cout << "\n";
        cout << " ■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n";
        cout << " ■" << "(●'ㅡ'●)캐릭터의 이름 : " << character.get_name() << "입니다." << endl;
        cout << " ■" << "(●'ㅡ'●)캐릭터의 HP : " << character.get_hp() << " 입니다." << endl;
        cout << " ■" << "(●'ㅡ'●)캐릭터의 Level : " << character.get_level() << "입니다." << endl;
        cout << " ■"; character.get_weapon();
        cout << " ■ \n";
        cout << " ■ \n";
        cout << " ■ \n";
        cout << " ■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n";

        int userSelect = Gaming_select(); // 게임시작 버튼 생성
        cout << userSelect << endl;
};

int Gaming_select() {
    int x = 3;
    int y = 11;
    gotoxy(x - 2, y); 
    printf(">  총기 획득 "); // 인덱스 0 반환!!!! 다른 애들보다 x값이 작은건 > 때문에 자연스럽게 보일려고
    gotoxy(x, y + 1); // 36 , 16
    printf(" 칼칼 획득 "); // 인덱스 1 반환!!!!
    gotoxy(x, y + 2); // 36, 17
    printf(" 공격 하기"); // 인덱스 2 반환!!!!
    gotoxy(x, y + 3); // 36, 17
    printf(" 종료 하기"); // 인덱스 3 반환!!!!

    while (1) {
        int n = keyControl(); //키값 받기
        switch (n) {
        case UP: {
            if (y > 11) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 14) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y - 11; // 시작 위치를 빼서 메뉴 선택을 0 , 1 , 2 값으로 좁힘.
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
int main(void) {

    //init 시작
    system("mode con cols=100 lines=30 | title 어떻게 C++까지 사랑하겠어 돈을 사랑하는거지 존나 테스트@@"); // 콘솔창 크기 및 제목 설정

    // 커서 깜빡이는거 삭제해버리
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오기
    CONSOLE_CURSOR_INFO consoleCrusor;
    consoleCrusor.bVisible = 0; // 0이나 false 처리하면 커서 숨기기
    consoleCrusor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &consoleCrusor);

    //init 끝
    Gaming_info();

    //while (1) {
    //    MainMenu(); // 메인 메뉴 그리기 생성자 호출
    //    int menuCode = MenuDraw(); // 게임시작 버튼 생성
    //    //printf("메뉴 코드는 %d ", menuCode);

    //    if (menuCode == 0) {
    //        // 게임시작 
    //    }
    //    else if (menuCode == 1) {
    //        infoGame();// 게임정보
    //    }
    //    else if (menuCode == 2) {
    //        cout << "\n\n\n";
    //        return 0; // 게임 종료
    //    }
    //    system("cls"); // 콘솔창을 클린 하란 의미
    //}



    // ★★ 키 컨트롤 함수 테스트 하는 구간 ★★
    /*int keyCode = keyControl();
    printf(" 입력 값 %d 입니다. ", keyCode);*/

    return 0;
}
