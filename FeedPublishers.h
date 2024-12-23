#pragma once

template </* ??? */>
class FeedPublisherBase {
public:
    FeedPublisherBase(/* ??? */) : /* ??? */ subscribers_(/* ??? */) {};

    // A function to invoke `onMessage` for all subscribers
    template </* ??? */>
    auto publishMessage( /**/ message) {
        /* ??? */
    }

private:
  /* ??? */ subscribers_;

};


template</* ??? */>
class SingaporeExchangeFeedPublisher : public FeedPublisherBase</* ??? */> {
public:
    SingaporeExchangeFeedPublisher(/* ??? */ subscribers)
        : FeedPublisherBase</* ??? */>(/* ??? */) {}

};

template</* ??? */>
class AmericanExchangeFeedPublisher : public FeedPublisherBase</* ??? */> {
public:
    AmericanExchangeFeedPublisher(/* ??? */ subscribers)
        : FeedPublisherBase</* ??? */>(/* ??? */) {}

};

// Function to deduce types of objects and instantiate FeedPublisherBase
template </* ??? */>
auto createFeedPublisher(/* ??? */ subscribers) {
    return FeedPublisherType</* ??? */>(/* ??? */);
}
