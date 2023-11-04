#include "pricingutil.h"

PricingUtil::PricingUtil(){}

float PricingUtil::calcVal(float prevPrice, float interest, float oleoConstant){
    val = (prevPrice*(0.9+interest))*oleoConstant;
    return val;
}
    
float PricingUtil::getVal(){
    return val;
}