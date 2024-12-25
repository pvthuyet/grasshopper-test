#include "Messages.h"
#include "OrderBooks.h"
#include "FeedPublishers.h"
#include "Strategies.h"
#include "MarketBuilders.h"

int main()
{
  CrossMarketStrategy           crossMktStrat;
  SingleAmericanMarketStrategy  singleMktStrat;
  ThreeMarketsStrategy          threeMktStrat;

  SingaporeExchangeMarketBuilder<CrossMarketStrategy, ThreeMarketsStrategy> singExchMarketBuilder(&crossMktStrat, &threeMktStrat);
  AmericanExchangeMarketBuilder<CrossMarketStrategy, SingleAmericanMarketStrategy, ThreeMarketsStrategy> amExchMarketBuilder(&crossMktStrat, &singleMktStrat, &threeMktStrat);
  EuropeanExchangeMarketBuilder<ThreeMarketsStrategy> euExchMarketBuilder(&threeMktStrat);

  SingaporeExchangeAddOrder msg1;
  AmericanExchangeAddOrder msg2;
  EuropeanExchangeAddOrder msg3;

  auto singExchPublisher = createFeedPublisher<SingaporeExchangeFeedPublisher>(&crossMktStrat, &threeMktStrat, &singExchMarketBuilder);
  auto amExchPublisher   = createFeedPublisher<AmericanExchangeFeedPublisher>(&singleMktStrat, &crossMktStrat, &threeMktStrat, &amExchMarketBuilder);
  auto euExchPublisher   = createFeedPublisher<EuropeanExchangeFeedPublisher>(&threeMktStrat, &euExchMarketBuilder);

  singExchPublisher.publishMessage(msg1);
  amExchPublisher.publishMessage(msg2);
  euExchPublisher.publishMessage(msg3);
  singExchPublisher.publishMessage(SingaporeExchangeTradeExecuted());
  amExchPublisher.publishMessage(AmericanExchangeTradeExecuted());
  euExchPublisher.publishMessage(EuropeanExchangeTradeExecuted());

  /*
  Optional ???: add ThreeMarketsStrategy listening to all events from
  SingaporeExchange, AmericanExchange and EuropeanExchange here.
  */


  return 0;
}


