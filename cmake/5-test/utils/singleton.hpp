#ifndef INCLUDED_SINGLETON_HPP
#define INCLUDED_SINGLETON_HPP

/*!
    \file    singleton.hpp
    \brief   以模板的方式实现单体类的基类

    \version 2024-02-20, V1.0
	\author	 kevin.wang
	\note    无
*/
#include <memory>

namespace WangV {

template <typename T> class Singleton {
    public:
        static T *Instance();

    protected:
    private:
        static std::unique_ptr<T> m_Instance; /* 仅仅是声明 */
};

template <typename T> std::unique_ptr<T> Singleton<T>::m_Instance; /* 定义 */

template <typename T> T *Singleton<T>::Instance() {
        if (m_Instance.get() == 0) {
                m_Instance.reset(new (std::nothrow) T());
        }
        return m_Instance.get();
}
/* 以下的宏定义要非常注意 */
#define ENABLE_SINGLETON(CLASS)                                                \
        friend class Singleton<CLASS>;                                         \
        friend class std::unique_ptr<CLASS>;

} // namespace WangV

#endif /* INCLUDED_SINGLETON_HPP */
