#include <string>
#include <cstdio>

class gst_camera
{
	unsigned int id;
	string gstString;

	gst_camera(unsigned int _id, unsigned int _width, unsigned int _height, string fmt)
	{
		_id = id;

	gstString = printf("nvarguscamerasrc sensor=id=%d ! \'video/x-raw(memory:NVMM), format=NV11, width=%d, height=%d\' ! nvvidconv ! \'video/x-raw, width=%d, height=%d, format=(string)RGB", _id, _width, _height, _fmt); 
	}



}
