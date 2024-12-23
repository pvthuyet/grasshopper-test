#pragma once
#include <cstdint>

struct SingaporeExchangeOrderBook {
  int32_t bid0_;
  int32_t ask0_;
  uint64_t bidSize0_;
  uint64_t askSize0_;
};

struct AmericanExchangeOrderBook {
  int64_t bid0_;
  int64_t ask0_;
  uint64_t bidSize0_;
  uint64_t askSize0_;
};


