#pragma once
#include "Messages.h"
#include "OrderBooks.h"
#include "FeedPublishers.h"
#include "FeedSubscriberBase.h"

// Define a concept to check if the class has a specific function
template <typename MessageType, typename Subscriber>
concept HasOnBookMethod = requires(MessageType message, Subscriber subscriber) {
    { subscriber.onBook(message) };
};

// Function to send a message to a single subscriber
template <class MessageType, class Subscriber>
void notifyOnBookToSubscriber(const MessageType& message, Subscriber* subscriber)
requires HasOnBookMethod<MessageType, Subscriber> {
    subscriber->onBook(message);
}

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
          [&](auto*... subscriber) { (notifyOnBookToSubscriber(qb, subscriber), ...); },
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
          [&](auto*... subscriber) { (notifyOnBookToSubscriber(qb, subscriber), ...); },
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
};

template<class... SubscriberType>
class EuropeanExchangeMarketBuilder : public FeedSubscriber<AmericanExchangeAddOrder, AmericanExchangeTradeExecuted>
{
public:
    // Constructor
    explicit EuropeanExchangeMarketBuilder(SubscriberType*... subscribers) : subscribers_(subscribers...) {};

    //template </*???*/>
    auto publishOnBook(/*???*/ const EuropeanExchangeOrderBook& qb) {
        /*???*/
        std::apply(
          [&](auto*... subscriber) { (notifyOnBookToSubscriber(qb, subscriber), ...); },
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
  std::tuple<SubscriberType*...> subscribers_;

  /* ??? Helper function if needed */
};