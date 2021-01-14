#!/bin/bash
echo "Usage: ./recv.sh location"
echo "location example: rtsp://192.168.1.100:8586/test"

gst-launch-1.0 \
      	rtspsrc  \
	location=$1 \
	! rtph264depay \
	! queue \
      	! h264parse \
       	! avdec_h264 \
       	! autovideosink -e \

