#include "iostream"
 #include <typeinfo>


using namespace std;

template<typename writer>
class logger {
public:
  void warn(const std::string& msg) {
	   cout << "DataType: " << typeid(this).name() << "::warn" << endl;
       static_cast<writer *>(this)->write("WARN", msg);
  }
};

class file_logger: public logger<file_logger>
{
public:
  void write( const std::string& kind, const std::string& msg ) {
		cout << typeid(this).name() << "::" << kind << " <msg> " << msg << endl;
  }
};

class network_logger: public logger<network_logger> {
public:
  void write( const std::string& kind, const std::string& msg ) {
		cout << "NetworkLogger: Warn" << endl;
  }
};

main()
{
	file_logger fl;
	std::string str("CRTP pattern found");
	fl.warn(str);
}
