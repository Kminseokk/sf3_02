#pragma once
#include "main.h"

#ifndef KEY_CODE
#define KEY_CODE

// �ڡڡڡ� Ű���� �� ���� �ڡڡڡ� //
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 // �����ϴ� ��

#endif

int MenuDraw();        // ���ӽ��� ��� ��ư ���� �Լ�
int keyControl();       // Ű���� �Է� �� ��Ʈ�� �Լ�
void infoGame();        //�������� ���
void MainMenu();
int Gaming_select();