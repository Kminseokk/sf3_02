#include "util.h"

void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� �ڵ� ��������
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

void init() {
    system("mode con cols=100 lines=30 | title ��� C++���� ����ϰھ� ���� ����ϴ°���, ���׷��̵����"); // �ܼ�â ũ�� �� ���� ����

    // Ŀ�� �����̴°� �����ع���
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� �ڵ� ��������
    CONSOLE_CURSOR_INFO consoleCrusor;
    consoleCrusor.bVisible = 0; // 0�̳� false ó���ϸ� Ŀ�� �����
    consoleCrusor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &consoleCrusor);
}