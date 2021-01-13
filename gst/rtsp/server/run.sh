#!/bin/bash


./test-launch  \
    --gst-debug=3 \
        '( nvarguscamerasrc sensor-id=0 \
        ! video/x-raw,width=640,height=480,framerate=30/1 \
        ! x264enc tune="zerolatency" byte-stream=true bitrate=2000 \
        ! rtph264pay name=pay0 pt=96 )'\
    --port 8886 \
