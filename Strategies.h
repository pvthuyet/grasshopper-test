#pragma once
#include <iostream>

#include "Messages.h"
#include "OrderBooks.h"
#include "FeedPublishers.h"
#include "FeedSubscriberBase.h"
#include "MarketBuilders.h"
#include "MarketBuilders.h"
#include "MarketSubscriberBase.h"

struct SingleAmericanMarketStrategy:
    public FeedSubscriber<AmericanExchangeAddOrder, AmericanExchangeTradeExecuted>,
    public MarketSubscriber<AmericanExchangeOrderBook>
{
  auto onMessage(const AmericanExchangeTradeExecuted& msg) {
    std::cout << "SingleAmericanMarketStrategy Do clever strategy level stuff with AmericanExchange:  "  << std::endl;
  };

  auto onMessage(const AmericanExchangeAddOrder& msg) {
    std::cout << "SingleAmericanMarketStrategy Do exciting clever strategy level stuff with AmericanExchange: "  << std::endl;
  };

  auto onBook(const AmericanExchangeOrderBook& qb) {
    std::cout << "SingleAmericanMarketStrategy receives AmericanExchange book update: "  << std::endl;
    std::cout << qb.askSize0_ << "; bidSize0_: " << qb.bidSize0_ << std::endl;
  };
};

struct CrossMarketStrategy: public FeedSubscriber<SingaporeExchangeAddOrder, SingaporeExchangeTradeExecuted, AmericanExchangeAddOrder, AmericanExchangeTradeExecuted>,
                 public MarketSubscriber<SingaporeExchangeOrderBook, AmericanExchangeOrderBook>
{
  auto onMessage(const SingaporeExchangeAddOrder& msg) {
    std::cout << "CrossMarketStrategy receive add order from SingaporeExchange: "  << std::endl;
  };

  auto onMessage(const SingaporeExchangeTradeExecuted& msg) {
    std::cout << "CrossMarketStrategy receive trade execution from SingaporeExchange: "  << std::endl;
  };

  auto onMessage(const AmericanExchangeAddOrder& msg) {
    std::cout << "CrossMarketStrategy receive add order from AmericanExchange: "  << std::endl;
  };

  auto onMessage(const AmericanExchangeTradeExecuted& msg) {
    std::cout << "CrossMarketStrategy receive trade execution from AmericanExchange:  "  << std::endl;
  };

  auto onBook(const SingaporeExchangeOrderBook& qb) {
    std::cout << "CrossMarketStrategy receive SingaporeExchange book update: "  << std::endl;
    std::cout << qb.askSize0_ << "; bidSize0_: " << qb.bidSize0_ << std::endl;
  };

  auto onBook(const AmericanExchangeOrderBook& qb) {
    std::cout << "CrossMarketStrategy receives AmericanExchange book update: "  << std::endl;
    std::cout << qb.askSize0_ << "; bidSize0_: " << qb.bidSize0_ << std::endl;
  };

};

/*
  Optional ???: add ThreeMarketsStrategy listening to all events from
  SingaporeExchange, AmericanExchange and EuropeanExchange here.
*/
