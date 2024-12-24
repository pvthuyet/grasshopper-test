#pragma once
#include "Messages.h"
#include "OrderBooks.h"
#include "FeedPublishers.h"
#include "FeedSubscriberBase.h"


/*
========================================================
Market Builder ( subscribe to feed and publish )
========================================================
*/
template</*???*/>
class SingaporeExchangeMarketBuilder : public FeedSubscriber<SingaporeExchangeAddOrder, SingaporeExchangeTradeExecuted> {

public:
    // Constructor
    SingaporeExchangeMarketBuilder(/*???*/ subscribers) : subscribers_(/*???*/) {};

    template </*???*/>
    auto publishOnBook(/*???*/ const SingaporeExchangeOrderBook& qb) {
      /*???*/
    }

    auto onMessage(const SingaporeExchangeAddOrder& msg) {
      SingaporeExchangeOrderBook qb;
      qb.askSize0_ = 100;
      qb.bidSize0_ = 200;
      publishOnBook(qb);
    };

    auto onMessage(const SingaporeExchangeTradeExecuted& msg) {
      SingaporeExchangeOrderBook qb;
      qb.askSize0_ = 10;
      qb.bidSize0_ = 100;
      publishOnBook(qb);
    };


private:
  // A data structure to hold pointers to the varying number of subscriber members
  std::/*???*/ subscribers_;

  /* ??? Helper function if needed */

};

template</*???*/>
class AmericanExchangeMarketBuilder : public FeedSubscriber<AmericanExchangeAddOrder, AmericanExchangeTradeExecuted> {

public:
    // Constructor
    AmericanExchangeMarketBuilder(/*???*/ subscribers) : subscribers_(/*???*/) {};

    template </*???*/>
    auto publishOnBook(/*???*/ const AmericanExchangeOrderBook& qb) {
      /*???*/
    }

    auto onMessage(const AmericanExchangeAddOrder& msg) {
      AmericanExchangeOrderBook qb;
      qb.askSize0_ = 80000000;
      qb.bidSize0_ = 90000000;
      publishOnBook(qb);
    };

    auto onMessage(const AmericanExchangeTradeExecuted& msg) {
      AmericanExchangeOrderBook qb;
      qb.askSize0_ = 3;
      qb.bidSize0_ = 5;
      publishOnBook(qb);
    };

private:
  // A data structure to hold pointers to the varying number of subscriber members
  std::/*???*/ subscribers_;

  /* ??? Helper function if needed */

};
