#!/bin/bash
echo "usage: ./host2.sh host_addr host_port"
gst-launch -v tcpclientsrc host=$1 port=$2 ! decodebin ! autovideosink
