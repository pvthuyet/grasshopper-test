#pragma once

#include <type_traits>

// Forward declaration of MarketSubscriberBase
template <typename OrderBookType> class MarketSubscriberBase;

// Concept to check if T is derived from MarketSubscriberBase<OrderBookType>
template <typename T, typename OrderBookType>
concept DerivedFromMarketSubscriberBase = std::is_base_of_v<MarketSubscriberBase<OrderBookType>, T>;

template <typename OrderBookType>
class MarketSubscriberBase {
public:
    // CRTP-based delegation with concept
    void onBookHandle(auto* derivedObj, const OrderBookType& orderBook)
      requires DerivedFromMarketSubscriberBase<decltype(*derivedObj), OrderBookType> {
        derivedObj->onBook(orderBook);
    }

private:
  auto onBook(const auto& orderBook); // defer implementation to derived classes
};


template <class... OrderBookTypes>
struct MarketSubscriber : public MarketSubscriberBase<OrderBookTypes>... {
  /* ??? */
};


