#pragma once

#include <iostream>
#include <string>
#include <vector>


// forward declarations
class Territory;
class Card;
class Deck;
class Hand;
class Orders;
class OrdersList;

/**
 * Player class representing a Warzone player
 * 
 * A player owns a collection of territories, a hand of cards, and a list of orders.
 * The player can issue orders, defend territories, and attack other territories.
 */
class Player {
private:
  std::string* playerName;
  std::vector<Territory *>* territories; // collection of owned territories
  Hand* hand; // player's hand of cards
  OrdersList* orders; // list of orders to execute
  int* reinforcementPool; // number of armies available for deployment

public:
  // constructors
  Player();

  Player(const std::string& name);

  Player(const Player& other); // copy constructor
  Player& operator=(const Player& other); // assignment operator
  ~Player(); // destructor

  // getters
  std::string getName() const;

  const std::vector<Territory *>& getTerritories() const;

  Hand* getHand() const;

  OrdersList* getOrders() const;

  int getReinforcementPool() const;

  // setters
  void setName(const std::string& name) const;

  void setReinforcementPool(int armies) const;

  // territory management
  void addTerritory(Territory* territory);

  void removeTerritory(Territory* territory);

  bool ownsTerritory(Territory* territory) const;

  // card management
  void addCard(Card* card);

  void playCard(int index, Deck* deck);

  // order management
  void issueOrder(Orders* order);

  void issueDeployOrder(Territory* target, int armies);

  void issueAdvanceOrder(Territory* source, Territory* target, int armies);

  void issueBombOrder(Territory* target);

  void issueBlockadeOrder(Territory* target);

  void issueAirliftOrder(Territory* source, Territory* target, int armies);

  void issueNegotiateOrder(Player* targetPlayer);

  // strategies (arbitrary implementation for now)
  std::vector<Territory *> toDefend() const;

  std::vector<Territory *> toAttack() const;

  // utility
  void displayInfo() const;

  int getTotalArmies() const;

  int getTerritoryCount() const;

  // stream insertion operator
  friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

// free function
void testPlayers();
