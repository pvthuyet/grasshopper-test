#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <utility>

// Base publisher class template
template <class... SubscriberType>
class FeedPublisherBase 
{
public:
    // Constructor to initialize subscribers as pointers
    explicit FeedPublisherBase(SubscriberType*... subscribers) : subscribers_(subscribers...) {}

    // Function to invoke `onMessage` for all subscribers
    template <class MessageType>
    void publishMessage(const MessageType& message) {
        std::apply(
            [&](auto*... sub) { (sendMessageToSubscriber(message, sub), ...); },
            subscribers_);
    }

private:
    // Function to send a message to a single subscriber
    template <typename MessageType, typename TSub>
    void sendMessageToSubscriber(const MessageType& message, TSub* subscriber) {
        subscriber->onMessage(message);
    }

    // Tuple to store pointers to subscribers
    std::tuple<SubscriberType*...> subscribers_;
};

// Specific publisher class template
template <class... SubscriberType>
class SingaporeExchangeFeedPublisher : public FeedPublisherBase<SubscriberType...> 
{
public:
    using FeedPublisherBase<SubscriberType...>::FeedPublisherBase; // Inherit constructor
};

template<class... SubscriberType>
class AmericanExchangeFeedPublisher : public FeedPublisherBase<SubscriberType...>
{
public:
    using FeedPublisherBase<SubscriberType...>::FeedPublisherBase; // Inherit constructor
};

// Function to deduce types of objects and instantiate FeedPublisherBase
template <template <class...> class FeedPublisherType, class... SubscriberType>
auto createFeedPublisher(SubscriberType*... subscribers) 
{
    return FeedPublisherType<SubscriberType...>(subscribers...);
}
