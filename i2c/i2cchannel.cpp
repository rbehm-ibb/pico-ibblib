// ******************************************************
// * copyright (C) 2024 by Reinhardt Behm/rbehm@hushmail.com
// * All Rights reserved
// * created 2024-02-03 by behm
// ******************************************************

// #include <iostream>
// #include <debug.h>
#include <hardware/gpio.h>
#include "i2cchannel.h"
#include <pico/binary_info.h>

I2cChannel::I2cChannel(i2c_inst *i2c, uint sda, uint scl)
	: m_channel(i2c)
	, m_sda(sda)
	, m_scl(scl)
{
	i2c_init(m_channel, 400 * 1000);
	gpio_set_function(m_sda, GPIO_FUNC_I2C);
	gpio_set_function(m_scl, GPIO_FUNC_I2C);
	gpio_pull_up(m_sda);
	gpio_pull_up(m_scl);
	bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));
}

bool I2cChannel::devOk(uint8_t addr) const
{
	uint8_t dummy;
	int rc = i2c_read_blocking(m_channel, addr, &dummy, 1, true);
	return rc == 1;
}

int I2cChannel::write(uint8_t addr, const uint8_t *data, size_t len)
{
	// uint8_t dummy;
	int rc = i2c_write_blocking(m_channel, addr, const_cast<uint8_t*>(data), len, true);
	return rc;
}

int I2cChannel::read(uint8_t addr, uint8_t *data, size_t len) const
{
	// uint8_t dummy;
	int rc = i2c_read_blocking(m_channel, addr, data, len, true);
	// Debug::dump(data, len, __PRETTY_FUNCTION__);
	// std::cout << "len=" << len << "rc="<< rc << std::endl;
	return rc;
}
