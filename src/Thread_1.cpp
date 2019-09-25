
#include "../include/Thread_1.hpp"


Thread_1::Thread_1(int a, int b, std::exception_ptr& e):a(a), b(b), except(e)
{
	LOG("constr");
}


int Thread_1::counter = 0;