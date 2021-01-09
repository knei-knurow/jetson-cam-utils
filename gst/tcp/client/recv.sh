#!/bin/bash
echo "Usage: ./recv.sh source_address port"

gst-launch-1.0 \
       	udpsrc \
       		address=$1 \
	       	port=$2 \
	       	caps='application/x-rtp, encoding-name=(string)H264, payload=(int)96'\
	! rtph264depay \
	! queue \
      	! h264parse \
       	! avdec_h264 \
       	! autovideosink -e
