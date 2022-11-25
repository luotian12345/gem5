#include "dev/acceleratorone.hh"
#include "params/AcceleratorOne.hh"

#include <string>
#include <iostream>
#include "base/trace.hh"
#include "sim/system.hh"
#include "debug/AcceleratorONE.hh"

namespace gem5
{

AcceleratorOne::AcceleratorOne(const Params &p)
    : BasicPioDevice(p, p.pio_size), trafficGen_1(p.traffic_gen_1),trafficGen_2(p.traffic_gen_2)
{
}


Tick
AcceleratorOne::write(PacketPtr pkt)
{
    DPRINTF(AcceleratorONE, "The function AcceleratorONE::write() is called\n");

    uint32_t write_data;
    
    //Addr offset = pkt->getAddr() - pioAddr;
    write_data = pkt->getUintX(byteOrder);

    //DPRINTF(AcceleratorONE, "The number you write to the accelerator is:%d \n", write_data);

    //control the traffic generator to send
    if(write_data == 0){
        DPRINTF(AcceleratorONE, "H1 sends a packet to H2\n");
        trafficGen_1->trafficControl = 1;
    }
    else if(write_data == 1){
        DPRINTF(AcceleratorONE, "H1 sends a packet to H3\n");
        trafficGen_1->trafficControl = 2;
    }
    else if(write_data == 2){
        DPRINTF(AcceleratorONE, "H1 sends a write request to DDR\n");
        trafficGen_2->trafficControl = 1;
    }
    else if(write_data == 3){
        DPRINTF(AcceleratorONE, "H1 sends a read request to DDR\n");
        trafficGen_2->trafficControl = 2;
    }
    else
        DPRINTF(AcceleratorONE, "The write_data is useless\n");


    pkt->makeResponse();
    return pioDelay;
}

Tick
AcceleratorOne::read(PacketPtr pkt)
{
    DPRINTF(AcceleratorONE, "The function AcceleratorONE::read() is called\n");
    DPRINTF(AcceleratorONE, "H1 receives a packet from H2\n");

    //uint8_t *data = new uint8_t;
    uint8_t data=20;
    Addr offset = pkt->getAddr() - pioAddr;
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

    pkt->setUintX(data, byteOrder);
    //pkt->dataDynamic(data);
    pkt->makeResponse();
    //pkt->makeAtomicResponse();
    return pioDelay;
}

} // namespace gem5
