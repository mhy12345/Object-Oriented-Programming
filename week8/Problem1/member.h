#ifndef MEMBER_H
#define MEMBER_H
#include <string>
#include <iostream>
using std::string;

class Member{
	private:
		const string name;//名字
		const int age;//年龄
	public:
		Member():name("???"),age(0){}
		Member(const string name,const int age):name(name),age(age){}
		void printInfo()const;
};

#endif //MEMBER_H
