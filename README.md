# 3D Mixer
The 3D mixer is a Open Frameworks based 8-channel 3D sound mixer prototype.

## Screenshot
![](http://github.com/thisandagain/3d-mixer/blob/master/screenshot.png) 

## Output Settings
By default, the application will use MacOS's system settings when assigning the output device. Normally, this will look something like:
	
	device = 0 (Apple Inc.: Built-in Microphone)
	----* default ----* 
	maximum output channels = 0
	maximum input channels = 2
	-----------------------------------------
	device = 1 (Apple Inc.: Built-in Output)
	maximum output channels = 2
	maximum input channels = 0
	-----------------------------------------
	
Because the default output device only supports 2 channels (top-left-front and top-right-front) only these channels will be heard. In order to take advantage of all 8 outputs you will need a Core Audio compatable sound card or breakout that supports at least 8 outputs.