#jetson-cam-utils

GStreamer camera utilities for NVidia Jetson devices with Accelerated GStreamer.

Includes:
 * GSt pipeline creator for OpenCV VideoCapture 
 * Shell scripts:
   * RTSP stream host 
   * RTSP stream receiver
   * UDP stream host (2 cams)
   * UDP host receiver (2 cams)


Live video streaming over TCP and UDP with h264 encoding for NVidia Accelerated Gstreamer.
The scripts for receivers work with regular gstreamer plugins. Make sure to have gst plugins including `libav` installed on the receiver.
Manual of each script can be printed by launching it.

Created on NVidia Jetson Nano.




