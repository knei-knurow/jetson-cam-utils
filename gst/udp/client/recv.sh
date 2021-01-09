#!/bin/bash
echo "Usage: ./recv.sh source_address port0 port1"

gst-launch-1.0 \
       	tcpclientsrc \
		host="$1" \
	       	port="$2" \	   
	! rtph264depay \
	! queue \
      	! h264parse \
       	! avdec_h264 \
       	! autovideosink -e &


gst-launch-1.0 \
       	tcpclientsrc \
	`	host="$1" \
	       	port="$3" \
	! rtph264depay \
	! queue \
      	! h264parse \
       	! avdec_h264 \
       	! autovideosink -e &

