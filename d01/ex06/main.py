#!/usr/bin/env python
import os
import argparse

def main():
    # my code here
    s = open("cities.txt").read(1000)
    cities = ''.join([i if ord(i) != 63 else 'o' for i in s])
    f = open("cities.txt", 'w')
    f.write(cities)
    f.close()

if __name__ == "__main__":
    main()
