.Net is platform

same runtime, API and lang features for any type of App

Cross platform
	any OS on x64, x86 + ARM32 n 64


.Net SDK : libs and tools to develope and run

CLI : tools to devlope, build, run and publish apps
.net driver to run the framework-dependant apps
Roslyn c#, VB and F# compilers
MSBuild, build engine
.Net runtime: CTS, BaseClassLib, GC, native interop, assembly
.Runtime libs : primitive data types, common utilities 

MSBuild
	csproj provides info for target, tasks of compiling, packaging and publishing
	Sdk identifiers define standard collection of targets and tasks to build, keeping config files small

Nudget : online pakcage managers. .zip package is dlls + version


.Net runs managed code in the CLR, ie code that allocatd on heap and Garage collected.
unmanged code is something thats outside of CLR, code in other languages

CLR
	Virtual machine which runs your app, compiles code JIT, handles mem allocation  

JIT compiler
	compiles MSIL into machine code and runs. Its runtime process and JIT tries balance between optimizing code time vs saving coming from
	the optimization. JIT knows the hardware so you dont need to ship platform specific implementations

	JIT could do tiered compilation ie recompile methods to produce highly tuned version of code

AOT compiler Ahead of Time
	To save runtime JIT cost, and loading cost
	100% target native code is generated ie in case of MacOS
	other type is most of the code is AOT compiled while some left for JIT (generic code). This is ready-to-run R2R compilation and only supported
	for the self contained apps for a specific targets. This ships both MSIL (for some scenarios) and JIt code so binaries are larger

Automatic Memeory Mgmt
	runtime allocated from managed heap, and when runs out of memory GC kicks in and frees memory
	CLR ensures that memory is not allocated out of bounds and CLR ensures memeory safty by allowing only to access memory allocated

Unmanaged code:	
	these resources are not maintained by .NET runtime
	.NEt provides IDisposable interface which calls the Dispose method implementation in which you can free the resources not managed by
	the .NET runtime ie file handle used in the FileStream
	Garbage collection runtime is not sure. So better to free resources held earliest possible with the Dispose

Publishing
	self-contained app : 
		has runtime and all required-libs, app code and dependant libs
		can run on the specific target machine
		can optionally published as AOT compilation
	
	framework dependant
		only has app and dependant libs
		need runtime on the target machine
		Executable is platform specific but dll are not

	you can install multiple versions on runtime to run differnt apps with different target versions

	Executables are produced for the specific OS only

Runtime libs
	core set is called BaseClassLibs
	all libs are called runtime libs includes general purpose, workload-specific, utility libs

	Basic premitive types
	Generic libs System.Collection
	FileStream and System.IO 
	Json and XML serializer
	Network
	Hight performance like Span, NumericVector, Pipelines

Data access
	.Net provide ORM object relational mapping between .Net objects and databases object to write SQL queries

	Entity Framework EF supports the ORM and it supports the multiple database engines making easy to write db code 

LINQ : Language integrated queries
	easy to operate on data, indepedant of underlying data source

Advance scenarios:
	NativeInterop:
		every "Op"rating system provide an API to uses its system services(system calls). .NET provides several ways to call those APIs.
		Main way is via PInvoke or Platform invoke supported on the Linux and Windows. Windows only ways is COM interop (component) 
	Unsafe code: 
		powerful but discouraged

	
====================
Architecture components
	.Net app is devloped and compile and run against the target .Net standard implementation
	.Net standarad
		API specification common among .NET implementations of the standard

	.Net standard implementation or multiple .NETs implement the BCL API.
	.Net standard is the API contract specification against which programs are compiled

	If you compile your app against one .NET standard it could run on any implementation of that .NET standard 
	ie ContractID or OS+Processor

	.NET implementations or Platforms
		.NET 5.0 : cross platform, maintained by windows
		.NET framework
		mono
		UWP 

	.NET implementation includes
		runtime CLR : to run app, .Net Runtime, .Net Framework runtime
		BCL libararies 
		Optionally any framework ie ASP.NET
		Optionally dev tools to develope, build, develope 
			Roslyn
			.NET project system
			MSBuild
			NuGet
			CAKE or FAKE

	.NET : cross platform implementation

	
===========================
Class libraries
	platform specific: runs only on platform ie Windoes registry on .Net Framework
	protable	: runs everywhere

	.Net Standard libraries
		They replace both Platform-specific and portable librares
		each .Net standard is set of libraries and .Net implementations must either fully support or not at all the
		API contract of the libraries
==============================
.Net standard
	Versioing of the API available to implement and implmented by the .Net Platform implementations 
	like
		.Net and .Net Core
		.Net Framework
		mono
		unity
		UWP
		Xamrin
	Higher .Net version more are the API and each .Net platform claiming to support the .Net standard version needs to
	implement the additional APIs
	.Net implementation support all the lower .Net standards also than the standard they claim to support
	
	so lower the .Net standard version your library implments, more apps and libraries can use it


	.Net standard is a language specification ie c++11, c++14, c++17
	.Net platforms are different compilers like gcc, clang etc 
	and .Net platform versions are the compiler versions 
	
