
#include <../include/Logger.hpp>
#include <thread>

using namespace std::chrono_literals;

class Thread_1
{

public:

	Thread_1(int a, int b, std::exception_ptr& excpt);

	void operator()() const
	{
		counter++;
		LOG("Thread_1 is running: counter: " + std::to_string(counter));	

		std::this_thread::sleep_for(2s);

		try
		{
			throw std::runtime_error("my_err");
		}
		catch(...)
		{
			except = std::current_exception();
		}
		
	}

	static int counter;

private:

	int a;
	int b;
	std::exception_ptr& except;
};