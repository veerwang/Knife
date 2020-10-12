/*
 * =====================================================================================
 *
 *       Filename:  newtemplate.hpp
 *
 *    Description:  自定义新内存申请模板 
 *
 *        Version:  1.0
 *        Created:  2020年10月12日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef INCLUDED_NEWTEMPLATE_HPP
#define INCLUDED_NEWTEMPLATE_HPP

#include <iostream>
#include <exception>
#include <cstdint>

namespace WangV {

// new type exception define
struct OverMaxLength : public std::exception {
	const char * what () const throw () {
		return "OverMaxLength";
	}
};

template<typename T>
class New {
  public:
	  // becareful, default creator function 
	  New() = default;

	  T* operator [](uint64_t len) {
		try {
			if ( len > MaxLength_ )
				throw OverMaxLength();
			return new T[len];
		}catch( OverMaxLength &e ) {
			std::cerr<<e.what()<<std::endl;
		}catch( std::exception &e ) {
			std::cerr<<"unknown exception"<<std::endl;
		}
		return nullptr;
	  }

  protected:
	
  private:
	  // Max buffer do not longer than 1024 * 1024
	  static constexpr uint64_t MaxLength_ = 1024 * 1024;
};

#define New(T,N) New<T>()[N]

} /* namespace WangV */
#endif /* INCLUDED_NEWTEMPLATE_HPP */
