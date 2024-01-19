namespace whether
{
	class string
	{
	public:
		
		string(char* str="")  //构造函数
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);
		}

		~string()      //析构函数
		{
			delete[] _str;
			_str = nullptr;
		}

		//编译器默认生成的是浅拷贝
		string(const string& s)//拷贝构造 （深拷贝）
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		string& operator=(string s)//赋值运算符重载
		{
			swap(_str, s._str);
                                                   return *this;
		}

		char& operator[](size_t i)    //str[i] -> str.operator[](*this,i)
		{
			return _str[i];
		}

		char* c_str()
		{
			return _str;
		}

		size_t size()
		{
			return strlen(_str);
		}

	private:    char* _str;
	};
}