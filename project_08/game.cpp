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
    cout << "\t\t"; cout << "******************************************************************* \n";
    cout << "\t\t"; cout << "������ ���� ������ �⵵�ϰ� �ֳ� �� ���׿� �� ����ð� \n";
    cout << "\t\t"; cout << "���� �鸮�� ���� �ʿ��Է� ������ ���ư� ���� �ʰ� �ڸ��� ��⸦ \n";
    cout << "\t\t"; cout << "I'll be there Ȧ�� �ȴ� ���� �ڿ� Singing till the end ��ġ�� ���� �� �뷡 \n";
    cout << "\t\t"; cout << "���� ��ø� �� ��￩ �� ������ �� ���� �ȴ� �� ���� �θ��� \n";
    cout << "\t\t"; cout << "�� �� �� ���� ���� ���� ���� �ֳ� �� ���׿� ��Ų ������ \n";
    cout << "\t\t"; cout << "���� �帣�� ���� �� ���� �Ҿ� ����� ������ ���ó�� ������� ��Ҹ� \n";
    cout << "\t\t"; cout << "I'll be there Ȧ�� �ȴ� ���� �ڿ� Singing till the end ��ġ�� ���� �� �뷡 \n";
    cout << "\t\t"; cout << "���� Ŀ�ٶ� ���� ���� �� �Ҹ� �� ��� ���� ���� �� ���� �θ��� \n";
    cout << "\t\t"; cout << "******************************************************************* \n";
    cout << "\t\t"; cout << "    �����̽��ٸ� �� �� �� �Է��Ͻø� �ʱ� ȭ������ ���ư��ϴ�. \n";

    while (1) {
        if (keyControl() == SUBMIT) { //�����̽��� ������ �� ������ �� ����â�� �ӹ����ϴ�.
            break;
        }
    }
}

int MenuDraw() { //ù ���� ����ȭ��

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


int Gaming_select() { //���� ���� �� �����ϴ� ��
    int x = 3;
    int y = 13;
    gotoxy(x - 2, y);
    printf(">  �ѱ� ȹ�� "); // �ε��� 0 ��ȯ!!!! �ٸ� �ֵ麸�� x���� ������ > ������ �ڿ������� ���Ϸ���
    gotoxy(x, y + 1); // 36 , 16
    printf(" ĮĮ ȹ�� "); // �ε��� 1 ��ȯ!!!!
    gotoxy(x, y + 2); // 36, 17
    printf(" ���� �ϱ�"); // �ε��� 2 ��ȯ!!!!
    gotoxy(x, y + 3); // 36, 17
    printf(" ���� �ϱ�"); // �ε��� 3 ��ȯ!!!!

    while (1) {
        int n = keyControl(); //Ű�� �ޱ�
        switch (n) {
        case UP: {
            if (y > 13) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 16) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y - 13; // ���� ��ġ�� ���� �޴� ������ 0 , 1 , 2 ������ ����.
        }
        }//����ġ�� �ݴ� ��

    }
}