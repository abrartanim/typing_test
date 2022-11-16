#include <iostream>
#include <conio.h>

#include "main_function.h"

int main(void)
{
    system("CLS");
    cout << "\n\t\t\tWelcome to Typing Tutor !!!!";
    cout << "\n\n\t\t\tEnter your name to proceed: ";
    cin >> name;
    int x = 1;
    int choice;
    while (x = 1)
    {
        system("CLS");
        cout << "\n\t\t\t\tHello Tanim. Please choose an option from below: ";
        cout << "\n\t\t\t1. Practice\n\t\t\t2. Show records\n\t\t\t3. Delete records\n\t\t\t4. Exit";
        cout << "\n\t\t\tYour choice ==>";
        cin >> choice;

        switch (choice)
        {
        case (1):
            system("CLS");

            chose_mode();
            //practice();
            //info_add();
            getch();
            break;

        case (2):
            system("CLS");
            show_info("records.txt");
            getch();
            break;

        case (3):
            system("CLS");
            delete_info();
            getch();
            break;

        case (4):
            cout << "\n\t\t\tThanks for using typing tutor!!!" << endl;
            return 0;
        }
    }

    getch();
    return 0;
}