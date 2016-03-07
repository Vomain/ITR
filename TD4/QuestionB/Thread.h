#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>

class Thread
{
public:
	Thread(int schedPolicy);
	void start(int priority);
	void join();
	void setStackSize(size_t);
	static void * call_run(void *);
	static void sleep(double);
	int join(double timeout_ms);
protected:
	virtual void run();
private:
	pthread_t tid;
	int schedPolicy;
    pthread_attr_t attr;
};

#endif
