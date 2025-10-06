#pragma once

#include <iostream>
#include <vector>


// forward declarations
class Orders;
class OrderDeploy;
class OrderAdvance;
class OrderBomb;
class OrderBlockade;
class OrderAirlift;
class OrderNegotiate;
class OrdersList;

class Orders {
public:
  virtual Orders* clone() const = 0;

  virtual ~Orders() = default;

  virtual bool validate() = 0;

  virtual void execute() = 0;
};

class OrderDeploy : public Orders {
public:
  OrderDeploy();

  OrderDeploy(const OrderDeploy& other);

  OrderDeploy& operator=(const OrderDeploy& other);

  Orders* clone() const override;

  bool validate() override;

  void execute() override;

  friend std::ostream& operator<<(std::ostream& os, const OrderDeploy& order);
};

class OrderAdvance : public Orders {
public:
  OrderAdvance();

  OrderAdvance(const OrderAdvance& other);

  OrderAdvance& operator=(const OrderAdvance& other);

  Orders* clone() const override;

  bool validate() override;

  void execute() override;

  friend std::ostream& operator<<(std::ostream& os, const OrderAdvance& order);
};

class OrderBomb : public Orders {
public:
  OrderBomb();

  OrderBomb(const OrderBomb& other);

  OrderBomb& operator=(const OrderBomb& other);

  Orders* clone() const override;

  bool validate() override;

  void execute() override;

  friend std::ostream& operator<<(std::ostream& os, const OrderBomb& order);
};

class OrderBlockade : public Orders {
public:
  OrderBlockade();

  OrderBlockade(const OrderBlockade& other);

  OrderBlockade& operator=(const OrderBlockade& other);

  Orders* clone() const override;

  bool validate() override;

  void execute() override;

  friend std::ostream& operator<<(std::ostream& os, const OrderBlockade& order);
};

class OrderAirlift : public Orders {
public:
  OrderAirlift();

  OrderAirlift(const OrderAirlift& other);

  OrderAirlift& operator=(const OrderAirlift& other);

  Orders* clone() const override;

  bool validate() override;

  void execute() override;

  friend std::ostream& operator<<(std::ostream& os, const OrderAirlift& order);
};

class OrderNegotiate : public Orders {
public:
  OrderNegotiate();

  OrderNegotiate(const OrderNegotiate& other);

  OrderNegotiate& operator=(const OrderNegotiate& other);

  Orders* clone() const override;

  bool validate() override;

  void execute() override;

  friend std::ostream& operator<<(std::ostream& os, const OrderNegotiate& order);
};

class OrdersList {
public:
  std::vector<Orders *>* orders;

  OrdersList();

  OrdersList(const OrdersList& other);

  OrdersList& operator=(const OrdersList& other);

  ~OrdersList();

  void add(Orders* order);

  void remove(int index);

  void move(int fromIndex, int toIndex);

  friend std::ostream& operator<<(std::ostream& os, const OrdersList& orderList);

private:
  bool validateIndex(int index) const;
};

// free function
void testOrdersLists();
