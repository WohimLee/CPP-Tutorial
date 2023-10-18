

#include <string>
#include <iostream>
#include <sstream>
#include <boost/serialization/access.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>


class MyClass
{
public:
	MyClass():mTag(0), mText(""){}
	MyClass(int tag, std::string text):mTag(tag), mText(text){}
 
	int mTag;
	std::string mText;
};

namespace boost {
namespace serialization
{
		template<class Archive>
		void serialize(Archive & ar, MyClass & obj, const unsigned int version)
		{
			ar & obj.mTag;
			ar & obj.mText;
		}
} // namespace serialization
} // namespace boost


int main(int argc, char** argv)
{
    // 序列化
    MyClass obj1(2023, "Hello!");
	std::ostringstream os;
	boost::archive::binary_oarchive oa(os);
	oa << obj1; // 序列化到一个 ostringstream 里面
 
	std::string content = os.str(); //content保存了序列化后的数据
    
    // 反序列化
	MyClass obj2;
	std::istringstream is(content);
	boost::archive::binary_iarchive ia(is);
	ia >> obj2; // 从一个保存序列化数据的 string 里面反序列化，从而得到原来的对象。
 
	printf("obj2.mTag: %d, obj2.mText: %s\n", obj2.mTag, obj2.mText.c_str());

    return 0;
}