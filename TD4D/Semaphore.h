#ifndef SEMAPHORE_H_INCLUDED
#define SEMAPHORE_H_INCLUDED


class Semaphore
{
public:
	void give();
	void flush();
	void take();
	bool take(double);
	~Semaphore();
private:
	unsigned counter;
	unsigned maxCount;
	
};

#endif
