#include <iostream>
#include <fstream>
#include<string>
using namespace std;

void addStudent(string filename, int *studentCount, int *inStateFees, int *outStateFees){
    cout<<endl<<"Press any key to add Students details";
    getchar();
    ofstream file(filename.c_str(), ios::app);
    char name[50];
    cout<<endl<<"\n Enter Name of Student : ";
    gets(name);

    file<<endl<<name;

    int state=-1;
    cout<<endl<<"\n Press 1 for In-State or 2 for Out-Of-State : ";
    cin>>state;

    if(state==1)
        file<<" | In-State";
    else if(state==2)
        file<<" | Out-Of-State";
    else
        file<<" | NA";

    int tutionFees;
    cout<<endl<<"Enter Tution Fees : ";
    cin>>tutionFees;

    file<<" | "<<tutionFees;

    if(state==1){
        *inStateFees = *inStateFees + tutionFees;
    }
    else if(state==2){
        *outStateFees = *outStateFees + tutionFees ;
    }

    *studentCount = *studentCount + 1;
    file.close();
}

void generateReport(const string filename, const int *studentCount, const int *inStateFees, const int *outStateFees){
    if(*studentCount==0){
        cout<<endl<<"No record found.";
    }
    else{
        ofstream file(filename.c_str(), ios::app);
        file<<endl<<"Total Tuition Paid for all In-State Students : "<<*inStateFees;
        file<<endl<<"Total Tuition Paid for all Out-of-State Students : "<<*outStateFees;
        file.close();
        cout<<endl<<"Success: "<<filename<<" generated ";
    }

}


int main(int argc, char** argv) {

    int choice = 0;
    string fileName = "tuition_report.txt";
    int studentCount =0;
    int inStateFees = 0;
    int outStateFees =0;

    ofstream file(fileName.c_str(), ios::out);
    file.close();

    while(choice!=-1){
        cout<<endl<<"-----College Student Tuition--------"<<endl;
        cout<<endl<<"1 Add Student Details";
        cout<<endl<<"2 Generate Report";
        cout<<endl<<"-1 Exit";
        cout<<"\n\n Enter your choice : ";
        cin>>choice;

        switch(choice){
            case 1: addStudent(fileName, &studentCount, &inStateFees, &outStateFees);
                break;
            case 2: generateReport(fileName, &studentCount, &inStateFees, &outStateFees);
                break;
            case -1: cout<<endl<<"Thank you~~";
                break;
            default: cout<<endl<<"Invalid Choice.."; getchar();

        }

    }

    return 0;
}
