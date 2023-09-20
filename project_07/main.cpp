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

using namespace std;

int main() {
    system("cls"); // �ܼ�â�� Ŭ�� �϶� �ǹ�
    // Character ��ü ����
    Character character("��μ�");
    Character enemy("�پ�");

    // Gun ��ü ����
    Gun* gun = new Gun();

    // Knife ��ü ����
    Knife* knife = new Knife();

    int user_choice;

    cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�" << endl;
    cout << "�� 1. ���� ���� ��� " << endl;
    cout << "�� 2. ���� �ѱ� ȹ�� " << endl;
    cout << "�� 3. ���� �ҵ� ȹ�� " << endl;
    cout << "�� 4. ���� �ϱ� !!!! " << endl;
    cout << "�� 5. ���� ���� ���� " << endl;
    cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�" << endl;
    cout << "\n\n";

    while (1) {
        cout << "\n �� ������ �ұ�? : ";
        cin >> user_choice;

        if (user_choice == 1) { // 1. ���� ���� ���
            cout << "(��'��'��)ĳ������ �̸� : " << character.get_name() << "�Դϴ�." << endl;
            cout << "(��'��'��)ĳ������ HP : " << character.get_hp() << "�Դϴ�." << endl;
            cout << "(��'��'��)ĳ������ Level : " << character.get_level() << "�Դϴ�." << endl;
            character.get_weapon();
            if (character.get_weaponIndex() == 1) { //��
                gun->get_AttackChance();
            }
            if (character.get_weaponIndex() == 2) { //Į
                knife->get_AttackChance();
            }
            cout << "\n";
        }
        if (user_choice == 2) { // 2. ���� �ѱ� ȹ�� �����ε��� 1
            character.Player_GetWeapon(1);
            gun->initAttackChance();
            cout << "\n";
        }
        if (user_choice == 3) { // 3. ���� �ҵ� ȹ�� �����ε��� 2
            character.Player_GetWeapon(2);
            knife->initAttackChance(); //����Ƚ�� �ʱ�ȭ.
            cout << "\n";
        }
        if (user_choice == 4) { // 4. ���� �ϱ� !!!! �� ����Ƚ�� �����Ǽ� ���� Ƚ�������� ���� ���ϴ°� �ؾ���.
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
        if (user_choice == 5) { // 5. ����
            cout << "������ �����ϰڽ��ϴ�. ��(*�ơ��*)�� " << endl;
            break;
        }
    }


    return 0;
}
