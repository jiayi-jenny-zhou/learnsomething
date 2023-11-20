//
// Created by Ethan on 9/13/2023.
//

#include "hackathonbot.h"



HackathonBot::HackathonBot():balance(0),holding(true), upwindow(0),downwindow(0){
    prices.push_back(100);
}

void HackathonBot::takeAction(float price){
    if(price>prices.back()){
        upwindow++;
        downwindow=0;
    }else if(price<prices.back()){
        downwindow++;
        upwindow=0;
    }else if(price == prices.back()){
        upwindow =0;
        downwindow = 0;
    }
    prices.push_back(price);
    int end = prices.size()-1;

    if(holding){
        //windows check
        if(upwindow == 52||downwindow==47||price<1-.62*prices[0]||price>1.89*prices[0]){
            sell(price);
        }
        else if(prices.size()>3&&prices[end]<=.75*prices[end-1] && prices[end-1]>=1.15*prices[end-2]&&prices[end-2]<=.85*prices[end-3]&&prices[end]<=.55*prices[end-3]){
            sell(price);
        }
        else if(prices.size()>3&&prices[end]>=1.3*prices[end-1]&&prices[end-1]<=.85*prices[end-2]&&prices[end-2]>=1.2*prices[end-3]&&prices[end]>=1.5*prices[end-3]){
            sell(price);
        }else if(prices.size()>10){ //10 cycles check
            int end = prices.size()-1;
            bool withinfive = true;
            for(int i = 0; i<10; i++){
                if(prices[end-i]>=1.05*prices[end-i-1]||prices[end-i]<=.95*prices[end-i-1]){
                    withinfive = false;
                }
            }

            if(withinfive){
                sell(price);
            }
        }

    }else{
        //price value check
        if(price < 52){
            buy(price);
        }else if(downwindow>=5){
            buy(price);
        }
    }

    
}

void HackathonBot::sell(float price){
            
    if(holding){
        balance+=price;
        prices.clear();
        prices.push_back(price);
        upwindow=0;
        downwindow=0;
        holding = false;
    }
    
}

void HackathonBot::buy(float price){
    if(!holding){
        balance-=price;
        prices.clear();
        prices.push_back(price);
        upwindow=0;
        downwindow=0;
        holding = true;
    }
}

double HackathonBot::getBalance(){
    return this->balance;
}
bool HackathonBot::isHolding(){
    return this->holding;
}
