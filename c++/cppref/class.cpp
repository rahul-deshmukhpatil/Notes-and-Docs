Class has
	members and funcs
		static and non-static
	enclosed enum and class decls
	using class and enum
	template members variables, funcs

	polymorphic classes with virtual functions
		both pointer and ref :
			can be used to call correct virtual funcs
			also typeid(*ptToBase) : gives derived typeid
			also typeid(refToBase) : gives derived typeid
	
	Trivial :  
		all base and members are trivial
		has atleast 1 trivial copyable:
			eligible(declared and not deleted)
			trivial: doesnt do anything special and byte by byte copying works
			because compiler might optimize default trivial constr to faster
			byte by byte copying

			copy or move constr 
			copy or move = op

	standard layout: 
		all base and members are standard layout
		all members have only 1 access public/private/protected
		only 1 class has non-static members
		no virtual function

		basically the compiler resolves to same binary format from class def
		and objects could be consumed from both C or C++
		could be read/written directly from file using de/serialization 



			



