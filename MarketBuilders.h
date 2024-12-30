#pragma once
#include "Messages.h"
#include "OrderBooks.h"
#include "FeedPublishers.h"
#include "FeedSubscriberBase.h"
#include "utils.h"

/*
========================================================
Market Builder ( subscribe to feed and publish )
========================================================
*/
template<class... SubscriberRegion>
class SingaporeExchangeMarketBuilder : public FeedSubscriber<SingaporeExchangeAddOrder, SingaporeExchangeTradeExecuted> 
{
public:
    // Constructor
    explicit SingaporeExchangeMarketBuilder(SubscriberRegion*... subscribers) : subscribers_(subscribers...) {
        static_assert(HasOnMessageMethod<SingaporeExchangeMarketBuilder, SingaporeExchangeAddOrder>);
        static_assert(HasOnMessageMethod<SingaporeExchangeMarketBuilder, SingaporeExchangeTradeExecuted>);
    };

    //template </*???*/>
    auto publishOnBook(/*???*/ const SingaporeExchangeOrderBook& qb) {
      /*???*/
      std::apply(
          [&](auto*... subscriber) { (notifyOnBookToSubscriber(subscriber, qb), ...); },
          subscribers_);
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
  std::tuple<SubscriberRegion*...> subscribers_;

  /* ??? Helper function if needed */
};

template<class... SubscriberRegion>
class AmericanExchangeMarketBuilder : public FeedSubscriber<AmericanExchangeAddOrder, AmericanExchangeTradeExecuted>
{
public:
    // Constructor
    explicit AmericanExchangeMarketBuilder(SubscriberRegion*... subscribers) : subscribers_(subscribers...) {
      static_assert(HasOnMessageMethod<AmericanExchangeMarketBuilder, AmericanExchangeAddOrder>);
      static_assert(HasOnMessageMethod<AmericanExchangeMarketBuilder, AmericanExchangeTradeExecuted>);
    };

    //template </*???*/>
    auto publishOnBook(/*???*/ const AmericanExchangeOrderBook& qb) {
        /*???*/
        std::apply(
          [&](auto*... subscriber) { (notifyOnBookToSubscriber(subscriber, qb), ...); },
          subscribers_);
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
  std::tuple<SubscriberRegion*...> subscribers_;

  /* ??? Helper function if needed */
};

template<class... SubscriberRegion>
class EuropeanExchangeMarketBuilder : public FeedSubscriber<EuropeanExchangeAddOrder, EuropeanExchangeTradeExecuted>
{
public:
    // Constructor
    explicit EuropeanExchangeMarketBuilder(SubscriberRegion*... subscribers) : subscribers_(subscribers...) {
      static_assert(HasOnMessageMethod<EuropeanExchangeMarketBuilder, EuropeanExchangeAddOrder>);
      static_assert(HasOnMessageMethod<EuropeanExchangeMarketBuilder, EuropeanExchangeTradeExecuted>);
    };

    //template </*???*/>
    auto publishOnBook(/*???*/ const EuropeanExchangeOrderBook& qb) {
        /*???*/
        std::apply(
          [&](auto*... subscriber) { (notifyOnBookToSubscriber(subscriber, qb), ...); },
          subscribers_);
    }

    auto onMessage(const EuropeanExchangeAddOrder& msg) {
      EuropeanExchangeOrderBook qb;
      qb.askSize0_ = 300;
      qb.bidSize0_ = 400;
      publishOnBook(qb);
    };

    auto onMessage(const EuropeanExchangeTradeExecuted& msg) {
      EuropeanExchangeOrderBook qb;
      qb.askSize0_ = 11;
      qb.bidSize0_ = 12;
      publishOnBook(qb);
    };

private:
  // A data structure to hold pointers to the varying number of subscriber members
  std::tuple<SubscriberRegion*...> subscribers_;

  /* ??? Helper function if needed */
};