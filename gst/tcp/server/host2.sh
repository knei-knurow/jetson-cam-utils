#!/bin/bash
echo "Usage: ./recv.sh host_ip host_port"

gst-launch-1.0 \
	-v videotestsrc \
		is-live=true \
	! video/x-raw,width=640,width=480,framerate=30/1 \
	! queue \
	! videoconvert \
	! x264enc \
		tune=zero-latency \
	! h264parse \
	! queue \
	! matroskamux \
	! queue \
		leaky=2 \
	! tcpserversink \
		port=$2 \
		host=$1 \
		recover-policy=keyframe \
		sync-method=latest-keyframe &
