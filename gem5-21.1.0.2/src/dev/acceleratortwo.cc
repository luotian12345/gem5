#include "dev/acceleratortwo.hh"
#include "params/AcceleratorTwo.hh"

#include <string>
#include "base/trace.hh"
#include "sim/system.hh"
#include "debug/AcceleratorTWO.hh"


namespace gem5
{

AcceleratorTwo::AcceleratorTwo(const Params &p)
    : BasicPioDevice(p, p.pio_size),trafficGen(p.traffic_gen_1)
{
    DPRINTF(AcceleratorTWO, "AcceleratorTwo initalized.\n");
}



Tick
AcceleratorTwo::write(PacketPtr pkt)
{
    DPRINTF(AcceleratorTWO, "The function AcceleratorTWO::write() is called\n");
    
    uint32_t write_data;
    
    //Addr offset = pkt->getAddr() - pioAddr;
    write_data = pkt->getUintX(byteOrder);

    //DPRINTF(AcceleratorTWO, "The number you write to the accelerator is:%d \n", write_data);
    DPRINTF(AcceleratorTWO, "H2 receives a packet from H1 and will response to H1\n");
    trafficGen->trafficControl = 1;

    pkt->makeResponse();
    return pioDelay;
}

Tick
AcceleratorTwo::read(PacketPtr pkt)
{
    DPRINTF(AcceleratorTWO, "The function AcceleratorTWO::read() is called\n");
    
    //uint8_t *data = new uint8_t;
    uint8_t data;
    Addr offset = pkt->getAddr() - pioAddr;
    switch(offset)
    {
        case 0:
            data = 'H';
            break;
        case 1:
            data = 'e';
            break;
        case 2:
            data = 'l';
            break;
        case 3:
            data = 'l';
            break;
        case 4:
            data = 'o';
            break;
        default:
            panic("Invalid regester address\n");
    }

    pkt->setUintX(data, byteOrder);
    //pkt->dataDynamic(data);
    
    pkt->makeResponse();
    //pkt->makeAtomicResponse();
    return pioDelay;
}

} // namespace gem5
