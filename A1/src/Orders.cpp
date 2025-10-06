#include "../include/Orders.h"

//  OrderDeploy
OrderDeploy::OrderDeploy() = default;

OrderDeploy::OrderDeploy(const OrderDeploy& other) {
}

OrderDeploy& OrderDeploy::operator=(const OrderDeploy& other) { return *this; }
bool OrderDeploy::validate() { return false; }

void OrderDeploy::execute() {
}

Orders* OrderDeploy::clone() const {
  return new OrderDeploy(*this);
}

std::ostream& operator<<(std::ostream& os, const OrderDeploy& order) {
  os << "A Deploy Order.";
  return os;
}

//  OrderAdvance
OrderAdvance::OrderAdvance() = default;

OrderAdvance::OrderAdvance(const OrderAdvance& other) {
}

OrderAdvance& OrderAdvance::operator=(const OrderAdvance& other) { return *this; }
bool OrderAdvance::validate() { return false; }

void OrderAdvance::execute() {
}

Orders* OrderAdvance::clone() const {
  return new OrderAdvance(*this);
}

std::ostream& operator<<(std::ostream& os, const OrderAdvance& order) {
  os << "A Advance Order.";
  return os;
}

//  OrderBomb
OrderBomb::OrderBomb() = default;

OrderBomb::OrderBomb(const OrderBomb& other) {
}

OrderBomb& OrderBomb::operator=(const OrderBomb& other) { return *this; }
bool OrderBomb::validate() { return false; }

void OrderBomb::execute() {
}

Orders* OrderBomb::clone() const {
  return new OrderBomb(*this);
}

std::ostream& operator<<(std::ostream& os, const OrderBomb& order) {
  os << "A Bomb Order.";
  return os;
}

//  OrderBlockade
OrderBlockade::OrderBlockade() = default;

OrderBlockade::OrderBlockade(const OrderBlockade& other) {
}

OrderBlockade& OrderBlockade::operator=(const OrderBlockade& other) { return *this; }
bool OrderBlockade::validate() { return false; }

void OrderBlockade::execute() {
}

Orders* OrderBlockade::clone() const {
  return new OrderBlockade(*this);
}

std::ostream& operator<<(std::ostream& os, const OrderBlockade& order) {
  os << "A Blockade Order.";
  return os;
}

//  OrderAirlift
OrderAirlift::OrderAirlift() = default;

OrderAirlift::OrderAirlift(const OrderAirlift& other) {
}

OrderAirlift& OrderAirlift::operator=(const OrderAirlift& other) { return *this; }
bool OrderAirlift::validate() { return false; }

void OrderAirlift::execute() {
}

Orders* OrderAirlift::clone() const {
  return new OrderAirlift(*this);
}

std::ostream& operator<<(std::ostream& os, const OrderAirlift& order) {
  os << "A Airlift Order.";
  return os;
}

//  OrderNegotiate
OrderNegotiate::OrderNegotiate() = default;

OrderNegotiate::OrderNegotiate(const OrderNegotiate& other) {
}

OrderNegotiate& OrderNegotiate::operator=(const OrderNegotiate& other) { return *this; }
bool OrderNegotiate::validate() { return false; }

void OrderNegotiate::execute() {
}

Orders* OrderNegotiate::clone() const {
  return new OrderNegotiate(*this);
}

std::ostream& operator<<(std::ostream& os, const OrderNegotiate& order) {
  os << "A Negotiate Order.";
  return os;
}

//  OrdersList
OrdersList::OrdersList() {
  orders = new std::vector<Orders *>();
}

OrdersList::OrdersList(const OrdersList& other) {
  orders = new std::vector<Orders *>();
  for (const auto& order : *other.orders) {
    orders->push_back(order->clone());
  }
}

OrdersList& OrdersList::operator=(const OrdersList& other) {
  if (this != &other) {
    delete orders;
    orders = new std::vector<Orders *>();
    for (const auto& order : *other.orders) {
      orders->push_back(order->clone());
    }
  }
  return *this;
}

std::ostream& operator<<(std::ostream& os, const OrdersList& orderList) {
  os << "A Orders List";
  return os;
}

bool OrdersList::validateIndex(int index) const {
  return index >= 0 && index < orders->size();
}

void OrdersList::add(Orders* order) {
  orders->push_back(order);
}

void OrdersList::remove(int index) {
  if (!validateIndex(index)) {
    return;
  }
  orders->erase(orders->begin() + index);
}

void OrdersList::move(int fromIndex, int toIndex) {
  if (!validateIndex(fromIndex) || !validateIndex(toIndex)) {
    return;
  }

  //Remove order from the list and reinsert it at the new index
  Orders* order = orders->at(fromIndex);
  orders->erase(orders->begin() + fromIndex);
  orders->insert(orders->begin() + toIndex, order);
}

OrdersList::~OrdersList() {
  //assume that OrdersList owns the orders and is responsible for deleting them
  for (const auto& order : *orders) {
    delete order;
  }

  delete orders;
}
