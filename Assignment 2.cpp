// Filename: Assignment 2.cpp
//------------------------------
// Author: Syed Nasif Ali (201304650)
// Course: CSCI 162
// Date: 11 February 2016
// Purpose: This program works as a Banking System which creates files storing
//the Balance and transaction record for customers.

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


// Structure Declaration

struct BalanceT
{
   int    id;
   string  name;
   double sum;

};


struct TransactionT
{
   int    pin;
   string description;
   double change;

};

//Function Declaration

bool ReadBalance (ifstream &infile, BalanceT*s);
bool ReadTransaction(ofstream &outtrans, ifstream& transaction, TransactionT*t);
void WriteBalanceOut(ofstream& statement, ofstream& outfile, BalanceT*s);
void UpdateBalance (ofstream &statement, BalanceT*s, TransactionT*t );
void OverDraft (ofstream &statemnet, BalanceT*s);
void OnScreen (BalanceT*s);
void WriteStatementOut1(ofstream& statement, BalanceT*s);
void WriteStatementOut2(ofstream& statement, TransactionT*t, BalanceT*s);


int main()
{

   ifstream infile("balance.txt");
   ofstream outfile("balanceout.txt");
   ifstream transaction ("transaction.txt");
   ofstream statement ("statementout.txt");
   ofstream outtrans ("trans.txt");
   BalanceT Balance;
   TransactionT Transaction;

   if (infile.fail() || outfile.fail() || transaction.fail()|| statement.fail () || outtrans.fail())
   {
      cout << "Error in file access!" << endl;
      return 0;
   }

    while (ReadBalance(infile, &Balance))
   {
       WriteStatementOut1(statement, &Balance);


       while (ReadTransaction(outtrans, transaction, &Transaction) && (Transaction.pin == Balance.id))
       {
            UpdateBalance(statement, &Balance, &Transaction);

           WriteStatementOut2(statement, &Transaction, &Balance);

       }
   OnScreen(&Balance);
   WriteBalanceOut(statement, outfile, &Balance);

}
return 0;
}

bool ReadBalance(ifstream &infile, BalanceT*s)
{
    infile >> s->id;
    if (infile.eof()) return false;

    getline(infile, s->name, '$');
    infile >> s->sum;

return true;
}

bool ReadTransaction (ofstream &outtrans, ifstream &transaction, TransactionT*t)

{
   transaction >> t->pin;
    if (transaction.eof()) return false;

    getline(transaction, t->description, '$');
    transaction >> t->change;
     outtrans << t->pin << setw(5) << t-> description << setw(11) << t-> change << endl;
}

void WriteBalanceOut(ofstream& statement, ofstream &outfile, BalanceT*s)
{
    outfile << s->id << " " << s->name << " " << s->sum << "\n";

    statement << "\n" << "Final Balance " << setw(37) << s->sum << "\n";
}

void UpdateBalance (ofstream &statement, BalanceT*s, TransactionT*t)
{
    s->sum += t->change;
}
void OverDraft(ofstream &statement, BalanceT*s)
{
   s->sum -= 5;
   statement << "OverDraft" << setw(27) << "5.00" << setw(15) << s->sum << "\n";
}
void OnScreen(BalanceT*s)
{
    if (s->sum < 0 || s->sum > 10000) cout << setprecision(2) << fixed << s->id << " " << s->name << " $ " << s->sum << "\n";
}
void WriteStatementOut1(ofstream &statement, BalanceT*s)
{
   statement << " First Antigonish Bank \n\n";

   statement << " Statement for " << s->name << "\n\n\n";

   statement << "Item " << setw(22) << "Deposit" << setw(13) << "Withdrawl" << setw(11) << "Balance" << "\n\n\n";

   statement << "Starting Balance:" << setw(34) << s->sum << "\n\n\n";
}

void WriteStatementOut2(ofstream &statement, TransactionT*t, BalanceT*s)
{
    int a, b, temp;
    temp = t-> change;
  statement << "\n";
  statement << t->description;

    if (t->change < 0)
  {
      a = 24;
      b = 15;
      temp = temp * -1;
  }
  else
 {
    a = 15;
    b = 24;
  }

  statement << setw(a) << temp << setw(b) << s-> sum<< "\n";
    if (s->sum < 0 && t->change < 0) (OverDraft(statement, s));
}
