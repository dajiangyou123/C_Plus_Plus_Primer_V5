#ifndef _BULK_QUOTE_H
#define _BULK_QUOTE_H

#include "quote.h"
#include <string>

class Bulk_quote: public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double p, std::size_t qty, double disc): Quote(book, p), min_qty(qty), discount(disc){}

	//覆盖基类的函数版本以实现基于大量购买的折扣政策
	double net_price(std::size_t cnt) const override
	{
		if(cnt >= min_qty)
			return cnt * (1 - discount) * price;     //这与现实生活中折扣的计算方式不太一样
		else
			return cnt * price;
	}

private:
	std::size_t min_qty = 0;   //适用折扣的最低购买量
	double discount = 0.0;		//以小数表示的折扣额
};


#endif
