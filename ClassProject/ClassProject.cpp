// Start blackjack game
#include "stdafx.h"
#include"Header.h"
#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>

// not sure if this is ever useful but whatever long live python
#define print(x) std::cout << x << std::endl;


// doesn't this sort of defeat the purpose of namespaces tho
using std::string;
using std::cout;
using std::endl;


class Card {
public:
	int suitLength = 4;
	int number;
	string type;

	Card(int _number, string _type) {
		number = _number;
		type = _type;
		
	}


	string getDescription() {
		return std::to_string(number) + " of " + type;
	}
private:
	
};

class Deck {
public:
	std::vector<Card> cards;
	string suit;

	void populateDeck() {
		// this is going to be called every time
		// we start a new round which means we want to 
		// put all the cards back into the deck
		if (!cards.empty()) {
			cards.clear();
		}

		insertCards(cards);
		
		/// TODO: rewrite this algorithm for data structures
		// shuffling the deck
		std::random_shuffle(cards.begin(), cards.end());
	}

	Card drawCard() {

	}

private:
	// passing deck by reference and not copying the contents since we're not returning the value
	
	void insertCards(std::vector<Card>& deck) {
		// modularizing
		for (int x = 0; x < 4; ++x) {
			// looping through the suites
			for (int i = 0; i < 13; ++i) {
				// looping through the numbers
				//std::cout << "hello" << "\n";
				Card card(i, Suit[x]);
				deck.emplace_back(card);
			}
		}
	}
};


class Entity {
	// totall overkill but it's just to learn inheritence in C++
public:
	Entity() {
		cardValue = 0;
	}

	void hold(){}


protected:
	void startTurn(string entity) {
		cout << entity << "\'s turn." << endl;
	}

	Card playCard() {

	}
	std::vector<Card> playedCards;
	int cardValue;

	
};

class Player : Entity {
	
public:
	Player() : Entity(){}

private:
	string name = "Player";

	void startTurn() {
		Entity::startTurn(name);
	}

};

class Enemy : Entity {
public:

	Enemy() : Entity() { 

	}

	

private:
	string name = "Computer";

	void startTurn() {
		Entity::startTurn(name);
	}
	void makeChoice() {
		
		if (cardValue < 17) {
			
		}
	}

};

string waitForPlayerInput() {
	return std::to_string(std::cin.get());
}


void gameLoop() {

	bool gameOver = false;
	bool playerTurn = false;
	string a;
	while (!gameOver) {
		if (playerTurn) {
			std::cin >> a;
			
			// setting the player turn to false
			// to switch turns
			playerTurn = false;
		}
		// computer turn
		else {
			cout << "Computer turn" << endl;

			playerTurn = true;
		}
		continue;
	}
}

int main() {	

	Deck deck;
	deck.populateDeck(); // populating our deck
	size_t size = deck.cards.size();
	std::cout << "The deck has a size of " << deck.cards.size() << "\nCards:\n";

	for (std::vector<Card>::size_type i = 0; i < size; ++i) {
		std::cout << deck.cards[i].getDescription() << "\n" ;

	}

	gameLoop();


	// pause the program at the end
	std::cin.get();


	return 0;
}

