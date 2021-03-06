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

	Card(int _number, string _type)
		: number(_number), type(_type) {

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
		// called at the start of every game


		// clearing the deck if restarting
		if (!cards.empty()) {
			cards.clear();
		}

		insertCards(cards);
		
		// TODO: rewrite this algorithm for data structures
		// shuffling the deck
		std::random_shuffle(cards.begin(), cards.end());
	}
	
	Card drawCard() {
		Card card = cards.back();
		int size = cards.size();
		cards.erase(cards.end());
		return card;
		
	}

private:
	// passing deck by reference and not copying the contents since we're not returning the value
	
	void insertCards(std::vector<Card>& deck) {
		// modularizing

	
		for (int x = 0; x < suiteLength; ++x) {
			// looping through the suites
			for (int i = 0; i < cardNumbersLength; ++i) {
				// looping through the numbers

				Card card(i, Suit[x]);
				// push_back copies variable unlike emplace_back
				deck.emplace_back(card);
			}
		}
	}
	// this doesn't necessarily have to take in a vector but it's what we're
	// working with right now
	void shuffleArray(std::vector<Card>& deck) {
		// we want the intial range to be the max size of the array
		int range = deck.size();
		
	}
};


class Entity {
	// totall overkill but it's just to learn inheritence in C++
public:
	Entity(Deck& _deck)
		: cardValue(0), deck(_deck) {}

	void hold(){}


protected:
	int cardValue;
	Deck deck;

	void startTurn(string entity) {
		cout << entity << "\'s turn." << endl;
	}

	Card hit() {
		// here we will be invoking a draw card from the deck
		// that returns and destroys the topmost card
		deck.drawCard();
	}
	std::vector<Card> playedCards;


	
};




class Player : Entity {
	
public:
	Player(Deck& deck) 
		: Entity(deck){
	}


	void startTurn() {
		Entity::startTurn(name);

	}


private:
	string name = "Player";

};




class Computer : Entity {
public:
	Computer(Deck& deck) 
		: Entity(deck) {

	}

	void taunt() {
		// we can get the computer to say some dumb 
		// stuff every once in a while based on chance 
		// and whether he's doing good or not
	}
private:
	string name = "Computer";

	void startTurn() {
		Entity::startTurn(name);
	}

	void makeChoice() {
		
		if (cardValue < 17) {
			hit();
		}

	}
};

string waitForPlayerInput() {
	return std::to_string(std::cin.get());
}


void gameLoop(Player& player, Computer& computer) {
	bool gameOver = false;
	bool playerTurn = false;
	// we might not really need this variable because we don't want to save anything 
	// but we need to initialize it if we don't want it to skip over randomly with cin.get()
	string a;
	while (!gameOver) {
		if (playerTurn) {
			player.startTurn();
			std::cin >> a;
			
			
			// setting the player turn to false
			// to switch turns
			playerTurn = false;
		}
		// computer turn
		// we might want to do something like waiting on computers turn 
		// before they make a decision to 
		else {
			cout << "Computer turn" << endl;

			playerTurn = true;
		}
	}
}

int main() {	

	Deck deck;
	deck.populateDeck(); // populating our deck
	Player player(deck);
	Computer computer(deck);

	size_t size = deck.cards.size();
	std::cout << "The deck has a size of " << deck.cards.size() << "\nCards:\n";

	for (std::vector<Card>::size_type i = 0; i < size; ++i) {
		std::cout << deck.cards[i].getDescription() << "\n" ;

	}

	gameLoop(player, computer);


	// pause the program at the end
	std::cin.get();


	return 0;
}

