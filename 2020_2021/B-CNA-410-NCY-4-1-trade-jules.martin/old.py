#!/usr/bin/env python3

import sys
from math import *

class Data:
    def __init__(self):
        self.date = []
        self.high = []
        self.low = []
        self.open = []
        self.close = []
        self.volume = []

    def debug_print_all(self):
        print("Date: ")
        print(self.date, end = "\n\n")
        print("High: ")
        print(self.high, end = "\n\n")
        print("Low: ")
        print(self.low, end = "\n\n")
        print("Open: ")
        print(self.open, end = "\n\n")
        print("Close: ")
        print(self.close, end = "\n\n")
        print("Volume: ")
        print(self.volume, end = "\n\n")

    def add_values(self, _format, values):
        idx = 0
        for val in _format:
            if val == "pair": pass
            if val == "date": self.date.append(int(values[idx]))
            if val == "high": self.high.append(float(values[idx]))
            if val == "low": self.low.append(float(values[idx]))
            if val == "open": self.open.append(float(values[idx]))
            if val == "close": self.close.append(float(values[idx]))
            if val == "volume": self.volume.append(float(values[idx]))
            idx += 1

class Trade:
    BTC_ETH = Data()
    USDT_ETH = Data()
    USDT_BTC = Data()

    stack_BTC = None
    stack_ETH = None
    stack_USDT = None

    player_names = None
    your_bot = None
    timebank = None
    time_per_move = None
    candle_interval = None
    candle_format = None
    candles_total = None
    candles_given = None
    initial_stack = None
    transaction_fee_percent = None

    error = None
    pair_idx = None
    
    def eprint(self, err):
        print(err, file=sys.stderr)

    def check_none(self):
        missing = None
        if self.player_names == None: missing = "player_names"
        if self.your_bot == None: missing = "your_bot"
        if self.timebank == None: missing = "timebank"
        if self.time_per_move == None: missing = "time_per_move"
        if self.candle_format == None: missing = "candle_format"
        if self.candles_total == None: missing = "candles_total"
        if self.candles_given == None: missing = "candles_given"
        if self.initial_stack == None: missing = "initial_stack"
        if self.transaction_fee_percent == None: missing = "transaction_fee_percent"
        if missing != None:
            raise ValueError("missing setting \"" + missing + "\"" )

    def get_settings(self):
        for i in range(0, 10):
            array = input().split(" ")
            if (len(array) < 3 or array[0] != "settings"):
                raise ValueError("bad settings format")
            if array[1] == "player_names": self.player_names = array[2]
            elif array[1] == "your_bot": self.your_bot = array[2]
            elif array[1] == "timebank": self.timebank = int(array[2])
            elif array[1] == "time_per_move": self.time_per_move = int(array[2])
            elif array[1] == "candle_interval": self.candle_interval = int(array[2])
            elif array[1] == "candle_format": self.candle_format = array[2].split(",")
            elif array[1] == "candles_total": self.candles_total = int(array[2])
            elif array[1] == "candles_given": self.candles_given = int(array[2])
            elif array[1] == "initial_stack": self.initial_stack = int(array[2])
            elif array[1] == "transaction_fee_percent": self.transaction_fee_percent = float(array[2])
            else:
                raise ValueError("unknown setting \"" + array[1] + "\"" )

    def add_data(self, array):
        pairs = array.split(";")
        pair = self.pair_idx
        for val in pairs:
            values = val.split(",")
            if len(values) != 7:
                raise ValueError("missing value in one of the pairs")
            if (values[pair] == "BTC_ETH"):
                self.BTC_ETH.add_values(self.candle_format, values)
            elif (values[pair] == "USDT_ETH"):
                self.USDT_ETH.add_values(self.candle_format, values)
            elif (values[pair] == "USDT_BTC"):
                self.USDT_BTC.add_values(self.candle_format, values)
        # [debug]
        #self.BTC_ETH.debug_print_all()
        #self.USDT_ETH.debug_print_all()
        #self.USDT_BTC.debug_print_all()

    def order(self, amount):
        print(self.BTC_ETH.volume)

    def get_stack(self, values):
        array = values.split(",")
        if (len(array) != 3):
            raise ValueError("invalid stack format: \"" + values + "\"")
        for val in array:
            values = val.split(":")
            if (len(values) != 2):
                raise ValueError("invalid stack: \"" + val + "\"")
            elif (values[0] == "BTC"):
                self.stack_BTC = float(values[1])
            elif (values[0] == "ETH"):
                self.stack_ETH = float(values[1])
            elif (values[0] == "USDT"):
                self.stack_USDT = float(values[1])
            else:
                raise ValueError("unknow value \"" + val + "\"")
        # [debug]
        #print(self.stack_BTC)
        #print(self.stack_ETH)
        #print(self.stack_USDT)

    def where_is_pair(self):
        idx = 0
        for val in self.candle_format:
            if (val == "pair"):
                self.pair_idx = idx
                break
            idx += 1

    def loop(self):
        try:
            # [debug]
            #self.candle_format = "pair,date,high,low,open,close,volume"

            self.get_settings()
            self.check_none()
            self.where_is_pair()
            while True:
                array = input().split(" ")
                if (array[0] == "update" and array[1] == "game" and array[2] == "next_candles"):
                    self.add_data(array[3])
                elif (array[0] == "update" and array[1] == "game" and array[2] == "stacks"):
                    self.get_stack(array[3])
                elif (array[0] == "action" and array[1] == "order"):
                    self.order(array[2])
                else:
                    self.eprint("Error: unknown command.")
        except Exception as error:
            print("Error: ", end = '')
            print(error, end = '\n')
            exit(84)

def main():
    obj = Trade()
    obj.loop()

main()