#!/bin/bash
echo "Usage: ./host.sh sinkaddress port"

gst-launch-1.0 \
     nvarguscamerasrc \
         sensor-id=1 \
    ! 'video/x-raw(memory:NVMM), format=NV12, width=1920, height=1080' \
    ! nvv4l2h264enc insert-sps-pps=true \
    ! h264parse \
    ! rtph264pay pt=96  \
    ! udpsink  host=$1 port=$2 sync=false -e

