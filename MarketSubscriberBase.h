#pragma once
template <typename OrderBookType>
class MarketSubscriberBase {
public:
  //template </* ??? */>
  auto onBookHandle(/* ??? */ const OrderBookType& orderBook) {
    /* ??? */
  }
private:
  auto onBook(const auto& orderBook); // defer implementation to derived classes
};


template <class... OrderBookTypes>
struct MarketSubscriber : public MarketSubscriberBase<OrderBookTypes>... {
  /* ??? */
};


