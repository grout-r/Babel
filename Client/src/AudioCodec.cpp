#include "AudioCodec.h"
#include <iostream>

AudioCodec::AudioCodec()
{
	int error;

	encoder = opus_encoder_create(RATE, CHANNEL, OPUS_APPLICATION_VOIP, &error);
	if (error != OPUS_OK)
		std::cout << "Opus encoder create fail" << std::endl; // excep

	decoder = opus_decoder_create(RATE, CHANNEL, &error);
	if (error != OPUS_OK)
		std::cout << "Opus decoder create fail" << std::endl; // excep
}

AudioCodec::~AudioCodec()
{
	if (encoder)
		opus_encoder_destroy(encoder);

	if (decoder)
		opus_decoder_destroy(decoder);
}

Sound::Encoded AudioCodec::encode(const Sound::Decoded &sound)
{
	Sound::Encoded Enc;
	
	std::cout << "proutttt" << "sound size   " <<  sound.size << std::endl;
	Enc.buffer.resize(sound.size);
	Enc.size = opus_encode_float(encoder, sound.buffer.data(), FRAMES, Enc.buffer.data(), sound.size);
	if (Enc.size < 0)
		std::cout << "encoder float error" << std::endl;
	return 	Enc;
}

Sound::Decoded	AudioCodec::decode(const Sound::Encoded &sound)
{
	Sound::Decoded Dec;

	Dec.buffer.resize(FRAMES * CHANNEL);
	Dec.size = opus_decode_float(decoder, sound.buffer.data(), sound.size, Dec.buffer.data(), FRAMES, 0) * CHANNEL;
	if (Dec.size < 0)
		std::cout << "size of Decode is under 0" << std::endl;
	return Dec;
}