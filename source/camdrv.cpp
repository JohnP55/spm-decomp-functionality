#include <spm/camdrv.h>

namespace spm::camdrv {

CamEntry* camGetCurPtr()
{
	return camPtrTbl[currentCamNo];
}
s32 camGetCurNo()
{
	return currentCamNo;
}

}