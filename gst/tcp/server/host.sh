#!/bin/bash
echo "Usage: ./host.sh port0 port1"

gst-launch-1.0 \
     nvarguscamerasrc \
         sensor-id=0 \
    ! 'video/x-raw(memory:NVMM), format=NV12, width=1920, height=1080' \
    ! nvv4l2h264enc insert-sps-pps=true \
    ! h264parse \
    ! rtph264pay pt=96  \
    ! tcpserversink port=$1  -e &

gst-launch-1.0 \
     nvarguscamerasrc \
         sensor-id=1 \
    ! 'video/x-raw(memory:NVMM), format=NV12, width=1920, height=1080' \
    ! nvv4l2h264enc insert-sps-pps=true \
    ! h264parse \
    ! rtph264pay pt=96  \
    ! tcpserversink port=$1 &

