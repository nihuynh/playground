#!/usr/bin/python
# coding: utf-8
__author__ = "Nicolas Huynh"
__create_date__ = "07/10/2019"
__version__ = "0.1.0"
__maintainer__ = "Nicolas Huynh"
__email__ = "nico.huynh@gmail.com"
__status__ = "Development"

import pyrealsense2


class AcquisitionT265:
    def __init__(self, pipe, origin_, v0_, a0_):
        self.origin = origin_
        self.v0 = v0_
        self.a0 = a0_
        try:
            frames = pipe.wait_for_frames()
            self.pose = frames.get_pose_frame()
            if self.pose:
                self.pose_data = self.pose.get_pose_data()
        except RuntimeError:
            print("Frame didn't arrived within 5000")

    def get_frame_number(self):
        return self.pose.frame_number

    def get_relative_acceleration(self):
        return self.pose_data.acceleration

    def get_relative_velocity(self):
        return self.pose_data.velocity

    def get_relative_translation(self):
        return self.pose_data.translation

    def get_data_pt(self):
        pos = self.get_relative_translation()
        v = self.get_relative_velocity()
        a = self.get_relative_acceleration()
        res = [self.origin[0] + pos.x, self.origin[1] + pos.y, self.origin[2] + pos.z,
               self.v0[0] + v.x, self.v0[1] + v.y, self.v0[2] + v.z,
               self.a0[0] + a.x, self.a0[1] + a.y, self.a0[2] + a.z]
        return res
