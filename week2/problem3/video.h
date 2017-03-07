#ifndef VIDEO_H_
#define VIDEO_H_
#include <string>
#include <cstdio>
using std::string;

class Video
{
	private:
		int price;
		int length;
		string author;
	public:
		Video();
		void set_price(int price);
		void set_length(int length);
		void set_author(string author);
		void print();
};
#endif
