#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct studentInfo
{
    string name;
    string lastName;
    int extraCredits;
};

/*-----------------------Stdent Info-------------------------*/
class Student
{
  private:
    studentInfo marcosExtraCredit;

  public:
    Student(); // sets member variables to their null states with respect to their datatype
    void asignCredits(int);
    studentInfo getStudentInfo();
};

Student::Student()
{
    marcosExtraCredit.extraCredits = 0; //stings are NULL by default
};

void Student::asignCredits(int numOfCredits)
{
    marcosExtraCredit.extraCredits = numOfCredits;
    marcosExtraCredit.name = "Marco";
    marcosExtraCredit.lastName = "Ramirez";
};

studentInfo Student::getStudentInfo()
{
    return marcosExtraCredit;
};
/*---------------------End of Student Info----------------------*/

/*-----------------------Interaction block-----------------------------*/
class Interaction
{
  private:
    char iLoveStudents;

  public:
    Interaction();
    int numOfCredits;

    void isACoolProfessor();
    bool isGenerous();
    char getLove() { return iLoveStudents; };
    bool validation();
    void hateStudents() { cout << endl
                               << "YOUR RESPONSE: "
                               << "No!, I hate students, I want them to Fail, Specially Marco, he's stupid..."; };
};

Interaction::Interaction()
{
    numOfCredits = 0;
};

bool Interaction::isGenerous()
{
    while (numOfCredits < 50)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
            cout << endl
                 << "Just play along dude, this code is bug free, please enter a good amount of credits, no tricks ";
        };
        cout << "Come on! you can do better, lets try again..." << endl;
        cin >> numOfCredits;
    };
    return true;
};

bool Interaction::validation()
{
    while (iLoveStudents != 'n' && iLoveStudents != 'N' && iLoveStudents != 'Y' && iLoveStudents != 'y')
    {
        cout << "We both know that ain't gonn work, please answer y or n" << endl;
        cin >> iLoveStudents;
    };

    if (iLoveStudents == 'Y' || iLoveStudents == 'y')
    {
        cout << "I'm glad to hear that because cool professors give extra credit!... How many extra credits would you like to donate?" << endl;
        cin >> numOfCredits;
        isGenerous();

        return true;
    }
    else if (iLoveStudents == 'n' || iLoveStudents == 'N')
    {
        return false;
    };
};

void Interaction::isACoolProfessor()
{
    cin >> iLoveStudents;
};

/*-------------------End of Interaction block---------------------------*/

int main()
{
    Student Marco;
    Interaction DrErasmo;
    studentInfo stuedntSatus;
    bool iLoveStudents;

    cout << "Are you a cool Professor? [y/n]";

    DrErasmo.isACoolProfessor();
    iLoveStudents = DrErasmo.validation();

    if (iLoveStudents)
    {
        DrErasmo.isGenerous();
        Marco.asignCredits(DrErasmo.numOfCredits);
        stuedntSatus = Marco.getStudentInfo();
        cout << endl
             << "Thank you! that was very generous, Here's your student's status: " << endl
             << endl
             << "Name: " << stuedntSatus.name << endl
             << "Last Name: " << stuedntSatus.lastName << endl
             << "Extra Credits Given: " << stuedntSatus.extraCredits << endl
             << endl;
        return EXIT_SUCCESS;
    }
    else
    {
        DrErasmo.hateStudents();
        cout << endl
             << endl
             << "ALERT!!: "
             << "that was super rude of you Dr Erasmo! you can't call a student stupid, that would be terrible, wanna try again?";
        DrErasmo.isACoolProfessor();
        iLoveStudents = DrErasmo.validation();
        if (!iLoveStudents)
        {   
            cout << endl;
            DrErasmo.hateStudents();
            cout << endl
                 << endl
                 << endl
                 << endl
                 << "Damn dog! u ain't know me like dat, peace out!" << endl
                 << endl;
            return EXIT_FAILURE;
        }
        else
        {
            DrErasmo.isGenerous();
            Marco.asignCredits(DrErasmo.numOfCredits);
            stuedntSatus = Marco.getStudentInfo();
            cout << "Thank you! that was very generous, Here's your student's status: " << endl
                 << endl
                 << "Name: " << stuedntSatus.name << endl
                 << "Last Name: " << stuedntSatus.lastName << endl
                 << "Extra Credits Given: " << stuedntSatus.extraCredits << endl
                 << endl;
            return EXIT_SUCCESS;
        }
    };
};
