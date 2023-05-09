#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Card {
private:
    string value;
    string suit;

public:
    Card(string v, string s) {
        value = v;
        suit = s;
    }

    string get_value() {
        return value;
    }

    string get_suit() {
        return suit;
    }

    void set_value(string v) {
        value = v;
    }

    void set_suit(string s) {
        suit = s;
    }

    string to_string() {
        return value + " " + suit;
    }
};
vector<Card> create_deck() {
    vector<string> suits = { "Srce", "Pik", "Karo", "Detelina" };
    vector<string> values = { "As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Dama", "Pop", "Joker" };

    vector<Card> deck;
    for (string suit : suits) {
        for (string value : values) {
            deck.push_back(Card(value, suit));
        }
    }

    return deck;
}
Card draw_card(vector<Card>& deck) {
    int index = rand() % deck.size();
    Card card = deck[index];
    deck.erase(deck.begin() + index);
    return card;
}
int main() {
    srand(time(NULL));

    vector<Card> deck = create_deck();
    vector<Card> drawn_cards;

    while (drawn_cards.size() < 5) {
        Card card = draw_card(deck);

        bool valid = true;
        for (Card drawn_card : drawn_cards) {
            if (card.to_string() == drawn_card.to_string()) {
                valid = false;
                break;
            }
        }

        if (valid) {
            drawn_cards.push_back(card);
        }
    }

    for (Card card : drawn_cards) {
        cout << card.to_string() << endl;
    }

    return 0;
}