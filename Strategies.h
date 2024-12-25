#pragma once
#include <iostream>

#include "Messages.h"
#include "OrderBooks.h"
#include "FeedSubscriberBase.h"
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

struct ThreeMarketsStrategy: public FeedSubscriber<SingaporeExchangeAddOrder, SingaporeExchangeTradeExecuted, AmericanExchangeAddOrder, AmericanExchangeTradeExecuted, EuropeanExchangeAddOrder, EuropeanExchangeTradeExecuted>,
                             public MarketSubscriber<SingaporeExchangeOrderBook, AmericanExchangeOrderBook, EuropeanExchangeOrderBook>
{
  auto onMessage(const SingaporeExchangeAddOrder& msg) {
    std::cout << "ThreeMarketsStrategy receive add order from SingaporeExchange: "  << std::endl;
  };

  auto onMessage(const SingaporeExchangeTradeExecuted& msg) {
    std::cout << "ThreeMarketsStrategy receive trade execution from SingaporeExchange: "  << std::endl;
  };

  auto onMessage(const AmericanExchangeAddOrder& msg) {
    std::cout << "ThreeMarketsStrategy receive add order from AmericanExchange: "  << std::endl;
  };

  auto onMessage(const AmericanExchangeTradeExecuted& msg) {
    std::cout << "ThreeMarketsStrategy receive trade execution from AmericanExchange:  "  << std::endl;
  };

  auto onMessage(const EuropeanExchangeAddOrder& msg) {
    std::cout << "ThreeMarketsStrategy receive add order from EuropeanExchange: "  << std::endl;
  };

  auto onMessage(const EuropeanExchangeTradeExecuted& msg) {
    std::cout << "ThreeMarketsStrategy receive trade execution from EuropeanExchange:  "  << std::endl;
  };

  auto onBook(const SingaporeExchangeOrderBook& qb) {
    std::cout << "ThreeMarketsStrategy receive SingaporeExchange book update: "  << std::endl;
    std::cout << qb.askSize0_ << "; bidSize0_: " << qb.bidSize0_ << std::endl;
  };

  auto onBook(const AmericanExchangeOrderBook& qb) {
    std::cout << "ThreeMarketsStrategy receives AmericanExchange book update: "  << std::endl;
    std::cout << qb.askSize0_ << "; bidSize0_: " << qb.bidSize0_ << std::endl;
  };

  auto onBook(const EuropeanExchangeOrderBook& qb) {
    std::cout << "ThreeMarketsStrategy receives EuropeanExchange book update: "  << std::endl;
    std::cout << qb.askSize0_ << "; bidSize0_: " << qb.bidSize0_ << std::endl;
  };

};