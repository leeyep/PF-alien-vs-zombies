// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TxxL 
// Names: LEE_HENG_YEP | ONG_KWANG_ZHENG
// IDs: 1211101790| 1211102806
// Emails: 1211101790@student.mmu.edu.my | 1211102806@student.mmu.edu.my
// Phones: MEMBER_PHONE_1 | 017-368-4493
// ********************************************************* 


#include "pf/helper.h"
#include <iostream>
using namespace std;

// void Gamesetting(int &selection)
//{
//    cout << "Your Selection is =";
//    int temp;
//    cin >> temp;
//
//    const int Numberofrows = 3;
//    const int NumberofColumns = 5;
//    const int NumberofZombies = 1;
//    int Numbofrows;
//    int NumbofColumns;
//    int NumbofZombies;
//    if (temp == 1)
//        ;
//    cout << "Numbers of rows:(#only odd numbers)" << endl;
//    cin >> Numbofrows;
//    cout << "Number of columns: " << endl;
//    cin >> NumbofColumns;
//    cout << "Number of Zombies" << endl;
//    cin >> NumbofZombies;

//   if (temp == 2)
//    cout << "Number of rows: " << Numberofrows << endl;
//    cout << "Number of Columns:" << NumberofColumns << endl;
//    cout << "Number of Zombies:" << NumberofZombies << endl;
//} <-----------------------------------------------------------------------(DONT DELETE YET NOT CONFIRMED)
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
int row;
int column;
char board[15][15];
void Createboard(int row, int column)
{
    for (int rows = 0; rows < row; rows++)
    {
        for (int columns = 0; columns < column; columns++)
        {
            if (rows % 2 == 0 && columns % 2 == 0)
            {
                board[rows][columns] = '+';
            }
            else if (rows % 2 == 0)
            {
                board[rows][columns] = '-';
            }
            else if (columns % 2 == 0)
            {
                board[rows][columns] = '|';
            }
            else
            {
                board[rows][columns] = ' ';
            }
        }
    }
}
void printBoard(int row, int column)
{
    for (int rows = 0; rows < row; rows++)
    {
        for (int columns = 0; columns < column; columns++)
        {
            if (rows % 2 == 0 && columns % 2 == 0)
            {
                std::cout << "+";
            }
            else if (rows % 2 == 0)
            {
                std::cout << "-";   
            }
            else if (columns % 2 == 0)
            {
                std::cout << "|";
                if (columns == column - 1)
                    std::cout << " ";
            }
            else
            {
                if (rows == 0)
                {
                    std::cout << "  ";
                }
            }
        }
        cout << endl;
    }
}
int main()
{
    int Numbofrows;
    int NumbofColumns;
    int NumbofZombies;
    cout << "Numbers of rows:(#only odd numbers)" << endl;
    cin >> Numbofrows;
    cout << "Number of columns: " << endl;
    cin >> NumbofColumns;
    cout << "Number of Zombies" << endl;
    cin >> NumbofZombies;

    cout << "Number of rows=" << Numbofrows << endl;
    cout << "Number of Columns=" << NumbofColumns << endl;
    cout << "Number of Zombies=" << NumbofZombies << endl;
    cout << "Game setting has been updated"<< endl;
    Createboard(Numbofrows, NumbofColumns);
    printBoard(Numbofrows,NumbofColumns);
}