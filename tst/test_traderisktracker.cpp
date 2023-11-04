#include "trade.h"
#include "risktracker.h"
#include <gtest/gtest.h>
#include <vector>

TEST(TradeRiskTrackerTest, TrackerInit) {
    std::vector<Trade> trackedTrades;
    Trade testTrade1(7, true, 1.2);
    Trade testTrade2(7, false, 1.2);
    trackedTrades.push_back(testTrade1);
    trackedTrades.push_back(testTrade2);
    RiskTracker riskTracker(0, trackedTrades);
    EXPECT_NEAR(riskTracker.getRisk(), 0, 1e-4);
    riskTracker.updateRisk();
    EXPECT_NEAR(riskTracker.getRisk(), 0, 1e-4);
    Trade testTrade3(14, true, 1.55);
    riskTracker.addTrade(testTrade3);
    riskTracker.updateRisk();
    EXPECT_NEAR(riskTracker.getRisk(), 21.7, 1e-4);
}


