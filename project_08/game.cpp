#include "game.h"
#include "util.h"

#include<iostream>
#include<stdio.h> 
#include<vector>
#include<windows.h> //��ǥ �ڵ鷯 ���
#include<conio.h> //_getch�� ���ԵǾ��ִ� ���



int keyControl() {
    char temp = _getch(); //�Է��� ���� �ܼ�â�� �ȳ����� �ٷ� �޾���. ����߰� �ʼ�

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

void MainMenu() {
        cout << "\n\n\n\n";
        cout << "\t\t"; cout << "@@@@@@@      @     @     @@@@@@@     @@@@@@@      @@@@@@@         \n";
        cout << "\t\t"; cout << "      @      @     @@    @      @    @      @    @                \n";
        cout << "\t\t"; cout << "      @      @     @     @      @    @      @   @                 \n";
        cout << "\t\t"; cout << "      @      @@@@  @@    @     @     @     @    @     @@@@        \n";
        cout << "\t\t"; cout << "      @        @@@@      @@@@@@      @@@@@@     @        @        \n";
        cout << "\t\t"; cout << "      @       @    @     @     @     @          @       @@        \n";
        cout << "\t\t"; cout << "              @    @     @      @    @           @     @ @        \n";
        cout << "\t\t"; cout << "@@@@@@@@       @@@@      @       @   @            @@@@@  @        \n";
        cout << "\t\t"; cout << "              ���۹�� W A S D / ���� : �����̽���                \n";

        //cout << "\t\t"; cout << "            ������ �����Ϸ��� �ƹ�Ű�� ��������.\n\n\n\n\n";
        //cout << "\t\t"; cout << "       ���� �ƹ������� ���� �ƹ��� ������ ���� �����̴�.\n";
        //getchar(); // �ƹ�Ű �Է� ��ٸ�
        //system("cls"); // �ܼ� â clear
};

void infoGame() {
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t"; cout << "one, two, three ���� ����� �ܵ��� ���� ����� \n";
    cout << "\t\t"; cout << "���νð� ���� ������ �ϳ��� ��, �ϳ��� �� \n";
    cout << "\t\t"; cout << "���� ���� �������  �޺��� �� ���ö� \n";
    cout << "\t\t"; cout << "Ooh-ooh-ooh (�̸���)  �ϳ��� �� (��), �ϳ���, �ϳ� yeah \n";
    cout << "\t\t"; cout << "�ذ� �߱� ���� �� �ʸ� ������ ���� ���� �� (oh-ooh) \n";
    cout << "\t\t"; cout << "���� ���� ���̳� ���� ���� ������ �㿡 ���� ������ ���ϰ� �־� \n";
    cout << "\t\t"; cout << "�ƴ� ô�ص� Ƽ�� �� ���� ���� ���� ���̳� ����? ��� ��� �� �㿡 \n";
    cout << "\t\t"; cout << "�� ���� ��ũ����Ʈ �� ����� ����� ȭ���ϰ� don't stop ��, �� ����� (��)\n";
    cout << "\t\t"; cout << "�츰 �߸� (�߸�) �������� �ϸ� �ܶ� ���� �� �߼�ó�� �������� \n";

    while (1) {
        if (keyControl() == SUBMIT) { //�����̽��� ������ �� ������ �� ����â�� �ӹ����ϴ�.
            break;
        }
    }
}

int MenuDraw() {
    // �ӽ� �׽�Ʈ ��ġ �ľ� �뵵�� ���!
    //gotoxy(2, 2);
    //printf("2, 2 ��ġ�Դϴ�.");
    // �ӽ� �׽�Ʈ ��ġ �ľ� �뵵�� �����!
    // [ �̵����� ]
    // ���� : x����
    // ���� : x����
    // �Ʒ� : y����
    // ���� : y����

    int x = 36;
    int y = 15;
    gotoxy(x - 2, y); // 35 , 15
    printf(">  ���� ���� "); //�ٸ� �ֵ麸�� x���� ������ > ������ �ڿ������� ���Ϸ���
    gotoxy(x, y + 1); // 36 , 16
    printf(" ���� ���� ");
    gotoxy(x, y + 2); // 36, 17
    printf(" ���� ����");

    while (1) {
        int n = keyControl(); //Ű�� �ޱ�
        switch (n) {
        case UP: {
            if (y > 15) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 17) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y - 15; // ���� ��ġ�� ���� �޴� ������ 0 , 1 , 2 ������ ����.
        }
        }//����ġ�� �ݴ� ��

    }
}
