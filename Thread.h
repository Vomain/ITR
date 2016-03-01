#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>

class Thread
{
public:
	void Thread(int schedPolicy);
	void start(int priority);
	void join();
protected:
	virtual void run();
private:
	pthread_t tid;
	int schedPolicy;
};

#endif
