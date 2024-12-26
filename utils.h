#pragma once

#include <concepts>

// Define a concept to check if the class has a specific function
template <typename Subscriber, typename MessageType>
concept HasOnMessageMethod = requires(Subscriber subscriber, const MessageType& message) {
    { subscriber.onMessage(message) };
};

// Function to send a message to a single subscriber
template <class Subscriber, class MessageType>
void notifyOnMessageToSubscriber(Subscriber* subscriber, const MessageType& message)
requires HasOnMessageMethod<Subscriber, MessageType> {
    subscriber->onMessage(message);
}

// Define a concept to check if the class has a specific function
template <typename Subscriber, typename MessageType>
concept HasOnBookMethod = requires(Subscriber subscriber, const MessageType& message) {
    { subscriber.onBook(message) };
};

// Function to send a message to a single subscriber
template <class Subscriber, class MessageType>
void notifyOnBookToSubscriber(Subscriber* subscriber, const MessageType& message)
requires HasOnBookMethod<Subscriber, MessageType> {
    subscriber->onBook(message);
}