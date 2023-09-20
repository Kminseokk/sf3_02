////////////////////////////////////////////////////////////////////////////
//      :: C++ 프로젝트 07 번 문제 ::
//      1. 캐릭터, 무기, 칼, 총 클래스를 만들어준다.
//      2. 캐릭터 클래스
//          -필드: ‘hp’, ‘level’, ‘무기들’
//          - 메소드 : 무기 줍기, 공격하기(공격하기 메소드에서는 가지고 있는 무기들만 사용해서 
//            공격할 수 있으며, 공격당한 캐릭터의 hp가 해당하는 무기의 공격력만큼 감소한다.)
//      3. 무기 클래스
//          - 필드: 공격력, 공격 가능 횟수
//          - 메소드 : 공격하기
//      4. 총 & 칼 클래스(무기 클래스를 상속 받는 클래스)
//          - 칼 : 공격력 - 5, 공격가능횟수 - 3, 공격하기 - "찌르기" 출력
//          - 총 : 공격력 - 10, 공격가능횟수 - 1, 공격하기 - "총쏘기" 출력
//      5. 파일 분리하기.
// 
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Character.h"
#include "Gun.h"
#include "Knife.h"

using namespace std;

int game_Start() {
    system("cls"); // 콘솔창을 클린 하란 의미
    // Character 객체 생성
    Character character("김민석");
    Character enemy("꾸엉");

    // Gun 객체 생성
    Gun* gun = new Gun();

    // Knife 객체 생성
    Knife* knife = new Knife();

    int user_choice;

    cout << "★★★★★★★★★★★★★★★★★★★" << endl;
    cout << "★ 1. 유저 정보 출력 " << endl;
    cout << "★ 2. 유저 총기 획득 " << endl;
    cout << "★ 3. 유저 소드 획득 " << endl;
    cout << "★ 4. 공격 하기 !!!! " << endl;
    cout << "★ 5. 종료 해주 세요 " << endl;
    cout << "★★★★★★★★★★★★★★★★★★★" << endl;
    cout << "\n\n";

    while (1) {
        cout << "\n ▶ 무엇을 할까? : ";
        cin >> user_choice;

        if (user_choice == 1) { // 1. 유저 정보 출력
            cout << "(●'ㅡ'●)캐릭터의 이름 : " << character.get_name() << "입니다." << endl;
            cout << "(●'ㅡ'●)캐릭터의 HP : " << character.get_hp() << "입니다." << endl;
            cout << "(●'ㅡ'●)캐릭터의 Level : " << character.get_level() << "입니다." << endl;
            character.get_weapon();
            if (character.get_weaponIndex() == 1){ //총
                gun->get_AttackChance();
            }
            if (character.get_weaponIndex() == 2) { //칼
                knife->get_AttackChance();
            }
            cout << "\n";
        }
        if (user_choice == 2) { // 2. 유저 총기 획득 웨폰인덱스 1
            character.Player_GetWeapon(1); 
            gun->initAttackChance();
            cout << "\n";
        }
        if (user_choice == 3) { // 3. 유저 소드 획득 웨폰인덱스 2
            character.Player_GetWeapon(2);
            knife->initAttackChance(); //공격횟수 초기화.
            cout << "\n";
        }
        if (user_choice == 4) { // 4. 공격 하기 !!!! 아 공격횟수 차감되서 공격 횟수없으면 공격 안하는거 해야함.
            if (character.get_weaponIndex() == 1) { //총
                if (gun->check_AttackChance() > 0 ) {
                    gun->Attack();
                    enemy.set_hp(enemy.get_hp() - gun->get_AttackDamage());
                }
                else {
                    cout << "공격 횟수가 부족해서 공격에 실패했습니다," << endl;
                }
            }
            else if (character.get_weaponIndex() == 2) { //칼
                if (knife->check_AttackChance() > 0 ) {
                    knife->Attack();
                    enemy.set_hp(enemy.get_hp() - knife->get_AttackDamage());
                }
                else {
                    cout << "공격 횟수가 부족해서 공격에 실패했습니다," << endl;
                }
            }            
            else {
                cout << "아무런 무기가 없어서 공격에 실패했습니다," << endl;
            }
            cout << "적에게 남은 체력은 : " << enemy.get_hp() << endl;

        }
        if (user_choice == 5) { // 5. 종료
            cout << "게임을 종료하겠습니다. ㄴ(*°▽°*)ㄱ " << endl;
            break;
        }
    }


    return 0;
}
