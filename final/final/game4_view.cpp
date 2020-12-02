#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "game4_view.h"
using namespace std;

vector <vector <int>> View4::startView() {

    vector <vector <int> > map(17, vector <int>(40, 0));
    map =
    {
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,1 ,2, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 6, 1, 1, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0, 0, 0, 0, 0, 1, 1, 1, 10, 1, 1, 1, 9, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,1 ,0 ,0 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };


    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            if (map[i][j] == 1)
                cout << "��";
            else if (map[i][j] == 0)
                cout << "  ";
            else if (map[i][j] != 1 && map[i][j] != 0)
                cout << "��";
        }
        cout << endl;
    }
    cout << endl;
    cout << "                Find where is the OOP class room!" << endl;

    return map;

}

vector <vector <int>> View4::classView(Classroom room) {


    vector <vector <int> > map(17, vector <int>(40, 0));
    map =
    {
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,1 ,0 ,0 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };

    int student_x = 0;
    int student_y = 0;

    srand(time(0));

    for (int i = 0; i < room.student_num; i++) {
        student_x = rand() % 28 + 9;
        student_y = rand() % 14 + 2;

        map[student_y][student_x] = 11;
    }

    int prof_x = rand() % 28 + 9;
    int prof_y = rand() % 14 + 2;

    map[prof_y][prof_x] = 12;

    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            if (map[i][j] == 1)
                cout << "��";
            else if (map[i][j] == 0)
                cout << "  ";
            else if (map[i][j] == 11)
                cout << "��";
            else if (map[i][j] == 12)
                cout << "��";
        }
        cout << endl;
    }
    cout << endl;
    cout << "                Find professor and answer the question!" << endl;



    return map;
}

string View4::quizView(Classroom enter_room) {

    string class_question = enter_room.getQuestion();

    string answer;
    bool correctness;

    int map[1][42] = {
    { 0 ,0 ,0, 0 ,0 ,0 ,0 ,0, 1 ,1 ,1 ,1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 42; j++)
        {
            if (map[i][j] == 1)
                cout << "=";
            else if (map[i][j] == 0)
                cout << "  ";
        }
        cout << endl;
    }

    //question print

    cout << "                ";
    cout << "Question : " << class_question << endl;

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 42; j++)
        {
            if (map[i][j] == 1)
                cout << "=";
            else if (map[i][j] == 0)
                cout << "  ";
        }
        cout << endl;
    }

    cout << "                ";
    cout << "Enter the answer : ";
    cin >> answer;

    return answer;
}