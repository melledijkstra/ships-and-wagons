#pragma once
class Animation
{
public:
	unsigned int startFrame;
	unsigned int endFrame;

	float duration;

	Animation(unsigned int startFrame, unsigned int endFrame, float duration);
	~Animation();

	unsigned int getLength() const;
};

