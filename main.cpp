#include "Messages.h"
#include "OrderBooks.h"
#include "FeedPublishers.h"
#include "Strategies.h"
//#include "MarketBuilders.h"

int main()
{
  CrossMarketStrategy           crossMktStrat;
  SingleAmericanMarketStrategy  singleMktStrat;

  // SingaporeExchangeMarketBuilder<CrossMarketStrategy> singExchMarketBuilder(&crossMktStrat);
  // AmericanExchangeMarketBuilder<CrossMarketStrategy, SingleAmericanMarketStrategy> amExchMarketBuilder(&crossMktStrat, &singleMktStrat);

  SingaporeExchangeAddOrder msg1;
  // AmericanExchangeAddOrder msg2;

  // auto singExchPublisher = createFeedPublisher<SingaporeExchangeFeedPublisher>(&crossMktStrat, &singExchMarketBuilder);
  auto singExchPublisher = createFeedPublisher<SingaporeExchangeFeedPublisher>(&crossMktStrat);

  // auto amExchPublisher   = createFeedPublisher<AmericanExchangeFeedPublisher>(&singleMktStrat, &crossMktStrat, &amExchMarketBuilder);

  singExchPublisher.publishMessage(msg1);
  // amExchPublisher.publishMessage(msg2);
  // singExchPublisher.publishMessage(SingaporeExchangeTradeExecuted());
  // amExchPublisher.publishMessage(AmericanExchangeTradeExecuted());

  /*
  Optional ???: add ThreeMarketsStrategy listening to all events from
  SingaporeExchange, AmericanExchange and EuropeanExchange here.
  */

  return 0;
}


