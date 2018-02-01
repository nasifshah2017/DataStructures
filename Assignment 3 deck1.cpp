/* Filename: deck1.cpp
 * ----------------------
 * Author:  M. van Bommel
 * Course:  CSci 162
 * Date:    8 February 2016
 * Purpose: Implementation file for deck.h - needs random to operate
 */

#include "deck.h"
#include "random.h"

#include <iostream>
#include <cstdlib>

using namespace std;

#define NumCards 52              // Number of cards in standard deck, no jokers

static cardT deck[NumCards];     // Deck of cards
static int   CardsLeft  = 0;     // Cards remaining in deck = zero -> Shuffle
static bool  Randomized = false; // Only want to call Randomize once

/* Function: Shuffle
 * -----------------
 * Sets the number of cards left to deal as NumCards (resets to full deck).
 *
 * If called for the first time (Randomized is false) then:
 *      Initializes the deck array with the 52 cards.
 *      Calls randomize to seed the random number generator.
 *      Sets Randomized to true
 */

void Shuffle()
{
    suitT s;
    int val, pos=0;

    CardsLeft = NumCards;           // all are available again

    if (!Randomized)                // called for first time?
    {
        Randomize();                // seed random number generator
        rand();                     // (burn first rand - always the same???)
        Randomized = true;          // don't do this again

        for (s = Spades; s <= Diamonds; s = (suitT) (s+1))
        {
            for (val=1; val<=13; val++)
            {
                deck[pos].suit = s;
                deck[pos].value = val;
                pos++;
            }
        }
    }
}

/* Function: Draw
 * --------------
 * Chooses a random card from deck, moves last card in deck to its position,
 * decrements size of remaining deck, and evaluates and returns the card.
 */

cardT Draw()
{
   int pos;
   cardT card;

   if (!CardsLeft)
   {
      cout << "Deck is empty\n";
      card.value = 0;
      card.suit = Spades;
   } else {
      CardsLeft--;                       // one less card in the deck
      pos = RandomInteger(0, CardsLeft); // pick a card
      card = deck[pos];                  // make a copy
      deck[pos] = deck[CardsLeft];       // swap with last card in deck
      deck[CardsLeft] = card;
   }

   return card;                          // return a copy of chosen card
}

/* Function: Cards
 * ---------------
 * Returns the number of cards left to deal from the deck.
 */

int Cards()
{
   return CardsLeft;
}

/* Function: DisplayCard
 * ---------------------
 * Displays the rank and suit of the given card.
 */

void DisplayCard(cardT card)
{
    char suits[] = "SHCD";
    switch (card.value)
    {
        case  1: cout << 'A'; break;
        case 10: cout << 'T'; break;
        case 11: cout << 'J'; break;
        case 12: cout << 'Q'; break;
        case 13: cout << 'K'; break;
        default: cout << card.value;
    }
    if (Spades <= card.suit && card.suit <= Diamonds )
        cout << suits[card.suit];
    else
        cout << '?';
}











