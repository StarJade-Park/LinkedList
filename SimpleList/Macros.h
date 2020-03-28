#pragma once

#ifdef _DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
#endif // _DEBUG

#define SAFE_RELEASE(p) \
if ( nullptr != p ) \
{ \
	delete p; \
	p = nullptr; \
}
