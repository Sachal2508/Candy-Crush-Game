#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int score = 0;
int moves = 0;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void printGameboard(char gameboard[10][10], int mode);
void matchAndTag(char gameboard[10][10], int mode);
void swaping(char gameboard[10][10], int mode);
bool checkMatches(char gameboard[10][10], int mode);
void updateBoard(char gameboard[10][10], int mode);
char randChar();
char randChar1();
void sleep(int x);


int main() {
    system("cls");
    sleep(150);
    srand(time(0));
    // Declare an 2d array to be gameboard
    char gameboard[10][10];
    int choice;



back:
    system("cls");
    SetConsoleTextAttribute(h, 4);
    cout << "  ****     ******   *           *  *******   *           *         ****     ******    *      *    *****    *     *" << endl;
    cout << " *    *   *      *  * *         *  *      *    *       *          *    *   *      *   *      *   *     *   *     *" << endl;
    cout << "*         *      *  *   *       *  *      *      *   *           *         *      *   *      *   *         *     *" << endl;
    cout << "*         ********  *     *     *  *      *        *             *         * *****    *      *    *****    *******" << endl;
    cout << "*         *      *  *       *   *  *      *        *             *         *  *       *      *         *   *     *" << endl;
    cout << " *    *   *      *  *         * *  *      *        *              *    *   *   *      *      *   *     *   *     *" << endl;
    cout << "  ****    *      *  *           *  *******         *               ****    *     *     ******  *  *****    *     * " << endl;

    sleep(200);
    SetConsoleTextAttribute(h, 6);
    cout << endl << endl << endl;
    cout << "\t\t\t\t|+++++++++++++++++++++|" << endl;
    cout << "\t\t\t\t|______GAME MENU______|" << endl;
    cout << "\t\t\t\t|                     |" << endl;
    cout << "\t\t\t\t|    1. Play Game     |" << endl;
    cout << "\t\t\t\t|    2. Credits       |" << endl;
    cout << "\t\t\t\t|    3. Quit          |" << endl;
    cout << "\t\t\t\t|_____________________|" << endl;
    cout << "\t\t\t\t";
qt:
    cout << "\nGive your Choice : ";
    cin >> choice;
    if (choice <= 0 || choice > 3) {
        cout << "Wrong Option\n";
        goto qt;
    }
    if (choice == 1) {
        string name;
        system("CLS");
        SetConsoleTextAttribute(h, 6);
        cout << endl << endl << endl;
        cout << "\t\t\t\t\t|         PLEASE ENTER YOUR NAME:          |" << endl;
        cout << "\t\t\t\t\t          ";
        cin.ignore();// without this control ignores user to input his name..
        getline(cin, name); // gets input in string with spaces..
        SetConsoleTextAttribute(h, 7);// white text color
    q:
        int mode;
        SetConsoleTextAttribute(h, 6);// yellow text color
        cout << "\n\t\t\t\t\t Select MODE:" << endl;
        SetConsoleTextAttribute(h, 2);//green text color
        cout << " \t\t\t\t\t 1. Easy Mode   (6 x 6 size)" << endl;
        SetConsoleTextAttribute(h, 4);// red text color
        cout << " \t\t\t\t\t 2. Hard Mode    (10 x 10 siize)" << endl;
        cout << "\t\t\t\t\t ";
        SetConsoleTextAttribute(h, 6);
        cin >> mode;
        if (mode < 1 || mode > 2) {
            cout << "Wrong Option\n";
            goto q;
        }
        SetConsoleTextAttribute(h, 7);
        if (mode == 1) {
            system("CLS");
            SetConsoleTextAttribute(h, 7);

            // Asigns value to all elements of 2d array
            for (int row = 0; row < 6; row++) {
                for (int col = 0; col < 6; col++)
                    gameboard[row][col] = randChar();
            }
            //match and tag function call
        again:
            matchAndTag(gameboard, mode);


            if (checkMatches(gameboard, mode))
                goto again;
            else
                printGameboard(gameboard, mode);

            do {
                //swaping function call
                swaping(gameboard, mode);

            } while (score < 100);

            if (score >= 100) {
                cout << "CONGRATULATIONS YOU WON!";
                return 0;
            }


        }
        else if (mode == 2) {
            system("CLS");
            SetConsoleTextAttribute(h, 7);

            // Asigns value to all elements of 2d array
            for (int row = 0; row < 10; row++) {
                for (int col = 0; col < 10; col++)
                    gameboard[row][col] = randChar1();
            }
            //match and tag function call
        again1:
            matchAndTag(gameboard, mode);


            if (checkMatches(gameboard, mode))
                goto again1;
            else
                printGameboard(gameboard, mode);

            do {
                //swaping function call
                swaping(gameboard, mode);

            } while (score < 300);

            if (score >= 300) {
                cout << "CONGRATULATIONS YOU WON!";
                return 0;
            }
        }
    }
    else if (choice == 2) {
        system("CLS");
        cout << "\t\t\t\t |----------CREDITS-----------|" << endl;
        cout << "\t\t\t\t |                            |" << endl;
        cout << "\t\t\t\t | Muhammad Umer    23L-3038  |" << endl;
        cout << "\t\t\t\t |                            |" << endl;
        cout << "\t\t\t\t | Muhammad Qudama  23L-0852  |" << endl;
        cout << "\t\t\t\t |                            |" << endl;
        cout << "\t\t\t\t |  Hafiz Sacahl    23L-0973  |" << endl;
        cout << "\t\t\t\t |                            |" << endl;
        cout << "\t\t\t\t |  Zain            23L-0578  |" << endl;
        cout << "\t\t\t\t |                            |" << endl;
        cout << "\t\t\t\t |   Press ESC to go back.    |" << endl;
        cout << "\t\t\t\t |----------------------------|" << endl;
    back1:
        char z = _getch();
        if (z == 27)       //ASCII Code for "Escape" = 27
            goto back;
        else {
            cout << "\nPress ESC to go back.\n";
            goto back1;
        }
    }
    else if (choice == 3) {
        return 0;
    }

    return 0;
} //end main function



void updateBoard(char gameboard[10][10], int mode) {
    if (mode == 1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                if (gameboard[i][j] == gameboard[i][j + 1] && gameboard[i][j + 1] == gameboard[i][j + 2]) {
                    int n = i;
                    while (n > 0) {
                        gameboard[n][j] = gameboard[n - 1][j];
                        gameboard[n][j + 1] = gameboard[n - 1][j + 1];
                        gameboard[n][j + 2] = gameboard[n - 1][j + 2];
                        n--;
                    }
                    gameboard[0][j] = randChar();
                    gameboard[0][j + 1] = randChar();
                    gameboard[0][j + 2] = randChar();

                    if (gameboard[i][j] == gameboard[i][j + 3]) {
                        int a = i;
                        if (gameboard[i][j] == gameboard[i][j + 4]) {
                            while (a > 0) {
                                gameboard[a][j + 3] = gameboard[a - 1][j + 3];
                                gameboard[a][j + 4] = gameboard[a - 1][j + 4];
                                a--;
                            }
                            gameboard[0][j + 3] = randChar();
                            gameboard[0][j + 4] = randChar();
                        }
                        else {
                            while (a > 0) {
                                gameboard[a][j + 3] = gameboard[a - 1][j + 3];
                                a--;
                            }
                            gameboard[0][j + 3] = randChar();
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 6; j++) {
                if (gameboard[i][j] == gameboard[i + 1][j] && gameboard[i + 1][j] == gameboard[i + 2][j]) {
                    if (i == 3) {
                        gameboard[i + 2][j] = gameboard[i - 1][j];
                        gameboard[i + 1][j] = gameboard[i - 2][j];
                        gameboard[i][j] = gameboard[i - 3][j];

                        gameboard[i - 1][j] = randChar();
                        gameboard[i - 2][j] = randChar();
                        gameboard[i - 3][j] = randChar();

                    }
                    else if (i == 2) {
                        if (gameboard[i][j] == gameboard[i + 3][j]) {

                            gameboard[i + 3][j] = gameboard[i - 1][j];
                            gameboard[i + 2][j] = gameboard[i - 2][j];

                            gameboard[i + 1][j] = randChar();
                            gameboard[i][j] = randChar();
                            gameboard[i - 1][j] = randChar();
                            gameboard[i - 2][j] = randChar();
                        }
                        else {
                            gameboard[i + 2][j] = gameboard[i - 1][j];
                            gameboard[i + 1][j] = gameboard[i - 2][j];


                            gameboard[i - 1][j] = randChar();
                            gameboard[i - 2][j] = randChar();
                            gameboard[i][j] = randChar();
                        }



                    }
                    else if (i == 1) {
                        if (gameboard[i][j] == gameboard[i + 3][j]) {
                            if (gameboard[i][j] == gameboard[i + 4][j]) {
                                gameboard[i + 4][j] = gameboard[i - 1][j];

                                gameboard[i + 3][j] = randChar();
                                gameboard[i + 2][j] = randChar();
                                gameboard[i + 1][j] = randChar();
                                gameboard[i][j] = randChar();
                                gameboard[i - 1][j] = randChar();
                            }
                            else {
                                gameboard[i + 3][j] = gameboard[i - 1][j];

                                gameboard[i + 2][j] = randChar();
                                gameboard[i + 1][j] = randChar();
                                gameboard[i][j] = randChar();
                                gameboard[i - 1][j] = randChar();
                            }
                        }
                        else {
                            gameboard[i + 2][j] = gameboard[i - 1][j];

                            gameboard[i - 1][j] = randChar();
                            gameboard[i][j] = randChar();
                            gameboard[i + 1][j] = randChar();
                        }
                    }
                    else if (i == 0) {
                        gameboard[i][j] = randChar();
                        gameboard[i + 1][j] = randChar();
                        gameboard[i + 2][j] = randChar();
                    }
                }
            }
        }
    }
    else if (mode == 2) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 8; j++) {
                if (gameboard[i][j] == gameboard[i][j + 1] && gameboard[i][j + 1] == gameboard[i][j + 2]) {
                    int n = i;
                    while (n > 0) {
                        gameboard[n][j] = gameboard[n - 1][j];
                        gameboard[n][j + 1] = gameboard[n - 1][j + 1];
                        gameboard[n][j + 2] = gameboard[n - 1][j + 2];
                        n--;
                    }
                    gameboard[0][j] = randChar1();
                    gameboard[0][j + 1] = randChar1();
                    gameboard[0][j + 2] = randChar1();
                }
            }
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 10; j++) {
                if (gameboard[i][j] == gameboard[i + 1][j] && gameboard[i + 1][j] == gameboard[i + 2][j]) {
                    continue;
                }
            }
        }
    }
}


char randChar() {
    int c = (rand() % 5) + 1;
    char x = ' ';
    if (c == 1)
        x = '@';
    else if (c == 2)
        x = '#';
    else if (c == 3)
        x = '$';
    else if (c == 4)
        x = '%';
    else if (c == 5)
        x = '&';
    return x;
}


char randChar1() {
    int c = (rand() % 7) + 1;
    char x = ' ';
    if (c == 1)
        x = '@';
    else if (c == 2)
        x = '#';
    else if (c == 3)
        x = '$';
    else if (c == 4)
        x = '%';
    else if (c == 5)
        x = '&';
    else if (c == 6)
        x = '!';
    else if (c == 7)
        x = '*';
    return x;
}

// Function that prints the gameboard
void printGameboard(char gameboard[10][10], int mode) {
    system("cls");
    if (mode == 1) {
        cout << "      ";
        for (int i = 0; i < 6; i++)
            cout << i << "     ";
        cout << "\n   _____________________________________\t\t\tSCORE : " << score << "     MOVES : " << moves << "\n";

        for (int i = 0; i < 6; i++) {
            cout << i << "  |  ";

            for (int j = 0; j < 6; j++) {
                if (gameboard[i][j] == '@')
                    SetConsoleTextAttribute(h, 1);    //colouring symbols
                else if (gameboard[i][j] == '#')
                    SetConsoleTextAttribute(h, 2);
                else if (gameboard[i][j] == '$')
                    SetConsoleTextAttribute(h, 3);
                else if (gameboard[i][j] == '%')
                    SetConsoleTextAttribute(h, 4);
                else if (gameboard[i][j] == '&')
                    SetConsoleTextAttribute(h, 5);
                cout << gameboard[i][j];
                SetConsoleTextAttribute(h, 15);
                cout << "  |  ";
            }

            cout << "\n   -------------------------------------\n";
        }
    }
    else if (mode == 2) {
        cout << "      ";
        for (int i = 0; i < 10; i++)
            cout << i << "     ";
        cout << "\n   _____________________________________________________________\t\t\tSCORE : " << score << "     MOVES : " << moves << "\n";

        for (int i = 0; i < 10; i++) {
            cout << i << "  |  ";

            for (int j = 0; j < 10; j++) {
                if (gameboard[i][j] == '@')
                    SetConsoleTextAttribute(h, 1);    //colouring symbols
                else if (gameboard[i][j] == '#')
                    SetConsoleTextAttribute(h, 2);
                else if (gameboard[i][j] == '$')
                    SetConsoleTextAttribute(h, 3);
                else if (gameboard[i][j] == '%')
                    SetConsoleTextAttribute(h, 4);
                else if (gameboard[i][j] == '&')
                    SetConsoleTextAttribute(h, 5);
                else if (gameboard[i][j] == '!')
                    SetConsoleTextAttribute(h, 8);
                else if (gameboard[i][j] == '*')
                    SetConsoleTextAttribute(h, 9);
                cout << gameboard[i][j];
                SetConsoleTextAttribute(h, 15);
                cout << "  |  ";
            }

            cout << "\n   -------------------------------------------------------------\n";
        }
    }


}


//function that checks 3 consecutive matches in rows and cols
bool checkMatches(char gameboard[10][10], int mode) {
    if (mode == 1) {
        bool isTrue = true;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                if (gameboard[i][j] == gameboard[i][j + 1] && gameboard[i][j + 1] == gameboard[i][j + 2])
                    return true;
                else
                    isTrue = false;
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 6; j++) {
                if (gameboard[i][j] == gameboard[i + 1][j] && gameboard[i + 1][j] == gameboard[i + 2][j])
                    return true;
                else
                    isTrue = false;
            }
        }
        if (isTrue == false)
            return false;
    }
    else if (mode == 2) {
        bool isTrue = true;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 8; j++) {
                if (gameboard[i][j] == gameboard[i][j + 1] && gameboard[i][j + 1] == gameboard[i][j + 2])
                    return true;
                else
                    isTrue = false;
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 8; j++) {
                if (gameboard[i][j] == gameboard[i + 1][j] && gameboard[i + 1][j] == gameboard[i + 2][j])
                    return true;
                else
                    isTrue = false;
            }
        }
        if (isTrue == false)
            return false;
    }
    return true;
}

//function that tags the consecutive values in rows and cols
void matchAndTag(char gameboard[10][10], int mode) {
    if (mode == 1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                if (gameboard[i][j] == gameboard[i][j + 1] && gameboard[i][j + 1] == gameboard[i][j + 2]) {
                    gameboard[i][j] = randChar();
                    gameboard[i][j + 1] = randChar();
                    gameboard[i][j + 2] = randChar();
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 6; j++) {
                if (gameboard[i][j] == gameboard[i + 1][j] && gameboard[i + 1][j] == gameboard[i + 2][j]) {
                    gameboard[i][j] = randChar();
                    gameboard[i + 1][j] = randChar();
                    gameboard[i + 2][j] = randChar();
                }
            }
        }
    }
    else if (mode == 2) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 8; j++) {
                if (gameboard[i][j] == gameboard[i][j + 1] && gameboard[i][j + 1] == gameboard[i][j + 2]) {
                    gameboard[i][j] = randChar1();
                    gameboard[i][j + 1] = randChar1();
                    gameboard[i][j + 2] = randChar1();
                }
            }
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 10; j++) {
                if (gameboard[i][j] == gameboard[i + 1][j] && gameboard[i + 1][j] == gameboard[i + 2][j]) {
                    gameboard[i][j] = randChar1();
                    gameboard[i + 1][j] = randChar1();
                    gameboard[i + 2][j] = randChar1();
                }
            }
        }
    }


}


//function that swaps the user entered coordinates
void swaping(char gameboard[10][10], int mode) {
    cout << "Which character you want to swap: \n";
p:
    cout << "Enter i of first character : ";
    int i1;
    cin >> i1;
    if (mode == 1) {
        if (i1 < 0 || i1 > 5) {
            cout << "Wrong Index\n";
            goto p;
        }

    }
    else {
        if (i1 < 0 || i1 > 9) {
            cout << "Wrong Index\n";
            goto p;
        }
    }
p1:
    cout << "Enter j of first character : ";
    int j1;
    cin >> j1;
    if (mode == 1) {
        if (j1 < 0 || j1 > 5) {
            cout << "Wrong Index\n";
            goto p1;
        }

    }
    else {
        if (j1 < 0 || j1 > 9) {
            cout << "Wrong Index\n";
            goto p1;
        }
    }
    cout << "\nYou Selected : " << gameboard[i1][j1];

    cout << "\nNow Press Arrow (w s a d) to move the Character : ";
    char a = _getch();
    if (a == 'w') {
        moves++;
        char temp = gameboard[i1][j1];
        gameboard[i1][j1] = gameboard[i1 - 1][j1];
        gameboard[i1 - 1][j1] = temp;

        if (!checkMatches(gameboard, mode)) {
            char temp = gameboard[i1][j1];
            gameboard[i1][j1] = gameboard[i1 - 1][j1];
            gameboard[i1 - 1][j1] = temp;
            printGameboard(gameboard, mode);
        }
        else {
            score += 10;
        repeat:
            updateBoard(gameboard, mode);
            if (checkMatches(gameboard, mode))
                goto repeat;
            else
                printGameboard(gameboard, mode);
        }

    }
    else if (a == 's') {
        moves++;
        char temp = gameboard[i1][j1];
        gameboard[i1][j1] = gameboard[i1 + 1][j1];
        gameboard[i1 + 1][j1] = temp;

        if (!checkMatches(gameboard, mode)) {
            char temp = gameboard[i1][j1];
            gameboard[i1][j1] = gameboard[i1 + 1][j1];
            gameboard[i1 + 1][j1] = temp;
            printGameboard(gameboard, mode);
        }
        else {
            score += 10;
        repeat1:
            updateBoard(gameboard, mode);
            if (checkMatches(gameboard, mode))
                goto repeat1;
            else
                printGameboard(gameboard, mode);
        }
    }
    else if (a == 'a') {
        moves++;
        char temp = gameboard[i1][j1];
        gameboard[i1][j1] = gameboard[i1][j1 - 1];
        gameboard[i1][j1 - 1] = temp;

        if (!checkMatches(gameboard, mode)) {
            char temp = gameboard[i1][j1];
            gameboard[i1][j1] = gameboard[i1][j1 - 1];
            gameboard[i1][j1 - 1] = temp;
            printGameboard(gameboard, mode);
        }
        else {
            score += 10;
        repeat2:
            updateBoard(gameboard, mode);
            if (checkMatches(gameboard, mode))
                goto repeat2;
            else
                printGameboard(gameboard, mode);
        }
    }
    else if (a == 'd') {
        moves++;
        char temp = gameboard[i1][j1];
        gameboard[i1][j1] = gameboard[i1][j1 + 1];
        gameboard[i1][j1 + 1] = temp;

        if (!checkMatches(gameboard, mode)) {
            char temp = gameboard[i1][j1];
            gameboard[i1][j1] = gameboard[i1][j1 + 1];
            gameboard[i1][j1 + 1] = temp;
            printGameboard(gameboard, mode);
        }
        else {
            score += 10;
        repeat3:
            updateBoard(gameboard, mode);
            if (checkMatches(gameboard, mode))
                goto repeat3;
            else
                printGameboard(gameboard, mode);
        }
    }

}

void sleep(int x) {
    while (x >= 0) {
    x--;
}
}