#pragma once
template <typename OrderBookType>
class MarketSubscriberBase {
public:
  template </* ??? */>
  auto onBookHandle(/* ??? */ orderBook) {
    /* ??? */
  }
private:
  auto onBook(const auto& orderBook); // defer implementation to derived classes
};


template </* ??? */>
struct MarketSubscriber : public MarketSubscriberBase<OrderBookTypes>... {
  /* ??? */
};


