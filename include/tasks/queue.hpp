#ifndef SPEDITOR_TASKS_QUEUE_HPP
#define SPEDITOR_TASKS_QUEUE_HPP
#include "task.hpp"

#include <vector>
#include <memory>

namespace speditor { namespace tasks {

using TaskPtr = std::shared_ptr<Task>;

class Queue : public Task
{
 public:
	Queue(bool strict = true);
	Queue(std::initializer_list<TaskPtr>, bool strict = true);

	virtual bool running();
	virtual bool finished();

	void addTask(TaskPtr);
	void removeTask(TaskPtr);
	std::vector<TaskPtr> getTasks();

	virtual void action(Timepoint);

 private:
	std::vector<TaskPtr> tasks_;
	std::vector<TaskPtr>::iterator current_task_;
	
};

} }

#endif
