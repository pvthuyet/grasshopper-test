#include <iostream>
#include "FeedPublishers.h"

int main()
{
    SubscriberExample1 sub1;
    SubscriberExample2 sub2;
    FeedPublisherBase<SubscriberExample1, SubscriberExample2> publisher(sub1, sub2);

    publisher.publishMessage(std::string("Hello Subscribers!"));
    return 0;
  
  /*
  Optional ???: add ThreeMarketsStrategy listening to all events from
  SingaporeExchange, AmericanExchange and EuropeanExchange here.
  */

}


