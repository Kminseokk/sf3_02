////////////////////////////////////////////////////////////////////////////
//      :: C++ ������Ʈ 07 �� ���� ::
//      1. ĳ����, ����, Į, �� Ŭ������ ������ش�.
//      2. ĳ���� Ŭ����
//          -�ʵ�: ��hp��, ��level��, ������顯
//          - �޼ҵ� : ���� �ݱ�, �����ϱ�(�����ϱ� �޼ҵ忡���� ������ �ִ� ����鸸 ����ؼ� 
//            ������ �� ������, ���ݴ��� ĳ������ hp�� �ش��ϴ� ������ ���ݷ¸�ŭ �����Ѵ�.)
//      3. ���� Ŭ����
//          - �ʵ�: ���ݷ�, ���� ���� Ƚ��
//          - �޼ҵ� : �����ϱ�
//      4. �� & Į Ŭ����(���� Ŭ������ ��� �޴� Ŭ����)
//          - Į : ���ݷ� - 5, ���ݰ���Ƚ�� - 3, �����ϱ� - "���" ���
//          - �� : ���ݷ� - 10, ���ݰ���Ƚ�� - 1, �����ϱ� - "�ѽ��" ���
//      5. ���� �и��ϱ�.
// 
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Character.h"
#include "Gun.h"
#include "Knife.h"
#include "util.h" //��ǥ ��Ʈ��
#include "game.h" //Ű ��Ʈ��

using namespace std;
//int Gaming_select();

int game_Start() {

    Character character("Ŀ�ٽ�"); 
    //���� ĳ���� ���� ������ �κ��� ���� ������ ������ (�����������̵� + ���̵� ���� ��й�ȣ.... �� ���� st)

    Character enemy("������"); // �ڡڡڡ� �ؾ�� ���� Ŭ������ ���� �־����� ���ڴ�.

    // Gun ��ü ����
    Gun* gun = new Gun();

    // Knife ��ü ����
    Knife* knife = new Knife();

    while (1) {
        system("cls"); // �ܼ�â�� Ŭ�� �϶� �ǹ�

        string message_01;
        cout << "\n";
        cout << " ���������������������������� \n";
        cout << " ��" << "(��'��'��)ĳ������ �̸� : " << character.get_name() << "�Դϴ�." << endl;
        cout << " ��" << "(��'��'��)ĳ������ HP : " << character.get_hp() << " �Դϴ�." << endl;
        cout << " ��" << "(��'��'��)ĳ������ Level : " << character.get_level() << "�Դϴ�." << endl;
        cout << " ��"; character.get_weapon();
        cout << " ��";
        //���� Ƚ�� ��Ÿ����
        if (character.get_weaponIndex() == 0) { //����
            cout << "\n";
        }
        if (character.get_weaponIndex() == 1) { //��
            gun->get_AttackChance();
        }
        if (character.get_weaponIndex() == 2) { //Į
            knife->get_AttackChance();
        }
        cout << " ��-------------- �̰� ���� �ߴ��� --------------\n";
        cout << " �� \n";
        cout << " ��" << "(��'��'��)���� hp : " << enemy.get_hp() << "�Դϴ�." << endl;
        cout << " �� \n";
        cout << " ���������������������������� \n";

        int userSelect = Gaming_select(); // ���ӽ��� ��ư ����
        cout << userSelect << endl;

        if (userSelect == 0) { // 0. ���� �ѱ� ȹ�� �����ε��� 1
            character.Player_GetWeapon(1);
            gun->initAttackChance();
            cout << "\n";
        }
        if (userSelect == 1) { // 1. ���� �ҵ� ȹ�� �����ε��� 2
            character.Player_GetWeapon(2);
            knife->initAttackChance(); //����Ƚ�� �ʱ�ȭ.
            cout << "\n";
        }
        if (userSelect == 2) { // 2. ���� �ϱ� !!!! �� ����Ƚ�� �����Ǽ� ���� Ƚ�������� ���� ���ϴ°� �ؾ���.
            if (character.get_weaponIndex() == 1) { //��
                if (gun->check_AttackChance() > 0) {
                    gun->Attack();
                    enemy.set_hp(enemy.get_hp() - gun->get_AttackDamage());
                }
                else {
                    cout << "���� Ƚ���� �����ؼ� ���ݿ� �����߽��ϴ�," << endl;
                }
            }
            else if (character.get_weaponIndex() == 2) { //Į
                if (knife->check_AttackChance() > 0) {
                    knife->Attack();
                    enemy.set_hp(enemy.get_hp() - knife->get_AttackDamage());
                }
                else {
                    cout << "���� Ƚ���� �����ؼ� ���ݿ� �����߽��ϴ�," << endl;
                }
            }
            else {
                cout << "�ƹ��� ���Ⱑ ��� ���ݿ� �����߽��ϴ�," << endl;
            }
            cout << "������ ���� ü���� : " << enemy.get_hp() << endl;

        }
        if (userSelect == 3) { // 5. ����
            cout << "������ �����ϰڽ��ϴ�. ��(*�ơ��*)�� " << endl;
            break;
        }


    }
    return 0;
};

//
//int Gaming_select() {
//    int x = 3;
//    int y = 13;
//    gotoxy(x - 2, y);
//    printf(">  �ѱ� ȹ�� "); // �ε��� 0 ��ȯ!!!! �ٸ� �ֵ麸�� x���� ������ > ������ �ڿ������� ���Ϸ���
//    gotoxy(x, y + 1); // 36 , 16
//    printf(" ĮĮ ȹ�� "); // �ε��� 1 ��ȯ!!!!
//    gotoxy(x, y + 2); // 36, 17
//    printf(" ���� �ϱ�"); // �ε��� 2 ��ȯ!!!!
//    gotoxy(x, y + 3); // 36, 17
//    printf(" ���� �ϱ�"); // �ε��� 3 ��ȯ!!!!
//
//    while (1) {
//        int n = keyControl(); //Ű�� �ޱ�
//        switch (n) {
//        case UP: {
//            if (y > 13) {
//                gotoxy(x - 2, y);
//                printf(" ");
//                gotoxy(x - 2, --y);
//                printf(">");
//            }
//            break;
//        }
//        case DOWN: {
//            if (y < 16) {
//                gotoxy(x - 2, y);
//                printf(" ");
//                gotoxy(x - 2, ++y);
//                printf(">");
//            }
//            break;
//        }
//        case SUBMIT: {
//            return y - 13; // ���� ��ġ�� ���� �޴� ������ 0 , 1 , 2 ������ ����.
//        }
//        }//����ġ�� �ݴ� ��
//
//    }
//}