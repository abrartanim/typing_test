#ifndef MAIN_FUNCTION_H
#define MAIN_FUNCTION_H

#include <stdio.h>
#include <iostream>
#include <fstream> //for writting and reading files
#include <string>
#include <chrono> //requried for high resolution clock funtion
//#include <thread>
#include <conio.h>   //used for getch
#include <windows.h> //used for the sleep function
#include <sstream>   //using istringstream
#include <vector>

#include "date.h" //library created by Howard Hinnat

using namespace std;
using namespace date;
using namespace std::chrono;

//global variables
string sample;
int word_count;
double time_taken;
string name;
int wpm;

//show comments
void Comments(string a)
{
    //system("CLS");
    vector<string> date;
    vector<string> name02;
    vector<int> wpm02;
    vector<string> mode;
    string line;

    ifstream file;

    //string a = "records.txt";
    file.open("records.txt");

    for (line; getline(file, line);)
    {
        string date01, name01, mode01, garbage;
        int wpm01;
        istringstream input(line);

        input >> date01;

        date.push_back(date01);

        input >> garbage;

        input >> name01;

        name02.push_back(name01);

        input >> mode01;

        mode.push_back(mode01);

        input >> wpm01;

        wpm02.push_back(wpm01);
    }

    int length = name.size();

    for (int i = 0; i < length - 2; i++)
    {
        if (name02[i] == name && mode[i] == a)
        {
            if (wpm02[i] == wpm)
            {
                break;
            }

            if (wpm02[i] < wpm)
            {
                cout << "\n\t\t\tYour previous speed was " << wpm02[i] << " and your current speed is " << wpm;
                cout << "\n\t\t\tGreat work, keep it up !!!";
            }

            else
            {
                cout << "\n\t\t\tYour previous speed was " << wpm02[i] << " and your current speed is " << wpm;
                cout << "\n\t\t\tKeep trying, you will eventually reach your goal";
            }

            break;
        }
    }

    int count = 0;
    for (int j = 0; j < length; j++)
    {

        if (name02[j] == name)
        {

            count++;
        }
    }

    if (count == 0)
    {
        cout << "\n\t\t\tThank you for trying out Typing Tutor " << name << ". Practice hard to increase your tyong speed. Good Luck !!!";
    }
}
//used to read the sample provided
void show_sample(string a)
{
    word_count = 1;
    string sample01;
    ifstream openfile(a);
    if (openfile.is_open())
    {
        while (!openfile.eof())
        {
            getline(openfile, sample);
            break;
            // cout << endl
            //      << "\t\t" << sample;
        }
    }
    openfile.close();

    int i = 0;
    ifstream file(a);
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, sample01);
            if (i != 0)
            {

                cout << endl
                     << "\t\t" << sample01;
            }

            i++;
        }
    }

    else
    {
        cout << "Cannot open file" << endl;
    }
    file.close();

    for (int j = 0; sample[j] != '\0'; j++)
    {
        if (sample[j] == ' ')
        {
            word_count++;
        }
    }
    //cout << word_count;
}

//used to calculate duration of a functtion
struct Timer
{
    time_point<chrono::high_resolution_clock> start, end; //declaring start time and time
    duration<float> duration;                             //represents time interval

    Timer()
    {
        start = high_resolution_clock::now(); // saves start time at start
    }

    ~Timer()
    {
        end = high_resolution_clock::now(); //saves end time at end
        duration = end - start;
        //cout << duration;
        //done because of date.h
        cout << "\n\t\t\tTime taken: " << duration << " seconds";
        time_taken = duration.count(); //done to match type
        int wpm = word_count / (time_taken / 60);
        cout << "\n\t\t\tYour Speed: " << wpm << " WPM!!!";
    }
};

//stopwatch for timer
void stopwatch()
{
    int h = 0;
    int m = 0;
    int s = 3;
    for (;;)
    {
        if (h == 0 && m == 0 && s == 0)
        {
            break;
        }
        if (s == 0 && m == 0)
        {
            m = 60;
            h--;
        }
        if (s == 0)
        {
            s = 60;
            m--;
        }

        s--;
        //cout << h << ":" << m << ":" << s--;
        Sleep(1000);
    }
}

void practice()
{
    Timer time;
    //stopwatch();
    int a;
    cin.ignore();
    string input;

    getline(cin, input);
    int count = 0, extra_characters = 0;

    int length = sample.length();

    for (int i = 0; i < input.length(); i++)
    {
        if (sample[i] != input[i])
        {
            count++;
        }
    }

    if (input.length() > length)
    {
        cout << "\n\t\t\tExtra chracters: " << input.length() - length;
    }

    cout << "\n\t\t\tErrors detected: " << count << endl;
}

void info_add(string a)
{
    int calculate;
    auto timenow =
        chrono::high_resolution_clock::now();

    ofstream file;
    file.open("records.txt", ofstream::app | ofstream::out);
    calculate = word_count / (time_taken / 60);
    wpm = calculate;

    file << (timenow) << " " << name << " " << a << " " << wpm << endl;

    file.close();
}

//shows information

void show_info(string a)
{
    system("CLS");
    vector<string> date;
    vector<string> name;
    vector<string> wpm;
    vector<string> mode;
    vector<string> time;
    string line;

    ifstream file;

    //string a = "records.txt";
    file.open(a);

    for (line; getline(file, line);)
    {
        string date01, name01, wpm01, mode01, time01;
        istringstream input(line);

        input >> date01;

        date.push_back(date01);

        input >> time01;

        time.push_back(time01);

        input >> name01;

        name.push_back(name01);

        input >> mode01;

        mode.push_back(mode01);

        input >> wpm01;

        wpm.push_back(wpm01);
    }

    string time02;
    for (int i = 0; i < date.size(); i++)
    {
        time02 = time[i].substr(0, 8);
        cout << "\n\t\t\t" << i + 1 << ". Date: " << date[i] << " Time: " << time02 << " Name: " << name[i] << " Mode: " << mode[i] << " WPM: " << wpm[i] << endl;
    }
}

//deletes records

void delete_info()
{
    system("CLS");
    int line_delete;
    cout << "\n\t\t\tWhich line do you want to delete: " << endl
         << endl;
    show_info("records.txt");

    cout << "\n\t\t\tYour choice ==> ";
    cin >> line_delete;
    string getcontent, tempstring, getcontent01, tempstring01;
    int count = 1;
    ifstream openfile("records.txt");
    if (openfile.is_open())
    {
        while (!openfile.eof())
        {
            getline(openfile, getcontent);

            if (count != line_delete)
            {
                ofstream temp("temp.txt", ofstream ::app | ofstream ::out);
                if (getcontent.length() == 0)
                {
                    continue;
                }
                temp << getcontent << endl;
            }
            count++;
        }
    }
    openfile.close();

    remove("records.txt");
    rename("temp.txt", "records.txt");
}

//level choosing
void chose_mode()
{
    int choice;
    cout << "\n\t\t\tEnter mode\n\t\t\t1. Easy\n\t\t\t2. Medium\n\t\t\t3. Hard\n\n\t\t\tYour choice ==> ";
    cin >> choice;

    switch (choice)
    {
    case (1):

        cout << "\t\tThe practice will start in 3 seconds";
        stopwatch();
        cout << endl;
        system("CLS");
        cout << "\t\t";
        show_sample("sample1.txt");

        cout << "\n\n\t\t\tWrite the above sentence below: " << endl
             << endl;
        practice();
        info_add("Easy");
        getch();
        Comments("Easy");
        getch();

        break;

    case (2):
        cout << "\t\tThe practice will start in 3 seconds";
        stopwatch();
        cout << endl;
        system("CLS");
        cout << "\t\t";
        show_sample("sample2.txt");

        cout << "\n\n\t\t\tWrite the above sentence below: " << endl
             << endl;
        practice();
        info_add("Medium");
        Comments("Medium");
        break;

    case (3):
        cout << "\t\tThe practice will start in 3 seconds";
        stopwatch();
        cout << endl;
        system("CLS");
        cout << "\t\t";
        show_sample("sample3.txt");

        cout << "\n\n\t\t\tWrite the above sentence below: " << endl
             << endl;
        practice();
        info_add("Hard");
        Comments("Hard");
        break;

    default:
        cout << "INVALID\n";
        break;
    }
}

//adds information to text files and stores them

// void info_add(void)
// {

//     ofc.open("check.txt", ofstream::out | ofstream::app);

//     total.open("total-expenditure.txt", ofstream::out | ofstream::app);
//     cout << "Enter expense: ";
//     cin >> expense;

//     cout << "Enter amount: ";
//     cin >> amount;

//     ofc << expense << " : " << amount << endl;

//     total << amount << " : " << expense << endl;
//     ;

//     ofc.close();
// }

#endif