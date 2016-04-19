#include <pthread.h>
class MutexLock
	{
	public:
		MutexLock();
		~MutexLock();

		void lock();
		void unlock();
	private:
		pthread_mutex_t mutex;
	};

	MutexLock::MutexLock()
	{
	    pthread_mutex_init(&mutex,NULL);
	}

	MutexLock::~MutexLock()
	{
	    pthread_mutex_destroy(&mutex);
	}
	void MutexLock::lock()
	{
	    pthread_mutex_lock(&mutex);
	}

	void MutexLock::unlock()
	{
	    pthread_mutex_unlock(&mutex);
	}

	int main()
	{
	    return 0;
	}
