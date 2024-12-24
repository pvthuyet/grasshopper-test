#pragma once
template <typename OrderBookType>
class MarketSubscriberBase {
public:
  template <class Derived>
  auto onBookHandle(Derived* derivedObj, const OrderBookType& orderBook) {
    /* ??? */
    derivedObj->onBook(orderBook);
  }
private:
  auto onBook(const auto& orderBook); // defer implementation to derived classes
};


template <class... OrderBookTypes>
struct MarketSubscriber : public MarketSubscriberBase<OrderBookTypes>... {
  /* ??? */
};


