#include "headers/student.h"
#include <string>
#include <iostream>

Student::Student() {
    this->gradesArrPtr = nullptr;

    this->id = -1;
    this->behavior = -1;
    this->numberOfAwards = -1;
    this->numberOfGrades = -1;
}

Student::Student(int id, std::string grades) {
    this->id = id;
    this->setGrades(grades);
    this->numberOfAwards = 0;
}

Student::Student(const Student& student) : id(student.id), numberOfGrades(student.numberOfGrades) {
    gradesArrPtr = new int[this->numberOfGrades];

    for (int i = 0; i < this->numberOfGrades; i++) {
        this->gradesArrPtr[i] = student.gradesArrPtr[i];
    }
}

Student::~Student() {
    delete[] this->gradesArrPtr;
}

float Student::avgGrades() {
    int sum = 0;
    for(int i=0;i<this->numberOfGrades;i++){
        sum += *(this->gradesArrPtr+i);
    }

    return (float)sum/(float)this->numberOfGrades;
}

void Student::setGrades(std::string s) {

    std::string g = "";
    std::string b = "";
    std::string numberOfGrades = "";

    int k=0;
    int i=0;
    for(i=0;i<10 && k<3;i++){
        if(s[i] == ' '){
            k++;
            continue;
        }

        switch(k){
            case 0:
                g += s[i];
                break;
            case 1:
                b += s[i];
                break;
            case 2:
                numberOfGrades += s[i];
                break;
            default:
                break;
        }
    }

    this->behavior = stoi(b);
    this->numberOfGrades = stoi(numberOfGrades);

    int *arrPtr = new int[this->numberOfGrades];

    int j=0;
    for(;i<s.length();i++){
        if(s[i] == ' '){
            j++;
            continue;
        }
        arrPtr[j] = s[i] - 48;
    }

    this->gradesArrPtr = arrPtr;

    return;
}

int Student::fivePlusCounter() {
    int c =0;
    for(int i=0;i<numberOfGrades;i++){
        if(gradesArrPtr[i] >= 5) c++;
    }
    return c;
}