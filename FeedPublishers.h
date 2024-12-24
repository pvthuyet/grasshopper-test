#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <utility>

// Base publisher class template
template <class... TSubscriber>
class FeedPublisherBase {
public:
    // Constructor to initialize subscribers as pointers
    explicit FeedPublisherBase(TSubscriber*... subs) : subscribers_(subs...) {}

    // Function to invoke `onMessageHandle` for all subscribers
    template <class TMessage>
    void publishMessage(const TMessage& message) {
        std::apply(
            [&](auto*... sub) { (sendMessageToSubscriber(message, sub), ...); },
            subscribers_);
    }

private:
    // Function to send a message to a single subscriber
    template <typename TMessage, typename TSub>
    void sendMessageToSubscriber(const TMessage& message, TSub* subscriber) {
        //subscriber->onMessageHandle(*subscriber, message);
        subscriber->onMessage(message);
    }

    // Tuple to store pointers to subscribers
    std::tuple<TSubscriber*...> subscribers_;
};

// Specific publisher class template
template <class... TSubscriber>
class SingaporeExchangeFeedPublisher : public FeedPublisherBase<TSubscriber...> {
public:
    using FeedPublisherBase<TSubscriber...>::FeedPublisherBase; // Inherit constructor
};

// template</* ??? */>
// class AmericanExchangeFeedPublisher : public FeedPublisherBase</* ??? */> {
// public:
//     AmericanExchangeFeedPublisher(/* ??? */ subscribers)
//         : FeedPublisherBase</* ??? */>(/* ??? */) {}

// };

// Function to deduce types of objects and instantiate FeedPublisherBase
template <template <class...> class FeedPublisherType, class... TSubscriber>
auto createFeedPublisher(TSubscriber*... subscribers) 
{
    return FeedPublisherType<TSubscriber...>(subscribers...);
}
