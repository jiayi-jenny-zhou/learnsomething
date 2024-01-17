class Exchange:
    # implement this!
    from queue import PriorityQueue


    def __init__(self, initialBalance):
        """Initial Balance is the amount that each account should start with."""
        self.accounts = [initialBalance for i in range(101)]
        self.bids = PriorityQueue()
        self.asks = PriorityQueue()


    def add_trade(self, trade):
        """Adds a trade to the exchange (validation required)
        and returns a match if required. It is up to you on how you will
        handle representing trades. """
        #trades are (amount, volume)

        buy = self.bids.get()
        if trade[2]>buy[2]:
            self.bids.put(buy)
            return False
        
        sell = self.asks.get()
        if trade[2]>sell[2]:
            self.asks.put(sell)
            return False
        
        if trade[2]<buy[2]:
            self.bids.put((trade[1], buy[2]-trade[2]))

        
        if trade[2]<sell[2]:
            self.asks.put((trade[1], sell[2]-trade[2]))

        return True



