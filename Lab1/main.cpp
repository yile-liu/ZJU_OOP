#include <iostream>
#include <iomanip>
#include <string>

#define STUDENT_NUM 10
#define COURSE_NUM 3

using namespace std;

/*
    FindAvg/FindMin/FindMax:

    obj == "student": return the average/min/max score of the num-th student in double/int/int
    obj == "course": return the average/min/max score of the num-th course in double/int/int
    
    Index starts from 0.
*/
double FindAvg(string obj, int num, int score[STUDENT_NUM][COURSE_NUM]) {
    double avg = 0;
    if (obj == "student" && num < STUDENT_NUM) {
        for (int i = 0; i < COURSE_NUM; i++) {
            avg += score[num][i];
        }
        avg /= COURSE_NUM;
    } else if (obj == "course" && num < COURSE_NUM) {
        for (int i = 0; i < STUDENT_NUM; i++) {
            avg += score[i][num];
        }
        avg /= STUDENT_NUM;
    } else {
        exit(-1);
    }

    return avg;
}

int FindMin(string obj, int num, int score[STUDENT_NUM][COURSE_NUM]) {
    int min;
    if (obj == "student" && num < STUDENT_NUM) {
        min = score[num][0];
        for (int i = 1; i < COURSE_NUM; i++)
            min = min < score[num][i] ? min : score[num][i];
    } else if (obj == "course" && num < COURSE_NUM) {
        min = score[0][num];
        for (int i = 1; i < STUDENT_NUM; i++)
            min = min < score[i][num] ? min : score[i][num];
    } else {
        exit(-1);
    }

    return min;
}

int FindMax(string obj, int num, int score[STUDENT_NUM][COURSE_NUM]) {
    int max;
    if (obj == "student" && num < STUDENT_NUM) {
        max = score[num][0];
        for (int i = 1; i < COURSE_NUM; i++)
            max = max > score[num][i] ? max : score[num][i];
    } else if (obj == "course" && num < COURSE_NUM) {
        max = score[0][num];
        for (int i = 1; i < STUDENT_NUM; i++)
            max = max > score[i][num] ? max : score[i][num];
    } else {
        exit(-1);
    }

    return max;
}

int main() {
    string name[STUDENT_NUM];
    int score[STUDENT_NUM][COURSE_NUM];
    cout.setf(ios::left);

    //guide text
    cout << "Student number: " << STUDENT_NUM << endl;
    cout << "Course number: " << COURSE_NUM << endl;
    cout << "Please input data in this format:" << endl;
    cout << "name score1 score2 score3 ......" << endl;

    //input
    for (int i = 0; i < STUDENT_NUM; i++) {
        cin >> name[i];
        for (int j = 0; j < COURSE_NUM; j++)
            cin >> score[i][j];
    }

    //output headline
    cout << setw(8) << "no" << setw(8) << "name";
    for (int j = 0; j < COURSE_NUM; j++)
        cout << "score" << setw(3) << j + 1;
    cout << setw(8) << "average" << endl;

    //output student info
    for (int i = 0; i < STUDENT_NUM; i++) {
        cout << setw(8) << i + 1 << setw(8) << name[i];
        for (int j = 0; j < COURSE_NUM; j++)
            cout << setw(8) << score[i][j];
        cout << setw(8) << FindAvg("student", i, score) << endl;
    }

    //output course info
    cout << setw(8) << " " << setw(8) << "average" <<
         setw(8) << FindAvg("course", 0, score) <<
         setw(8) << FindAvg("course", 1, score) <<
         setw(8) << FindAvg("course", 2, score) << endl;
    cout << setw(8) << " " << setw(8) << "min" <<
         setw(8) << FindMin("course", 0, score) <<
         setw(8) << FindMin("course", 1, score) <<
         setw(8) << FindMin("course", 2, score) << endl;
    cout << setw(8) << " " << setw(8) << "max" <<
         setw(8) << FindMax("course", 0, score) <<
         setw(8) << FindMax("course", 1, score) <<
         setw(8) << FindMax("course", 2, score) << endl;

    system("pause");
    return 0;
}
