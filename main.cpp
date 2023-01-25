// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TxxL 
// Names: LEE_HENG_YEP | ONG_KWANG_ZHENG
// IDs: 1211101790| MEMBER_ID_2
// Emails: 1211101790@student.mmu.edu.my | MEMBER_EMAIL_2
// Phones: MEMBER_PHONE_1 | MEMBER_PHONE_2
// ********************************************************* 

// TODO: Fill in the missing information above and delete this line.

#include "pf/helper.cpp"
#include <iostream>
using namespace std;


void display_settingscreen(int numofrows, int numofcolumns, int numofzombies)
{
    a:
    cout << "Number of rows : ";
    cin >> numofrows;
    if (numofrows < 1 || numofrows > 10)
    {
        cout << "number is invalid, cannot be less than 1 or more than 10" << endl;
        goto a;
    }

    b:
    cout << "Number of columns : ";
    cin >> numofcolumns;
    if (numofcolumns < 1 || numofcolumns > 10)
    {
        cout << "number is invalid, cannot be less than 1 or more than 10" << endl;
        goto b;
    }

    c:
    cout << "Number of zombies";
    cin >> numofzombies;
    if (numofzombies < 1 || numofzombies > 10)
    {
        cout << "number is invalid, cannot be less than 1 or more than 10" << endl;
        goto c;
    }

}
int main()
{
    cout << "Alien vs Zombies" << endl;
    cout << "Let's Get Started!" << endl;
    pf::Pause();

    int numofrows = 1;
    int numofcolumns = 1;
    int numofzombies = 1;
    display_settingscreen(numofrows,numofcolumns,numofzombies);
}