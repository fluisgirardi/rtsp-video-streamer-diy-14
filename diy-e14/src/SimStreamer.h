#pragma once

#include "JPEGSamples.h"
#include "CStreamer.h"

unsigned char *capture_jpg;
unsigned char *octo_jpg;
unsigned int octo_jpg_len, capture_jpg_len;

class SimStreamer : public CStreamer
{
    bool m_showBig;
public:
    SimStreamer(SOCKET aClient, bool showBig);

    virtual void    streamImage(uint32_t curMsec);
};


SimStreamer::SimStreamer(SOCKET aClient, bool showBig) : CStreamer(aClient, showBig ? 800 : 640, showBig ? 600 : 480)
{
    m_showBig = showBig;
}

void SimStreamer::streamImage(uint32_t curMsec)
{
    if(m_showBig) {
        BufPtr bytes = capture_jpg;
        uint32_t len = capture_jpg_len;

        streamFrame(bytes, len, curMsec);
    }
    else {
        BufPtr bytes = octo_jpg;
        uint32_t len = octo_jpg_len;

        streamFrame(bytes, len, curMsec);
    }
}
