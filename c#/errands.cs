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


IEnumerable exmaple
using System.Collections;

class MyObjects : IEnumerable<MyObject>
{
	List<MyObject> mylist = new List<MyObject>();

	public MyObject this[int index]
	{
		get { return mylist[index]; }
		set { mylist.Insert(index, value); }
	}

	public IEnumerator<MyObject> GetEnumerator()
	{
		return mylist.GetEnumerator();
	}

	IEnumerator IEnumerable.GetEnumerator()
	{
		return this.GetEnumerator();
	}
}
