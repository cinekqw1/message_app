
#include <../include/Logger.hpp>

class Thread_1
{

public:

	Thread_1(int a, int b, std::exception_ptr& excpt);

	void operator()() const
	{
		LOG("Thread_1 is running: " + std::to_string(a) + ", " +  std::to_string(b));	

		try
		{
			throw std::runtime_error("my_err");
		}
		catch(...)
		{
			except = std::current_exception();
		}
		
	}

private:

	int a;
	int b;
	std::exception_ptr& except;
};