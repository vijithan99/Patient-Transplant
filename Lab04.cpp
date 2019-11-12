//============================================================================
// Name        : Lab04.cpp
// Author      : Vijithan Mangaleswaran
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

enum blood {A, AB, B, O};
enum organ {Heart, Kidney, Lung, Liver};

struct patientinfo {
    string firstname;
    string lastname;
    blood bloodtype;
    organ organtype;
    int age;
    int year;
};

patientinfo patient[100];
patientinfo secpatient [100];

void tokenizeandfillup (stringstream& str, patientinfo& patient);
void processtoken(int toknum, string& tok, patientinfo& patient);
void displayinfo (patientinfo myarray[], int id);

void addfile(patientinfo patient[], int idnumber);
void writeintofilestream (patientinfo emparray[], ofstream& outputfilestream, int arraysize);
void readfromfile(ifstream& inputfilestream, patientinfo secpatient[], int number);

int main (int argc, const char* argv[]){

    int choice;
    string astring;

    int id = 0;

    ifstream inputfilestream;
    inputfilestream.open(argv[1]);
    if (inputfilestream.is_open()){
        readfromfile(inputfilestream, secpatient, id);
        inputfilestream.close();
        }
   else cout <<"\nUnable to open file" << endl;




    while(1){
        cout << "ORGAN TRANSPLANT LIST:" << endl;
        cout << "There are currently " << id << " patient(s) in the list." << endl;
        cout << "   ";
        cout << "Please choose an option:" << endl;
        cout << "1. Add Patients" << endl;
        cout << "2. Show Patients" << endl;
        cout << "3. Quit" << endl;
        cout << "4. Save List" << endl;
        cout << ">>  ";
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cout << "\n\n";
        cout << "=============================" <<endl;

        if (choice == 1){
            cout << "[Add Patient]" <<endl;
            getline(cin, astring, '\n');
            cout <<".. [Adding]\n" << endl;
            stringstream ss;
            ss.str(astring);

            tokenizeandfillup (ss, patient[id]);

            ss.str("");
            ss.clear();
            id++;
        }
        else if (choice == 2){
            cout << "[Show Patients]" <<endl;
            displayinfo (patient, id);
        }

        else if (choice == 3){
            cout << "Program Ended." << endl;
            break;
        }

        else if (choice == 4){
            cout << "..[Saving file]" << endl;
            addfile (patient, id);
        }


    }


    return 0;
}

void tokenizeandfillup (stringstream& str, patientinfo& patient){
string token;
int num = 1;

    while (str >> token){
    processtoken(num, token, patient);
        num ++;
    }
}

void processtoken(int toknum, string& tok, patientinfo& patient){
size_t pos = 0;

    if (1 == toknum){
    patient.firstname = tok;
            char last = tok.at(pos);
        patient.firstname = last;
    }

    if (2 == toknum){
        patient.lastname = tok;
    }
    if (3 == toknum){
    if (0 == tok.compare("Heart"))
        patient.organtype = Heart;
    if (0 == tok.compare("Kidney"))
        patient.organtype = Kidney;
    if (0 == tok.compare("Lung"))
        patient.organtype = Lung;
    if (0 == tok.compare("Liver"))
        patient.organtype = Liver;}
    if (4 == toknum){
        if (0 == tok.compare("A"))
        patient.bloodtype = A;
        if (0 == tok.compare("AB"))
            patient.bloodtype = AB;
        if (0 == tok.compare("B"))
            patient.bloodtype = B;
        if (0 == tok.compare("O"))
            patient.bloodtype = O;
    }
    if (5 == toknum)
        patient.age = atoi(tok.c_str());
    if (6 == toknum)
        patient.year = atoi(tok.c_str());

}

void displayinfo (patientinfo myarray[], int arraysize) {
 string tab = "\t\t";
  cout << "\nID    \t" <<"Name"<< tab << "Blood\t" << "Organ\t" << "Age"<< tab << "Waiting Since" << endl;
         cout <<"---------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < arraysize; i++){

            cout << i + 1 << "\t";

        cout << myarray[i].lastname << ", ";

        cout << myarray[i].firstname << "\t";

        if (AB == myarray[i].bloodtype) {
            cout << "AB" << tab;
        }
        if (A == myarray[i].bloodtype){
            cout << "A" << tab;
        }
        if (B == myarray[i].bloodtype){
            cout << "B" << tab;
        }
        if (O == myarray[i].bloodtype){
            cout << "O" << tab;
        }

        if (Heart == myarray[i].organtype){
                cout << "Heart" << tab;
                }
        if (Lung == myarray[i].organtype){
            cout << "Lung" << tab;
        }
        if (Liver == myarray[i].organtype){
            cout << "Liver" << tab;
            }
        if (Kidney == myarray[i].organtype){
            cout << "Kidney" << tab;
            }

        cout << myarray[i].age << tab;
        cout <<myarray[i].year << "\n";
    }
}

void addfile(patientinfo info[], int idnumber){
int count;
ofstream outputfilestream;

outputfilestream.open("transplantPatients.txt");
if (outputfilestream.is_open()){
    writeintofilestream (info,outputfilestream, idnumber);
    outputfilestream.close();
}
else cout << "\nUnable to open file" << endl;

}

void writeintofilestream (patientinfo patientarray[], ofstream& outputfilestream, int lenofarray){
 string space = " ";

int counter = 0;
outputfilestream << "Number of Patients is " << lenofarray << endl;
for (int i = 0; i < lenofarray; i++){

outputfilestream << patientarray[i].firstname << space << patientarray[i].lastname << space;
	if (Heart == patientarray[i].organtype){
        outputfilestream << "Heart" << space;
        }
   if (Lung == patientarray[i].organtype){
    outputfilestream << "Lung" << space;
  }
   if (Liver == patientarray[i].organtype){
    outputfilestream << "Liver" << space;
    }
   if (Kidney == patientarray[i].organtype){
    outputfilestream << "Kidney" << space;
    }
    if (AB == patientarray[i].bloodtype) {
    outputfilestream << "AB" << space;
  }
   if (A == patientarray[i].bloodtype){
    outputfilestream << "A" << space;
  }
   if (B == patientarray[i].bloodtype){
    outputfilestream << "B" << space;
  }
   if (O == patientarray[i].bloodtype){
    outputfilestream << "O" << space;
  }
  outputfilestream << patientarray[i].age << space << patientarray[i].year << endl;
  counter++;
}

}





void readfromfile(ifstream& inputfilestream, patientinfo secpatient[], int number){
stringstream ss;
string textline;
int num = 0;


   while(getline(inputfilestream, textline)){

	   ss.str( textline );
       tokenizeandfillup (ss, secpatient[num]);

       num++;
       ss.str("");
       ss.clear();
   }
   string tab = "\t\t";

   for (int i = 1; i < num; i++){

        cout << i + number << tab;
        cout << secpatient[i].lastname << ", ";
        cout << secpatient[i].firstname << "\t";

     if (Heart == secpatient[i].organtype){
           cout << "Heart" << tab;
           }
      if (Lung == secpatient[i].organtype){
       cout << "Lung" << tab;
     }
      if (Liver == secpatient[i].organtype){
       cout << "Liver" << tab;
       }
      if (Kidney == secpatient[i].organtype){
       cout << "Kidney" << tab;
       }
     if (AB == secpatient[i].bloodtype) {
       cout << "AB" << tab;
     }
      if (A == secpatient[i].bloodtype){
       cout << "A" << tab;
     }
      if (B == secpatient[i].bloodtype){
       cout << "B" << tab;
     }
      if (O == secpatient[i].bloodtype){
       cout << "O" << tab;
     }
      cout << secpatient[i].age << tab;

      cout << secpatient[i].year << "\n";
   }
}
