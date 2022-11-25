#include "dev/acceleratorthree.hh"
#include "params/AcceleratorThree.hh"

#include <string>
#include <iostream>
#include "base/trace.hh"
#include "sim/system.hh"
#include "debug/AcceleratorTHREE.hh"

namespace gem5
{

AcceleratorThree::AcceleratorThree(const Params &p)
    : BasicPioDevice(p, p.pio_size), trafficGen_1(p.traffic_gen_1),counter(0)
{
}


Tick
AcceleratorThree::write(PacketPtr pkt)
{
    DPRINTF(AcceleratorTHREE, "The function AcceleratorTHREE::write() is called\n");

    //uint32_t write_data;
    
    Addr offset = pkt->getAddr() - pioAddr;
    //write_data = pkt->getUintX(byteOrder);

    DPRINTF(AcceleratorTHREE, "H3 receives packet from H1\n");
    counter++;


    pkt->makeResponse();
    return pioDelay;
}

Tick
AcceleratorThree::read(PacketPtr pkt)
{
    DPRINTF(AcceleratorTHREE, "The function AcceleratorTHREE::read() is called\n");

    //uint8_t *data = new uint8_t;
    //uint8_t data=20;
    //Addr offset = pkt->getAddr() - pioAddr;
    /*
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
            panic("Invalid regester address.\n");
    }
    */


    pkt->setUintX(counter, byteOrder);
    //pkt->dataDynamic(data);
    pkt->makeResponse();
    //pkt->makeAtomicResponse();

    if(counter!=0)
        counter--;

    return pioDelay;
}

} // namespace gem5
