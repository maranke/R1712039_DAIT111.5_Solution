/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Student.h
 * Author: R17117855
 *
 * Created on 24 April 2019, 13:14
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include<cstring>
#include "Student.h"

using namespace std;


class Student {
    
public:
   Student();
Student(int studID,int reconumber,int lascdnumber, char* StdntNam, char* StdntAdrs, char* Studntpne);
   void GetStudent() ;
   void WriteToFile(Student student);
   void GetRecordDetails() ;
   void ReadFromFile(streamsize position);
   void ReadRecordPosition() ;
   
private:
  int studentID;
  int recordnumber;
  int lastcode;
    char StudentName[40];
    char StudentAdress[60];;
    char Studentphonenum[30];

};

#endif /* STUDENT_H */

