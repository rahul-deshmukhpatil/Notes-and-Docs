Process Mangament
	Background:
	-	Process are one of the fundamental abstraction provided by linux.
	-	process = program in execution + related resources like open files, pending signals, adress space, 
	-		data section, processor registers, program counter, kernel data.
	-	Threads are objects of activities in the process.
	-	Kernl schedules threads and not processes.
	-	Threads are just special kind of process in linux.
	
	-	Virtual	processor: abstraction provided by os that process is alone monopolising the system/processor, 
	-		despite being sharing with dozen of processes on time sharing basis.
	-	Virtual memory: abstraction provided by os which allocates and manages memory assinged to the process 
	-		showing that all the memory is owned ny process.
	
	-	Two processes can share some resources like address space, open files.

	System calls
	A> fork();
	-	process begins its life with fork
	-	fork duplicates the process.
	-	fork returns two times at same place 1> in paren where parent resumes the execution 
		2>	in child where child begins the execution.
	- 	in linux fork is actualy implemented via clone.

	B> exec*()
	-	Oftenly after fork returns into child, exec*() family function is called.
	-	This system call creates the new address space and loads new program into it.
	
	C> exit();
	-	exit terminates the program and releases the resources held by the process.

	C> wait();
	-	parent process can inquire about the specefic child process through wait4() system call.
	-	process when completes the execution placed into zombie state, until parent calls wait or waitpid();
	-	wait, waitpid, wait3 and wait4 and c lib functions which internally calls wait.
	
Process Descriptor and Task Struct
	-	Task list is circular list of process(task) descriptors(task_array in OS which use static array to store it).
	-	task_struct is 1.7k struct which contains every possible info required to execute the process.
	
Allocating the Process Descriptor
	-	They are allocated in kernel memory via slab allocater which uses object resue and cache coloring.
	-	Previous to 2.6 kernel, tast_struct was lying at the end of kernel stack of process.
	-	Which was to make essy to calculte pointer to the task struct.
	-	But now its in thread_info struct which contains pointer to task_struct of the process.

Storing process descriptors
	-	Each process is identified by pid(at userspace level), a member into task_struct of type pid_t(process identification number)
	-	This is unique, at default max value is 32768 for compatibility with older linux/unix versions.
	-	This max value could be changed by modifying file /proc/sys/kernel/pid_max or sysctl -w kernel.pid_max=<NUMBER>
	-	At kernel level, process are referred by pointer to task_struct.
	-	Finding current process task_struct is crucial operation.	
	-	'current' is macros which gives pointer to current task_struct
	-	'current_thread_info' gives pointer to the current process thread_info residing at the base of kernel stack.
	-	on x86 arch where few registers are present, its implemented as(considering the	8kb kernel stack) 
		mov	eax, 8192 	;make last 13 bits 0
		andl esp, eax	;make last 13 digits of stack pointer 0 to point base/end.
	-	Architerctures with rich regesters store pointer to current process into the specail register for it.
	
Process states:
	-	Process state is stored in 'state' variable of task_struct.
	A> TASK_RUNNABLE:
	-	Either it is task running or task in the runnable queue.
	
	B> TASK_INTRRUPTABLE
	-	task is waiting for something to happen, disk I/O or lock. After which it will be runnable.
	-	If task in TASK_INTRRUPTABLE recieves a signal it becomes runnable.
	
	C> TASK_UNINTRRUPTABLE	
	-	Similar to TASK_INTRRUPTABLE just that task doesnt wakeup upon recieving any signal.
	-	Used where task must wait to happen some event without intrruption.
	-	Blocking event is expected to happen quickly.
	-	Because these processes doesnt respond to the signal they are less often used.

	D>	TASK_ZOMBIE
	-	Task is terminated but parent has not called wait4().
	-	Process descriptor of the child process is not deallocated till parent inquires through wait();

	E>	TASK_STOPPED
	-	Task is not running, neither it is eligible to run.
	-	Task is put into TASK_STOPPED when it recieves signal like SIGSTOP, SIGTTIN, SIGTSTP or any signal while debugging.
	 

Manipulating the Current Process State:
	
	A> set_task_state(task, state) { task->state = state;}
	-	used to set state of `task` to `state`.
	-	It also provides memory barrier to ordersing on the other process(This is only needed on SMP process)
	-	set_current_state(state); <=> set_task_state(current, state)
	
	

				


	
				
		
