#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include "utils.h"

// Base publisher class template
template <class... SubscriberRegion>
class FeedPublisherBase 
{
public:
    // Constructor to initialize subscribers as pointers
    explicit FeedPublisherBase(SubscriberRegion*... subscribers) : subscribers_(subscribers...) {}

    // Function to invoke `onMessage` for all subscribers
    template <class MessageType>
    void publishMessage(const MessageType& message) {
        std::apply(
            [&](auto*... subscriber) { (notifyOnMessageToSubscriber(subscriber, message), ...); },
            subscribers_);
    }

private:

    // Tuple to store pointers to subscribers
    std::tuple<SubscriberRegion*...> subscribers_;
};

// Specific publisher class template
template <class... SubscriberRegion>
class SingaporeExchangeFeedPublisher : public FeedPublisherBase<SubscriberRegion...> 
{
public:
    using FeedPublisherBase<SubscriberRegion...>::FeedPublisherBase; // Inherit constructor
};

template<class... SubscriberRegion>
class AmericanExchangeFeedPublisher : public FeedPublisherBase<SubscriberRegion...>
{
public:
    using FeedPublisherBase<SubscriberRegion...>::FeedPublisherBase; // Inherit constructor
};

template<class... SubscriberRegion>
class EuropeanExchangeFeedPublisher : public FeedPublisherBase<SubscriberRegion...>
{
public:
    using FeedPublisherBase<SubscriberRegion...>::FeedPublisherBase; // Inherit constructor
};

// Function to deduce types of objects and instantiate FeedPublisherBase
template <template <class...> class FeedPublisherType, class... SubscriberRegion>
auto createFeedPublisher(SubscriberRegion*... subscribers) -> FeedPublisherType<SubscriberRegion...>
{
    return FeedPublisherType<SubscriberRegion...>(subscribers...);
}
