

#include <string>
#include <iostream>
#include <sstream>
#include <boost/serialization/access.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>


class Base
{
public:
	Base():mTag(0), mText(""){}
	Base(int tag, std::string text):mTag(tag), mText(text){}
 
	int mTag;
	std::string mText;
};

class Sub : public Base
{
public:
	Sub():mNum(0.0){}
	Sub(int tag, std::string text, float num):Base(tag, text), mNum(num){}

	float mNum;
};


namespace boost{
namespace serialization
{
	template<class Archive>
	void serialize(Archive & ar, Base & obj, const unsigned int version)
	{
		ar & obj.mTag;
		ar & obj.mText;
	}
	template<class Archive>
	void serialize(Archive & ar, Sub & obj, const unsigned int version)
	{
		// serialize base class information
		ar & boost::serialization::base_object<Base>(obj);
		ar & obj.mNum;
	}
} // serialization
} // boost

int main(int argc, char** argv)
{
    // 序列化
    Sub obj1(2023, "Non-Intrusive Sub class", 3.14);
	std::ostringstream os;
	boost::archive::binary_oarchive oa(os);
	oa << obj1; // 序列化到一个 ostringstream 里面
 
	std::string content = os.str(); // content 保存了序列化后的数据
    
    // 反序列化
	Sub obj2;
	std::istringstream is(content);
	boost::archive::binary_iarchive ia(is);
	ia >> obj2; // 从一个保存序列化数据的 string 里面反序列化，从而得到原来的对象。
 
	printf("Sub object: mTag: %d, obj2.mText: %s, mNum: %f\n", 
			obj2.mTag, obj2.mText.c_str(), obj2.mNum);

    return 0;
}
