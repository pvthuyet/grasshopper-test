#pragma once

template <typename OrderBookType>
class MarketSubscriberBase {
public:
  //template </* ??? */>
  auto onBookHandle(const auto& orderBook) {
    /* ??? */
  }
private:
  auto onBook(const auto& orderBook); // defer implementation to derived classes
};

template <typename ...OrderBookTypes>
struct MarketSubscriber : public MarketSubscriberBase<OrderBookTypes>... {
  /* ??? */
};