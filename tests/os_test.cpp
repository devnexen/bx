/*
 * Copyright 2010-2017 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bx#license-bsd-2-clause
 */

#include "test.h"
#include <bx/os.h>
#include <bx/semaphore.h>
#include <bx/timer.h>

TEST_CASE("getProcessMemoryUsed", "")
{
	REQUIRE(0 != bx::getProcessMemoryUsed() );
//	DBG("bx::getProcessMemoryUsed %d", bx::getProcessMemoryUsed() );
}

TEST_CASE("getTempPath", "")
{
	char tmpDir[512];
	uint32_t len = BX_COUNTOF(tmpDir);
	REQUIRE(bx::getTempPath(tmpDir, &len) );
}

#if !BX_PLATFORM_OSX
TEST_CASE("semaphore_timeout", "")
{
	bx::Semaphore sem;

	int64_t start = bx::getHPCounter();
	bool ok = sem.wait(900);
	int64_t elapsed = bx::getHPCounter() - start;
	int64_t frequency = bx::getHPFrequency();
	double ms = double(elapsed) / double(frequency) * 1000;
	printf("%f\n", ms);
	REQUIRE(!ok);
}
#endif // !BX_PLATFORM_OSX
