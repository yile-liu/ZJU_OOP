#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>

#define PRINTWIDTH 10
#define INVALID (-1)

using namespace std;

struct scoreClass {
    int courseNo;
    int courseScore;

    scoreClass(int newNo, int newScore) {
        courseNo = newNo;
        courseScore = newScore;
    }
};

struct courseClass {
    string name;
    int courseNo;
    int minScore, maxScore, sumScore, studentsNum;

    courseClass(string newName, int newNo) {
        name = newName;
        courseNo = newNo;
        minScore = INVALID;
        maxScore = INVALID;
        sumScore = INVALID;
        studentsNum = 0;
    }
};

class studentClass {
    string name;
    vector<scoreClass> taken;

public:
    studentClass(string newName) {
        name = newName;
    }

    void takeNewCourse(int courseNo, int score) {
        scoreClass newTaken = scoreClass(courseNo, score);
        auto iter = taken.begin(), end = taken.end();
        while (iter != end && (*iter).courseNo < courseNo) ++iter;
        taken.insert(iter, newTaken);
    }

    void printInfo(int coursesCnt, int printWidth) {
        //print name
        cout << setw(printWidth) << name;
        //print courses score
        int takenCnt = 0, totalScore = 0;
        auto iter = taken.begin(), end = taken.end();
        for (int i = 0; i < coursesCnt; ++i) {
            if (iter != end && (*iter).courseNo == i) {
                cout << setw(printWidth) << (*iter).courseScore;
                ++takenCnt;
                totalScore += (*iter).courseScore;
                ++iter;
            } else {
                cout << setw(printWidth) << "NULL";
            }
        }
        //print avg score of this student
        cout << setw(printWidth) << (double) totalScore / takenCnt << endl;
    }
};

/*
 * int getCourseNo(vector<courseClass *> &courses, string name):
 *
 * return course number in vector with specific name.
 * automatically vector.push_back(name) as a new course and assign it a number
 * if name is not found in vector
 */
int getCourseNo(vector<courseClass *> &courses, string name) {
    auto iter = courses.begin(), end = courses.end();
    int cnt = 0;
    for (; iter != end; ++iter, ++cnt) {
        if ((*iter)->name == name) return (*iter)->courseNo;
    }
    auto newCourse = new courseClass(name, cnt);
    courses.push_back(newCourse);
    return cnt;
}

void printHeadLine(vector<courseClass *> courses) {
    //print in this format:
    //no    name    courseName1 courseName2 ......  average
    cout << setw(PRINTWIDTH) << "no" << setw(PRINTWIDTH) << "name";
    auto coursesIter = courses.begin(), coursesEnd = courses.end();
    for (; coursesIter != coursesEnd; ++coursesIter)
        cout << setw(PRINTWIDTH) << (*coursesIter)->name;
    cout << setw(PRINTWIDTH) << "average" << endl;
}

void printStudentsInfo(vector<studentClass *> students, vector<courseClass *> courses) {
    auto studentsIter = students.begin(), studentsEnd = students.end();
    for (int i = 1; studentsIter != studentsEnd; ++studentsIter, ++i) {
        //print no.
        cout << setw(PRINTWIDTH) << i;
        //print student info
        (*studentsIter)->printInfo(courses.size(), PRINTWIDTH);
    }
}

void printCoursesInfo(vector<courseClass *> courses) {
    auto iter = courses.begin(), end = courses.end();
    //avg score
    cout << setw(PRINTWIDTH) << " " << setw(PRINTWIDTH) << "average";
    for (; iter != end; ++iter)
        cout << setw(PRINTWIDTH) << (double) ((*iter)->sumScore / (double) (*iter)->studentsNum);
    cout << endl;
    //min score
    iter = courses.begin(), end = courses.end();
    cout << setw(PRINTWIDTH) << " " << setw(PRINTWIDTH) << "min";
    for (; iter != end; ++iter)
        cout << setw(PRINTWIDTH) << (*iter)->minScore;
    cout << endl;
    //max score
    iter = courses.begin(), end = courses.end();
    cout << setw(PRINTWIDTH) << " " << setw(PRINTWIDTH) << "max";
    for (; iter != end; ++iter)
        cout << setw(PRINTWIDTH) << (*iter)->maxScore;
    cout << endl;
}

int main() {
    string name;
    int score, courseNo;
    vector<studentClass *> students;
    vector<courseClass *> courses;

    //get new student name
    cout << "Input a student name without space, input '#' if you want to exit: " << endl;
    cin >> name;
    while (name[0] != '#') {
        auto newStudent = new studentClass(name);
        students.push_back(newStudent);
        //get new course and score a student take
        cout << "Input course id/name and score one by one seperated by space," << endl;
        cout << "input # after finished: " << endl;
        cin >> name;
        while (name[0] != '#') {
            //update student taken info
            cin >> score;
            courseNo = getCourseNo(courses, name);
            newStudent->takeNewCourse(courseNo, score);
            //update courses info
            if (courses[courseNo]->minScore == INVALID || courses[courseNo]->minScore > score)
                courses[courseNo]->minScore = score;
            if (courses[courseNo]->maxScore == INVALID || courses[courseNo]->maxScore < score)
                courses[courseNo]->maxScore = score;
            if (courses[courseNo]->sumScore == INVALID)
                courses[courseNo]->sumScore = 0;
            courses[courseNo]->sumScore += score;
            ++courses[courseNo]->studentsNum;
            //next course name
            cin >> name;
        }
        //next student name
        cout << "Input a student name without space, input '#' if you want to exit: " << endl;
        cin >> name;
    }

    cout.setf(ios::left);
    //output headline
    printHeadLine(courses);
    //output student no., name, scores of each course and avg score
    printStudentsInfo(students, courses);
    //output avg score, min score and max score of each course
    printCoursesInfo(courses);

    return 0;
}