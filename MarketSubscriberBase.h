#pragma once

template <typename OrderBookType>
class MarketSubscriberBase {
public:
  //template </* ??? */>
  auto onBookHandle(const OrderBookType& orderBook) {
    /* ??? */
  }
private:
  auto onBook(const OrderBookType& orderBook); // defer implementation to derived classes
};

template <typename ...OrderBookTypes>
struct MarketSubscriber : public MarketSubscriberBase<OrderBookTypes>... {
  /* ??? */
};