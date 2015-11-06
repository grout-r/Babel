#include <iostream>
#include "Core.h"
#include "InterClientCom.h"
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

	core.start();

}
