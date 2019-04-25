/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Student.cpp
 * 
 * Created on 24 April 2019, 13:14
 */

#include "Student.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include<cstring>
#include "Student.h"

using namespace std;

    Student::Student() {
    }

    Student::Student(int studID,int reconumber,int lascdnumber, char* StdntNam, char* StdntAdrs, char* Studntpne) {
      studentID= studID;
      recordnumber=reconumber;
      lastcode=lascdnumber
        strcpy(StudentName,StdntNam);
       strcpy(StudentAdress, StdntAdrs);
        strcpy(Studentphonenum,Studntpne);

    }
    void Student::GetStudent() {
        cout << "\n";
        cout << "Student Name...." << StudentName << endl;
        cout << "Student Record number...." <<  recordnumber<< endl;
        cout << "Student lastcode number..." << lastcode << endl;
        cout << "Student name ...." << StudentName<< endl;
        cout << "Student Adresss..." <<StudentAdress  << endl;
         cout << "Parent Phone number...." <<Studentphonenum<< endl;
    }
void Student::GetRecordDetails() {
    char opt;
    char ch;

    int sID;
    int recordNum;
    int lastcode;
    char sName[40];
    char sAdres[50];
    char sPhone[50];
  

    do {
        cout << "Enter ID..";
        cin >> sID;
        cout << "Enter record number..";
        cin >>recordNum ;
          cout << "Enter last code .";
        cin >> lastcode;
        
        cin.ignore();
        
        cout << "Enter Student Name..";
        cin.getline(sName, 40);
        cout << "Enter Student Address..";
         cin.getline(sAdres, 50);
          cout << "Enter Phone..";
         cin.getline(sPhone,50);
        Student student( sID, recordNum,lastcode, sName, sAdres, sPhone);
        WriteToFile(student);

        cout << "Another record <y-yes n-no>" << endl;
        opt = getchar();
        cin.ignore();

    } while (opt != 'n');


}
void Student::WriteToFile(Student student) {

    ofstream outFile("students", ios::app | ios::binary);
    outFile.write((char*) &student, sizeof (Student));
    outFile.flush();

    if (outFile)
        cout << "\nRecord saved successfully" << endl;
    else
        cout << "Error saving file" << endl;

    outFile.close();

}

void Student::ReadRecordPosition() {
    streamsize position;
    cout << "Enter the record number to retrieve...";
    cin>>position;
    ReadFromFile(position);
}

void Student::ReadFromFile(streamsize position) {
    Student student;

    ifstream inFile("students", ios::in | ios::binary);

    inFile.seekg(sizeof (Student)*(position - 1), ios::beg);
    inFile.read((char *) &student, sizeof (Student));
    student.GetStudent();
}

