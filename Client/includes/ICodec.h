#ifndef _ICODEC_H_
# define _ICODEC_H_

# include "Sound.hpp"

class ICodec
{
public:
	virtual ~ICodec() {};

public:
	virtual Sound::Encoded	encode(const Sound::Decoded &sound) = 0;
	virtual Sound::Decoded	decode(const Sound::Encoded &sound) = 0;
};

#endif
