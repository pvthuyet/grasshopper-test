#pragma once
#include <cstdint>

struct SingaporeExchangeAddOrder {
    uint64_t timeStamp_;
    uint32_t orderId_;
    int32_t price_;
};

struct SingaporeExchangeTradeExecuted {
    uint64_t timeStamp_;
    bool isAggressive_;
    int32_t price_;
};

struct AmericanExchangeAddOrder {
    uint64_t timeStamp_;
    uint64_t orderId_;
    int64_t price_;
};

struct AmericanExchangeTradeExecuted {
    uint64_t timeStamp_;
    uint16_t participantOneId_;
    uint16_t participantTwoId_;
    int64_t price_;
};

struct EuropeanExchangeAddOrder {
    uint64_t timeStamp_;
    uint64_t orderId_;
    int64_t price_;
};

struct EuropeanExchangeTradeExecuted {
    uint64_t timeStamp_;
    uint16_t participantOneId_;
    uint16_t participantTwoId_;
    int64_t price_;
};