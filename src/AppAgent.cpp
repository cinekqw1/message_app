#include "../include/AppAgent.hpp"
#include "../include/Stages.hpp"
#include <../include/messages/Messages.hpp>
#include <../include/Logger.hpp>
#include <../include/Thread_1.hpp>
#include <../include/Thread_2.hpp>
#include <thread>
#include <cassert>
#include <string.h>
#include <queue>

AppAgent::AppAgent()
{}



void AppAgent::run()
{

	std::exception_ptr thd_exception;


	Thread_1 thred_1(2,4, std::ref(thd_exception));
	Thread_2 thred_2(4,8, std::ref(thd_exception));
	
	std::thread t1(thred_1);
	std::thread t2(thred_2);

	t1.detach(); 
	t2.detach(); 

	std::queue<std::exception_ptr> l_exceptions;

	while (true)
	{

		if(thd_exception)
		{
			l_exceptions.push(thd_exception);
			LOG("pushed");	
		}
		if( !l_exceptions.empty() && l_exceptions.back() != thd_exception)
		{
			l_exceptions.push(thd_exception);
			LOG("pushed");	
		}

		try {
	        if (!l_exceptions.empty()) {
	        	std::exception_ptr l_exception = l_exceptions.front();
	        	l_exceptions.pop();
	            std::rethrow_exception(l_exception);
	            
	        }
	    } catch(const std::exception& e) {
	        std::cout << "Caught exception \"" << e.what() << "\"\n";
	        if(strcmp(e.what(), "my_err_thread_1")== 0)
	        {	
	        	std::thread t1(thred_1);
	       		t1.detach();
	        }
	        if(strcmp(e.what(), "my_err_thread_2")== 0)
	        {
	        	std::thread t2(thred_2);
	        	t2.detach();
	        }
	        thd_exception = nullptr;
    }

	}

	

   

}


