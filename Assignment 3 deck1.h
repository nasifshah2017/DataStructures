/* Filename: deck1.h
 * -----------------
 * Author:  M. van Bommel
 * Course:  CSci 162
 * Date:    8 February 2016
 *
 * Partial interface file for a standard deck of cards without jokers.
 *
 * Must call Shuffle() before any others or no cards can be dealt.
 *
 * Mode of use is typically:
 *
 *    card_t card;
 *    Shuffle();
 *    while (Cards()) {
 *       card = Draw();
 *       DisplayCard(card);
 *    }
 */

#ifndef DECK1_H_INCLUDED
#define DECK1_H_INCLUDED

#include <iostream>

using namespace std;

enum suitT { Spades, Hearts, Clubs, Diamonds }; // card suits

struct cardT { int value;  suitT suit; };       // card structure

/* Function: Shuffle
 * Usage:    Shuffle();
 * --------------------
 * Shuffles the deck of cards, making all of them available for dealing,
 * or resets the deck after dealing some of them.
 */

extern void Shuffle();


/* Function: Cards
 * Usage:    n = Cards();
 * ----------------------
 * Returns the number of cards remaining in the deck.
 */

extern int Cards();


/* Function: Draw
 * Usage:    card = Draw();
 * ---------------------------
 * Selects the top card off of the deck, and returns it.
 */

extern cardT Draw();


/* Function: DisplayCard
 * Usage:    DisplayCard(card);
 * ----------------------------
 * Displays the rank and suit of the given card.
 * Displays rank as A, 1, 2, ... , 9, T, J, Q, K.
 * Displays suit as S (Spades), C (Clubs), H (Hearts), or D (Diamonds).
 */

extern void DisplayCard(cardT card);

#endif // DECK1_H_INCLUDED
