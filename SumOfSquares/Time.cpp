#include "Time.h"

Time::Time() {
	m_start_time = 0;
	m_end_time = 0;
}

Time::~Time() {

}

int64_t Time::ticks() {
	int64_t ticks = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
	return ticks;
}

void Time::start() {
	m_start_time = ticks();
}

void Time::end() {
	m_end_time = ticks();
}

int64_t Time::get_elapsed() {
	return m_end_time - m_start_time;
}