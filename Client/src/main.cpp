#include <iostream>
#include "Core.h"
#include "InterClientCom.h"
<<<<<<< HEAD
#include "InterClientPacket.h"
////#include "portaudio.h"
//#include "AudioController.h"

int main()
{/*
	AudioController tt;
	IAudio *a = new AudioInput();

	tt.startRecord();
	Pa_Sleep(10000);
	tt.stopRecord();
	tt.SoundEvent(a);
	tt.startPlay();
	Pa_Sleep(10000);
	tt.stopPlay();*/

	Core core;
	InterCPacket *pack = new InterCPacket;

=======
#include "portaudio.h"
#include "AudioController.h" 

int main()
{
	Core core;

>>>>>>> ee812928ba1d95d3d44bbde5a62d284a924c66c3
	core.start();

}
