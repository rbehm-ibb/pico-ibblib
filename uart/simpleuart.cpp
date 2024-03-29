// ******************************************************
// * copyright (C) 2023 by Reinhardt Behm/rbehm@hushmail.com
// * All Rights reserved
// * created 2/9/2023 by behm
// ******************************************************

#include "simpleuart.h"

//#define USE_TXISR

SimpleUart::SimpleUart(int uartIdx, int txPin, int rxPin, int baud)
	: UartBase(uartIdx, txPin, rxPin, baud)
	// , m_rxq(uint8_t, qsize)
{
}

SimpleUart::~SimpleUart()
{
}

void SimpleUart::uartIsr()
{
	while (uart_is_readable(m_uart))
	{
		uint8_t ch = uart_getc(m_uart);
		m_rxq.put(ch);
	}
#ifdef USE_TXISR
	// TODO: need to handle tx interr.
#endif
}



uint8_t SimpleUart::get()
{
	uint8_t c;
	m_rxq.get(c);
	return c;
}

bool SimpleUart::canTx()
{
#ifdef USE_TXISR
	return ! queue_is_full(&m_txq);
#else
	return uart_is_writable(m_uart);
#endif
}

bool SimpleUart::put(uint8_t c)
{
#ifdef USE_TXISR
	if (queue_try_add(&m_txq, &c))
	{
		// need  to (re-)start tx interr.
		return true;
	}
	return false;
#else
	if (canTx())
	{
//		std::cout << __PRETTY_FUNCTION__  << "[" << c << "]" << std::endl;
		uart_putc_raw(m_uart, char(c));
		return true;
	}
	return false;
#endif
}

void SimpleUart::put(const char *s)
{
//	std::cout << __PRETTY_FUNCTION__ << "<" << s << ">" << std::endl;
	while (*s)
	{
		do {}
		while (! put(*s));
		++s;
	}
}

void SimpleUart::put(const uint8_t *s, size_t n)
{
	while (n)
	{
		do {}
		while (! put(*s));
		++s;
		--n;
	}
}

const IbQueue<uint8_t, SimpleUart::qsize>  &SimpleUart::rxq() const
{
	return m_rxq;
}
