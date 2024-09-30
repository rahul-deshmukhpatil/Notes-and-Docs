bitand  // using bin = std::bitset<8>; bin1 & bin2
bitor
bool
break
case


1. alignas

struct s1 final {};
struct alignas(2) s2 final {};

 static_assert(alignof(s1) == 1);
 static_assert(alignof(s2) == 2);

2. alignof
alignof(std::max_align_t)
alignof(std::string)
alignof(ClassType)

alternative operators
3. and,  &&
4. and_eq, &=

5. asm

int main() noexcept
{
    const char* const c_string = "Hello, world!\n";
    asm
    (R"(
        movq $1, %%rax                 # syscall number for sys_write ,		rax = 1u 
        movq $1, %%rdi                 # file descriptor 1 (stdout)			rdi = 1u
        movq %0, %%rsi                 # pointer to the c‐string			rsi = 0th arg
        movq %1, %%rdx                 # length of the c‐string				rdx = 1st arg
        syscall                        # invokes an OS system-call handler
    )"
    :                                  // no output operands				: no output reg
    :   "r"(c_string),                 // input: pointer to the c‐string	: 0th arg
        "r"(std::strlen(c_string))     // input: size of the c‐string		: 1st arg
    :   "%rax", "%rdi", "%rsi", "%rdx" // clobbered registers				: call systemcall with this order/convention of registers 
    );
}


6. atomic

	Transactional memory
	atomic : either occurs or not
	isolated: cant see any half written writes, as atomic blocks might run in parallel 

	HW support with fallback to SW
	
	implmented with optimistic concurrency: i.e other parallel executions will not interfere as best case
	but	if see the write by another execution
		- rollback
		- retry
	this is why it could only call another transaction safe code

	accessing same variable inside and outside transaction is  data race


7. synchronized: 
		block with its own global lock
		can call the 
		can call transaction unsafe code
	
	
	
