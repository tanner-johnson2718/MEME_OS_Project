Q: ThreadPool/Q.h ThreadPool/Q.cc
	g++ -c ThreadPool/Q.h ThreadPool/Q.cc

Q_Test: Q ThreadPool/Q.h ThreadPool/Q_Test.cc
	g++ -o test Q.o ThreadPool/Q_Test.cc
	./test

timer: Timer/timer.h Timer/timer.cc
	g++ -c Timer/timer.h Timer/timer.cc

timer_test: timer Timer/timer_test.cc
	g++ -o test timer.o Timer/timer_test.cc
	./test

threadPool: Q ThreadPool/threadPool.cc
	g++ -c ThreadPool/Q.h ThreadPool/threadPool.cc

perf: threadPool timer ThreadPool/PerfTest.cc
	g++ -o test Q.o timer.o threadPool.o ThreadPool/PerfTest.cc -pthread
	./test

orbit: threadPool ThreadPool/orbit.cc
	g++ -lm -pthread ThreadPool/orbit.cc ThreadPool/threadPool.cc Q.o threadPool.o -o test
	./test

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.gch" -type f -delete
	find . -name "test" -type f -delete
	
