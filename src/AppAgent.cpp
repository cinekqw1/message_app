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

	std::exception_ptr thd_exception_1;
	std::exception_ptr thd_exception_2;


	Thread_1 thred_1(2,4, std::ref(thd_exception_1));
	Thread_2 thred_2(4,8, std::ref(thd_exception_2));
	
	std::thread t1(thred_1);
	std::thread t2(thred_2);

	t1.detach(); 
	t2.detach(); 


	while (true)
	{

		try {
			
	        if (thd_exception_1) std::rethrow_exception(thd_exception_1);
	        if (thd_exception_2) std::rethrow_exception(thd_exception_2);
	        
	    } catch(const std::exception& e) {
	        std::cout << "Caught exception \"" << e.what() << "\"\n";
	        if(strcmp(e.what(), "my_err_thread_1")== 0)
	        {	thd_exception_1 = nullptr;
	        	std::thread t1(thred_1);
	       		t1.detach();
	        }
	        if(strcmp(e.what(), "my_err_thread_2")== 0)
	        {
	        	thd_exception_2 = nullptr;
	        	std::thread t2(thred_2);
	        	t2.detach();
	        }
    }

	}

	

   

}


