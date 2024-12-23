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
template<class... SubscriberType>
class SingaporeExchangeMarketBuilder : public FeedSubscriber<SingaporeExchangeAddOrder, SingaporeExchangeTradeExecuted> 
{
public:
    // Constructor
    explicit SingaporeExchangeMarketBuilder(SubscriberType*... subscribers) : subscribers_(subscribers...) {};

    //template </*???*/>
    auto publishOnBook(/*???*/ const SingaporeExchangeOrderBook& qb) {
      /*???*/
      std::apply(
          [&](auto*... subscriber) { (sendMessageToSubscriber(qb, subscriber), ...); },
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
  std::tuple<SubscriberType*...> subscribers_;

  /* ??? Helper function if needed */
    // Function to send a message to a single subscriber
    template <class MessageType, class Subscriber>
    void sendMessageToSubscriber(const MessageType& message, Subscriber* subscriber) {
        subscriber->onBook(message);
    }
};

template<class... SubscriberType>
class AmericanExchangeMarketBuilder : public FeedSubscriber<AmericanExchangeAddOrder, AmericanExchangeTradeExecuted>
{
public:
    // Constructor
    explicit AmericanExchangeMarketBuilder(SubscriberType*... subscribers) : subscribers_(subscribers...) {};

    //template </*???*/>
    auto publishOnBook(/*???*/ const AmericanExchangeOrderBook& qb) {
        /*???*/
        std::apply(
          [&](auto*... subscriber) { (sendMessageToSubscriber(qb, subscriber), ...); },
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
  std::tuple<SubscriberType*...> subscribers_;

  /* ??? Helper function if needed */
    // Function to send a message to a single subscriber
    template <class MessageType, class Subscriber>
    void sendMessageToSubscriber(const MessageType& message, Subscriber* subscriber) {
        subscriber->onBook(message);
    }
};

