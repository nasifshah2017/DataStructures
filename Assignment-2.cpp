#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


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





bool ReadBalance (ifstream &infile, BalanceT*s);
bool ReadTransaction(ifstream& transaction, TransactionT*t);
//bool WriteTransaction(ofstream&);


int main()
{
    //ifstream infile;
    //Balance ENtry;

    ifstream infile("balance.txt");
   ofstream outfile("balanceout.txt");
   ifstream transaction ("transaction.txt");
   //ofstream statement ("statementout.txt");
   BalanceT Balance;
   TransactionT Transaction;

   if (infile.fail() /*|| outfile.fail() */|| transaction.fail()) //|| statement.fail ())
   {
      cout << "Error in file access!" << endl;
      return 0;
   }

   //ReadBalance(infile, &Balance);

   while (ReadBalance(infile, &Balance))
   {
     cout << "!" << "\n";
   }

   ReadTransaction (transaction, &Transaction);





    return 0;
}

bool ReadBalance(ifstream &infile, BalanceT*s)
{


    //int  i;
    //char comma, space;


    infile >> s->id;
    if (infile.eof()) return false;

    getline(infile, s->name, '$');
    infile >> s->sum;

   cout << s->id  << " " << s->name << " " << s->sum << endl;





    return true;

}

bool ReadTransaction (ifstream &transaction, TransactionT*t)

{
   transaction >> t->pin;
    if (transaction.eof()) return false;

    getline(transaction, t->description, '$');
    transaction >> t->change;

   cout << t->pin  << " " << t->description << " " << t->change << endl;





}

