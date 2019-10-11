#!/usr/bin/python
# coding: utf-8
__author__ = "Nicolas Huynh"
__create_date__ = "08/10/2019"
__version__ = "0.1.0"
__maintainer__ = "Nicolas Huynh"
__email__ = "nico.huynh@gmail.com"
__status__ = "Development"

import numpy
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import pyrealsense2
import pandas
from AcquisitionT265 import AcquisitionT265

fig = plt.figure()
ax = plt.axes(projection='3d', proj_type='ortho')
ax.set_xlabel('axe des x')
ax.set_ylabel('axe des y')
ax.set_zlabel('axe des z')



# Declare RealSense pipeline, encapsulating the actual device and sensors
pipeline = pyrealsense2.pipeline()
cfg = pyrealsense2.config()
cfg.enable_stream(pyrealsense2.stream.pose)
pipeline.start(cfg)

try:
    dataArray = []
    origin = numpy.array([0.0, 0.0, 0.0])
    v0 = numpy.array([0.0, 0.0, 0.0])
    a0 = numpy.array([0.0, 0.0, 0.0])
    for i in range(1800):
        data = AcquisitionT265(pipeline, origin, v0, a0)
        dataArray.append(data.get_data_pt())
    df = pandas.DataFrame(dataArray, columns=['Pos.x (m)', 'Pos.y (m)', 'Pos.z (m)',
                                              'V.x (m/s)', 'V.y (m/s)', 'V.z (m/s)',
                                              'A.x (m/s^2)', 'A.y (m/s^2)', 'A.z (m/s^2)'])
    z_points = df['Pos.z (m)'].tolist()
    x_points = df['Pos.x (m)'].tolist()
    y_points = df['Pos.y (m)'].tolist()
    ax.scatter3D(x_points, y_points, z_points, c=z_points, cmap='hsv')
    plt.show()
finally:
    pipeline.stop()


