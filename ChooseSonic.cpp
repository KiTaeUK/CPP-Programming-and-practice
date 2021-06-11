class ChooseSonic {
    //공룡을 그리는 함수
public:

    void DrawSonic(int sonicY, bool ball)
    {
        GotoXY(0, sonicY);
        if (!ball) {
            cout << " ######       " << endl;
            cout << "   #######    " << endl;
            cout << " #######  ##  " << endl;
            cout << "    ######### " << endl;
            cout << " ##########   " << endl;
            cout << "     ######   " << endl;
            cout << "    ##   ##   " << endl;
            cout << "    ##   ##   " << endl;
        }
        else {
            cout << "    #######   " << endl;
            cout << "  ##########  " << endl;
            cout << " ############ " << endl;
            cout << "   #########  " << endl;
            cout << "     ####     " << endl;

        }
    }

    void DrawTrap(int trapX)
    {
        GotoXY(trapX, TRAP_ROOT_Y);
        cout << "##";
        GotoXY(trapX, TRAP_ROOT_Y + 1);
        cout << "##";
        GotoXY(trapX, TRAP_ROOT_Y + 2);
        cout << "##";
        GotoXY(trapX, TRAP_ROOT_Y + 3);
        cout << "##";
        GotoXY(trapX, TRAP_ROOT_Y + 4);
        cout << "##";
        GotoXY(trapX, TRAP_ROOT_Y + 5);
        cout << "##";
    }

    void DrawRing(int ringX) {
        GotoXY(ringX, RING_ROOT_Y);
        cout << "  ##  ";
        GotoXY(ringX, RING_ROOT_Y + 1);
        cout << " #  # ";
        GotoXY(ringX, RING_ROOT_Y + 2);
        cout << "  ##  ";

    }

    bool isCrush_High(const int trapX, const int sonicY)
    {
        GotoXY(0, 0);

        cout << "trapX : " << trapX << "sonicY : " << sonicY << endl;
        if (trapX <= 4 && trapX >= 2 &&
            sonicY > 7)
        {
            return true;
        }
        return false;
    }

    bool ringCrush(const int ringX, const int sonicY)
    {
        GotoXY(0, 0);

        cout << "ringX : " << ringX << "sonicY : " << sonicY << endl;
        if (ringX <= 2 && ringX >= 0 &&
            sonicY > 1)
        {
            return true;
        }
        return false;
    }
};