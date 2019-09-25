#include "../include/AppAgent.hpp"
#include "../include/Stages.hpp"
#include <../include/messages/Messages.hpp>
#include <../include/Logger.hpp>
#include <../include/Thread_1.hpp>
#include <thread>
#include <cassert>


AppAgent::AppAgent()
{}



void AppAgent::run()
{

	std::exception_ptr thd_exception;


	Thread_1 thred_1(2,4, std::ref(thd_exception));
	
	std::thread t1(thred_1);

	t1.detach(); 

	while (true)
	{


	std::this_thread::sleep_for(1s);

	try {
        if (thd_exception) {
            std::rethrow_exception(thd_exception);
        }
    } catch(const std::exception& e) {
        std::cout << "Caught exception \"" << e.what() << "\"\n";
        thd_exception = nullptr;
        
        std::thread t1(thred_1);
        t1.detach();
    }

	}

	

   

}


