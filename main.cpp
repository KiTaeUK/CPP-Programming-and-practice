//Upgrade_Dino

#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include <iostream>

#define DINO_ROOT_Y 12
#define TREE_ROOT_Y 20
#define TREE_ROOT_X 45
#define ROCK_ROOT_X 45
#define ROCK_ROOT_Y 20

#define SONIC_ROOT_Y 16
#define TRAP_ROOT_Y 17
#define TRAP_ROOT_X 45
#define RING_ROOT_X 45
#define RING_ROOT_Y 5

#define MARIO_ROOT_Y 16
#define MUSHROOM_ROOT_X 45
#define MUSHROOM_ROOT_Y 19
#define BAR_X 45
#define BAR_Y 4

using namespace std;
int main() {
    SetGameScreen();


    while (true)        //���� ����
    {
        //���� ���۽� �ʱ�ȭ
        bool isJumping = false;
        bool isRoot = true;
        const int gravity = 3;

        int dinoY = DINO_ROOT_Y;
        int sonicY = SONIC_ROOT_Y;
        int marioY = MARIO_ROOT_Y;
        int mushroomX = MUSHROOM_ROOT_X;
        int treeX = TREE_ROOT_X;
        int rockX = ROCK_ROOT_X;
        int ringX = RING_ROOT_X;
        int trapX = TRAP_ROOT_X;
        int mushroomY = MUSHROOM_ROOT_Y;
        int barX = BAR_X;
        int barY = BAR_Y;

        int score = 0;
        clock_t start, curr;    //���� ���� �ʱ�ȭ
        start = clock();        //���۽ð� �ʱ�ȭ

        int input_key;
        Selectcharacter();
        input_key = _getch();  //_getch�Լ��� cin�� �޸� �Է°� ���ÿ� ����ȴ�.
        switch (input_key) {
        case 50: // ASCII�ڵ�� 50�� 2�� �ǹ�
            ChooseSonic B;
            while (true)    //�� �ǿ� ���� ����
            {
                bool jump_check = false;
                //�浹üũ Ʈ���� x���� ������ y������ �Ǵ�
                if (B.isCrush_High(trapX, sonicY))
                    break;

                if (B.ringCrush(ringX, sonicY))
                {
                    score = score + 10;
                }

                //zŰ�� ���Ȱ�, �ٴ��� �ƴҶ� ����
                if (GetKeyDown() == 'z' && isRoot)
                {
                    isJumping = true;
                    isRoot = false;
                    jump_check = true;
                }

                //�������̶�� Y�� ����, ������ �������� Y�� ����.
                if (isJumping)
                {
                    sonicY -= gravity;
                }
                else
                {
                    sonicY += gravity;
                }

                //Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����.
                if (sonicY >= SONIC_ROOT_Y)
                {
                    sonicY = SONIC_ROOT_Y;
                    isRoot = true;
                }

                //������ �������� (x����) �������ϰ�
                //������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
                trapX -= 2;
                if (trapX <= 0)
                {
                    trapX = TRAP_ROOT_X;
                }

                ringX -= 1;
                if (ringX <= 0)
                {
                    ringX = RING_ROOT_X;
                }


                //������ ������ ������ ������ ���� ��Ȳ.
                if (sonicY <= 3)
                {
                    isJumping = false;
                }

                B.DrawSonic(sonicY, jump_check);        //draw dino
                B.DrawTrap(trapX);
                B.DrawRing(ringX);

                //(v2.0)
                curr = clock();            //����ð� �޾ƿ���
                if (((curr - start) / CLOCKS_PER_SEC) >= 1)    // 1�ʰ� �Ѿ�����
                {
                    score++;    //���ھ� UP
                    start = clock();    //���۽ð� �ʱ�ȭ
                }
                Sleep(60);
                system("cls");    //clear

            //��������� 1�ʸ��� ���ִ°��� �ƴ϶� �׻� ������ָ鼭, 1�ʰ� �������� ++ ����
                GotoXY(22, 0);    //Ŀ���� ��� �������� �ű��. �ܼ�â�� cols=100�̴ϱ� 2*x�̹Ƿ� 22���� �־���
                cout << "Score : " << score << endl;    //���� �������.
            }
            break;
        }
        //���� ���� �޴�
        DrawYouDied(score);
    }
    return 0;
}