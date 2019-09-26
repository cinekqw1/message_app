
#include "../include/Thread_2.hpp"


Thread_2::Thread_2(int a, int b, std::exception_ptr& e):a(a), b(b), except(e)
{
	LOG("constr");
}


int Thread_2::counter = 0;