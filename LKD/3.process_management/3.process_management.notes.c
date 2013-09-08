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
	

	
				
		
