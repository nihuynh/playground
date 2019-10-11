#!/usr/bin/python
# coding: utf-8
__author__ = "Nicolas Huynh"
__create_date__ = "07/10/2019"
__version__ = "0.1.0"
__maintainer__ = "Nicolas Huynh"
__email__ = "nico.huynh@gmail.com"
__status__ = "Development"

import matplotlib.pyplot as plt
import numpy
import pandas
import pyrealsense2
from AcquisitionT265 import AcquisitionT265

# Declare RealSense pipeline, encapsulating the actual device and sensors
pipeline = pyrealsense2.pipeline()
cfg = pyrealsense2.config()
cfg.enable_stream(pyrealsense2.stream.pose)
pipeline.start(cfg)

try:
    dataArray = []
    plt.ion()
    fig, ax = plt.subplots()
    origin = numpy.array([0.0, 0.0, 0.0])
    v0 = numpy.array([0.0, 0.0, 0.0])
    a0 = numpy.array([0.0, 0.0, 0.0])
    for i in range(30):
        data = AcquisitionT265(pipeline, origin, v0, a0)
        dataArray.append(data.get_data_pt())
        df = pandas.DataFrame(dataArray, columns=['Pos.x (m)', 'Pos.y (m)', 'Pos.z (m)',
                                                  'V.x (m/s)', 'V.y (m/s)', 'V.z (m/s)',
                                                  'A.x (m/s^2)', 'A.y (m/s^2)', 'A.z (m/s^2)'])
        ax.clear()
        df.plot(subplots=True, layout=(3, 3), ax=ax)
        plt.draw()
        plt.pause(0.005)
    plt.show()
finally:
    pipeline.stop()
    plt.close(fig)
