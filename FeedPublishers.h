#pragma once
#include <iostream>
#include <string>

template <typename... TSubscriber>
class FeedPublisherBase {
public:
    FeedPublisherBase(TSubscriber... subs) : subscribers_(std::move(subs)...) {}

    // A function to invoke `onMessage` for all subscribers
    template <class TMessage>
    auto publishMessage(const TMessage& message) {
        std::apply(
            [&](auto &... sub) { (sendMessageToSubscriber(message, sub), ...);}, 
            subscribers_);
    }

    // Function to publish data to all subscribers
    // template <typename TData>
    // void publish(const TData& data) {
    //     publishToSubscribers(data);
    // }

private:
    // Helper function to call publish on each subscriber
    // template <std::size_t Index = 0, typename TData>
    // void publishToSubscribers(const TData& data) {
    //     if constexpr (Index < sizeof...(TSubscriber)) {
    //         // Call publish on the current subscriber
    //         std::get<Index>(subscribers_).publish(data);
    //         // Recur to the next subscriber
    //         publishToSubscribers<Index + 1>(data);
    //     }
    // }

    auto sendMessageToSubscriber(const auto& message, auto &subscriber) -> void {
        //subscriber.onMessage(message); 
        // for (auto &device : device_list) {
        //     device.update(); 
        // }
    }

    // Tuple to store subscribers
    std::tuple<TSubscriber...> subscribers_;
};


// Example Subscriber Class for testing
class SubscriberExample1 {
public:
    void publish(const std::string& message) {
        std::cout << "[SubscriberExample1] Received message: " << message << std::endl;
    }
};

class SubscriberExample2 {
public:
    void publish(const std::string& message) {
        std::cout << "[SubscriberExample2] Received message: " << message << std::endl;
    }
};

template<typename TStrategy, typename TMarketBuilder>
class SingaporeExchangeFeedPublisher : public FeedPublisherBase<TStrategy, TMarketBuilder> {
public:
    SingaporeExchangeFeedPublisher(/* ??? */ subscribers)
        : FeedPublisherBase</* ??? */>(/* ??? */) {}

};

// template</* ??? */>
// class AmericanExchangeFeedPublisher : public FeedPublisherBase</* ??? */> {
// public:
//     AmericanExchangeFeedPublisher(/* ??? */ subscribers)
//         : FeedPublisherBase</* ??? */>(/* ??? */) {}

// };

// // Function to deduce types of objects and instantiate FeedPublisherBase
// template </* ??? */>
// auto createFeedPublisher(/* ??? */ subscribers) {
//     return FeedPublisherType</* ??? */>(/* ??? */);
// }
