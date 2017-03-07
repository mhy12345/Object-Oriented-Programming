#include "video.h"

Video::Video()
{
	price = length = 0;
	author = "unknown";
}

void Video::print()
{
	printf("-----Video info-----\n");
	printf("Price:%d\n",price);
	printf("Length:%d\n",length);
	printf("Author:%s\n",author.c_str());
}

void Video::set_price(int price)
{
	this->price = price;
}

void Video::set_length(int length)
{
	this->length = length;
}

void Video::set_author(string author)
{
	this->author = author;
}

