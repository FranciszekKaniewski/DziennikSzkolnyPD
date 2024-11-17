#include <iostream>
#include <fstream>
#include <string>
#include "headers/student.h"
#include "headers/group.h"

using namespace std;
int main(){

    Group diary[8];
    for(int i=0;i<8;i++){
        diary[i] = Group(i);
    }

    fstream f;
    f.open("uczniowie.txt", ios::in);

    string l;
    while(getline(f, l)){
        diary[l[0]-48 - 1].addStudentToGroup(l);
    }


    float highestStudentAvgOfAll = 0.0f;
    for(int i=0;i<8;i++){
//        cout<<"==================== Grupa "<< i+1 <<" ===================="<<endl; //TEST
        float highestStudentAvg = 0.0f;

        for(int j=0;j<diary[i].numberOfStudents;j++){
            float studentAvg = diary[i].studentsArr[j]->avgGrades();
            if(highestStudentAvg < studentAvg){
                highestStudentAvg = studentAvg;
            }
            if(highestStudentAvgOfAll < studentAvg){
                highestStudentAvgOfAll = studentAvg;
            }
        }

        for(int j=0;j<diary[i].numberOfStudents;j++){
            float studentAvg = diary[i].studentsArr[j]->avgGrades();

            if(studentAvg == highestStudentAvg) {
                diary[i].studentsArr[j]->numberOfAwards ++;
//                cout<<"Student id:"<<diary[i].studentsArr[j]->id<<" otrzymuje nagrode za najwysza srednia w klasie!"<<endl;  //TEST
            }
        }
//        cout<< "Najwyzsza srednia: "<<highestStudentAvg <<endl<<endl; //TEST
    }


    for(int i=0;i<8;i++){
        for(int j=0;j<diary[i].numberOfStudents;j++){
            float studentAvg = diary[i].studentsArr[j]->avgGrades();
            if(studentAvg == highestStudentAvgOfAll) {
                diary[i].studentsArr[j]->numberOfAwards ++;
//                cout<<"Student id:"<<diary[i].studentsArr[j]->id<<" z grupy "<<i+1<<" otrzymuje nagrode za najwysza srednia w szkole!"<<endl; //TEST
                diary[i].studentsArr[j]->numberOfAwards ++;
            }
            if(diary[i].studentsArr[j]->fivePlusCounter() >= 5){
//                cout<<"Student id:"<<diary[i].studentsArr[j]->id<<" z grupy "<<i+1<<" otrzymuje nagrode za conajmniej 5 piatek+!"<<endl; //TEST
                diary[i].studentsArr[j]->numberOfAwards ++;
            }
            if(diary[i].studentsArr[j]->behavior == 6){
//                cout<<"Student id:"<<diary[i].studentsArr[j]->id<<" z grupy "<<i+1<<" otrzymuje nagrode za ocene 6 z zachowania!"<<endl; //TEST
                diary[i].studentsArr[j]->numberOfAwards ++;
            }
        }
    }

    int arr[5] = {0,0,0,0,0};
    for(int i=0;i<8;i++){
        for(int j=0;j<diary[i].numberOfStudents;j++){
            int studentAwards = diary[i].studentsArr[j]->numberOfAwards;
            arr[studentAwards] ++;
        }
    }
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" Studentow orzymalo "<<i<<" nagrod"<<endl;
    }

    Student studentsCopyArr[8];
    for(int i=0;i<8;i++){
        studentsCopyArr[i] = *(diary[i].studentsArr[0]);
    }

//    //TEST
//    for(int i=0;i<8;i++){
//        cout<<"\nOceny kopi studenta o id:"<<studentsCopyArr[i].id<<endl;
//        for(int j=0;j<studentsCopyArr[i].numberOfGrades;j++)
//            cout<<studentsCopyArr[i].gradesArrPtr[j]<<"|";
//        cout<<endl;
//    }



    f.close();
    return 0;
}
