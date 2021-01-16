#!/bin/bash


./test-launch --gst-debug=3 \
        "( nvarguscamerasrc sensor-id=1 \
        ! video/x-raw(memory:NVMM),format=NV12,width=1920,height=1080,framerate=30/1 \
        ! nvvidconv ! timeoverlay ! nvvidconv \
        ! nvv4l2h264enc insert-sps-pps=true bitrate=3200000 profile=4 maxperf-enable=true\
        ! rtph264pay name=pay0 pt=96 )"\
        --port 8886
     
