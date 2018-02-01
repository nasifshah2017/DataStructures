// Filename: Assignment 3.cpp
//------------------------------
// Author: Syed Nasif Ali (201304650)
// Course: CSCI 162
// Date: 2016/03/10
// Purpose: This program works as the Blackjack Game played in Casinos
// The user can play against the dealer by drawing cards, and at the
// end the one with the cards closer to 21 will win the game.


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "deck.h"
#include "random.h"



using namespace std;

void dealCards ();
void dealThirdCard ();
void dealFourthCard ();
void StandGame ();
void StandGame2 ();
void StandGame3 ();


int playerCard1, playerCard2, playerCard3, playerCard4, dealerCard1, dealerCard2, dealerCard3, dealerCard4, dealerTotal, playerTotal, playerDiff, dealerDiff, Diff;


int main()
{
    int HitStand;

    cout << " *** WELCOME TO BLACKJACK *** \n\n\n"
         << "Please ENTER to get your first two cards \n\n\n";


          dealCards();

    cout << "Card 1 is: " << playerCard1 << "\n"
         << "Card 2 is: " << playerCard2 << "\n";

        playerTotal = playerCard1 + playerCard2;

    cout << "Your card total is: " << playerTotal << "\n";

    if (playerTotal > 21)
    {
        cout << "Sorry! You busted...\n";
        return 0;
    }
    else if (playerTotal == 21)
    {
        cout << "You Win !!!\n";

        return 0;
    }
    else
    {
        cout << "Do you want to HIT or STAND"
             << " To HIT enter 1, To STAND enter 2 \n";
        cin  >> HitStand;

    if (HitStand == 1)
    {
        dealThirdCard();

    }
    else if (HitStand == 2)
    {
        StandGame();

        playerDiff = 21 - playerTotal;
        dealerDiff = 21 - dealerTotal;
        Diff = playerDiff - dealerDiff;



        if (playerDiff < 0 && dealerDiff < 0)
        {

            cout << " Sorry, You and Dealer both got busted ....\n";
            return 0;
        }

        else if (playerDiff < 0 && dealerDiff > 0)
        {
            cout << " Sorry, You got busted and the Dealer won...\n";
            return 0;
        }

        else if (playerDiff > 0 && dealerDiff > 0)
        {
            if (Diff < 0)
            {
                Diff = (Diff * -1);
                cout << " Congrats !!! You have defeated the dealer by " << Diff << "\n";
                return 0;
            }
            else if (Diff > 0)
            {
                cout << "Sorry, You got defeated by the Dealer for " << Diff << "\n";
                return 0;
            }
            else
            {
                cout << " You both tied \n";
            }
        }
        else if (playerDiff > 0 && dealerDiff < 0)
        {
            cout << "Congrats you won by " << Diff << " and the dealer got busted \n";
        }
        else if (playerDiff == 0 && dealerDiff > 0)
        {
            cout << " Congrats you scored 21 !!! \n";
        }
        else if (playerDiff == 0 && dealerDiff < 0)
        {
            cout << " Congrats you scored 21 !!!\n";
        }
        else if (playerDiff < 0 && dealerDiff == 0)
        {
            cout << " Sorry, the Dealer scored 21 !!!\n";
        }
        else if (playerDiff > 0 && dealerDiff == 0)
        {
            cout << " Sorry, the Dealer scored 21...\n";
        }
        else if (playerDiff == 0 && dealerDiff == 0)
        {
            cout << " You scored 21 with the dealer, and TIED...\n";
        }
        else
        {
            cout << "Disaster !!! \n";
        }
    }
    else
    {
         cout << " You have entered wrong number.\n"
              << " To HIT enter 1, To STAND enter 2 \n";
    }


    }


    cout << " Card 1 is: " << playerCard1 << "\n"
         << " Card 2 is: " << playerCard2 << "\n"
         << " Card 3 is: " << playerCard3 << "\n";

    playerTotal = playerTotal + playerCard3;

    cout << " Your card total is: " << playerTotal << "\n";

    if (playerTotal > 21)
    {
        cout << "Sorry! You lost...\n";
        return 0;
    }
    else if (playerTotal == 21)
    {
        cout << "You Win !!!\n";

        return 0;
    }

   else
    {
        cout << "Do you want to HIT or STAND"
             << " To HIT enter 1,  To STAND enter 2 \n";
        cin  >> HitStand;

    if (HitStand == 1)
    {
        dealFourthCard();

    }
    else if (HitStand == 2)
    {
        StandGame2();

        playerDiff = 21 - playerTotal;
        dealerDiff = 21 - dealerTotal;
        Diff = playerDiff - dealerDiff;



        if (playerDiff < 0 && dealerDiff < 0)
        {

            cout << " Sorry, You and Dealer both got busted ....\n";
            return 0;
        }

        else if (playerDiff < 0 && dealerDiff > 0)
        {
            cout << " Sorry, You got busted and the Dealer won...\n";
            return 0;
        }

        else if (playerDiff > 0 && dealerDiff > 0)
        {
            if (Diff < 0)
            {
                Diff = (Diff * -1);
                cout << " Congrats !!! You have defeated the dealer by " << Diff << "\n";
                return 0;
            }
            else if (Diff > 0)
            {
                cout << "Sorry, You got defeated by the Dealer for " << Diff << "\n";
                return 0;
            }
            else
            {
                cout << " You both tied \n";
            }
        }
        else if (playerDiff > 0 && dealerDiff < 0)
        {
            cout << "Congrats you won by " << Diff << " and the dealer got busted \n";
        }
        else if (playerDiff == 0 && dealerDiff > 0)
        {
            cout << " Congrats you scored 21 !!! \n";
        }
        else if (playerDiff == 0 && dealerDiff < 0)
        {
            cout << " Congrats you scored 21 !!!\n";
        }
        else if (playerDiff < 0 && dealerDiff == 0)
        {
            cout << " Sorry, the Dealer scored 21 !!!\n";
        }
        else if (playerDiff > 0 && dealerDiff == 0)
        {
            cout << " Sorry, the Dealer scored 21...\n";
        }
        else if (playerDiff == 0 && dealerDiff == 0)
        {
            cout << " You scored 21 with the dealer, and TIED...\n";
        }
        else
        {
            cout << "Disaster !!! \n";
        }
    }
    else
    {
         cout << " You have entered wrong number.\n"
              << " To HIT enter 1,  To STAND enter 2 \n";
    }

  }



    cout << " Card 1 is: " << playerCard1 << "\n"
         << " Card 2 is: " << playerCard2 << "\n"
         << " Card 3 is: " << playerCard3 << "\n"
         << " Card 4 is: " << playerCard4 << "\n";

    playerTotal = playerTotal + playerCard4;

    cout << " Your card total is: " << playerTotal << "\n";

    if (playerTotal > 21)
    {
        cout << "Sorry! You lost...\n";
        return 0;
    }
    else if (playerTotal == 21) cout << "You Win !!!\n";

    else cout << " The Game Ends !!! \n";


    return 0;
}

/*
 * Function: dealCards
 * -----------------------
 * This function deals first two cards randomly
 * for the player.
 */


void dealCards()
{
   Shuffle();
   playerCard1 = Draw().value;
   playerCard2 = Draw().value;



}

/*
 * Function: dealThirdCard
 * -----------------------
 * This function deals the Third card randomly
 * for the player.
 */

void dealThirdCard()
{
    Shuffle();
    playerCard3 = Draw().value;
}

/*
 * Function: dealFourthCard
 * -----------------------
 * This function deals the Fourth card randomly
 * for the player.
 */


void dealFourthCard()
{
  Shuffle();
  playerCard4 = Draw().value;
}

/*
 * Function: StandGame
 * -----------------------
 * This function calculates the card total
 * for the player.
 */

void StandGame ()
{
  Shuffle();

  dealerCard1 = Draw().value;
  dealerCard2 = Draw().value;

  dealerTotal = dealerCard1 + dealerCard2;

  cout << " Dealer Card 1 is: " << dealerCard1 << "\n"
       << " Dealer Card 2 is: " << dealerCard2 << "\n"
       << " Dealer Card Total is: " << dealerTotal << "\n";
}


/*
 * Function: StandGame2
 * -----------------------
 * This function calculates the card total
 * for the player.
 */

void StandGame2 ()
{
    StandGame();
    Shuffle();
    dealerCard3 = Draw().value;

    dealerTotal = dealerTotal + dealerCard3;

  cout << " Dealer Card 3 is: " << dealerCard3 << "\n"
       << " Dealer Card Total is: " << dealerTotal << "\n";

}

/*
 * Function: StandGame3
 * -----------------------
 * This function calculates the card total
 * for the player.
 */

void StandGame3 ()
{
    StandGame2();
    Shuffle ();
    dealerCard4 = Draw().value;

    dealerTotal = dealerTotal + dealerCard4;

     cout << " Dealer Card 4 is: " << dealerCard4 << "\n"
          << " Dealer Card Total is: " << dealerTotal << "\n";
}



