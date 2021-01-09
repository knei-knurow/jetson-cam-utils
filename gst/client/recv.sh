gst-launch-1.0 udpsrc address=176.97.27.134 port=8885 caps='application/x-rtp, encoding-name=(string)H264, payload=(int)96' ! rtph264depay ! queue ! h264parse ! nvh264dec ! autovideosink -e
