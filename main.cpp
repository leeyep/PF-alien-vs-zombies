// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T13L
// Names: LEE_HENG_YEP | ONG_KWANG_ZHENG
// IDs: 1211101790| 1211102806
// Emails: 1211101790@student.mmu.edu.my | 1211102806@student.mmu.edu.my
// Phones: 018-870-3882 | 017-368-4493
// *********************************************************

// todo:
// entities on board
// show hp and atk of alien and zombies
// movement
// rotation of arrow
// game over/you win
// video of p2

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
char Board[50][50];

void display_settingscreen(int &numofrows, int &numofcolumns, int &numofzombies) //Author: Ong Kwang Zheng + Lee Heng Yep
{
    cout << "Do You Wanna Change Your Game Setting? (1=Yes 2 = No) :";
    int temp;
    cin >> temp;
    if (temp == 1)
    {
        cout << "Number of rows (Odd numbers only) : ";
        cin >> numofrows;
        while (numofrows < 1 || numofrows > 15 || numofrows % 2 != 1)
        {
            cout << "Invalid input. Number of rows must be odd and between 1 and 15." << endl;
            cout << "Number of rows (Odd numbers only) : ";
            cin >> numofrows;
        }

        cout << "Number of columns (Odd numbers only) : ";
        cin >> numofcolumns;
        while (numofcolumns < 1 || numofcolumns > 49 || numofcolumns % 2 != 1)
        {
            cout << "Invalid input. Number of columns must be odd and between 1 and 49." << endl;
            cout << "Number of columns (Odd numbers only) : ";
            cin >> numofcolumns;
        }

        cout << "Number of zombies : ";
        cin >> numofzombies;
        while (numofzombies < 1 || numofzombies > 10)
        {
            cout << "Invalid input. Number of zombies must be between 1 and 10." << endl;
            cout << "Number of zombies : ";
            cin >> numofzombies;
        }
    }
    if (temp == 2)
    {
        cout << "Number of rows: " << numofrows << endl;
        cout << "Number of Columns:" << numofcolumns << endl;
        cout << "Number of Zombies:" << numofzombies << endl;
    }
}
void createBoard(int row, int column) //Author: Ong Kwang Zheng
{

    for (int rowcounter = 0; rowcounter < row; rowcounter++)
    {
        for (int columncounter = 0; columncounter < column; columncounter++)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        for (int columncounter = 0; columncounter < column; columncounter++)
        {
            cout << "|"
                 << Board[rowcounter][columncounter];
        }
        cout << "|" << endl;
    }
    for (int columncounter = 0; columncounter < column; columncounter++)
    {
        cout << "+-";
    }
    cout << "+" << endl;
}

void feature(int &numofrows, int &numofcolumns, int &numofzombies) // Author: Ong Kwang Zheng
{
    int random;
    int randomrows;
    int randomcolumns;
    srand(time(NULL));
    for (int rowcounter = 0; rowcounter < numofrows; rowcounter++)
    {
        for (int columncounter = 0; columncounter < numofcolumns; columncounter++)
        {
            random = rand() % 100;
            if (random < 20)
            {
                Board[rowcounter][columncounter] = 'p';
            }
            else if (random < 40)
            {
                Board[rowcounter][columncounter] = 'h';
            }
            else if (random < 45)
            {
                Board[rowcounter][columncounter] = '^';
            }
            else if (random < 50)
            {
                Board[rowcounter][columncounter] = 'v';
            }
            else if (random < 55)
            {
                Board[rowcounter][columncounter] = '<';
            }
            else if (random < 60)
            {
                Board[rowcounter][columncounter] = '>';
            }
            else if (random < 80)
            {
                Board[rowcounter][columncounter] = 'r';
            }
            else if (random < 100)
            {
                Board[rowcounter][columncounter] = ' ';
            }
        }
    }
    Board[numofrows / 2][numofcolumns / 2] = 'A';
    for (int zombiecounter = 0; zombiecounter < numofzombies; zombiecounter++)
    {
        randomrows = rand() % numofrows;
        randomcolumns = rand() % numofcolumns;
        if (Board[randomrows][randomcolumns] != 'A' || Board[randomrows][randomcolumns] != 'Z')
        {
            Board[randomrows][randomcolumns] = 'Z';
        }
    }

    createBoard(numofrows, numofcolumns);
}

// void userinput(char x)
// {
//     cout << "User input : ";
//     cin >> x;
//     x = toupper(x);
//     cout << endl;

//     switch (x)
//     {
//     case 'Help':
//         help::main();
//         break;
//     case 'Up':
//         cout << "Alien moves up" << endl;
//         // up movement
//         break;
//     case 'Down':
//         cout << "Alien moves down" << endl;
//         // down
//         break;
//     case 'Left':
//         cout << "Alien moves left" << endl;
//         // left
//         break;
//     case 'Right':
//         cout << "Alien moves right" << endl;
//         // right
//         break;
//     case 'SAve':
//         // save
//         break;
//     case 'Load':
//         // load
//         break;
//     case 'Quit':
//         // quit
//         break;
//     case 'Arrow':
//         // rotate arrow
//         break;

//     default:
//         cout << "Invalid command, please refer to command list *H* for list of commands" << endl;
//         break;
//     }
// }

class Alien
{
public:
    int HP = 100;
    int ATK = 10;
};

class Zoms
{
public:
    int HP = 100 + rand() % 250;
    int ATK = 20 + rand() % 40;
};

class Pods
{
public:
    int ATK = 10; // atk closest zombie
};

class Healthpack
{
public:
    int HP = 20; // adds hp to alien
};
int main() // Authors: Ong Kwang Zheng + Lee Heng Yep
{
    int numofrows = 3;
    int numofColumns = 5;
    int numofZombies = 1;
    int selection;

    char x;
    display_settingscreen(numofrows, numofColumns, numofZombies);
    feature(numofrows, numofColumns, numofZombies);
    // after spawning entities
    // userinput(x);
//     if (win = false)
//     {
//         userinput(x);
//     }
//     else if (win = true)
//     {
//         cout << "You Win!";
//         pf::Pause();
//         std::terminate();
//     }
}
