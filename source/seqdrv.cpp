#include "spm/seqdrv.h"
#include "spm/system.h"
#include <cstring>

namespace spm::seqdrv
{
    s32 seqGetSeq()
    {
        return now_seq;
    }
    void seqInit_SPMARIO()
    {
        memset(&seqWork, 0, sizeof(SeqWork));
    }
    void seqSetSeq(s32 seqNum, char * map, char * bero)
    {
        next_seq = seqNum;
        next_map = map;
        next_bero = bero;
    }
    void seqMain()
    {
        if (next_seq != now_seq)
        {
            if (now_seq != -1)
            {
                system::sysWaitDrawSync();
                seq_data[now_seq].exit(&seqWork);
            }

            prev_seq = now_seq;
            memset(&seqWork, 0, sizeof(SeqWork));
            
            now_seq = next_seq;
            seqWork.seq = next_seq;
            seqWork.stage = 0;
            
            seqWork.next_map = next_map;
            seqWork.next_bero = next_bero;
            
            seqWork.afterFunc = NULL;
            
            seq_data[next_seq].init(&seqWork);
        }
        seq_data[now_seq].main(&seqWork);
        
        if (seqWork.afterFunc != NULL)
            seqWork.afterFunc();
        
        return;
    }
}
