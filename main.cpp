#include <stdio.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

void incr(unsigned int, double*);
void printTime(timespec*, timespec*);
void *call_incr(void *arg_pointer);
void incr(unsigned int nLoops, double* pCounter);

struct arg_struct
{
	unsigned int nLoops;
	double *pCounter;
};
	
int main(int argc, char* argv[])
{
	unsigned int nLoopsPrim, nTasks;
	//sscanf(argv[1], "%d", &nLoops);
	//sscanf(argv[2], "%d", &nTasks);
	
	for(nLoopsPrim=1;nLoopsPrim<5;nLoopsPrim++)
	{
		for(nTasks = 1;nTasks<7;nTasks++)
		{
			printf("\n\n\n %d : %d\n", nLoopsPrim, nTasks);
			unsigned int nLoops = 10000000 * nLoopsPrim;

			pthread_t threads[nTasks];
			
			pthread_attr_t attr;
			pthread_attr_init(&attr);
			pthread_attr_setschedpolicy(&attr, SCHED_RR);
			sched_param schedParams;
			schedParams.sched_priority = 8;
			pthread_attr_setschedparam(&attr, &schedParams);	
			
			struct timespec tDebut;
			struct timespec tFin;
			clock_gettime(CLOCK_REALTIME, &tDebut);
			
			double counter = 0.0;
			struct arg_struct arg;
			arg.nLoops = nLoops;
			arg.pCounter = &counter;
			
			for(int i = 0;i<nTasks;i++)
			{
				pthread_create(&threads[i], &attr, call_incr, &arg);
			}

			for (int i = 0; i < nTasks; i++)
			{
			   pthread_join(threads[i], NULL);
			}

			clock_gettime(CLOCK_REALTIME, &tFin);
			printTime(&tDebut, &tFin);
			printf("result : %lf\n", counter);
			
			/* Question A
			struct timespec tDebut;
			struct timespec tFin;
			clock_gettime(CLOCK_REALTIME, &tDebut);
			incr(nLoops, &counter);
			clock_gettime(CLOCK_REALTIME, &tFin);
			printTime(&tDebut, &tFin);
			*/
			pthread_attr_destroy(&attr);
		}
	}

	
	return 0;
}

void* call_incr(void *arg_pointer)
{
	arg_struct *argument = (arg_struct *) arg_pointer;
	double *pCounter = argument->pCounter;
	incr(argument->nLoops, argument->pCounter);
}

void incr(unsigned int nLoops, double* pCounter)
{
	unsigned int i;
	for(i=0;i<nLoops;i++)
	{
		*pCounter += 1.0;
	}
}

void printTime(timespec *t2, timespec *t1)
{
	float sec = t1->tv_sec - t2->tv_sec;
	float nsec = t1->tv_nsec - t2->tv_nsec;
	if(nsec < 0)
	{
		sec--;
		nsec = 1000000000-nsec;
	}
	float nsecDiff = fmod(nsec, 1000000000);
	float secDiff = (nsec - nsecDiff) / 1000000000 + sec;
	printf("time diff : %.0f,%.0fs\n\n", secDiff, nsecDiff);
}

/*
 * Notes : 
 * 
 * B) 
 * Valeurs du counter : 10 10 : 100
 * 100 10 : 972
 * 1000 10 : 9322
 * 
 * 
 * 
 * FIFO 
 1 : 1
time diff : 0,235429088s

result : 10000000.000000



 1 : 2
time diff : 1,750388736s

result : 9955471.000000



 1 : 3
time diff : 0,426325440s

result : 13999374.000000



 1 : 4
time diff : 1,500777600s

result : 14734104.000000



 1 : 5
time diff : 0,627923840s

result : 15947990.000000



 1 : 6
time diff : 1,243636480s

result : 19503694.000000



 2 : 1
time diff : 0,464991296s

result : 20000000.000000



 2 : 2
time diff : 1,503118208s

result : 19953691.000000



 2 : 3
time diff : 1,248163712s

result : 27559760.000000



 2 : 4
time diff : 1,25530868s

result : 29896429.000000



 2 : 5
time diff : 1,309157536s

result : 32519863.000000



 2 : 6
time diff : 1,500115488s

result : 35130135.000000



 3 : 1
time diff : 1,305954560s
 1 : 1
time diff : 0,233812224s

result : 10000000.000000



 1 : 2
time diff : 0,250519696s

result : 9967066.000000



 1 : 3
time diff : 1,574413696s

result : 14832258.000000



 1 : 4
time diff : 0,514312992s

result : 14804337.000000



 1 : 5
time diff : 1,369874176s

result : 16773778.000000



 1 : 6
time diff : 1,235290496s

result : 20994610.000000



 2 : 1
time diff : 0,460494912s

result : 20000000.000000



 2 : 2
time diff : 1,502379008s

result : 19933401.000000



 2 : 3
time diff : 1,156850048s

result : 28310072.000000



 2 : 4
time diff : 1,12750033s

result : 28606118.000000



 2 : 5
time diff : 1,273817760s

result : 33747348.000000



 2 : 6
time diff : 1,527771360s

result : 37203788.000000



 3 : 1
time diff : 1,306863104s

result : 30000000.000000



 3 : 2
time diff : 1,251459072s

result : 29882677.000000



 3 : 3
time diff : 1,177976928s

result : 41611146.000000



 3 : 4
time diff : 2,487011328s

result : 45311755.000000



 3 : 5
time diff : 1,908470784s

result : 47332570.000000



 3 : 6
time diff : 3,733742848s

result : 59694979.000000



 4 : 1
time diff : 1,72604352s

result : 40000000.000000



 4 : 2
time diff : 1,3988224s

result : 39888177.000000



 4 : 3
time diff : 1,598989824s

result : 57037847.000000



 4 : 4
time diff : 2,25530868s

result : 59701486.000000



 4 : 5
time diff : 3,423507456s

result : 68846337.000000



 4 : 6
time diff : 3,6036249s

result : 66455432.000000
/ $ 

result : 30000000.000000



 3 : 2
time diff : 1,252228992s

result : 29889346.000000



 3 : 3
time diff : 1,181918976s

result : 42333946.000000



 3 : 4
time diff : 2,505412608s

result : 42371973.000000



 3 : 5
time diff : 2,40436736s

result : 54229885.000000



 3 : 6
time diff : 2,251197248s

result : 54963592.000000



 4 : 1
time diff : 1,71187712s

result : 40000000.000000



 4 : 2
time diff : 1,1847808s

result : 39843879.000000



 4 : 3 1 : 1
time diff : 0,233812224s

result : 10000000.000000



 1 : 2
time diff : 0,250519696s

result : 9967066.000000



 1 : 3
time diff : 1,574413696s

result : 14832258.000000



 1 : 4
time diff : 0,514312992s

result : 14804337.000000



 1 : 5
time diff : 1,369874176s

result : 16773778.000000



 1 : 6
time diff : 1,235290496s

result : 20994610.000000



 2 : 1
time diff : 0,460494912s

result : 20000000.000000



 2 : 2
time diff : 1,502379008s

result : 19933401.000000



 2 : 3
time diff : 1,156850048s

result : 28310072.000000



 2 : 4
time diff : 1,12750033s

result : 28606118.000000



 2 : 5
time diff : 1,273817760s

result : 33747348.000000



 2 : 6
time diff : 1,527771360s

result : 37203788.000000



 3 : 1
time diff : 1,306863104s

result : 30000000.000000



 3 : 2
time diff : 1,251459072s

result : 29882677.000000



 3 : 3
time diff : 1,177976928s

result : 41611146.000000



 3 : 4
time diff : 2,487011328s

result : 45311755.000000



 3 : 5
time diff : 1,908470784s

result : 47332570.000000



 3 : 6
time diff : 3,733742848s

result : 59694979.000000



 4 : 1
time diff : 1,72604352s

result : 40000000.000000



 4 : 2
time diff : 1,3988224s

result : 39888177.000000



 4 : 3
time diff : 1,598989824s

result : 57037847.000000



 4 : 4
time diff : 2,25530868s

result : 59701486.000000



 4 : 5
time diff : 3,423507456s

result : 68846337.000000



 4 : 6
time diff : 3,6036249s

result : 66455432.000000
/ $ 

time diff : 1,530389120s

result : 55700026.000000



 4 : 4
time diff : 2,32875996s

result : 55942186.000000



 4 : 5
time diff : 3,461988608s

result : 67534010.000000



 4 : 6
time diff : 3,26254600s

result : 72469270.000000

 * */
 
 /*
  * ROUND ROBIN
  * 
  *  1 : 1
time diff : 0,233812224s

result : 10000000.000000



 1 : 2
time diff : 0,250519696s

result : 9967066.000000



 1 : 3
time diff : 1,574413696s

result : 14832258.000000



 1 : 4
time diff : 0,514312992s

result : 14804337.000000



 1 : 5
time diff : 1,369874176s

result : 16773778.000000



 1 : 6
time diff : 1,235290496s

result : 20994610.000000



 2 : 1
time diff : 0,460494912s

result : 20000000.000000



 2 : 2
time diff : 1,502379008s

result : 19933401.000000



 2 : 3
time diff : 1,156850048s

result : 28310072.000000



 2 : 4
time diff : 1,12750033s

result : 28606118.000000



 2 : 5
time diff : 1,273817760s

result : 33747348.000000



 2 : 6
time diff : 1,527771360s

result : 37203788.000000



 3 : 1
time diff : 1,306863104s

result : 30000000.000000



 3 : 2
time diff : 1,251459072s

result : 29882677.000000



 3 : 3
time diff : 1,177976928s

result : 41611146.000000



 3 : 4
time diff : 2,487011328s

result : 45311755.000000



 3 : 5
time diff : 1,908470784s

result : 47332570.000000



 3 : 6
time diff : 3,733742848s

result : 59694979.000000



 4 : 1
time diff : 1,72604352s

result : 40000000.000000



 4 : 2
time diff : 1,3988224s

result : 39888177.000000



 4 : 3
time diff : 1,598989824s

result : 57037847.000000



 4 : 4
time diff : 2,25530868s

result : 59701486.000000



 4 : 5
time diff : 3,423507456s

result : 68846337.000000



 4 : 6
time diff : 3,6036249s

result : 66455432.000000
/ $ 

  * */

