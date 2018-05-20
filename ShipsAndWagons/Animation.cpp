#include "Animation.h"



Animation::Animation(unsigned int startFrame, unsigned int endFrame, float duration)
{
	this->startFrame = startFrame;
	this->endFrame = endFrame;
	this->startFrame = startFrame;
}


Animation::~Animation()
{
}

unsigned Animation::getLength() const
{
	return endFrame - startFrame + 1;
}

