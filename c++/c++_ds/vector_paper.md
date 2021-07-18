The result of vectors move assigment must be equal to result of moving each element?

if the T has explicit move assigment defined
result will differ depending on below case

	if Allocators do not match
		move assign individual
	else:
		move the data ptr in the vector 


Similarily, in case of copy assigment, if reallocation happens, moves elements to new location and  destructors called on old elemetns.

If the T has explicit move assignemtn which does not copy all members then we have a problem, and different result based on if rellocation happens or not.



class T
{
	const T()
};
