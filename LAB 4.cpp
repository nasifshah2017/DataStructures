/* Filename: LAB 16.cpp
 * -------------------
 * Author: Syed Nasif Ali Shah
 * Course: CSci 162
 * Date:   28/29 January 2016
 *
 * Purpose: It arranges a file by placing the last name of the students at
 * the front, and also calculates the final marks from all the marks
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#define NumAssign   5       // Number of assignments
#define NumQuiz     2       // Number of quizzes

struct studentT
{
   int    id;
   string fname, sname;
   int    assign[NumAssign], quiz[NumQuiz], exam;
   double mark;
};

/* Function Prototypes */

bool ReadStudent(ifstream &infile, studentT *s);
void CalcMark(studentT *s);
void WriteStudent(ofstream &outfile, studentT *s);

/* Main Program */

int main()
{
   studentT student;

   ifstream infile("marks.txt");
   ofstream outfile("marksout.txt");

   if (infile.fail() || outfile.fail())
   {
      cout << "Error in file access!" << endl;
      return 0;
   }

   outfile << "ID" << setw(13) << "Name" << setw(21)
           << "A1" << setw(4) << "A2" << setw(4)
           << "A3" << setw(4) << "A4" << setw(4)
           << "A5" << setw(4) << "Q1" << setw(5)
           << "Q2" << setw(7) << "Exam" << setw(6)
           << "Mark" << "\n";

   while (ReadStudent(infile, &student))
   {
      CalcMark(&student);
      WriteStudent(outfile, &student);
   }

   infile.close();
   outfile.close();

   return 0;
}

/* Function: ReadStudent
 * Usage: if (ReadStudent(infile, &student))
 * -----------------------------------------
 * Attempts to read the next student record from infile.
 * Assumes the file contains complete records, so detects
 * end of file when it attempts to read the id number.
 * Returns true of record successfully read, false otherwise.
 */

bool ReadStudent(ifstream &infile, studentT *s)
{
    int  i;
    char comma, space;

    infile >> s->id;
    if (infile.eof()) return false;

    infile >> comma >> s->fname;

    infile.get(space);

    getline(infile, s->sname, ',');

    for (i=0; i<NumAssign; i++) infile >> s->assign[i] >> comma;

    for (i=0; i<NumQuiz; i++) infile >> s->quiz[i] >> comma;

    infile >> s->exam;

    return true;
}

/* Function: CalcMark
 * Usage: CalcMark(&student);
 * --------------------------
 * Calculates and records the final course grade for the student
 * in the structure containing the student's other grades.
 *
 * Currently sets the grade to 50%.
 */

void CalcMark(studentT *s)
{

    s->mark = 50.0;
}

/* Function: WriteStudent
 * Usage: WriteStudent(outfile, &student);
 * ---------------------------------------
 * Writes to screen a poorly formatted version of the student record.
 * Supposed to write a well-formatted version to the outfile.
 */

void WriteStudent(ofstream &outfile, studentT *s)
{
    int i;
    double m = 0, n = 0, p = 0, mark;



    outfile << left << setw(11) << s->id
         << setw(20) << (s->sname + ", " + s->fname) << right;

for(i = 0; i<NumAssign; i++)
     {
         outfile << setw(4)<< s->assign[i];

         m = m + s->assign [i];
     }

m = (m/50)*20;







for (i = 0; i<NumQuiz; i++)
     {

         outfile << setw(5) << s-> quiz[i];


         n = n + s->quiz [i];


    }

n = (n/200)*40;

   outfile << setw(6) << s->exam << " ";

     p = ((double)(s->exam*40)/100);

      mark = m + n + p;

    outfile << setprecision(1) << fixed << setw(6) << mark << "\n";

}
