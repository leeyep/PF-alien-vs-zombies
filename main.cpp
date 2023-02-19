// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T13L
// Names: LEE_HENG_YEP | ONG_KWANG_ZHENG
// IDs: 1211101790| 1211102806
// Emails: 1211101790@student.mmu.edu.my | 1211102806@student.mmu.edu.my
// Phones: 018-870-3882 | 017-368-4493
// *********************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int ClearScreen()
{
#if defined(_WIN32)
    return std::system("cls");
#elif defined(__linux__) || defined(__APPLE__)
    return std::system("clear");
#endif
}

int Pause()
{
#if defined(_WIN32)
    return std::system("pause");
#elif defined(__linux__) || defined(__APPLE__)
    return std::system(R"(read -p "Press any key to continue . . . " dummy)");
#endif
}

char rockfeature();
char Board[50][50];
class Alien
{
public:
    int HP=100;
    int ATK=100;
    int rowlocation;
    int columnlocation;
};
class Zoms
{
public:
    int HP = 100 + rand() % 150;
    int ATK = 20 + rand() % 20;
    int range = 1 + rand() % 2;
    int rowLocation;
    int columnLocation;
};

void display_settingscreen(int &numofrows, int &numofcolumns, int &numofzombies) // Author: Ong Kwang Zheng + Lee Heng Yep
{
    cout << "ALIEN VS ZOMBIE" << endl;
    Pause();
    cout << "Do You Wanna Change Your Game Setting?" << endl;
    cout << "Default Game settings:" << endl;
    cout << "Number of rows:3" << endl;
    cout << "Number of Columns:5" << endl;
    cout << "Number of Zombie:1" << endl;
    cout << "(1=Yes 2 = No):";
    int temp;
    cin >> temp;
    while (temp != 1 && temp != 2)
    {
        cout << "Invalid Option!" << endl;
        cout << "===============" << endl;
        cout << "Do You Wanna Change Your Game Setting?" << endl;
        cout << "Default Game settings:" << endl;
        cout << "Number of rows:3" << endl;
        cout << "Number of Columns:5" << endl;
        cout << "Number of Zombie:1" << endl;
        cout << "(1=Yes 2 = No):";
        cin >> temp;
    }
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
void createBoard(int row, int column) // Author: Ong Kwang Zheng + Lee Heng Yep
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

void ZombieMovement(int &numofrow, int &numofcolumns, Zoms zombie[], int zombieCounter) // Author:Ong Kwang Zheng
{
    srand(time(NULL));
    int newposition;
    bool movement = false;
    for (int i = 0; i < zombieCounter; i++)
    {
        movement = false;
        while (movement == false)
        {
            newposition = 1 + rand() % 3;
            if (newposition == 1)
            {
                if (zombie[i].rowLocation - 1 >= 0 && Board[zombie[i].rowLocation - 1][zombie[i].columnLocation] != 'A' && Board[zombie[i].rowLocation - 1][zombie[i].columnLocation] != 'Z')
                {
                    Board[zombie[i].rowLocation][zombie[i].columnLocation] = ' ';
                    Board[zombie[i].rowLocation - 1][zombie[i].columnLocation] = 'Z';
                    zombie[i].rowLocation = zombie[i].rowLocation - 1;
                    movement = true;
                }
            }

            if (newposition == 2)
            {
                if (zombie[i].columnLocation + 1 < numofcolumns && Board[zombie[i].rowLocation][zombie[i].columnLocation + 1] != 'A' && Board[zombie[i].rowLocation][zombie[i].columnLocation + 1] != 'Z')
                {

                    Board[zombie[i].rowLocation][zombie[i].columnLocation] = ' ';
                    Board[zombie[i].rowLocation][zombie[i].columnLocation + 1] = 'Z';
                    zombie[i].columnLocation = zombie[i].columnLocation + 1;
                    movement = true;
                }
            }
            if (newposition == 3)
            {
                if (zombie[i].columnLocation - 1 >= 0 && Board[zombie[i].rowLocation][zombie[i].columnLocation - 1] != 'A' && Board[zombie[i].rowLocation][zombie[i].columnLocation - 1] != 'Z')
                {
                    Board[zombie[i].rowLocation][zombie[i].columnLocation] = ' ';
                    Board[zombie[i].rowLocation][zombie[i].columnLocation - 1] = 'Z';
                    zombie[i].columnLocation = zombie[i].columnLocation - 1;
                    movement = true;
                }
            }
            if (newposition == 4)
            {
                if (zombie[i].rowLocation + 1 < numofrow && Board[zombie[i].rowLocation + 1][zombie[i].columnLocation] != 'A' && Board[zombie[i].rowLocation + 1][zombie[i].columnLocation] != 'Z')
                {
                    Board[zombie[i].rowLocation][zombie[i].columnLocation] = ' ';
                    Board[zombie[i].rowLocation + 1][zombie[i].columnLocation] = 'Z';
                    zombie[i].rowLocation = zombie[i].rowLocation + 1;
                    movement = true;
                }
            }
        }
    }
    createBoard(numofrow, numofcolumns);
}
void alienmovement(int &numofrow, int &numofcolumns) // Author :Ong Kwang Zheng + Lee Heng Yep
{
    Alien alien;
    alien.rowlocation = numofrow / 2;
    alien.columnlocation = numofcolumns / 2;
    cout << "=============" << endl;
    cout << "|| 1=Up    ||" << endl;
    cout << "|| 2=Down  ||" << endl;
    cout << "|| 3=Left  ||" << endl;
    cout << "|| 4=Right ||" << endl;
    cout << "=============" << endl;
    cout << "Your Option? :";
    int y;
    cin >> y;
    while (y < 1 || y > 4)
    {
        cout << "Invalid Command!" << endl;
        cout << "===============-" << endl;
        cout << "=============" << endl;
        cout << "|| 1=Up    ||" << endl;
        cout << "|| 2=Down  ||" << endl;
        cout << "|| 3=Left  ||" << endl;
        cout << "|| 4=Right ||" << endl;
        cout << "=============" << endl;
        cout << "Your Option? :";
        cin >> y;
    }

    bool stop = false;

    if (y == 1) // Up ^
    {
    u:
        do
        {
            if (Board[alien.rowlocation - 1][alien.columnlocation] != 'r')
            {
                if (alien.rowlocation > 0)
                {
                    if (Board[alien.rowlocation - 1][alien.columnlocation] == 'h') // hp
                    {
                        alien.HP += 20;
                    }
                    else if (Board[alien.rowlocation - 1][alien.columnlocation] == 'p') // pod
                    {
                        if (Board[alien.rowlocation - 1][alien.columnlocation - 1] == 'Z' || Board[alien.rowlocation - 1][alien.columnlocation] == 'Z' || Board[alien.rowlocation - 1][alien.columnlocation + 1] == 'Z' ||
                            Board[alien.rowlocation][alien.columnlocation - 1] == 'Z' || Board[alien.rowlocation][alien.columnlocation + 1] == 'Z' || Board[alien.rowlocation + 1][alien.columnlocation - 1] == 'Z' || Board[alien.rowlocation + 1][alien.columnlocation] == 'Z' || Board[alien.rowlocation + 1][alien.columnlocation + 1] == 'Z')
                        {
                            // not done yet, unable to select zombies
                        }
                    }
                    else if (Board[alien.rowlocation - 1][alien.columnlocation] == '^' || Board[alien.rowlocation - 1][alien.columnlocation] == 'v' || Board[alien.rowlocation - 1][alien.columnlocation] == '<' || Board[alien.rowlocation - 1][alien.columnlocation] == '>')
                    {
                        alien.ATK += 10;
                        if (Board[alien.rowlocation - 1][alien.columnlocation] == '^')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation - 1][alien.columnlocation];
                            continue;
                        }
                        else if (Board[alien.rowlocation - 1][alien.columnlocation] == 'v')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation - 1][alien.columnlocation];
                            goto d;
                        }
                        else if (Board[alien.rowlocation - 1][alien.columnlocation] == '<')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation - 1][alien.columnlocation];
                            goto l;
                        }
                        else if (Board[alien.rowlocation - 1][alien.columnlocation] == '>')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation - 1][alien.columnlocation];
                            goto r;
                        }
                    }
                    Board[alien.rowlocation][alien.columnlocation] = '.';
                    Board[alien.rowlocation - 1][alien.columnlocation] = 'A';
                    alien.rowlocation = alien.rowlocation - 1;
                }
                else if (alien.rowlocation <= 0)
                {
                    alien.rowlocation = alien.rowlocation;
                    stop = true;
                }
            }
            else if (Board[alien.rowlocation - 1][alien.columnlocation] == 'r')
            {
                alien.rowlocation = alien.rowlocation;
                Board[alien.rowlocation - 1][alien.columnlocation] = rockfeature();
                stop = true;
            }
            else if (Board[alien.rowlocation - 1][alien.columnlocation] == '-')
            {
                alien.rowlocation = alien.rowlocation;
                stop = true;
            }
            else
            {
                stop = true;
            }
        } while (stop == false);
    }

    if (y == 2) // Down v
    {
    d:
        do
        {
            if (Board[alien.rowlocation + 1][alien.columnlocation] != 'r')
            {
                if (alien.rowlocation + 1 < numofrow)
                {
                    if (Board[alien.rowlocation + 1][alien.columnlocation] == 'h') // hp
                    {
                        alien.HP += 20;
                    }
                    else if (Board[alien.rowlocation + 1][alien.columnlocation] == 'p') // pod
                    {
                        if (Board[alien.rowlocation - 1][alien.columnlocation - 1] == 'Z' || Board[alien.rowlocation - 1][alien.columnlocation] == 'Z' || Board[alien.rowlocation - 1][alien.columnlocation + 1] == 'Z' ||
                            Board[alien.rowlocation][alien.columnlocation - 1] == 'Z' || Board[alien.rowlocation][alien.columnlocation + 1] == 'Z' || Board[alien.rowlocation + 1][alien.columnlocation - 1] == 'Z' || Board[alien.rowlocation + 1][alien.columnlocation] == 'Z' || Board[alien.rowlocation + 1][alien.columnlocation + 1] == 'Z')
                        {
                            // not done yet, unable to select zombies
                        }
                    }
                    else if (Board[alien.rowlocation + 1][alien.columnlocation] == '^' || Board[alien.rowlocation + 1][alien.columnlocation] == 'v' || Board[alien.rowlocation + 1][alien.columnlocation] == '<' || Board[alien.rowlocation + 1][alien.columnlocation] == '>')
                    {
                        alien.ATK += 10;
                        if (Board[alien.rowlocation + 1][alien.columnlocation] == '^')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation + 1][alien.columnlocation];
                            goto u;
                        }
                        else if (Board[alien.rowlocation + 1][alien.columnlocation] == 'v')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation + 1][alien.columnlocation];
                            continue;
                        }
                        else if (Board[alien.rowlocation + 1][alien.columnlocation] == '<')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation + 1][alien.columnlocation];
                            goto l;
                        }
                        else if (Board[alien.rowlocation + 1][alien.columnlocation] == '>')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation + 1][alien.columnlocation];
                            goto r;
                        }
                    }
                    Board[alien.rowlocation][alien.columnlocation] = '.';
                    Board[alien.rowlocation + 1][alien.columnlocation] = 'A';
                    alien.rowlocation = alien.rowlocation + 1;
                }
                else
                {
                    stop = true;
                }
            }
            else if (Board[alien.rowlocation + 1][alien.columnlocation] == 'r')
            {
                alien.rowlocation = alien.rowlocation;
                Board[alien.rowlocation - 1][alien.columnlocation] = rockfeature();
                stop = true;
            }
            else
            {
                stop = true;
            }
        } while (stop == false);
    }

    if (y == 3) // Left <--
    {
    l:
        do
        {
            if (Board[alien.rowlocation][alien.columnlocation - 1] != 'r')
            {
                if (alien.columnlocation - 1 >= 0)
                {
                    if (Board[alien.rowlocation][alien.columnlocation - 1] == 'h') // hp
                    {
                        alien.HP += 20;
                    }
                    else if (Board[alien.rowlocation][alien.columnlocation - 1] == 'p') // pod
                    {
                        if (Board[alien.rowlocation - 1][alien.columnlocation - 1] == 'Z' || Board[alien.rowlocation - 1][alien.columnlocation] == 'Z' || Board[alien.rowlocation - 1][alien.columnlocation + 1] == 'Z' ||
                            Board[alien.rowlocation][alien.columnlocation - 1] == 'Z' || Board[alien.rowlocation][alien.columnlocation + 1] == 'Z' || Board[alien.rowlocation + 1][alien.columnlocation - 1] == 'Z' || Board[alien.rowlocation + 1][alien.columnlocation] == 'Z' || Board[alien.rowlocation + 1][alien.columnlocation + 1] == 'Z')
                        {
                            // not done yet, unable to select zombies
                        }
                    }
                    else if (Board[alien.rowlocation][alien.columnlocation - 1] == '^' || Board[alien.rowlocation][alien.columnlocation - 1] == 'v' || Board[alien.rowlocation][alien.columnlocation - 1] == '<' || Board[alien.rowlocation][alien.columnlocation - 1] == '>')
                    {
                        alien.ATK += 10;
                        if (Board[alien.rowlocation][alien.columnlocation - 1] == '^')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation][alien.columnlocation - 1];
                            goto u;
                        }
                        else if (Board[alien.rowlocation][alien.columnlocation - 1] == 'v')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation][alien.columnlocation - 1];
                            goto d;
                        }
                        else if (Board[alien.rowlocation][alien.columnlocation - 1] == '<')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation][alien.columnlocation - 1];
                            goto l;
                        }
                        else if (Board[alien.rowlocation][alien.columnlocation - 1] == '>')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation][alien.columnlocation - 1];
                            goto r;
                        }
                    }
                    Board[alien.rowlocation][alien.columnlocation] = '.';
                    Board[alien.rowlocation][alien.columnlocation - 1] = 'A';
                    alien.columnlocation = alien.columnlocation - 1;
                }
                else
                {
                    stop = true;
                }
            }
            else if (Board[alien.rowlocation][alien.columnlocation - 1] == 'r')
            {
                alien.columnlocation = alien.columnlocation;
                Board[alien.rowlocation][alien.columnlocation - 1] = rockfeature();
                stop = true;
            }
            else if (Board[alien.rowlocation][alien.columnlocation - 1] == '|')
            {
                alien.columnlocation = alien.columnlocation;
                stop = true;
            }
            else
            {
                stop = true;
            }
        } while (stop == false);
    }

    if (y == 4) // Right -->
    {
    r:
        do
        {
            if (Board[alien.rowlocation - 1][alien.columnlocation + 1] != 'r')
            {
                if (alien.columnlocation + 1 < numofcolumns)
                {
                    if (Board[alien.rowlocation][alien.columnlocation + 1] == 'h') // hp
                    {
                        alien.HP += 20;
                    }
                    else if (Board[alien.rowlocation][alien.columnlocation + 1] == 'p') // pod
                    {
                        if (Board[alien.rowlocation - 1][alien.columnlocation - 1] == 'Z' || Board[alien.rowlocation - 1][alien.columnlocation] == 'Z' || Board[alien.rowlocation - 1][alien.columnlocation + 1] == 'Z' ||
                            Board[alien.rowlocation][alien.columnlocation - 1] == 'Z' || Board[alien.rowlocation][alien.columnlocation + 1] == 'Z' || Board[alien.rowlocation + 1][alien.columnlocation - 1] == 'Z' || Board[alien.rowlocation + 1][alien.columnlocation] == 'Z' || Board[alien.rowlocation + 1][alien.columnlocation + 1] == 'Z')
                        {
                            // not done yet, unable to select zombies
                        }
                    }
                    else if (Board[alien.rowlocation][alien.columnlocation + 1] == '^' || Board[alien.rowlocation][alien.columnlocation + 1] == 'v' || Board[alien.rowlocation][alien.columnlocation + 1] == '<' || Board[alien.rowlocation][alien.columnlocation + 1] == '>')
                    {
                        alien.ATK += 10;
                        if (Board[alien.rowlocation][alien.columnlocation + 1] == '^')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation][alien.columnlocation + 1];
                            goto u;
                        }
                        else if (Board[alien.rowlocation][alien.columnlocation + 1] == 'v')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation][alien.columnlocation + 1];
                            goto d;
                        }
                        else if (Board[alien.rowlocation][alien.columnlocation + 1] == '<')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation][alien.columnlocation + 1];
                            goto l;
                        }
                        else if (Board[alien.rowlocation][alien.columnlocation + 1] == '>')
                        {
                            Board[alien.rowlocation][alien.columnlocation] = Board[alien.rowlocation][alien.columnlocation + 1];
                            goto r;
                        }
                    }

                    Board[alien.rowlocation][alien.columnlocation] = '.';
                    Board[alien.rowlocation][alien.columnlocation + 1] = 'A';
                    alien.columnlocation = alien.columnlocation + 1;
                }
                else
                {
                    stop = true;
                }
            }
            else if (Board[alien.rowlocation][alien.columnlocation + 1] == 'r')
            {
                alien.columnlocation = alien.columnlocation;
                Board[alien.rowlocation][alien.columnlocation + 1] = rockfeature();
                stop = true;
            }
            else if (Board[alien.rowlocation][alien.columnlocation + 1] == '|')
            {
                alien.columnlocation = alien.columnlocation;
                stop = true;
            }
        } while (stop == false);
    }
    createBoard(numofrow, numofcolumns);
}

void arrowspinnythingy(int numofrows, int numofcolumns)
{
    for (int i = 0; i < numofrows; i++)
    {
        for (int j = 0; j < numofcolumns; j++)
        {
            if (Board[i][j] == '^')
            {
                Board[i][j] = '>';
            }
            else if (Board[i][j] == '>')
            {
                Board[i][j] = 'v';
            }
            else if (Board[i][j] == 'v')
            {
                Board[i][j] = '<';
            }
            else if (Board[i][j] == '<')
            {
                Board[i][j] = '^';
            }
        }
    }
    createBoard(numofrows, numofcolumns);
}

void feature(int &numofrows, int &numofcolumns, int &numofzombies) // Author: Ong Kwang Zheng
{
    Alien alien;
    Zoms zombie[numofzombies];
    int zombieCounter = 0;
    {
        int randomrows;
        int randomcolumns;
        int newposition;
        int random;
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
                else if (random < 70)
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
            if (Board[randomrows][randomcolumns] != 'A' && Board[randomrows][randomcolumns] != 'Z')
            {
                Board[randomrows][randomcolumns] = 'Z';
                zombie[zombieCounter].rowLocation = randomrows;
                zombie[zombieCounter].columnLocation = randomcolumns;
                zombieCounter++;
            }
        }
        createBoard(numofrows, numofcolumns);
    }
    cout << "Alien HP:" << alien.HP << "   "
         << "Alien ATK:" << alien.ATK << endl;
    for (int zombiecounter = 0; zombiecounter < numofzombies; zombiecounter++)
    {
        cout << "Zombie" << zombiecounter + 1 << " "
             << "HP:" << zombie[zombiecounter].HP << "   "
             << "Zombie" << zombiecounter + 1 << " "
             << "ATK:" << zombie[zombiecounter].ATK << "   "
             << "Zombie" << zombiecounter + 1 << " "
             << "Range:" << zombie[zombiecounter].range << endl;
    }
    // ZombieMovement(numofrows,numofcolumns,zombie,zombieCounter);// was testing something

    // cout << "Zombie1 HP:" << zombie.HP << "   " << "Zombie1 ATk:" << zombie.ATK << endl;
}

void userinput(int &numofrow, int &numofcolumns, Alien &alien,int &numofzombies)
{
    int x;
    Zoms zombie[numofzombies];
    int zombieCounter = 0;
    cout << "=====================" << endl;
    cout << "||1=Help           ||" << endl;
    cout << "||2=Alien Movement ||" << endl;
    cout << "||3=Arrow          ||" << endl;
    cout << "||4=Save           ||" << endl;
    cout << "||5=Load           ||" << endl;
    cout << "||6=Quit           ||" << endl;
    cout << "=====================" << endl;
    cout << "User input : ";
    cin >> x;
    while (x < 1 || x > 6)
    {
        cout << "Invalid Input!" << endl;
        cout << "==============" << endl;
        cout << "=====================" << endl;
        cout << "||1=Help           ||" << endl;
        cout << "||2=Alien Movement ||" << endl;
        cout << "||3=Arrow          ||" << endl;
        cout << "||4=Save           ||" << endl;
        cout << "||5=Load           ||" << endl;
        cout << "||6=Quit           ||" << endl;
        cout << "=====================" << endl;
        cout << "User input : ";
        cin >> x;
    }
    if (x == 1)
    {
        std::string commands[] = {"Up", "Down", "Left", "Right", "Arrow", "Help", "Save", "Load", "Quit"};
        std::string descriptions[] = {"Command Alien to move up", "Command Alien to move down", "Command Alien to move left", "Command Alien to move right", "Rotate arrow clockwise", "Show Command that can be used in game", "Save The Current Game Progession", "Load Saved Game Progession", "Quit Current Game"};

        std::cout << "Game Help List:" << std::endl;
        for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
        {
            std::cout << commands[i] << ": " << descriptions[i] << std::endl;
        }
    }
    else if (x == 2)
    {
        alienmovement(numofrow, numofcolumns);
        cout << "Zombie move"<<endl;
        cout << "VVVVVVVVVVV" << endl;
        ZombieMovement(numofrow,numofcolumns,zombie,zombieCounter);
    }
    else if (x == 3)
    {
        arrowspinnythingy(numofrow, numofcolumns);
    }
    else if (x == 6)
    {
        cout << "Thank you for playing" << endl;
        terminate();
    }
    cout << "Alien HP:" << alien.HP << "   "
         << "Alien ATK:" << alien.ATK << endl;
}

char rockfeature()
{
    int random = rand() % 70;
    if (random < 10)
    {
        return 'p';
    }
    else if (random < 20)
    {
        return 'h';
    }
    else if (random < 30)
    {
        return '^';
    }
    else if (random < 40)
    {
        return 'v';
    }
    else if (random < 50)
    {
        return '<';
    }
    else if (random < 60)
    {
        return '>';
    }
    else if (random < 70)
    {
        return ' ';
    }
    return 0;
}

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
    int numofcolumns;
    int selection;
    int zombieCounter;
    Zoms zombie;
    Alien alien;
    char x;
    int draw;
    bool gg;
    alien.HP = 100;
    alien.ATK = 0;

    display_settingscreen(numofrows, numofColumns, numofZombies);
    feature(numofrows, numofColumns, numofZombies);
    do
    {
        userinput(numofrows, numofColumns, alien,numofZombies);
        draw += 1;
        Pause();
        ClearScreen();
        if (alien.HP == 0)
        {
            gg = true;
            cout << "You lose!" << endl;
        }
        else if (zombieCounter == 0)
        {
            gg = true;
            cout << "You win!" << endl;
        }
        else if (draw >= 100) // failsafe
        {
            cout << "Draw!" << endl;
        }
    } while (gg == false && draw <= 100);
}
