Three main || modes

1. Async await
	await basically yeild
	you have to declare methods as async to use await
	Two modes
	1> IO bound processes for network and file I/O just wait for task to complete
		native interop basically returns the Task/Task<Result> object from boundry
		if its async operation gonna take time
	2> Processory bound operation create a Task.Run(lambda) object and await on the
		its calling the object
		ie  
		async Task<string> func()
		{
			var runMethod = Task.Run(() => {Method(args)})
			var result = await runMethod;
			return result = "Done":"NotDone";
		}

2. TPL Task Parallel library
	to run Parallel Linq Queries and Parallel Data strucutres
	They take advantage of System.Linq.ParallelEnumerable

	var evenNums = from num in source.AsParallel()
	               where num % 2 == 0
				    select num;


3. Threading
	Main thread for GUI, user input output
	other threads for background computation
	class : System.Threading.Thread
		acepts lambda to be called along with the arguments
	 Thread.Abort to kill thread
	 Thread.Join to wait for finishing taks
	 Thread.Sleep to pause
	 Thread.Interuppt to wake up

	 IsAlive,
	 IsBackground
	 Name
	 Priority
	 ThreadState
