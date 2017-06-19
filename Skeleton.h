#pragma once
class Skeleton
{
public:
	Skeleton();
	virtual ~Skeleton();
	virtual void Initialize() = 0;
	virtual void Draw(int n) = 0;
	virtual int Timer() = 0;
	virtual void Key(unsigned char key, int x_t, int y_t) = 0;
};

