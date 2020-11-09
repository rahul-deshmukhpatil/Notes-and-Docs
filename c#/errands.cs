Only one class can have Main in project
	if two classes have it, compiletime  error : two  mains, more than one entry points
	or if none have it, then as well, no Main found in case of project output is exe
	: no entry point
	 If void is returned from Main, the exit code will be implicitly 0.
	 Async Main return values
	 	static async Task<int> Main(string[] args)
		{
			return await AsyncConsoleWork();
		}
