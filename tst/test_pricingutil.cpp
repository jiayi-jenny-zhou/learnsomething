#include <gtest/gtest.h>
#include <pricingutil.h>


TEST(PricingUtilTests, sample) {
    EXPECT_EQ(4, 4);
}

TEST(PricingUtilTests, PricingUtilInit) {
    PricingUtil pricingUtil = PricingUtil();
    EXPECT_NEAR(pricingUtil.getVal(),0, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(0,0,0),0, 1e-4);
    
}
//TV = (Previous Price * (0.9 + Interest Rate)) * Oleo Constant
TEST(PricingUtilTests, PricingUtilCalcValZeros) {
    PricingUtil pricingUtil = PricingUtil();
    EXPECT_NEAR(pricingUtil.calcVal(0,0,0),0, 1e-4);

    EXPECT_NEAR(pricingUtil.calcVal(0,100,0),0, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(0,0,100),0, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(100,0,0),0, 1e-4);
    
}

TEST(PricingUtilTests, PricingUtilPosCalcVal) {
    PricingUtil pricingUtil = PricingUtil();
    EXPECT_NEAR(pricingUtil.calcVal(50,60,0),0, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(0,70,80),0, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(40,0,41),1476, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(40,45,41),75276, 1e-4);
    
}

TEST(PricingUtilTests, PricingUtilPosCalcValDecimals) {
    PricingUtil pricingUtil = PricingUtil();

    EXPECT_NEAR(pricingUtil.calcVal(0.45,0,.12),.0486, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(.85,0.12,0),0, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(0,.4,0.45),0, 1e-4);

    EXPECT_NEAR(pricingUtil.calcVal(0.45,0.48,0.15),.09315, 1e-4);
    
}

TEST(PricingUtilTests, PricingUtilNegCalcVal) {
    PricingUtil pricingUtil = PricingUtil();

    EXPECT_NEAR(pricingUtil.calcVal(-50,-60,0),0, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(0,-70,-80),0, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(-40,0,-41),1476, 1e-4);

    EXPECT_NEAR(pricingUtil.calcVal(-40,-45,-41),-72324, 1e-4);

    
    
}

TEST(PricingUtilTests, PricingUtilNegCalcValDecimals) {
    PricingUtil pricingUtil = PricingUtil();

    EXPECT_NEAR(pricingUtil.calcVal(-0.45,0,0),0, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(0,-0.12,0),0, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(0,0,-0.45),0, 1e-4);

    EXPECT_NEAR(pricingUtil.calcVal(-0.45,-0.48,-0.15),0.02835, 1e-4);
    
}


TEST(PricingUtilTests, PricingUtilMixedCalcVal) {
    PricingUtil pricingUtil = PricingUtil();

    EXPECT_NEAR(pricingUtil.calcVal(45,-.4,4),90, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(12,.4,45),702, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(-56,4.5,1),-302.4, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(-1.2,.01,-45),49.14, 1e-4);
    EXPECT_NEAR(pricingUtil.calcVal(45,.12,5),229.5, 1e-4);
    
}

TEST(PricingUtilTests, PricingUtilGetVal) {
    PricingUtil pricingUtil = PricingUtil();
    EXPECT_NEAR(pricingUtil.getVal(),0, 1e-4);
    pricingUtil.calcVal(45,-.4,4);
    EXPECT_NEAR(pricingUtil.getVal(),90, 1e-4);
    pricingUtil.calcVal(12,.4,45);
    EXPECT_NEAR(pricingUtil.getVal(),702, 1e-4);
    pricingUtil.calcVal(-56,4.5,1);
    EXPECT_NEAR(pricingUtil.getVal(),-302.4, 1e-4);
    pricingUtil.calcVal(-1.2,.01,-45);
    EXPECT_NEAR(pricingUtil.getVal(),49.14, 1e-4);
    pricingUtil.calcVal(45,.12,5);
    EXPECT_NEAR(pricingUtil.getVal(),229.5, 1e-4);
    
}

