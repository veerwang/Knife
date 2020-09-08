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

#include <climits>

template <typename tchar>
class ZFileT {
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
    ZFileT(const this_string &path) {
	    /* 判断文件是否存在 */
	    auto FileExist = [] (const this_string& path) {
		    std::ifstream fin(path);
		    if(!fin){
			    return false;
		    }
		    else {
			fin.close();
		    	return true;
		    }
	    };

	    /* 创建文件标志 */
	    bool cf = false;
	    /* 如果是写操作，并且文件不存在 */
	    if ( !FileExist(path) ) {
		    std::ofstream fout(path); 
		    cf = true;
		    fout.close();
	    }

	    char *crealpath = new char[PATH_MAX];
	    if ( realpath(path.c_str(),crealpath) )
		    mPath = this_string(crealpath);
	    else
		    mPath = "";

	    delete[] crealpath;
	    crealpath = nullptr;

	    if (cf)
	    	remove(path.c_str());
	    
	    auto GetFileLength = [](this_string& path) {
		    std::ifstream ifs;
		    ifs.open(path, std::ios::binary);
		    if (ifs.is_open()) {
			    auto pos = ifs.tellg();
			    ifs.seekg(0, std::ios::end);
			    auto size = ifs.tellg();
			    ifs.seekg(pos);
			    ifs.close();
			    if ( ifs.good() )
			    	return size;
		    }
	    };

	    mLength = GetFileLength(mPath);
    }

    ~ZFileT() {
    }

    /* 
     * ===  FUNCTION  ======================================================================
     *         Name:  GetPath
     *  Description:  获得文件名的绝对路径 
     * =====================================================================================
     */
    this_string GetPath() {
	if ( mOpenFlag )
		return mPath;
	else
		return "";
    }

    /* 
     * ===  FUNCTION  ======================================================================
     *         Name:  GetFileLength 
     *  Description:  获得文件长度 
     * =====================================================================================
     */
    int GetFileLength() {
	if ( mOpenFlag )
	    return mLength;
	else
		return 0;
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

protected:
	this_string mPath;
	bool mOpenFlag {false};
	char mType;
	int  mLength;

private:
};

template <typename tchar>
class RFileT : public ZFileT<tchar> {
public:
	/* 如果基类没有默认构造函数，需要显式的调用基类的构造函数 */
	/* 注意typename的用法 */
	RFileT(const typename ZFileT<tchar>::this_string &path) : ZFileT<tchar>(path) {
		mifs.open(this->mPath, std::ios::binary);
		if (mifs.is_open())
			this->mOpenFlag = true;
		else
			this->mOpenFlag = false;
	}
	~RFileT() {
		if ( this->mOpenFlag ) {
			mifs.close();
			mifs.good();
		} 
	}

	bool Read(typename ZFileT<tchar>::this_string& msg,int start,int length ) {
		if ( start + length > this->mLength ) {
			return false;
		}

		char *buf = new char[length];
		mifs.seekg(start, std::ios::beg);
		mifs.read(buf,length);
		msg = buf;
		delete[] buf;
		buf = nullptr;
		return true;
	}

	bool ReadAll(std::vector<char> &context) {
		if ( !this->mLength )
			return false;
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

private:
	/*读操作的变量*/
        std::ifstream mifs;
};

template <typename tchar>
class WFileT : public ZFileT<tchar> {
public:
	/* 如果基类没有默认构造函数，需要显式的调用基类的构造函数 */
	/* 注意typename的用法 */
	WFileT(const typename ZFileT<tchar>::this_string &path) : ZFileT<tchar>(path) {
		mofs.open(this->mPath,std::ios::binary|std::ios::app);
		if (mofs.is_open())
			this->mOpenFlag = true;
		else
			this->mOpenFlag = false;
	}
	~WFileT() {
		if ( this->mOpenFlag ) {
			mofs.close();
			mofs.good();
		}
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
	bool Write(const typename ZFileT<tchar>::this_string msg) {
		//写入缓冲区数据到文件
		mofs.write(msg.c_str(), msg.size());
		return mofs.good();
	}
private:
	/*写操作的变量*/
        std::ofstream mofs;
};

typedef ZFileT<char> ZFileA;
typedef ZFileT<wchar_t> ZFileW;

typedef RFileT<char> RFileA;
typedef RFileT<wchar_t> RFileW;

typedef WFileT<char> WFileA;
typedef WFileT<wchar_t> WFileW;
 
#ifdef UNICODE
typedef ZFileW ZFile;
typedef RFileW RFile;
typedef WFileW WFile;
#else
typedef ZFileA ZFile;
typedef RFileA RFile;
typedef WFileA WFile;
#endif // UNICODE

#endif /* INCLUDED_FILEOPT_H */
