#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>

class Thread
{
public:
	Thread(int schedPolicy);
	void start(int priority);
	void join();
	static void * call_run(void *);
protected:
	static void run();
private:
	pthread_t tid;
	int schedPolicy;
};

#endif
