#pragma once

template <typename MessageType>
class FeedSubscriberBase {
public:
  template<class Derived>
  auto onMessageHandle(Derived& derived, const MessageType& message) {
    /* ??? - need to call the onMessage in derived class */
    derived.onMessage(message);
  }

private:
  auto onMessage(const auto& message);         // defer to derived classes to override into different types.
};


// Subscriber class
template <class... MessageType>
struct FeedSubscriber : public FeedSubscriberBase<MessageType>... {
    /* ??? */
};



