#!/usr/bin/python
# coding: utf-8
__author__ = "Nicolas Huynh"
__create_date__ = "11/10/2019"
__version__ = "0.1.0"
__maintainer__ = "Nicolas Huynh"
__email__ = "nico.huynh@gmail.com"
__status__ = "Development"

import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('merge_data00.csv', names=['TIME', 'TIME (USEC)', 'FIX_TYPE', 'LAT', 'LOG', 'ALT', 'EPH', 'EPV', 'VEL', 'COG', 'SAT_VISIBLE'])

df.plot(x='TIME', y=['LAT'])
plt.show()
plt.savefig('ex00_LAT.png')
df.plot(x='TIME', y=['LOG'])
plt.show()
plt.savefig('ex0_LOG.png')