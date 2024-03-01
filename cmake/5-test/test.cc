/*!
    \file    main.cc
    \brief   测试程序

    \version 2024-02-14, V1.0
	\author	 kevin.wang
	\note    无 
*/

#include "utils/module.h"
#include "api.h"

#include <cstdlib>
#include <unistd.h>

class Base : public WangV::Singleton<Base> {
	public:
		int id;

	public:
		virtual ~Base() {;}

	private:
		Base() { id = 10;}
		Base(const Base &) {;}

		ENABLE_SINGLETON(Base);
};

/*!
	\brief			test function entry	
	\param[in]		输入参数
	\param[out]		输出参数
	\retval			返回值
*/
int
main(int argc, char **argv) {
	int opt;
	while((opt = getopt(argc, argv, "abh:")) != -1) {
		switch (opt) {
			case 'a': {
						  int intvalue = 0;
						  std::string numstr = "16";
						  intvalue = WangV::string_to_number<int>(numstr);
						  if (intvalue != 16) {
							  return EXIT_FAILURE;
						  }

						  int inputvalue = 32;
						  std::string outputvalue = WangV::number_to_string(inputvalue);
						  if ( outputvalue != "32" ) {
							  return EXIT_FAILURE;
						  }

						  WangV::Value<int> mID;
						  mID.set(12);
						  if (mID.get() != 12) {
							  return EXIT_FAILURE;
						  }

						  return EXIT_SUCCESS;
					  }
					  break;
			case 'b': {
						  Base *base = Base::Instance();
						  if (base->id == 10) {
							  return EXIT_SUCCESS;
						  }
					  }
					  break;
			case 'h': {
						  std::cout << optarg << std::endl;
						  return EXIT_SUCCESS;
					  }
					  break;
			default:
					  break;
		}
	}

	return EXIT_FAILURE;
}
