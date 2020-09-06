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
    /* 
     * ===  FUNCTION  ======================================================================
     *         Name:  ZFileT 
     *  Description:  初始化，获得绝对路径 
     * =====================================================================================
     */
    ZFileT(const this_string &path,char flag) {
	    char *crealpath = new char[PATH_MAX];
	    if ( realpath(path.c_str(),crealpath) )
		    mPath = this_string(crealpath);
	    else
		    mPath = ""; 
	    
	    auto GetFileLength = [](this_string path) {
		    
		    ifs.open(mPath, std::ios::binary);
		    if (mifs.is_open())

		    auto pos = ifs.tellg();
		    ifs.seekg(0, std::ios::end);
		    auto size = ifs.tellg();
		    ifs.seekg(pos);
		    return size;

	    }

	    switch ( flag ) {
	    	case 'r':
			mifs.open(mPath, std::ios::binary);
			if (mifs.is_open())
				mOpenFlag = true;
			else
				mOpenFlag = false;
			mType = flag;
	    		break;
	    	case 'w':
			mofs.open(mPath, std::ios::binary);
			if (mofs.is_open())
				mOpenFlag = true;
			else
				mOpenFlag = false;
			mType = flag;
	    		break;
	    }

	    delete[] crealpath;
	    crealpath = nullptr;
    }

    ~ZFileT() {
	    if ( mOpenFlag ) {
		    switch ( mType ) {
			    case 'r':
				    mifs.close();
				    mifs.good();
				    break;
			    case 'w':
				    mofs.close();
				    mofs.good();
				    break;
		    }
	    } 
    }

    /* 
     * ===  FUNCTION  ======================================================================
     *         Name:  GetPath
     *  Description:  获得文件名的绝对路径 
     * =====================================================================================
     */
    this_string GetPath() {
	return mPath;
    }

    /* 
     * ===  FUNCTION  ======================================================================
     *         Name:  GetFileLength 
     *  Description:  获得文件长度 
     * =====================================================================================
     */
    int GetFileLength() {
	    if ( this->mOpenFlag ) {
		    //获取文件大小
		    if ( mType == 'r' ) {
			    auto pos = mifs.tellg();
			    mifs.seekg(0, std::ios::end);
			    auto size = mifs.tellg();
			    mifs.seekg(pos);
			    return size;
		    }
	    }
	    return 0;
    }

    /* 
     * ===  FUNCTION  ======================================================================
     *         Name:  ReadAll
     *  Description:  获取换从前 
     *
     * \param path 文件路径
     * \param context 内容
     * \return 成功返回true，否则返回false。
     *
     * =====================================================================================
     */
    bool ReadAll(std::vector<char> &context) {
        //获取文件大小
        auto pos = mifs.tellg();
        mifs.seekg(0, std::ios::end);
        auto size = mifs.tellg();
        mifs.seekg(pos);
 
        //读取全部
        context.resize((size_t)size);
        mifs.read(context.data(), size);
        return mifs.good();
    }

    /* 
     * ===  FUNCTION  ======================================================================
     *         Name:  Write 
     *  Description:   
     * \param path 文件路径
     * \param buffer 缓冲区
     * \param size 字节数
     * \return 成功返回true，否则返回false
     * \note 如果文件已经存在，之前的内容都将被清除，如果内容不存在，则创建新的文件
     * =====================================================================================
     */
    bool Write(const void *buffer, size_t size) {
        //写入缓冲区数据到文件
        mofs.write((const char *)buffer, size);
	return mofs.good();
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
	bool mOpenFlag {false};
	char mType;
	int  mLength;

	/*读操作的变量*/
        std::ifstream mifs;
	/*写操作的变量*/
        std::ofstream mofs;
};

typedef ZFileT<char> ZFileA;
typedef ZFileT<wchar_t> ZFileW;
 
#ifdef UNICODE
typedef ZFileW ZFile;
#else
typedef ZFileA ZFile;
#endif // UNICODE

#endif /* INCLUDED_FILEOPT_H */
