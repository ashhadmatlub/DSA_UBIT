#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct SNode
{
    int SNum;
    SNode *Snext;
};

struct CNode
{
    int CNum;
    CNode *Cnext;
    SNode *StuList;
};

CNode *Clist = NULL;
bool crs_flag = false;

void insertCourse(int CrcNum)
{
    crs_flag = true;
    CNode *temp;
    temp = (CNode *)malloc(sizeof(CNode));
    temp->CNum = CrcNum;
    temp->Cnext = NULL;
    temp->StuList = NULL;

    if (Clist == NULL)
    {
        Clist = temp;
    }
    else
    {
        CNode *Ccurr = Clist;
        while (Ccurr->Cnext != NULL)
        {
            if (Ccurr->CNum == CrcNum)
            {
                cout << "Course with the same code already exists \n";
                return;
            }
            Ccurr = Ccurr->Cnext;
        }
        Ccurr->Cnext = temp;
    }
}

void insertStudents(int CNumber, int SNum)
{
    CNode *Ccurr = Clist;
    while (Ccurr != NULL)
    {
        SNode *STemp;
        if (Ccurr->CNum == CNumber)
        {
            STemp = (SNode *)malloc(sizeof(SNode));
            STemp->SNum = SNum;
            STemp->Snext = NULL;

            if (Ccurr->StuList == NULL)
            {
                Ccurr->StuList = STemp;
                return;
            }
            else
            {
                SNode *Scurr = Ccurr;
                while (Scurr != NULL)
                {
                    SNode *scurrent = Ccurr->StuList;
                    while (scurrent != NULL)
                    {

                        if (scurrent->SNum == SNum)
                        {
                            cout << "The Student with the same ID already exists in this course \n";
                            return;
                        }
                        scurrent = scurrent->Snext;
                    }
                    Scurr = Scurr->Snext;
                }
                Scurr->Snext = STemp;
            }
        }

        Ccurr = Ccurr->Cnext;
    }
    cout << "The Course with this code doesn't exists \n";
    return;
}

void display()
{
    if (Clist == NULL)
    {
        cout << "Course list is empty \n";
        return;
    }
    CNode *Ccurrent = Clist;
    while (Ccurrent != NULL)
    {
        cout << Ccurrent->CNum;
        if (Ccurrent->StuList == NULL)
        {
            cout << " : There are no Students enrolled in this Course \n";
        }
        else
        {
            cout << " \n Students enrolled in this course are given below \n";
            while (Ccurrent->StuList != NULL)
            {
                cout << Ccurrent->StuList->SNum << "\n";
                Ccurrent->StuList = Ccurrent->StuList->Snext;
            }
        }
        Ccurrent = Ccurrent->Cnext;
    }
}
int main()
{
    bool flag = true;
    int input, times, value;
    while (flag)
    {
        cout << "Enter: 1 : Add a Course , 5 : To add Students in a course, 11: To Display All , 12 : To Exit => ";
        cin >> input;

        if (input == 1)
        {
            bool crs_flag = false;
            cout << "How many course do you want to add ? : ";
            cin >> times;
            for (int i = 0; i < times; i++)
            {
                cout << "Enter Course Code ( Must be unique ): ";
                cin >> value;
                insertCourse(value);
            }
        }
        else if (input == 5)
        {
            if (crs_flag == true)
            {

                int C_ID, Std_ID;
                cout << "Enter Course Code: ";
                cin >> C_ID;
                cout << "Enter Student ID : ";
                cin >> Std_ID;
                insertStudents(C_ID, Std_ID);
            }
            else
            {
                cout << "Course list is empty \n";
            }
        }
        else if (input == 11)
        {
            display();
        }
        else if (input == 12)
        {
            flag = false;
        }
        else
        {
            cout << "Invalid Input \n";
        }
    }
}