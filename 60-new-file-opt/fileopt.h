/*
 * =====================================================================================
 *
 *       Filename:  fileopt.h
 *
 *    Description:  文件操作实现 
 *
 *        Version:  1.0
 *        Created:  2020年09月04日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef INCLUDED_FILEOPT_H
#define INCLUDED_FILEOPT_H

#include <string>
#include <vector>
#include <fstream>
#include <limits.h>

template <typename tchar>
class ZFileT
{
public:
    typedef std::basic_string<tchar, std::char_traits<tchar>, std::allocator<tchar> >
        this_string;
 
    typedef std::basic_istringstream<tchar, std::char_traits<tchar>, std::allocator<tchar> >
        this_istringstream;

public:
    ZFileT(const this_string &path) {
	    char *crealpath = new char[PATH_MAX];
	    if ( realpath(path.c_str(),crealpath) )
		    mPath = this_string(crealpath);
	    else
		    mPath = ""; 

	    delete[] crealpath;
	    crealpath = nullptr;
    }

    this_string GetPath() {
	return mPath;
    }

    /*!
    * 读取文件缓冲区数据
    *
    * \param path 文件路径
    * \param context 内容
    * \return 成功返回true，否则返回false。
    */
    static bool Read(const this_string &path, std::vector<char> &context) {
        std::ifstream ifs;
        ifs.open(path, std::ios::binary);
        if (!ifs.is_open())
            return false;
 
        //获取文件大小
        auto pos = ifs.tellg();
        ifs.seekg(0, std::ios::end);
        auto size = ifs.tellg();
        ifs.seekg(pos);
 
        //读取全部
        context.resize((size_t)size);
        ifs.read(context.data(), size);
        ifs.close();
        return ifs.good();
    }

    /**
    * 将缓冲区的数据写入文件
    *
    * \param path 文件路径
    * \param buffer 缓冲区
    * \param size 字节数
    * \return 成功返回true，否则返回false
    * \note 如果文件已经存在，之前的内容都将被清除，如果内容不存在，则创建新的文件
    */
    static bool Write(const this_string &path, const void *buffer, size_t size) {
        std::ofstream ofs;
        ofs.open(path, std::ios::binary);
        if (!ofs.is_open())
            return false;
 
        //写入缓冲区数据到文件
        ofs.write((const char *)buffer, size);
        ofs.close();
        return ofs.good();
    }

    /*!
    * 读取文件所有文本内容
    *
    * \param path 文件路径
    * \param text 字符串引用
    * \return 如果成功返回true，否则返回false。
    */
    static bool ReadAllText(const this_string &path, std::string &text) {
        std::ifstream ifs(path);
        if (!ifs.is_open())
            return false;
 
        //读取文件
        std::istreambuf_iterator<char>beg(ifs), end;
        text.assign(beg, end);
        ifs.close();
        return ifs.good();
    }
 
    /*!
    * 写入所有文本
    *
    * \param path 文件路径
    * \param text 字符内容
    * \return 如果成功返回true，否则返回false。
    */
    static bool WriteAllText(const this_string &path, const std::string &text) {
        std::ofstream ofs(path);
        if (!ofs.is_open())
            return false;
 
        //内容流入文件
        ofs << text;
        ofs.close();
        return ofs.good();
    }
 
    /*!
    * 读取所有行
    *
    * \param path 文件路径
    * \param lines 行容器
    * \return 如果成功返回true，否则返回false。
    */
    static bool ReadAllLines(const this_string &path, std::vector<std::string> &lines) {
        std::ifstream ifs(path);
        if (!ifs.is_open())
            return false;
 
        //读取到并放到容器中
        std::string line;
        while (!ifs.eof() && !ifs.bad())
        {
            getline(ifs, line);
            lines.push_back(line);
        }
        ifs.close();
        return !ifs.bad();  //此处不能使用ifs.good()，ifs.eof()为true时此函数返回false
    }

private:
	this_string mPath;
};

typedef ZFileT<char> ZFileA;
typedef ZFileT<wchar_t> ZFileW;
 
#ifdef UNICODE
typedef ZFileW ZFile;
#else
typedef ZFileA ZFile;
#endif // UNICODE

#endif /* INCLUDED_FILEOPT_H */
