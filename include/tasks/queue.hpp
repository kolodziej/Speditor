#ifndef SPEDITOR_TASKS_QUEUE_HPP
#define SPEDITOR_TASKS_QUEUE_HPP
#include "task.hpp"

#include <vector>

namespace speditor { namespace tasks {

using TaskPtr = std::shared_ptr<Task>;

class Queue : public Task
{
public:
	Queue() {}
	Queue(std::initializer_list<TaskPtr>);

	virtual void begin();
	virtual void loop(Timepoint);
	virtual bool isRunning();
	virtual bool isFinished();

	void addTask(TaskPtr);
	void removeTask(TaskPtr);
	std::vector<TaskPtr>&& getTasks();


private:
	std::vector<TaskPtr> tasks_;
	
};

} }

#endif
