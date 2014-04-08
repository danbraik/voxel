#ifndef PROFILTIMER_HPP
#define PROFILTIMER_HPP


#include <iostream>
#include <sys/time.h>

class ProfilTimer
{
	public:
		ProfilTimer();
		
		void begin() {
			clock_gettime(CLOCK_REALTIME, &tbegin);
		}

		void end() {
			timespec tend;
			clock_gettime(CLOCK_REALTIME, &tend);
			
			double texec = (tend.tv_nsec - tbegin.tv_nsec);
			
			std::cout << "Execution time : " << texec << std::endl;
		}
	private:
		timespec tbegin;
};

#endif // PROFILTIMER_HPP
