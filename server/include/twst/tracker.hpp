//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWST_SERVER_TRACKER_HPP
#define TWST_SERVER_TRACKER_HPP


#include <mlk/time/time.h>
#include <mlk/log/log.h>


namespace twst
{
	class tracker
	{
		static constexpr mlk::ullong m_update_interval{120000}; // update all 2 minutes

		mlk::hrs_time_pnt m_last_update{mlk::tm::time_pnt()};

	public:
		tracker() = default;

		int run()
		{
			for(;;)
			{
				if(mlk::tm::timed_out(m_last_update, m_update_interval))
				{
					this->update();
					m_last_update = mlk::tm::time_pnt();
				}
				mlk::tm::sleep(1);
			}

			return 0;
		}

	private:
		void update()
		{
			mlk::lout("twst::tracker::update") << "updating...";
		}
	};
}



#endif // TWST_SERVER_TRACKER_HPP
