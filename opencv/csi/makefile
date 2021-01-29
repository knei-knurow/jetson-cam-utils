CC = g++
CFLAGS = -g -Wall -lstdc++
SRCS = csi.cpp
PROG = csi

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
