#include "Character.h"
#include <iostream>
#include <vector>
using namespace std;

Character::Character(string name) {
	this->hp = 100;
	this->level = 1;
	this->name = name;
	this->weapons = { 0, }; //�ʱⰪ �ʱ�ȭ

}

void Character::Player_Attack() {
	cout << "�÷��̾ ������ �մϴ�." << endl;
}


void Character::Player_GetWeapon(int WeaponIndex) { //�÷��̾ ���⸦ ȹ���ϴ� ����.
	if (WeaponIndex == 1) {
		this->weapons.push_back(WeaponIndex);
		cout << "�÷��̾ �ѱ⸦ ȹ���ϼ̽��ϴ�." << endl;
	}
	if (WeaponIndex == 2) {
		this->weapons.push_back(WeaponIndex);
		cout << "�÷��̾ Į�� ȹ���ϼ̽��ϴ�." << endl;
	}
}

int Character::get_hp() {
	return hp;
}

int Character::get_level() {
	return level;
}

string Character::get_name() {
	return name;
}

void Character::get_weapon() {
	if (weapons.back() == 1) {
		cout << "(��'��'��)�÷��̾ �ѱ⸦ ����ֽ��ϴ�." << endl;
	}
	else if (weapons.back() == 2) {
		cout << "(��'��'��)�÷��̾ �˰˸� ����ֽ��ϴ�." << endl;
	}
	else {
		cout << "(��'��'��)�÷��̾ ��������." << endl;
	}
}

int Character::get_weaponIndex()
{
	return weapons.back(); //1 Ȥ�� 2�� �����.
}

void Character::set_hp(int hp)
{
	this->hp = hp;
}

