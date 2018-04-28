# delta.io
convert trade history of Binance to import csv file

extremly simple and fast solution...

Tested with Ubuntu and it works. Downloaded the trade history of my binance account.
Make sure the trade history is a csv file.

How to compile (c++17 not really needed...):
g++ -std=c++17 BinanceDeltaConverter.cpp -o conv

How to convert
 ./conv {yourfilename}.csv 
 
 this will generate {yourfilename}.csv
 
 
 ETH: 0xB8f0efd6Be462399e7Eba25FaE79A04D7a5559b2
 
