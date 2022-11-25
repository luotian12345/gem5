from m5.params import *
from m5.objects.Device import BasicPioDevice
from m5.objects.TrafficGen import *



class AcceleratorOne(BasicPioDevice):
    type = 'AcceleratorOne'
    cxx_header = "dev/acceleratorone.hh"
    cxx_class = 'gem5::AcceleratorOne'

    traffic_gen_1 = Param.TrafficGen("traffic generator in accelerator")
    traffic_gen_2 = Param.TrafficGen("traffic generator in accelerator")
    pio_size = Param.Addr(0x04, "PIO size")
