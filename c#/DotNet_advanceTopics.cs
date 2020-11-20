Managed code
	high level lang like c#, f#, VB compiler produce MSIL code,
	which CLR reads and runs using the JIT under its context
	CLR manages the mem allocated and de-allocation, type safty, security boundries

	c/C++ code is umanaged where programmer is responsible for everythig

IL and execution
	all languages output common IL code
	CLR runs IL code buy JITing 
	IL is called Common Intermidiatory Language or MS microsoft IL


Unmanaged code interoperability
	if you want run code outside of BCL or CLR, you cross the boundry into unmanaged code
	CLR might wrap those functions and call the P/Invoke 


Automatic Memory Management
	programmer need not to remember to free allocations
	no mem leak

Allocating Memeory
	CLR allocated the cotinous chunk of memory called Managed heap
	refernce types are allocated in it
	heap maintains the next free address to be allocated
	GC allocates the memory from heap whenever needed

	Allocating memory from heap is fast and simple operation

Realsing memory
	GC frees mem by analysing all roots
	roots are starting point of the mem alloctions
	ie static fields, globa var, thread stack, registers

	GC has access to all CLR and JIT active roots and it creates graph of
	all active objects

	Objects that are not in the graph are unreachable from the application-s roots. The garbage collector considers unreachable objects garbage and will release the memory allocated for them. During a collection, the garbage collector examines the managed heap, looking for the blocks of address space occupied by unreachable objects. As it discovers each unreachable object, it uses a memory-copying function to compact the reachable objects in memory, freeing up the blocks of address spaces allocated to unreachable objects. Once the memory for the reachable objects has been compacted, the garbage collector makes the necessary pointer corrections so that the application-s roots point to the objects in their new locations. It also positions the managed heap's pointer after the last reachable object. Note that memory is compacted only if a collection discovers a significant number of unreachable objects. If all the objects in the managed heap survive a collection, then there is no need for memory compaction.

	GC maintains generations of the objects allocated in the heap. ie 0th, 1st, 2nd, 3rd.
	0th gen objects are more likely new and candidate for the freeing space. 
	0th gen objects are the freed first and then if sufficient space is not available then other generations are looked for.
	
